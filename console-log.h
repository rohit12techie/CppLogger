#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "log-writer.h"

class ConsoleLog : public LogWriter{
  public:
    ConsoleLog() = default;

    void write(const std::string& logmsg) override {
        std::cout << logmsg << std::endl;
    }
};


#endif //CONSOLE_H