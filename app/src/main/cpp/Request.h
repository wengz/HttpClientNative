//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_REQUEST_H
#define HTTPCLIENTNATIVE_REQUEST_H

#include <string>

#include "Headers.h"
#include "HttpUrl.h"
#include "RequestBody.h"

namespace http_client_native {

    using namespace std;

    class Request {

    public :

        class Builder;

        Request(){}

        Request(Builder & builder);

        std::string getMethod();

        Headers & getHeaders();

        HttpUrl getUrl();

        RequestBody getBody();

    private :
        std::string method;
        HttpUrl url;
        Headers headers;
        RequestBody body;

    };

}

#endif //HTTPCLIENTNATIVE_REQUEST_H
