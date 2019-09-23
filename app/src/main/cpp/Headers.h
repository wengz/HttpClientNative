//
// Created by wengzc on 2019/9/23.
//

#ifndef HTTPCLIENTNATIVE_HEADERS_H
#define HTTPCLIENTNATIVE_HEADERS_H

#include <string>
#include <vector>

namespace http_client_native {

    class Headers {

    public:

        /**
         * 构造器
         */
        class Builder{

        public:
            friend class Headers;

            Builder (){}
            Builder & addLenient (std::string line);
            Builder & add (std::string line);
            Builder & add (std::string name, std::string value);
            Builder & addLenient (std::string name, std::string value);
            Builder & removeAll (std::string name);
            Headers * build ();

        private :
            std::vector<std::string> nameAndValues;
        };


        Headers (){}
        Headers(const Headers & rhs);
        Headers(Builder & builder);
        Headers & operator=(const Headers & rhs);
        virtual ~Headers();

        Builder * newBuilder  (){
            Builder * res = new Builder;
            for (int i = 0; i < nameAndValuesSize; i++){
                res->nameAndValues.push_back(*(nameAndValues+i));
            }
            return res;
        }

        size_t size() const{
            return nameAndValuesSize/2;
        }

        std::string name(int index) const {
            return nameAndValues[index*2];
        }

        std::string value (int index) const {
            return nameAndValues[index * 2 + 1];
        }

    private :
        std::string * nameAndValues;
        size_t nameAndValuesSize;
    };

}


#endif //HTTPCLIENTNATIVE_HEADERS_H
