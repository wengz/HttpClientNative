//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_DNS_H
#define HTTPCLIENTNATIVE_DNS_H

#include <string>
#include <vector>

namespace http_client_native {

    class Dns {

    public:
        static std::vector<std::string> lookup(const std::string &hostname);
    };

}


#endif //HTTPCLIENTNATIVE_DNS_H
