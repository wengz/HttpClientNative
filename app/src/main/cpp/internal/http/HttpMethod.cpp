//
// Created by wengzc on 2019/9/23.
//

#include "HttpMethod.h"

namespace http_client_native {

    using namespace std;

    bool HttpMethod::permitsRequestBody(const string & method) {
        if ( method == "GET" || method == "HEAD" ){
            return false;
        }
        return true;
    }


}