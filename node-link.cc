#include <node.h>
#include <memory>
#include <chrono>
#include <pthread.h>


using namespace std;

#include <ableton/Link.hpp>

namespace LinkNode{

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    static InterfaceTable *ft;

    static ableton::Link *gLink = NULL;
    static float gTempo = 60.0;

    void Method(const FunctionCallbackInfo<Value>& args) {
      Isolate* isolate = args.GetIsolate();
      args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }


    void enableLink(const FunctionCallbackInfo<Value>& args) {
      Isolate* isolate = args.GetIsolate();

      ableton::Link link(gTempo);
      link.enable(true);
      gLink = &link;

      args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }
    void disableLink(const FunctionCallbackInfo<Value>& args) {
      Isolate* isolate = args.GetIsolate();
      if (gLink!=NULL){
          gLink.enable(false);
      }
      args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }




    //node
    void init(Local<Object> exports) {
    //Method를 Hello라는 이름으로 매칭 시킨다->addon.hello()
      NODE_SET_METHOD(exports, "hello", Method);

      NODE_SET_METHOD(exports, "enable", enableLink);
      NODE_SET_METHOD(exports, "disable", disableLink);


    }

    NODE_MODULE(LinkNode, init)

};
