//
// Created by wengzc on 2019/9/23.
//

#include "HttpClient.h"
#include "RealCall.h"

namespace http_client_native {

    Call *HttpClient::newCall(HttpClient *client, Request *request) {
        return new RealCall(client, request);
    }
}
