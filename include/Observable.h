#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <node.h>
#include <node_buffer.h>
#include <node_object_wrap.h>

using namespace v8;

class Observable: public node::ObjectWrap
{
public:
	static Persistent<FunctionTemplate> constructor;
	static void Init(Handle<Object> target);

protected:
	Observable();

	static Handle<Value> New(const Arguments& args);
	static Handle<Value> publish(const Arguments&);
	static Handle<Value> subscribe(const Arguments&);
};

#endif
