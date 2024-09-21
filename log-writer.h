#ifndef LOGWRITER_H
#define LOGWRITER_H
#include <iostream>

class LogWriter {
  public:
    virtual ~LogWriter() = default;
    virtual void write(const std::string&) = 0;
};

#endif //LOGWRITER_H