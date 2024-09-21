#include "logger.h"

void Logger::log(std::string loglevel, std::string logmsg) {
	//std::cout << "*** Curernt Level :: " << LogTypeMap[level_] << std::endl;
	for(auto logwriter : logwriters_) {
		logwriter->write(logformatter_.format(loglevel, logmsg));
	}
}

Logger::Logger(LogLevel level) {
	level_ = level;
	LogWriter* console = new ConsoleLog();
	logwriters_.push_back(console);
}

Logger::~Logger() {
	for(auto logwriter : logwriters_) {
		delete logwriter;
	}
}

Logger::Logger(LogWriter* logWriter, LogLevel level) : level_(level) {
	logwriters_.push_back(logWriter);
}

void Logger::appendWriter(LogWriter* logwriter) {
	logwriters_.push_back(logwriter);
}

void Logger::critical(std::string logmsg) {
	log("CRITICAL", logmsg);
}

void Logger::error(std::string logmsg) {
	log(LogTypeMap[LogLevel::ERROR], logmsg);
}

void Logger::info(std::string logmsg){
	if(level_ >= LogLevel::INFO) {
		log(LogTypeMap[LogLevel::INFO], logmsg);
	}
}

void Logger::warn(std::string logmsg) {
	if(level_ >= LogLevel::WARN) {
		log(LogTypeMap[LogLevel::WARN], logmsg);
	}
}

void Logger::debug(std::string logmsg) {
	if(level_ >= LogLevel::DEBUG) {
		log(LogTypeMap[LogLevel::DEBUG], logmsg);
	}
}