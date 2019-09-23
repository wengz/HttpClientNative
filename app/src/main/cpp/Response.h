//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_RESPONSE_H
#define HTTPCLIENTNATIVE_RESPONSE_H

#include <string>

#include "Protocol.h"
#include "Headers.h"
#include "ResponseBody.h"

namespace http_client_native {

    using namespace std;

    class Response {

    public:
        Response (){
            //nothing
        }

        Response & setProtocol (Protocol protocol){
            this->mProtocol = protocol;
            return *this;
        }

        Response & setCode (int code){
            this->mCode = code;
            return *this;
        }

        Response & setMessage(string & message){
            this->mMessage = message;
            return *this;
        }

        Response & setHeaders(Headers & headers){
            this->mHeaders = headers;
            return *this;
        }

        Response & setResponseBody (ResponseBody * responseBody){
            this->mResponseBody = responseBody;
            return *this;
        }

        ResponseBody * getResponseBody(){
            return mResponseBody;
        }

    private:
        Protocol mProtocol;
        int mCode;
        string mMessage;
        Headers mHeaders;
        ResponseBody * mResponseBody;
    };

}


#endif //HTTPCLIENTNATIVE_RESPONSE_H
