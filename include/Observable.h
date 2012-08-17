#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <node.h>
#include <node_object_wrap.h>
#include <vector>

#include "req_wrap.h"
#include "handle_wrap.h"

using namespace v8;

struct Observer
{
	Local<String> topic;
};

class Observable: public node::ObjectWrap
{

std::vector<Observer> observers;

public:
	static Persistent<FunctionTemplate> constructor;
	static void Init(Handle<Object> target);

protected:
	Observable();
	virtual ~Observable();

	static Handle<Value> New(const Arguments& args);
	static Handle<Value> publish(const Arguments&);
	static Handle<Value> subscribe(const Arguments&);

};

#endif
