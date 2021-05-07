//
// Simple listener.c program for UDP multicast
//
// Changes:
// * Compiles for Windows as well as Linux
// * Takes the port and group on the command line
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#ifdef _WIN32
#include <Winsock2.h> // before Windows.h, else Winsock 1 conflict
#include <Ws2tcpip.h> // needed for ip_mreq definition for multicast
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#endif

#pragma comment (lib, "Ws2_32.lib")

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <string>

#define MSGBUFSIZE 256

constexpr int port = 10086;

// 本地组播
#define group "239.255.255.250"

int createMultiCastListener(int port, int id);
int createMultiCastSender(int port);

int main(int argc, char *argv[])
{
	if (argc != 2){
		return -1;
	}

#ifdef _WIN32
	WSADATA wsaData;
	if (WSAStartup(0x0101, &wsaData)) {
		perror("WSAStartup");
		return 1;
	}
#endif

	if (argv[1][0] == 'c') {
		std::vector<std::thread> ths;
		for (int i = 0; i < 10; ++i) {
			ths.emplace_back(&createMultiCastListener, port, i);
		}

		for (auto& th : ths) {
			th.join();
		}
	}
	else if (argv[1][0] == 's') {
		createMultiCastSender(port);
	}
	else {

	}

#ifdef _WIN32
	//
	// Program never actually gets here due to infinite loop that has to be
	// canceled, but since people on the internet wind up using examples
	// they find at random in their own code it's good to show what shutting
	// down cleanly would look like.
	//
	WSACleanup();
#endif

	return 0;
}

int createMultiCastListener(int port, int id) {
	// create what looks like an ordinary UDP socket
//
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // 第三个参数是协议，但是输入了个0
	if (fd < 0) {
		perror("socket");
		return 1;
	}

	// allow multiple sockets to use the same PORT number
	//
	u_int yes = 1;
	if (
		setsockopt(
			fd, SOL_SOCKET, SO_REUSEADDR, (char*)&yes, sizeof(yes)
		) < 0
		) {
		perror("Reusing ADDR failed");
		return 1;
	}

	// set up destination address
	
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // differs from sender
	addr.sin_port = htons(port);

	// bind to receive address
	//
	if (bind(fd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
		perror("bind");
		return 1;
	}

	// use setsockopt() to request that the kernel join a multicast group
	//
	struct ip_mreq mreq;
	mreq.imr_multiaddr.s_addr = inet_addr(group);
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
	if (
		setsockopt(
			fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mreq, sizeof(mreq)
		) < 0
		) {
		perror("setsockopt");
		return 1;
	}

	// now just enter a read-print loop
	//
	while (1) {
		char msgbuf[MSGBUFSIZE];
		int addrlen = sizeof(addr);
		int nbytes = recvfrom(
			fd,
			msgbuf,
			MSGBUFSIZE,
			0,
			(struct sockaddr *) &addr,
			&addrlen
		);
		if (nbytes < 0) {
			perror("recvfrom");
			return 1;
		}
		msgbuf[nbytes] = '\0';
		printf("%d : %s\n", id, msgbuf);
	}
}

int createMultiCastSender(int port)
{
	const int delay_secs = 1;
	const char *message = "Hello, World!";

	// create what looks like an ordinary UDP socket
	//
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd < 0) {
		perror("socket");
		return 1;
	}

	//// set up destination address
	////
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(group);
	addr.sin_port = htons(port);

	// join group
	struct ip_mreq imr;
	imr.imr_multiaddr.s_addr = inet_addr(group);
	//imr.imr_sourceaddr.s_addr = srcaddr;
	imr.imr_interface.s_addr = htonl(INADDR_ANY);
	if (setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&imr, sizeof(imr)) < 0) {
		perror("setsockopt");
		return 1;
	}

	// now just sendto() our destination!
  //
	while (1) {
		char ch = 0;
		int nbytes = sendto(
			fd,
			message,
			strlen(message),
			0,
			(struct sockaddr*) &addr,
			sizeof(addrinfo)
		);
		if (nbytes < 0) {
			perror("sendto");
			return 1;
		}

#ifdef _WIN32
		Sleep(delay_secs * 1000); // Windows Sleep is milliseconds
#else
		sleep(delay_secs); // Unix sleep is seconds
#endif
	}
}