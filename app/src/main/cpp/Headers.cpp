//
// Created by wengzc on 2019/9/23.
//

#include "Headers.h"
#include "Util.h"

http_client_native::Headers::Headers(const http_client_native::Headers &rhs): nameAndValuesSize(rhs.nameAndValuesSize) {
    nameAndValues = new std::string[nameAndValuesSize];
    memcpy(nameAndValues, rhs.nameAndValues, sizeof(std::string)*nameAndValuesSize);
}

http_client_native::Headers::Headers(http_client_native::Headers::Builder &builder) {
    size_t size = builder.nameAndValues.size();
    this->nameAndValues = new std::string[size];
    this->nameAndValuesSize = 0;
    for (int i = 0; i < size; i++) {
        (this->nameAndValues)[i] = builder.nameAndValues.at(i);
        this->nameAndValuesSize++;
    }
}

http_client_native::Headers &
http_client_native::Headers::operator=(const http_client_native::Headers &rhs) {
    nameAndValuesSize = rhs.nameAndValuesSize;
    nameAndValues = new std::string[nameAndValuesSize];
    memcpy(nameAndValues, rhs.nameAndValues, sizeof(std::string)*nameAndValuesSize);
    return * this;
}

http_client_native::Headers::~Headers() {
    delete[] nameAndValues;
}

http_client_native::Headers::Builder & http_client_native::Headers::Builder::addLenient(std::string line) {
    size_t index = line.find(":", 1);
    if (index != std::string::npos) {
        return addLenient(line.substr(0, index), line.substr(index + 1));
    } else if (line[0] == ':') {
        return addLenient("", line.substr(1));
    } else {
        return addLenient("", line);
    }
}

http_client_native::Headers::Builder & http_client_native::Headers::Builder::add(std::string line) {
    size_t index = line.find(":");
    if (index == std::string::npos) {
        //格式不正确
        return * this;
    }
    std::string name = line.substr(0, index);
    name = trim(name);
    std::string value = line.substr(index + 1);
    return add(name, value);
}

http_client_native::Headers::Builder & http_client_native::Headers::Builder::add(std::string name, std::string value) {
    return addLenient(name, value);
}

http_client_native::Headers::Builder & http_client_native::Headers::Builder::addLenient(std::string name, std::string value) {
    nameAndValues.push_back(name);
    nameAndValues.push_back(trim(value));
    return *this;
}

http_client_native::Headers::Builder & http_client_native::Headers::Builder::removeAll(std::string name) {
    auto itr = nameAndValues.begin();
    while (itr != nameAndValues.end()){
        if (strcasecmp(name.c_str(), (*itr).c_str()) == 0){
            itr = nameAndValues.erase(itr, itr + 1);
        }else{
            itr += 2;
        }
    }
    return *this;
}

http_client_native::Headers * http_client_native::Headers::Builder::build() {
    return nullptr;
}

