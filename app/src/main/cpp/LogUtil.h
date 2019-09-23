//
// Created by wengzc on 2019/9/20.
//

#ifndef HTTPCLIENTNATIVE_LOGUTIL_H
#define HTTPCLIENTNATIVE_LOGUTIL_H

#include <string>

namespace http_client_native {

class LogUtil {

    /**
     * android logcat对较长信息进行截断，类中方法进行分段打印
     *
     */

public :

    static void debug (const std::string & msg);

    static void debug (const char * msg);

private :

    /**
     * 日志分段大小
     */
    static const int LOG_SEGMENT_LIMIT;
    static const char * LOG_TAG;

};

}

#endif //HTTPCLIENTNATIVE_LOGUTIL_H
