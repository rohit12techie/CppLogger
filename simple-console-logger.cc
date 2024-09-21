#include <iostream>
#include "logger.h"
Logger logger;

struct Name {
    std::string first_name_;
    std::string second_name_;
};

class Employee  {
  private:
    Name name_; 
    float age_;
    std::string emp_id_;

  public:
    Employee(Name name) : name_(name) {
        age_ = 0;
        emp_id_ = "EMP_RAND_12X";
    }

    std::string getName() const {
        return name_.first_name_ + " " + name_.second_name_;
    }

    double getAge() const {
        return age_;
    }

    std::string getEmpId() const {
        return emp_id_;
    }

    ~Employee() {
        logger.info("Destructor of Employee called");
    }

};

void print(const Employee& emp) {
    logger.debug("This is inside print function----");
    logger.info("Name : " + emp.getName());
    logger.info("Age  : " + std::to_string(emp.getAge()));
    logger.info("employee id : " + emp.getEmpId());
    logger.critical("Ahh cricitical messages are shown");
    logger.error("This is just to test error (-_-)");
    logger.warn("Why to leave warn");
}

int main() {
    Name name{"Rohit", "Kumar"};
    Employee emp(name);
    logger.info("Print Employee details ---- ");
    print(emp);
    logger.info("Print Employee details ---- ");
    
    return 0;
}