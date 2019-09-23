//
// Created by wengzc on 2019/9/20.
//

#include <android/log.h>
#include <algorithm>

#include "LogUtil.h"

const int http_client_native::LogUtil::LOG_SEGMENT_LIMIT = 3 * 1024;

const char * http_client_native::LogUtil::LOG_TAG = "http_client_native";

void http_client_native::LogUtil::debug(const std::string &msg) {
    int pos = 0;
    int contentLength = msg.size();
    int segmentLength;
    while (pos < contentLength){
        segmentLength = LOG_SEGMENT_LIMIT;
        int rest = contentLength - pos;
        segmentLength = std::min(rest, segmentLength);
        std::string segmentContent = msg.substr(pos, segmentLength);
        __android_log_write(ANDROID_LOG_DEBUG, LOG_TAG, segmentContent.c_str());
        pos += segmentLength;
    }
}

void http_client_native::LogUtil::debug(const char *msg) {
    debug(std::string(msg));
}
