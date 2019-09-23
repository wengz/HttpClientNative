//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_STATUSLINE_H
#define HTTPCLIENTNATIVE_STATUSLINE_H

#include <string>
#include <stdexcept>
#include "../../Protocol.h"

namespace http_client_native {

    class StatusLine {

        using namespace std;

    public :

        static const int HTTP_TEMP_REDIRECT;
        static const int HTTP_PERM_REDIRECT;
        static const int HTTP_CONTINUE;

        static StatusLine parse(const string &statusLine) throw(runtime_error);

        StatusLine(Protocol protocol, int code, std::string &message);

        Protocol protocol;
        int code;
        std::string message;

    };

}


#endif //HTTPCLIENTNATIVE_STATUSLINE_H
