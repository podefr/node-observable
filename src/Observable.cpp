#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <iostream>
#include "Observable.h"

using namespace v8;

Observable::Observable() {};
Observable::~Observable() {};

Persistent<Function> constructor;

void Observable::Init( Handle<Object> target ) {

	Local<FunctionTemplate> tpl = FunctionTemplate::New( New );
	Local<String> name = String::NewSymbol( "Observable" );

	tpl->SetClassName( name );
	tpl->InstanceTemplate()->SetInternalFieldCount( 2 );
	tpl->PrototypeTemplate()->Set(String::NewSymbol( "subscribe" ),
		FunctionTemplate::New(subscribe)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol( "publish" ),
		FunctionTemplate::New(publish)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(name, constructor);

}

Handle<Value> Observable::New( const Arguments& args ) {
	HandleScope scope;

	Observable * obj = new Observable;
	obj->Wrap( args.This() );

	return args.This();
}

Handle<Value> Observable::subscribe( const Arguments& args ) {
	HandleScope scope;

	Observable* obs = ObjectWrap::Unwrap<Observable>( args.This() );

	Observer observer;

	observer.topic = Persistent<String>::New(args[0]->ToString());
	observer.callback = Persistent<Function>::New( Local<Function>::Cast(args[1]) );

	if (!args[2]->IsUndefined()) {
		observer.thisObject = Persistent<Object>::New( args[2]->ToObject() );
	}

	obs->observers.push_back( observer );

	return scope.Close( Undefined() );
}

Handle<Value> Observable::publish( const Arguments& args ) {
	HandleScope scope;

	Observable* obs = ObjectWrap::Unwrap<Observable>( args.This() );

	Local<String> topic = args[0]->ToString();

	for ( std::vector<Observer>::iterator i = obs->observers.begin(); i != obs->observers.end(); i++ ) {
		if ( topic == i->topic ) {

			const unsigned argc = 1;
			Local<Value> argv[argc] = { Local<Value>::New( args[1]) };
			i->callback->Call(i->thisObject, argc, argv);

		}
	}

	return scope.Close( Undefined() );
}
