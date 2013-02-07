#include <node.h>

#include <cmath>

using namespace v8;

struct Baton {
    uv_work_t request;
    Persistent<Function> callback;
    int32_t result;
};


Handle<Value> Fn1(const Arguments& args) {
    HandleScope scope;
    int answer = 133.7f / M_PI;
    return scope.Close(Integer::New(answer));
}

Handle<Value> Fn2(const Arguments& args) {
    HandleScope scope;
    int answer = 133.7f / M_PI;
    Local<Value> argv[] = {
        Local<Value>::New(Null()),
        Local<Value>::New(Integer::New(answer))
    };
    Local<Function> callback = Local<Function>::Cast(args[0]);
    callback->Call(Context::GetCurrent()->Global(), 2, argv);
    return Undefined();
}

void Fn3Work(uv_work_t* req) {
    Baton* baton = static_cast<Baton*>(req->data);
    baton->result = 133.7f / M_PI;
}

void Fn3After(uv_work_t* req) {
    HandleScope scope;
    Baton* baton = static_cast<Baton*>(req->data);
    Local<Value> argv[] = {
        Local<Value>::New(Null()),
        Local<Value>::New(Integer::New(baton->result))
    };
    TryCatch try_catch;
    baton->callback->Call(Context::GetCurrent()->Global(), 2, argv);
    if (try_catch.HasCaught()) {
        node::FatalException(try_catch);
    }
    baton->callback.Dispose();
    delete baton;
}

Handle<Value> Fn3(const Arguments& args) {
    HandleScope scope;
    Baton* baton = new Baton();
    baton->request.data = baton;
    Local<Function> callback = Local<Function>::Cast(args[0]);
    baton->callback = Persistent<Function>::New(callback);
    uv_queue_work(uv_default_loop(), &baton->request, Fn3Work,
                  (uv_after_work_cb)Fn3After);
    return Undefined();
}


void RegisterModule(Handle<Object> target) {
    NODE_SET_METHOD(target, "fn1", Fn1);
    NODE_SET_METHOD(target, "fn2", Fn2);
    NODE_SET_METHOD(target, "fn3", Fn3);
}

NODE_MODULE(modulename, RegisterModule);
