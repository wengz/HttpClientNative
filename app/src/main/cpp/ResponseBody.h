//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_RESPONSEBODY_H
#define HTTPCLIENTNATIVE_RESPONSEBODY_H

#include <string>
#include "Http1Codec.h"
#include "internal/http/Http1Codec.h"

namespace http_client_native {

    class ResponseBody {

    public:
        ResponseBody (Http1Codec http1Codec)
            :mHttp1Codec(http1Codec){
            //nothing
        }

    private:
        Http1Codec mHttp1Codec;
    };


}


#endif //HTTPCLIENTNATIVE_RESPONSEBODY_H
