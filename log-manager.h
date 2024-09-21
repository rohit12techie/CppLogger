#ifndef LOGGERMANAGER_H
#define LOGGERMANAGER_H

#include <mutex>
#include <memory>

#include "logger.h"

//typedef std::shared_ptr<Logger*> logger_ptr;

enum class LogClass { 
    FILE = 0, 
    CONSOLE, 
    QUEUE,
	DATABASE,
};

class LogManager {
  private:
    static Logger* logger_;    
    static std::mutex mtx_;
    static LogLevel level_;
    LogManager() = default;
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;
    
  public:
    static Logger& getLogger(LogLevel level = LogLevel::DEBUG, std::string logfile = "application-user.log") {
        if(logger_ == nullptr) {
            std::lock_guard<std::mutex> guard(mtx_);
            if(logger_ == nullptr) {
                level_ = level;
                LogWriter* fileLogWriter = new FileLog(logfile);
                logger_ = new Logger(fileLogWriter);
            }
        }
        return *logger_;
    }
};

Logger* LogManager::logger_ = nullptr;
std::mutex LogManager::mtx_;
LogLevel LogManager::level_;

#endif // LOGGERMANAGER_H