#ifndef FILELOG_H
#define FILELOG_H

#include <iostream>
#include <string>
#include <fstream>
#include "log-writer.h"

class FileLog : public LogWriter{
  private:
    std::string logfile_;
    std::ofstream filestream;
  public:

    FileLog(std::string logfile) : logfile_(logfile) {
        filestream.open(logfile_, std::ios_base::app);
    }

    ~FileLog() {
        filestream.close();
    }

    void write(const std::string& logmsg) override {
        filestream << logmsg << std::endl;
        filestream.flush();
    }
};

#endif //FILELOG_H