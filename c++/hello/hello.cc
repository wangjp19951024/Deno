#include <node.h>
#include <v8.h>
#include <iostream>

namespace demo {
    using v8 :: FunctionCallBackInfo;
    using v8 :: Isolate;
    using v8 :: Local;
    using v8 :: Object;
    using v8 :: String;
    using v8 :: Value;
    using v8 :: Number;

    void Method1 (const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String :: NewFromUtf8(isolate, "hello world"));
    }

    void Method2 (const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Local<Number> value = Local<Number>::Cast(args[0]);
        // double num = value->NumberValue() + 1;
        double num = value -> NumberValue() + 1;

        char buf[128] = {0};
        sprintf(buf, "%f", num);

        args.GetReturnValue().Set(String :: NewFromUtf8(isolate, buf));
    }

    void init (Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello1", Method1);
        NODE_SET_METHOD(exports, "addone", Method2);
    }

    NODE_MODULE(hello, init)
} // namespace hello
