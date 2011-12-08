#include <node.h>

#include "modulename.hpp"

using namespace v8;


Persistent<FunctionTemplate> MyObject::constructor;

void MyObject::Init(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    Local<String> name = String::NewSymbol("MyObject");

    constructor = Persistent<FunctionTemplate>::New(tpl);
    // ObjectWrap uses the first internal field to store the wrapped pointer.
    constructor->InstanceTemplate()->SetInternalFieldCount(1);
    constructor->SetClassName(name);

    // Add all prototype methods, getters and setters here.
    NODE_SET_PROTOTYPE_METHOD(constructor, "value", Value);

    // This has to be last, otherwise the properties won't show up on the
    // object in JavaScript.
    target->Set(name, constructor->GetFunction());
}

MyObject::MyObject(int val)
    : ObjectWrap(),
      value_(val) {}


Handle<Value> MyObject::New(const Arguments& args) {
    HandleScope scope;

    if (!args.IsConstructCall()) {
        return ThrowException(Exception::TypeError(
            String::New("Use the new operator to create instances of this object."))
        );
    }

    if (args.Length() < 1) {
        return ThrowException(Exception::TypeError(
            String::New("First argument must be a number")));
    }

    // Creates a new instance object of this type and wraps it.
    MyObject* obj = new MyObject(args[0]->ToInteger()->Value());
    obj->Wrap(args.This());

    return args.This();
}


Handle<Value> MyObject::Value(const Arguments& args) {
    HandleScope scope;

    // Retrieves the pointer to the wrapped object instance.
    MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());

    return scope.Close(Integer::New(obj->value_));
}








void RegisterModule(Handle<Object> target) {
    MyObject::Init(target);
}

NODE_MODULE(modulename, RegisterModule);
