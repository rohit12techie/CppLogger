#ifndef LOGGER_H 
#define LOGGER_H

#include <vector>
#include "log-writer.h"
#include "console-log.h"
#include "file-log.h"
#include "log-formatter.h"
#include <map>

enum class LogLevel { 
    ERROR = 0, 
    INFO, 
    WARN,
    DEBUG
};

class Logger {
  private: 
    std::vector<LogWriter*> logwriters_;
	  LogFormatter logformatter_;
	  LogLevel level_;
    std::map<LogLevel, std::string> LogTypeMap { 
	    {LogLevel::ERROR,    "ERROR"}, 
	    {LogLevel::INFO,     "INFO"}, 
	    {LogLevel::WARN,     "WARN"}, 
	    {LogLevel::DEBUG,    "DEBUG"}, 
    };
	void log(std::string loglevel, std::string logmsg);
  void appendWriter(LogWriter* logwriter);

  public:
    
    Logger(LogLevel level = LogLevel::DEBUG);

    Logger(LogWriter* logWriter, LogLevel level = LogLevel::DEBUG); 

    ~Logger();

	void critical(std::string logmsg);

    void error(std::string logmsg);

    void info(std::string logmsg);

    void warn(std::string logmsg);

    void debug(std::string logmsg);
};

#endif // LOGGER_H