//
// Created by wengzc on 2019/9/20.
//

#ifndef HTTPCLIENTNATIVE_UTIL_H
#define HTTPCLIENTNATIVE_UTIL_H

#include <string>

namespace http_client_native {

    unsigned long hexToDec(const char *hex, int length);

    std::string & trim(std::string &);

    int delimiterOffset (std::string input, int pos, int limit, std::string delimiters);

    std::string strToLower(std::string str);

    std::string strToUpper(std::string str);

    bool compareIgnoreCase(std::string str_a, std::string str_b);

    int decodeHexDigit(char c);

    int skipLeadingAsciiWhiteSpace(std::string & input, int pos, int limit);

    int skipTrailingAsciiWhiteSpace(std::string & input, int pos, int limit);

    bool regionMatches(const std::string & s1, const std::string & s2, bool ignore_case, int offset_1, int offset_2, int length );

    int getContentLength(std::string line);

    int decodeHexDeigit (char c);

    std::string utilCanonicalizeHost (std::string host);

}

#endif //HTTPCLIENTNATIVE_UTIL_H
