//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_REALCALL_H
#define HTTPCLIENTNATIVE_REALCALL_H

#include "Call.h"
#include "HttpClient.h"
#include "Request.h"
#include "Response.h"

namespace http_client_native {

    class RealCall : public Call {

    public:
        RealCall(HttpClient * client, Request * request)
        :mClient(client), mRequest(request){
            //nothing
        };

        virtual ~RealCall(){

        };

        Response *execute();
        void cancel();

    private:
        HttpClient * mClient;
        Request * mRequest;
    };

}


#endif //HTTPCLIENTNATIVE_REALCALL_H
