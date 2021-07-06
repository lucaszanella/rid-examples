import 'dart:typed_data';

import 'package:flutter/material.dart';
import 'package:plugin/generated/rid_api.dart';
import 'package:plugin/wasm/utils.dart';

const WASM_FILE = 'target/wasm32-unknown-unknown/debug/wasm_counter.wasm';
void main() async {
  HTTP_HOST = 'localhost:8080';
  await initWasm(WASM_FILE);
  final store = await Store.instance;
  runApp(MyApp(store));
}

class MyApp extends StatelessWidget {
  final Store _store;
  MyApp(this._store);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Rust/Flutter Counter App Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(_store, title: 'Rust/Flutter Counter Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  final Store _store;
  MyHomePage(this._store, {Key? key, required this.title}) : super(key: key);
  final String title;
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'You have counted to:',
            ),
            Text(
              '${widget._store.count}',
              style: Theme.of(context).textTheme.headline4,
            ),
            const SizedBox(height: 100),
          ],
        ),
      ),
      floatingActionButton: Row(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          FloatingActionButton(
            onPressed: () {
              _addStringLen();
            },
            tooltip: 'Add String Len',
            child: Row(mainAxisAlignment: MainAxisAlignment.center, children: [
              Icon(Icons.add),
              Icon(Icons.format_strikethrough_rounded)
            ]),
          ),
          FloatingActionButton(
            onPressed: () {
              _addTen();
            },
            tooltip: 'Add 10',
            child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [Icon(Icons.add), Icon(Icons.add)]),
          ),
          FloatingActionButton(
            onPressed: _incrementCounter,
            tooltip: 'Increment',
            child: Icon(Icons.add),
          ),
        ],
      ),
    );
  }

  void _addTen() async {
    await widget._store.msgAdd(10);
    debugPrint("${widget._store.raw.debug(true)}");
    setState(() {});
  }

  void _incrementCounter() {
    widget._store.msgInc().then((res) {
      debugPrint("${widget._store.raw.debug(true)}");
      debugPrint(widget._store.wasmToString());
      setState(() {});
    });
  }

  void _addStringLen() async {
    await widget._store.msgAddStringLen("hello world");
    debugPrint("${widget._store.raw.debug(true)}");
    setState(() {});
  }
}
