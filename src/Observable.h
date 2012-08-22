#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <string>
#include <node.h>
#include <vector>

using namespace v8;

struct Observer {
	Persistent<String> topic;
	Persistent<Function> callback;
	Persistent<Object> thisObject;
};

class Observable: public node::ObjectWrap {
	public:
		static void Init(Handle<Object>);

	private:
		Observable();
		~Observable();

		std::vector<Observer> observers;

		static Handle<Value> New(const Arguments&);
		static Handle<Value> publish(const Arguments&);
		static Handle<Value> subscribe(const Arguments&);
		static Handle<Value> unsubscribe(const Arguments&);
		static Handle<Value> hasObserver(const Arguments&);

		static std::vector<Observer>::iterator* getObserver( std::vector<Observer>*, 
			const Local<String>,
			const Local<Function>,
			const Local<Object> );
		
};

#endif
