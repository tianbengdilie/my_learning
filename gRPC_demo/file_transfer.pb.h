// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: file_transfer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_file_5ftransfer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_file_5ftransfer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015006 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_file_5ftransfer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_file_5ftransfer_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_file_5ftransfer_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_file_5ftransfer_2eproto_metadata_getter(int index);
namespace filetransfer {
class FileMetadata;
struct FileMetadataDefaultTypeInternal;
extern FileMetadataDefaultTypeInternal _FileMetadata_default_instance_;
class FileName;
struct FileNameDefaultTypeInternal;
extern FileNameDefaultTypeInternal _FileName_default_instance_;
class Slice;
struct SliceDefaultTypeInternal;
extern SliceDefaultTypeInternal _Slice_default_instance_;
class SliceRequest;
struct SliceRequestDefaultTypeInternal;
extern SliceRequestDefaultTypeInternal _SliceRequest_default_instance_;
}  // namespace filetransfer
PROTOBUF_NAMESPACE_OPEN
template<> ::filetransfer::FileMetadata* Arena::CreateMaybeMessage<::filetransfer::FileMetadata>(Arena*);
template<> ::filetransfer::FileName* Arena::CreateMaybeMessage<::filetransfer::FileName>(Arena*);
template<> ::filetransfer::Slice* Arena::CreateMaybeMessage<::filetransfer::Slice>(Arena*);
template<> ::filetransfer::SliceRequest* Arena::CreateMaybeMessage<::filetransfer::SliceRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace filetransfer {

// ===================================================================

class SliceRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:filetransfer.SliceRequest) */ {
 public:
  inline SliceRequest() : SliceRequest(nullptr) {}
  virtual ~SliceRequest();
  explicit constexpr SliceRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SliceRequest(const SliceRequest& from);
  SliceRequest(SliceRequest&& from) noexcept
    : SliceRequest() {
    *this = ::std::move(from);
  }

  inline SliceRequest& operator=(const SliceRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SliceRequest& operator=(SliceRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SliceRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const SliceRequest* internal_default_instance() {
    return reinterpret_cast<const SliceRequest*>(
               &_SliceRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SliceRequest& a, SliceRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SliceRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SliceRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SliceRequest* New() const final {
    return CreateMaybeMessage<SliceRequest>(nullptr);
  }

  SliceRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SliceRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SliceRequest& from);
  void MergeFrom(const SliceRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SliceRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "filetransfer.SliceRequest";
  }
  protected:
  explicit SliceRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_file_5ftransfer_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdxFieldNumber = 1,
    kOffsetFieldNumber = 2,
  };
  // int32 idx = 1;
  void clear_idx();
  ::PROTOBUF_NAMESPACE_ID::int32 idx() const;
  void set_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_idx() const;
  void _internal_set_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 offset = 2;
  void clear_offset();
  ::PROTOBUF_NAMESPACE_ID::int32 offset() const;
  void set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_offset() const;
  void _internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:filetransfer.SliceRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 idx_;
  ::PROTOBUF_NAMESPACE_ID::int32 offset_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_file_5ftransfer_2eproto;
};
// -------------------------------------------------------------------

class Slice PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:filetransfer.Slice) */ {
 public:
  inline Slice() : Slice(nullptr) {}
  virtual ~Slice();
  explicit constexpr Slice(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Slice(const Slice& from);
  Slice(Slice&& from) noexcept
    : Slice() {
    *this = ::std::move(from);
  }

  inline Slice& operator=(const Slice& from) {
    CopyFrom(from);
    return *this;
  }
  inline Slice& operator=(Slice&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Slice& default_instance() {
    return *internal_default_instance();
  }
  static inline const Slice* internal_default_instance() {
    return reinterpret_cast<const Slice*>(
               &_Slice_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Slice& a, Slice& b) {
    a.Swap(&b);
  }
  inline void Swap(Slice* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Slice* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Slice* New() const final {
    return CreateMaybeMessage<Slice>(nullptr);
  }

  Slice* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Slice>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Slice& from);
  void MergeFrom(const Slice& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Slice* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "filetransfer.Slice";
  }
  protected:
  explicit Slice(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_file_5ftransfer_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 4,
    kIdxFieldNumber = 1,
    kOffsetFieldNumber = 2,
    kLengthFieldNumber = 3,
  };
  // bytes data = 4;
  void clear_data();
  const std::string& data() const;
  void set_data(const std::string& value);
  void set_data(std::string&& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  std::string* mutable_data();
  std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // int32 idx = 1;
  void clear_idx();
  ::PROTOBUF_NAMESPACE_ID::int32 idx() const;
  void set_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_idx() const;
  void _internal_set_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 offset = 2;
  void clear_offset();
  ::PROTOBUF_NAMESPACE_ID::int32 offset() const;
  void set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_offset() const;
  void _internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 length = 3;
  void clear_length();
  ::PROTOBUF_NAMESPACE_ID::int32 length() const;
  void set_length(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_length() const;
  void _internal_set_length(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:filetransfer.Slice)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  ::PROTOBUF_NAMESPACE_ID::int32 idx_;
  ::PROTOBUF_NAMESPACE_ID::int32 offset_;
  ::PROTOBUF_NAMESPACE_ID::int32 length_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_file_5ftransfer_2eproto;
};
// -------------------------------------------------------------------

class FileMetadata PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:filetransfer.FileMetadata) */ {
 public:
  inline FileMetadata() : FileMetadata(nullptr) {}
  virtual ~FileMetadata();
  explicit constexpr FileMetadata(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FileMetadata(const FileMetadata& from);
  FileMetadata(FileMetadata&& from) noexcept
    : FileMetadata() {
    *this = ::std::move(from);
  }

  inline FileMetadata& operator=(const FileMetadata& from) {
    CopyFrom(from);
    return *this;
  }
  inline FileMetadata& operator=(FileMetadata&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FileMetadata& default_instance() {
    return *internal_default_instance();
  }
  static inline const FileMetadata* internal_default_instance() {
    return reinterpret_cast<const FileMetadata*>(
               &_FileMetadata_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(FileMetadata& a, FileMetadata& b) {
    a.Swap(&b);
  }
  inline void Swap(FileMetadata* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FileMetadata* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FileMetadata* New() const final {
    return CreateMaybeMessage<FileMetadata>(nullptr);
  }

  FileMetadata* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FileMetadata>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FileMetadata& from);
  void MergeFrom(const FileMetadata& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FileMetadata* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "filetransfer.FileMetadata";
  }
  protected:
  explicit FileMetadata(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_file_5ftransfer_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBlockCountFieldNumber = 1,
    kBlockSizeFieldNumber = 2,
    kFileSizeFieldNumber = 3,
  };
  // int32 blockCount = 1;
  void clear_blockcount();
  ::PROTOBUF_NAMESPACE_ID::int32 blockcount() const;
  void set_blockcount(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_blockcount() const;
  void _internal_set_blockcount(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 blockSize = 2;
  void clear_blocksize();
  ::PROTOBUF_NAMESPACE_ID::int32 blocksize() const;
  void set_blocksize(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_blocksize() const;
  void _internal_set_blocksize(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 fileSize = 3;
  void clear_filesize();
  ::PROTOBUF_NAMESPACE_ID::int32 filesize() const;
  void set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_filesize() const;
  void _internal_set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:filetransfer.FileMetadata)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 blockcount_;
  ::PROTOBUF_NAMESPACE_ID::int32 blocksize_;
  ::PROTOBUF_NAMESPACE_ID::int32 filesize_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_file_5ftransfer_2eproto;
};
// -------------------------------------------------------------------

class FileName PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:filetransfer.FileName) */ {
 public:
  inline FileName() : FileName(nullptr) {}
  virtual ~FileName();
  explicit constexpr FileName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FileName(const FileName& from);
  FileName(FileName&& from) noexcept
    : FileName() {
    *this = ::std::move(from);
  }

  inline FileName& operator=(const FileName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FileName& operator=(FileName&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FileName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FileName* internal_default_instance() {
    return reinterpret_cast<const FileName*>(
               &_FileName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(FileName& a, FileName& b) {
    a.Swap(&b);
  }
  inline void Swap(FileName* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FileName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FileName* New() const final {
    return CreateMaybeMessage<FileName>(nullptr);
  }

  FileName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FileName>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FileName& from);
  void MergeFrom(const FileName& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FileName* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "filetransfer.FileName";
  }
  protected:
  explicit FileName(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_file_5ftransfer_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:filetransfer.FileName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_file_5ftransfer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SliceRequest

// int32 idx = 1;
inline void SliceRequest::clear_idx() {
  idx_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SliceRequest::_internal_idx() const {
  return idx_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SliceRequest::idx() const {
  // @@protoc_insertion_point(field_get:filetransfer.SliceRequest.idx)
  return _internal_idx();
}
inline void SliceRequest::_internal_set_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  idx_ = value;
}
inline void SliceRequest::set_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_idx(value);
  // @@protoc_insertion_point(field_set:filetransfer.SliceRequest.idx)
}

// int32 offset = 2;
inline void SliceRequest::clear_offset() {
  offset_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SliceRequest::_internal_offset() const {
  return offset_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SliceRequest::offset() const {
  // @@protoc_insertion_point(field_get:filetransfer.SliceRequest.offset)
  return _internal_offset();
}
inline void SliceRequest::_internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  offset_ = value;
}
inline void SliceRequest::set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_offset(value);
  // @@protoc_insertion_point(field_set:filetransfer.SliceRequest.offset)
}

// -------------------------------------------------------------------

// Slice

// int32 idx = 1;
inline void Slice::clear_idx() {
  idx_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::_internal_idx() const {
  return idx_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::idx() const {
  // @@protoc_insertion_point(field_get:filetransfer.Slice.idx)
  return _internal_idx();
}
inline void Slice::_internal_set_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  idx_ = value;
}
inline void Slice::set_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_idx(value);
  // @@protoc_insertion_point(field_set:filetransfer.Slice.idx)
}

// int32 offset = 2;
inline void Slice::clear_offset() {
  offset_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::_internal_offset() const {
  return offset_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::offset() const {
  // @@protoc_insertion_point(field_get:filetransfer.Slice.offset)
  return _internal_offset();
}
inline void Slice::_internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  offset_ = value;
}
inline void Slice::set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_offset(value);
  // @@protoc_insertion_point(field_set:filetransfer.Slice.offset)
}

// int32 length = 3;
inline void Slice::clear_length() {
  length_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::_internal_length() const {
  return length_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Slice::length() const {
  // @@protoc_insertion_point(field_get:filetransfer.Slice.length)
  return _internal_length();
}
inline void Slice::_internal_set_length(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  length_ = value;
}
inline void Slice::set_length(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_length(value);
  // @@protoc_insertion_point(field_set:filetransfer.Slice.length)
}

// bytes data = 4;
inline void Slice::clear_data() {
  data_.ClearToEmpty();
}
inline const std::string& Slice::data() const {
  // @@protoc_insertion_point(field_get:filetransfer.Slice.data)
  return _internal_data();
}
inline void Slice::set_data(const std::string& value) {
  _internal_set_data(value);
  // @@protoc_insertion_point(field_set:filetransfer.Slice.data)
}
inline std::string* Slice::mutable_data() {
  // @@protoc_insertion_point(field_mutable:filetransfer.Slice.data)
  return _internal_mutable_data();
}
inline const std::string& Slice::_internal_data() const {
  return data_.Get();
}
inline void Slice::_internal_set_data(const std::string& value) {
  
  data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void Slice::set_data(std::string&& value) {
  
  data_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:filetransfer.Slice.data)
}
inline void Slice::set_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:filetransfer.Slice.data)
}
inline void Slice::set_data(const void* value,
    size_t size) {
  
  data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:filetransfer.Slice.data)
}
inline std::string* Slice::_internal_mutable_data() {
  
  return data_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* Slice::release_data() {
  // @@protoc_insertion_point(field_release:filetransfer.Slice.data)
  return data_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Slice::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    
  } else {
    
  }
  data_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:filetransfer.Slice.data)
}

// -------------------------------------------------------------------

// FileMetadata

// int32 blockCount = 1;
inline void FileMetadata::clear_blockcount() {
  blockcount_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::_internal_blockcount() const {
  return blockcount_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::blockcount() const {
  // @@protoc_insertion_point(field_get:filetransfer.FileMetadata.blockCount)
  return _internal_blockcount();
}
inline void FileMetadata::_internal_set_blockcount(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  blockcount_ = value;
}
inline void FileMetadata::set_blockcount(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_blockcount(value);
  // @@protoc_insertion_point(field_set:filetransfer.FileMetadata.blockCount)
}

// int32 blockSize = 2;
inline void FileMetadata::clear_blocksize() {
  blocksize_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::_internal_blocksize() const {
  return blocksize_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::blocksize() const {
  // @@protoc_insertion_point(field_get:filetransfer.FileMetadata.blockSize)
  return _internal_blocksize();
}
inline void FileMetadata::_internal_set_blocksize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  blocksize_ = value;
}
inline void FileMetadata::set_blocksize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_blocksize(value);
  // @@protoc_insertion_point(field_set:filetransfer.FileMetadata.blockSize)
}

// int32 fileSize = 3;
inline void FileMetadata::clear_filesize() {
  filesize_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::_internal_filesize() const {
  return filesize_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FileMetadata::filesize() const {
  // @@protoc_insertion_point(field_get:filetransfer.FileMetadata.fileSize)
  return _internal_filesize();
}
inline void FileMetadata::_internal_set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  filesize_ = value;
}
inline void FileMetadata::set_filesize(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_filesize(value);
  // @@protoc_insertion_point(field_set:filetransfer.FileMetadata.fileSize)
}

// -------------------------------------------------------------------

// FileName

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace filetransfer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_file_5ftransfer_2eproto
