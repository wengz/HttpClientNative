//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_MEDIATYPE_H
#define HTTPCLIENTNATIVE_MEDIATYPE_H

#include <string>
#include <regex>

namespace http_client_native {

    class MediaType {

        using namespace std;

    public :

        static MediaType get(string str) throw (runtime_error);

        static MediaType parse(string string) ;

        string getType() const;

        string getSubtype() const;

        string getCharset() const;

        string getCharset(string & defaultValue) const;

        MediaType();
        MediaType (string & mediaType, string &type, string &subtype, string &charset);

    private :
        static const string TOKEN;
        static const string QUOTED;

        static const regex TYPE_SUBTYPE;
        static const regex PARAMETER;

        string mediaType;
        string type;
        string subtype;
        string charset;
    };

}

#endif //HTTPCLIENTNATIVE_MEDIATYPE_H
