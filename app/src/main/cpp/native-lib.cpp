#include <jni.h>
#include <string>
#include "LogUtil.h"
#include "Util.h"
#include "Dns.h"
#include "Headers.h"
#include "HttpUrl.h"
#include "HttpUrlBuilder.h"
#include "MediaType.h"
#include "internal/http/StatusLine.h"
#include "internal/http/HttpMethod.h"
#include "internal/http/Http1Codec.h"
#include "RequestBody.h"
#include "Request.h"
#include "RequestBuilder.h"
#include "HttpClient.h"
#include "ResponseBody.h"
#include "Response.h"
#include "Call.h"
#include "RealCall.h"

extern "C" JNIEXPORT jstring JNICALL
Java_per_wengzc_httpclientnative_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_per_wengzc_httpclientnative_MainActivity_testJNI(
        JNIEnv *env,
        jobject /* this */) {

    http_client_native::LogUtil::debug("hello, http_client_native");

    using namespace http_client_native;
    using namespace std;
    HttpClient * client = new HttpClient();
    Request * request = Request::Builder().setUrl("").build();
    Response * response = HttpClient::newCall(client, request)->execute();

    delete response;
}
