#ifndef MODULENAME_HPP
#define MODULENAME_HPP

#include <node.h>


// Do not include this line. It's generally frowned upon to use namespaces
// in header files as it may cause issues with other code that includes your
// header file.
// using namespace v8;


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
