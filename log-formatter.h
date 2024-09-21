#ifndef LOGFORMATTER_H
#define LOGFORMATTER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

class LogFormatter {
    public:
    LogFormatter() = default; 
    
    std::string format(std::string logtype, std::string logmsg) {
        auto currentTime = [](){
            std::ostringstream oss;
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            oss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
            return oss.str();
        };

        return currentTime() + " " + logtype + " " + logmsg; 
    }
};

#endif //LOGFORMATTER_H