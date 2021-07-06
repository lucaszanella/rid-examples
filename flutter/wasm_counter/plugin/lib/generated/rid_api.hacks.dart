import 'dart:async' as dart_async;
import 'package:plugin/generated/wasm_reply_channel.dart';
import 'package:plugin/wasm/utils.dart';

import 'ffigen_binding.dart' as package_ffi;
import 'ffigen_binding.dart' as dart_ffi;
import 'ffigen_binding.dart' as ffigen_bind;

import 'package:flutter/widgets.dart';
import 'package:flutter/foundation.dart' as Foundation;

// Forwarding dart_ffi types essential to access raw Rust structs
export 'ffigen_binding.dart' show Pointer;

// Forwarding Dart Types for raw Rust structs
export 'ffigen_binding.dart' show RawReplyStruct, RawStore;

// :93
// TODO: we could generate stubs for non-wasm and include in ffigen_binding
Future<void> initWasm(String wasmFile) async {
  final moduleData = await loadWasmFromNetwork(wasmFile);
  await ffigen_bind.NativeLibrary.init(moduleData);
}

// :336
PostedReply wasmDecode(ReplyStruct reply) {
  return PostedReply._(Reply.values[reply.ty], reply.reqId, null);
}

late final ReplyChannel<PostedReply>? _replyChannel;
ReplyChannel<PostedReply> get replyChannel {
  if (_replyChannel == null) {
    _replyChannel = ReplyChannel.instance(_dl, wasmDecode, _isDebugMode);
  }
  return _replyChannel!;
}

extension Rid_ExtOnPointerInt8 on dart_ffi.Pointer<dart_ffi.Int8> {
  String toDartString([int? len]) {
    return ffigen_bind.toDartString(this);
  }

  void free() {
    rid_ffi.rid_cstring_free(this);
  }
}

//
// Exporting Native Library to call Rust functions directly
//
ffigen_bind.NativeLibrary get _dl => ffigen_bind.NativeLibrary.instance;
ffigen_bind.NativeLibrary get rid_ffi => _dl;
