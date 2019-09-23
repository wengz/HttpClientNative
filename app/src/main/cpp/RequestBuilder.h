//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_REQUESTBUILDER_H
#define HTTPCLIENTNATIVE_REQUESTBUILDER_H

#include "Request.h"

namespace http_client_native {

    class Request::Builder {
    public :
        Builder();
        Builder & setUrl (HttpUrl & url);
        Builder & setUrl (string & url);
        Builder & setUrl (const char * url);
        Request * build();
        Headers::Builder & getHeaders();
        HttpUrl getUrl();

        Builder & post(RequestBody &rb);

        Builder & setMethod(string method, RequestBody & rb);

        string getMethod();

        RequestBody getBody();

    private :
        string method;
        HttpUrl url;
        Headers::Builder headers;
        RequestBody body;

    };

}


#endif //HTTPCLIENTNATIVE_REQUESTBUILDER_H
