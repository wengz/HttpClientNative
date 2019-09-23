//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_HTTPCLIENT_H
#define HTTPCLIENTNATIVE_HTTPCLIENT_H

#include "Call.h"
#include "Request.h"

namespace http_client_native {

    class HttpClient {

    public:
        static Call * newCall(HttpClient * client, Request * request);

    protected:
        //超时设置等属性
    };

}

#endif //HTTPCLIENTNATIVE_HTTPCLIENT_H
