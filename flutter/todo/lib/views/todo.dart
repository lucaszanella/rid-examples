import 'package:flutter/material.dart';
import 'package:plugin/generated/rid_generated.dart';

class TodoView extends StatefulWidget {
  final Pointer<Todo> todo;
  final void Function() onToggle;
  final void Function() onRemove;

  const TodoView(this.todo,
      {required this.onToggle, required this.onRemove, Key? key})
      : super(key: key);

  @override
  _TodoViewState createState() => _TodoViewState();
}

class _TodoViewState extends State<TodoView> {
  @override
  Widget build(BuildContext context) {
    return Dismissible(
      key: Key("Todo ${widget.todo.id}"),
      child: Card(
        child: InkWell(
          onTap: () => setState(widget.onToggle),
          child: ListTile(
            leading: widget.todo.completed
                ? Icon(Icons.check, color: Colors.green)
                : Icon(Icons.calendar_today_rounded),
            title: Text('${widget.todo.title}'),
          ),
        ),
      ),
      direction: DismissDirection.endToStart,
      onDismissed: (_) => widget.onRemove(),
      background: Padding(
        padding: EdgeInsets.all(5.0),
        child: Container(
          color: Colors.red,
        ),
      ),
    );
  }
}
