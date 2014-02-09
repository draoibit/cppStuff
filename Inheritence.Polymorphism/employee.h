//
//  employee.h
//  McEntee_Lab7
//
//  Created by Rory McEntee on 1/30/14.
//  Copyright (c) 2014 Rory McEntee. All rights reserved.
//

#ifndef __McEntee_Lab7__EMPLOYEE_H__
#define __McEntee_Lab7__EMPLOYEE_H__
using namespace std;

class Employee {
public:
    Employee(string theName, float thePayRate);
    
    string getName() const;
    void setName(const string & name);
    float getPayRate() const;
    void setPayRate(const float & payRate);
    float pay(float hoursWorked) const;
    
protected:
    string name;
    float payRate;
};

#endif /* not defined _EMPLOYEE_H */