#pragma once

#include "tutorial.pb.h"
#include "tutorial.grpc.pb.h"

#include <vector>
#include <mutex>
using namespace std;

using namespace routeguide;
using grpc::Status;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::ServerReader;
using grpc::ServerReaderWriter;

class RouteGuideImpl final : public routeguide::RouteGuide::Service {
public:
	explicit RouteGuideImpl(const std::string& db);

	virtual Status getFeature(ServerContext* context, const ::routeguide::Point* point, ::routeguide::Feature* feature) override;
	virtual Status listFeature(ServerContext* context, const ::routeguide::Rectangle* rectangle, ServerWriter< ::routeguide::Feature>* writer) override;
	virtual Status recordRoute(ServerContext* context, ServerReader< ::routeguide::Point>* reader, ::routeguide::RouteSummary* summary) override;
	virtual Status routeChat(ServerContext* context, ServerReaderWriter< ::routeguide::RouteNote, ::routeguide::RouteNote>* stream) override;

private:
	vector<Feature> feature_list_;
	mutex mu_;
	vector<RouteNote> received_notes_;
};