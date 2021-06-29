import Cocoa
import FlutterMacOS

public class Plugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result(nil)
  }
}
// <rid:prevent_tree_shake Start>
func dummyCallsToPreventTreeShaking() {
    rid_poll_reply();
    rid_handled_reply(0);
    _to_dart_for_ReplyStruct();
    rid_rawreplystruct_debug(nil);
    rid_rawreplystruct_debug_pretty(nil);
    rid_cstring_free(nil);
    rid_replystruct_ty(nil);
    rid_replystruct_req_id(nil);
    rid_replystruct_data(nil);
    rid_replystruct_data_len(nil);
    _to_dart_for_Store();
    rid_rawstore_debug(nil);
    rid_rawstore_debug_pretty(nil);
    create_store();
    rid_store_unlock();
    rid_store_free();
    rid_store_count(nil);
    _include_Store_field_wrappers();
    rid_msg_Inc(0);
    rid_msg_Add(0, 0);
}
// <rid:prevent_tree_shake End>