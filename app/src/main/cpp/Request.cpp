//
// Created by wengzc on 2019/9/23.
//

#include "Request.h"
#include "RequestBuilder.h"

namespace http_client_native {

    std::string Request::getMethod() {
        return method;
    }

    Headers & Request::getHeaders() {
        return headers;
    }

    Request::Request(Request::Builder & builder)
            : headers(builder.getHeaders()), url(builder.getUrl()) , method(builder.getMethod()), body(builder.getBody()) {
    }

    HttpUrl Request::getUrl() {
        return url;
    }

    RequestBody Request::getBody() {
        return body;
    }


}