#ifndef MODULENAME_HPP
#define MODULENAME_HPP

#include <v8.h>
#include <node.h>

class MyObject : public node::ObjectWrap {
public:
    static v8::Persistent<v8::FunctionTemplate> constructor;
    static void Init(v8::Handle<v8::Object> target);

protected:
    MyObject(int val);

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> Value(const v8::Arguments& args);

    // Your own object variables here
    int value_;
};

#endif
