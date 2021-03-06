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
		Observable();
		virtual ~Observable();

	private:
		std::vector<Observer> observers;

		static Handle<Value> New( const Arguments& );
		static Handle<Value> Publish( const Arguments& );
		static Handle<Value> Subscribe( const Arguments& );
		static Handle<Value> Unsubscribe( const Arguments& );
		static Handle<Value> HasObserver( const Arguments& );

		static std::vector<Observer>::iterator* GetObserver( 	std::vector<Observer>*, 
																const Local<String>,
																const Local<Function>,
																const Local<Object> );
		
};

#endif
