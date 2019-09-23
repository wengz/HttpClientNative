//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_HTTPMETHOD_H
#define HTTPCLIENTNATIVE_HTTPMETHOD_H

#include <string>

namespace http_client_native {

    class HttpMethod {
        using namespace std;

    public :

        static bool permitsRequestBody(const string &method);
    };

}


#endif //HTTPCLIENTNATIVE_HTTPMETHOD_H
