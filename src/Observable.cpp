#include <node.h>
#include "../include/Observable.h"


using namespace v8;

Persistent<FunctionTemplate> Observable::constructor;

void
Observable::Init(Handle<Object> target) {
	HandleScope scope;

	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	Local<String> name = String::NewSymbol("Observable");

	constructor = Persistent<FunctionTemplate>::New(tpl);

	constructor->InstanceTemplate()->SetInternalFieldCount(1);
	constructor->SetClassName(name);

	NODE_SET_PROTOTYPE_METHOD(constructor, "subscribe", subscribe);
	NODE_SET_PROTOTYPE_METHOD(constructor, "publish", publish);

	target->Set(name, constructor->GetFunction());
}

Observable::Observable()
:ObjectWrap() {
}

Handle<Value>
Observable::New(const Arguments& args) {
	HandleScope scope;

	Observable* obj = new Observable();
	obj->Wrap(args.This());
	return args.This();
}

Handle<Value>
Observable::subscribe(const Arguments& args) {
	HandleScope scope;

	return scope.Close(String::New("subscribe"));
}

Handle<Value>
Observable::publish(const Arguments& args) {
	HandleScope scope;

	return scope.Close(String::New("publish"));
}


void RegisterModule(Handle<Object> target) {
	Observable::Init(target);
}

// Register the module with node.
NODE_MODULE(Observable, RegisterModule);
