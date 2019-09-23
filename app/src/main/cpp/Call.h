//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_CALL_H
#define HTTPCLIENTNATIVE_CALL_H


#include "Response.h"

namespace http_client_native {


    class Call {

    public:
        virtual Response * execute() = 0;

    };

}


#endif //HTTPCLIENTNATIVE_CALL_H
