//
// Created by wengzc on 2019/9/23.
//

#include "RequestBuilder.h"

namespace http_client_native {

    Request * Request::Builder::build() {
        return new Request(*this);
    }

    Request::Builder::Builder() {
        method = "GET";
        headers.add("Connection", "Keep-Alive");
    }

    Request::Builder & Request::Builder::setUrl(HttpUrl & urlArg) {
        url = urlArg;
        headers.add("Host", urlArg.getHost());
        return * this;
    }

    Request::Builder &Request::Builder::setUrl(string &url) {
        HttpUrl retUrl = HttpUrl::get(url);
        return setUrl(retUrl);
    }

    Headers::Builder &Request::Builder::getHeaders() {
        return headers;
    }

    HttpUrl Request::Builder::getUrl() {
        return url;
    }

    Request::Builder &Request::Builder::post(RequestBody &rb) {
        return setMethod("post", rb);
    }

    Request::Builder &Request::Builder::setMethod(string method, RequestBody & rb) {
        this->method = method;
        this->body = rb;
        return * this;
    }

    string Request::Builder::getMethod() {
        return method;
    }

    RequestBody Request::Builder::getBody() {
        return body;
    }

    Request::Builder &Request::Builder::setUrl(const char *url) {
        std::string url_str(url);
        HttpUrl retUrl = HttpUrl::get(url_str);
        return setUrl(retUrl);
    }


}