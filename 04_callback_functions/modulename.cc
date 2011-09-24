#include <node/v8.h>
#include <node/node.h>

using namespace v8;


Handle<Value> Callback(const Arguments& args) {
    HandleScope scope;

    // Ensure that we got a callback. Generally, your functions should have
    // optional callbacks. In this case, you can declare an empty
    // Local<Function> handle and check for content before calling.
    if (!args[1]->IsFunction()) {
        return ThrowException(Exception::TypeError(
            String::New("Second argument must be a callback function")));
    }
    // There's no ToFunction(), use a Cast instead.
    Local<Function> callback = Local<Function>::Cast(args[args.Length() - 1]);

    // Our fake API allows the user to tell us whether we should cause an error.
    bool error = args[0]->BooleanValue();

    if (error) {
        Local<Value> err = Exception::Error(String::New("Something went wrong!"));

        // Optionally add more properties to the exception object.
        err->ToObject()->Set(NODE_PSYMBOL("errno"), Integer::New(23));

        // Prepare the parameters for the callback function.
        const unsigned argc = 1;
        Local<Value> argv[argc] = { err };

        // Note: When calling this in an asynchronous function that just returned
        // from the threadpool, you have to wrap this in a v8::TryCatch.
        // You can also pass another handle as the "this" parameter.
        callback->Call(Context::GetCurrent()->Global(), argc, argv);
    } else {
        // In case the operation succeeded, convention is to pass null as the
        // first argument before the result arguments.
        const unsigned argc = 2;
        Local<Value> argv[argc] = {
            Local<Value>::New(Null()),
            Local<Value>::New(Integer::New(42))
        };

        // Note: When calling this in an asynchronous function that just returned
        // from the threadpool, you have to wrap this in a v8::TryCatch.
        // You can also pass another handle as the "this" parameter.
        callback->Call(Context::GetCurrent()->Global(), argc, argv);
    }

    return Undefined();
}

void RegisterModule(Handle<Object> target) {
    target->Set(String::NewSymbol("callback"),
        FunctionTemplate::New(Callback)->GetFunction());
}

NODE_MODULE(modulename, RegisterModule);
