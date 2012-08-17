#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <node.h>
#include <vector>

using namespace v8;

struct Observer {
	Local<String> topic;
	Local<Function> callback;
};

class Observable: public node::ObjectWrap {
	public:
		static void Init(Handle<Object> target);

	private:
		Observable();
		~Observable();

		std::vector<Observer> observers;

		static Handle<Value> New(const Arguments& args);
		static Handle<Value> publish(const Arguments&);
		static Handle<Value> subscribe(const Arguments&);

};

#endif
