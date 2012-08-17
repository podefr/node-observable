#include <node.h>
#include <iostream>
#include "../include/Observable.h"


using namespace v8;

Persistent<FunctionTemplate> Observable::constructor;

void Observable::Init(Handle<Object> target)
{
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	Local<String> name = String::NewSymbol("Observable");

	tpl->SetClassName(name);
	tpl->InstanceTemplate()->SetInternalFieldCount(1);
	tpl->PrototypeTemplate()->Set(String::NewSymbol("subscribe"),
		FunctionTemplate::New(subscribe)->GetFunction());
		tpl->PrototypeTemplate()->Set(String::NewSymbol("publish"),
		FunctionTemplate::New(publish)->GetFunction());

	Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(name, constructor);

}

Observable::Observable() {}

Observable::~Observable() {}


Handle<Value> Observable::New(const Arguments& args)
{
	HandleScope scope;

	Observable * obj = new Observable;
	obj->Wrap(args.This());
	return args.This();
}

Handle<Value> Observable::subscribe(const Arguments& args)
{
	HandleScope scope;

	Observer observer;

	Observable * obs = ObjectWrap::Unwrap<Observable>(args.This());

	observer.topic = args[0]->ToString();

	obs->observers.push_back( observer );

	std::cout << obs->observers.size();

	return scope.Close(String::New("subscribe"));
}

Handle<Value> Observable::publish(const Arguments& args)
{
	HandleScope scope;


	return scope.Close(String::New("publish"));
}


void RegisterModule(Handle<Object> target)
{
	Observable::Init(target);
}

// Register the module with node.
NODE_MODULE(Observable, RegisterModule);
