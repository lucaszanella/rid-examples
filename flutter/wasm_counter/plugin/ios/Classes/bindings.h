/* Generated with cbindgen:0.18.0 */

#include "stdint.h"



typedef struct RawReplyStruct RawReplyStruct;

typedef struct RawStore RawStore;

const struct ReplyStruct *rid_poll_reply(void);

void rid_handled_reply(uint64_t req_id);

/**
 * ```dart
 *
 * // Dart class representation of ReplyStruct.
 * class ReplyStruct {
 *    @dart_ffi.Int32()
 *   final int ty;
 *    @dart_ffi.Int64()
 *   final int reqId;
 *   final String data;
 *
 *   const ReplyStruct._(this.ty, this.reqId, this.data);
 *  @override
 *  bool operator ==(Object other) {
 *    return identical(this, other) ||
 *      other is ReplyStruct &&
 *          ty == other.ty &&
 *          reqId == other.reqId &&
 *          data == other.data;
 *  }
 *  @override
 *  int get hashCode {
 *    return
 *      ty.hashCode ^
 *      reqId.hashCode ^
 *      data.hashCode;
 *  }
 *  @override
 *  String toString() {
 *    return 'ReplyStruct{ty: $ty, reqId: $reqId, data: $data}';
 *  }
 * }
 *
 * // Extension method `toDart` to instantiate a Dart ReplyStruct by resolving all fields from Rust
 * extension Rid_ToDart_ExtOnReplyStruct on dart_ffi.Pointer<ffigen_bind.RawReplyStruct> {
 *   ReplyStruct toDart() {
 *      ridStoreLock();
 *      final instance = ReplyStruct._(this.ty, this.req_id, this.data);
 *      ridStoreUnlock();
 *      return instance;
 *   }
 * }
 * ```
 */
void _to_dart_for_ReplyStruct(void);

/**
 * Extension to expose Debug<RawReplyStruct> via `this.debug([pretty])` on dart_ffi.Pointer<ffigen_bind.RawReplyStruct>.
 *
 * ```dart
 * extension rid_rawreplystruct_debug_ExtOnReplyStruct on dart_ffi.Pointer<ffigen_bind.RawReplyStruct> {
 *   String debug([bool pretty = false]) {
 *     final ptr = pretty
 *       ? rid_ffi.rid_rawreplystruct_debug_pretty(this)
 *       : rid_ffi.rid_rawreplystruct_debug(this);
 *     final s = ptr.toDartString();
 *     ptr.free();
 *     return s;
 *   }
 * }
 * ```
 */
const char *rid_rawreplystruct_debug(RawReplyStruct *ptr);

const char *rid_rawreplystruct_debug_pretty(RawReplyStruct *ptr);

void rid_cstring_free(char *ptr);

/**
 * FFI access methods generated for Rust struct 'ReplyStruct' implemented on 'RawReplyStruct'.
 *
 * Below is the dart extension to call those methods.
 *
 * ```dart
 * extension Rid_Model_ExtOnPointerRawReplyStruct on dart_ffi.Pointer<ffigen_bind.RawReplyStruct> {
 * @dart_ffi.Int32()
 * int get ty => rid_ffi.rid_replystruct_ty(this);
 * @dart_ffi.Int64()
 * int get req_id => rid_ffi.rid_replystruct_req_id(this);
 * String get data {
 *   int len = rid_ffi.rid_replystruct_data_len(this);
 *   dart_ffi.Pointer<dart_ffi.Int8> ptr = rid_ffi.rid_replystruct_data(this);
 *   String s = ptr.toDartString(len);
 *   ptr.free();
 *   return s;
 * }
 * }
 * ```
 */
uint8_t rid_replystruct_ty(RawReplyStruct *ptr);

uint64_t rid_replystruct_req_id(RawReplyStruct *ptr);

const char *rid_replystruct_data(RawReplyStruct *ptr);

uintptr_t rid_replystruct_data_len(RawReplyStruct *ptr);

/**
 * ```dart
 * // rid API that provides memory safety and which is recommended to use.
 * // Use the lower level API (via `Store.raw`) only when you need more control,
 * // i.e. if you run into performance issues with this higher level API.
 * class Store {
 *   final dart_ffi.Pointer<ffigen_bind.RawStore> _store;
 *
 *   /// Provides direct access to the underlying Rust store.
 *   /// You should not need to work with this lower level API except for cases
 *   /// where you want more fine grained control over how data is retrieved from
 *   /// Rust and converted into Dart, i.e. to tweak performance.
 *   /// In all other cases you should use the higher level API which is much
 *   /// easier to use and also guarantees memory safety.
 *   dart_ffi.Pointer<ffigen_bind.RawStore> get raw => _store;
 *
 *   const Store(this._store);
 *
 *   T _read<T>(T Function(dart_ffi.Pointer<ffigen_bind.RawStore> store) accessor, String? request) {
 *     return _store.runLocked(accessor, request: request);
 *   }
 *
 *   StoreState toDartState() => _store.toDart();
 *   String debug([bool pretty = false]) => _store.debug(pretty);
 *
 *   /// Disposes the store and closes the Rust reply channel in order to allow the app
 *   /// to exit properly. This needs to be called when exiting a Dart application.
 *   Future<void> dispose() => _store.dispose();
 *
 *   static Store? _instance;
 *   static Store get instance {
 *     if (_instance == null) {
 *       _instance = Store(_createStore());
 *     }
 *     return _instance!;
 *   }
 * }
 *
 * // Dart class representation of Store.
 * class StoreState {
 *    @dart_ffi.Int32()
 *   final int count;
 *
 *   const StoreState._(this.count);
 *  @override
 *  bool operator ==(Object other) {
 *    return identical(this, other) ||
 *      other is StoreState &&
 *          count == other.count;
 *  }
 *  @override
 *  int get hashCode {
 *    return
 *      count.hashCode;
 *  }
 *  @override
 *  String toString() {
 *    return 'StoreState{count: $count}';
 *  }
 * }
 *
 * // Extension method `toDart` to instantiate a Dart Store by resolving all fields from Rust
 * extension Rid_ToDart_ExtOnStore on dart_ffi.Pointer<ffigen_bind.RawStore> {
 *   StoreState toDart() {
 *      ridStoreLock();
 *      final instance = StoreState._(this.count);
 *      ridStoreUnlock();
 *      return instance;
 *   }
 * }
 * ```
 */
void _to_dart_for_Store(void);

/**
 * Extension to expose Debug<RawStore> via `this.debug([pretty])` on dart_ffi.Pointer<ffigen_bind.RawStore>.
 *
 * ```dart
 * extension rid_rawstore_debug_ExtOnStore on dart_ffi.Pointer<ffigen_bind.RawStore> {
 *   String debug([bool pretty = false]) {
 *     final ptr = pretty
 *       ? rid_ffi.rid_rawstore_debug_pretty(this)
 *       : rid_ffi.rid_rawstore_debug(this);
 *     final s = ptr.toDartString();
 *     ptr.free();
 *     return s;
 *   }
 * }
 * ```
 */
const char *rid_rawstore_debug(RawStore *ptr);

const char *rid_rawstore_debug_pretty(RawStore *ptr);

/**
 * ```dart
 * void _initRid() {
 *   print('Set RID_DEBUG_LOCK to change if/how locking the rid store is logged');
 *   print('Set RID_DEBUG_REPLY to change if/how posted replies are logged');
 *   print('Set RID_MSG_TIMEOUT to change the default for if/when messages without reply time out');
 * }
 *
 * dart_ffi.Pointer<ffigen_bind.RawStore> _createStore() {
 *   _initRid();
 *   return rid_ffi.create_store();
 * }
 * ```
 */
const RawStore *create_store(void);

/**
 * ```dart
 * int _locks = 0;
 *
 * void Function(bool, int, {String? request})? RID_DEBUG_LOCK = (bool locking, int locks, {String? request}) {
 *   if (locking) {
 *     if (locks == 1) print('🔐 {');
 *     if (request != null) print(' $request');
 *   } else {
 *     if (locks == 0) print('} 🔓');
 *   }
 * };
 *
 * void ridStoreLock({String? request}) {
 *   if (_locks == 0) rid_ffi.rid_store_lock();
 *   _locks++;
 *   if (RID_DEBUG_LOCK != null) RID_DEBUG_LOCK!(true, _locks, request: request);
 * }
 *
 * void ridStoreUnlock() {
 *   _locks--;
 *   if (RID_DEBUG_LOCK != null) RID_DEBUG_LOCK!(false, _locks);
 *   if (_locks == 0) rid_ffi.rid_store_unlock();
 * }
 * ```
 */
void rid_store_lock(void);

void rid_store_unlock(void);

/**
 * ```dart
 * extension rid_store_specific_extension on dart_ffi.Pointer<ffigen_bind.RawStore> {
 *   /// Executes the provided callback while locking the store to guarantee that the
 *   /// store is not modified while that callback runs.
 *   T runLocked<T>(T Function(dart_ffi.Pointer<ffigen_bind.RawStore>) fn, {String? request}) {
 *     try {
 *       ridStoreLock(request: request);
 *       return fn(this);
 *     } finally {
 *       ridStoreUnlock();
 *     }
 *   }
 *   /// Disposes the store and closes the Rust reply channel in order to allow the app
 *   /// to exit properly. This needs to be called when exiting a Dart application.
 *   Future<void> dispose() {
 *     return replyChannel.dispose();
 *   }
 * }
 * ```
 */
void rid_store_free(void);

/**
 * FFI access methods generated for Rust struct 'Store' implemented on 'RawStore'.
 *
 * Below is the dart extension to call those methods.
 *
 * ```dart
 * extension Rid_Model_ExtOnPointerRawStore on dart_ffi.Pointer<ffigen_bind.RawStore> {
 * @dart_ffi.Int32()
 * int get count => rid_ffi.rid_store_count(this);
 * }
 * ```
 */
uint32_t rid_store_count(RawStore *ptr);

/**
 * ```dart
 * /// Wrappers to access fields with the higher level API which is memory safe.
 * extension FieldAccessWrappersOn_Store on Store {
 *     @dart_ffi.Int32() int get count =>
 *       _read((store) => store.count, 'store.count');
 * }
 * ```
 */
void _include_Store_field_wrappers(void);

/**
 *
 * The below extension provides convenience methods to send messages to rust.
 *
 * ```dart
 *
 * final Duration? RID_MSG_TIMEOUT = const Duration(milliseconds: 200);
 *
 * Future<PostedReply> _replyWithTimeout(
 *   Future<PostedReply> reply,
 *   String msgCall,
 *   StackTrace applicationStack,
 *   Duration timeout,
 * ) {
 *   final failureMsg = '''$msgCall timed out\n
 * ---- Application Stack ----\n
 * $applicationStack\n
 * ---- Internal Stack ----
 * ''';
 *
 *   return reply.timeout(timeout,
 *       onTimeout: () => throw dart_async.TimeoutException(failureMsg, timeout));
 * }
 *
 * extension Rid_Message_ExtOnPointerStoreForMsg on dart_ffi.Pointer<ffigen_bind.RawStore> {
 *   Future<PostedReply> msgInc({Duration? timeout}) {
 *     final reqId = replyChannel.reqId;
 *     rid_ffi.rid_msg_Inc(reqId, );
 *
 *     final reply = _isDebugMode && RID_DEBUG_REPLY != null
 *         ? replyChannel.reply(reqId).then((PostedReply reply) {
 *             if (RID_DEBUG_REPLY != null) RID_DEBUG_REPLY!(reply);
 *             return reply;
 *           })
 *         : replyChannel.reply(reqId);
 *
 *     if (!_isDebugMode) return reply;
 *
 *     timeout ??= RID_MSG_TIMEOUT;
 *     if (timeout == null) return reply;
 *     final msgCall = 'msgInc() with reqId: $reqId';
 *     return _replyWithTimeout(reply, msgCall, StackTrace.current, timeout);
 *   }
 *   Future<PostedReply> msgAdd(@dart_ffi.Int32() int arg0, {Duration? timeout}) {
 *     final reqId = replyChannel.reqId;
 *     rid_ffi.rid_msg_Add(reqId, arg0);
 *
 *     final reply = _isDebugMode && RID_DEBUG_REPLY != null
 *         ? replyChannel.reply(reqId).then((PostedReply reply) {
 *             if (RID_DEBUG_REPLY != null) RID_DEBUG_REPLY!(reply);
 *             return reply;
 *           })
 *         : replyChannel.reply(reqId);
 *
 *     if (!_isDebugMode) return reply;
 *
 *     timeout ??= RID_MSG_TIMEOUT;
 *     if (timeout == null) return reply;
 *     final msgCall = 'msgAdd($arg0) with reqId: $reqId';
 *     return _replyWithTimeout(reply, msgCall, StackTrace.current, timeout);
 *   }
 * }
 * extension MsgApiFor_Store on Store {
 *   Future<PostedReply> msgInc({Duration? timeout}) {
 *     return _store.msgInc(timeout: timeout);
 *   }
 *   Future<PostedReply> msgAdd(@dart_ffi.Int32() int arg0, {Duration? timeout}) {
 *     return _store.msgAdd(arg0, timeout: timeout);
 *   }
 * }
 * ```
 */
void rid_msg_Inc(uint64_t __rid_req_id);

void rid_msg_Add(uint64_t __rid_req_id, uint32_t arg0);

/**
 *
 * ```dart
 * /// Dart enum implementation for Rust Reply enum.
 * enum Reply { Increased, Added }
 * ```
 *
 * ```dart
 *
 * class PostedReply extends IReply {
 *   final Reply type;
 *   final int? reqId;
 *   final String? data;
 *
 *   PostedReply._(this.type, this.reqId, this.data);
 *
 *   @override
 *   String toString() {
 *     return '''PostedReply {
 *   type:  ${this.type.toString().substring('Reply.'.length)}
 *   reqId: $reqId
 *   data:  $data
 * }
 * ''';
 *   }
 * }
 *
 * void Function(PostedReply)? RID_DEBUG_REPLY = (PostedReply reply) {
 *   print('$reply');
 * };
 *
 * const int _TYPE_MASK= 0x000000000000ffff;
 * const int _I64_MIN = -9223372036854775808;
 *
 * PostedReply decode(int packed, String? data) {
 *   final ntype = packed & _TYPE_MASK;
 *   final id = (packed - _I64_MIN) >> 16;
 *   final reqId = id > 0 ? id : null;
 *
 *   final type = Reply.values[ntype];
 *   return PostedReply._(type, reqId, data);
 * }
 *
 * final ReplyChannel<PostedReply> replyChannel = ReplyChannel.instance(_dl, decode, _isDebugMode);
 * ```
 */
void include_reply(void);