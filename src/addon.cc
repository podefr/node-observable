#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "Observable.h"

using namespace v8;

void InitAll(Handle<Object> target) {
	Observable::Init(target);
}

NODE_MODULE(Observable, InitAll);
