#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <iostream>
#include "Observable.h"

using namespace v8;

Observable::Observable() {};
Observable::~Observable() {};

void Observable::Init( Handle<Object> target ) {

	Local<FunctionTemplate> tpl = FunctionTemplate::New( New );
	Local<String> name = String::NewSymbol( "Observable" );

	tpl->SetClassName( name );
	tpl->InstanceTemplate()->SetInternalFieldCount( 2 );
	tpl->PrototypeTemplate()->Set(String::NewSymbol( "subscribe" ),
		FunctionTemplate::New(subscribe)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol( "publish" ),
		FunctionTemplate::New(publish)->GetFunction());

	Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
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

	Observer observer;

	Observable* obs = ObjectWrap::Unwrap<Observable>( args.This() );

	observer.topic = args[0]->ToString();
	observer.callback = Local<Function>::Cast( args[1] );

	obs->observers.push_back( observer );

	char test[10];

	observer.topic->WriteAscii( test, 0, observer.topic->Length() );

	std::cout << "\n" << "adding " << test << "\n";


	return scope.Close( Undefined() );
}

Handle<Value> Observable::publish( const Arguments& args ) {
	HandleScope scope;

	Observable* obs = ObjectWrap::Unwrap<Observable>( args.This() );

	Local<String> topic = args[0]->ToString();

	for ( int i = 0, length = obs->observers.size(); i<length; i++ ) {
		if ( topic == obs->observers[i].topic ) {
		
			char test [10];

			topic->WriteAscii( test, 0, topic->Length() );
			std::cout << test << "==";
			obs->observers[i].topic->WriteAscii( test, 0, topic->Length() );
			std::cout << test << "\n";

		}
	}

	return scope.Close( Undefined() );
}
