//
//  supervisor.h
//  McEntee_Lab7
//
//  Created by Rory McEntee on 1/30/14.
//  Copyright (c) 2014 Rory McEntee. All rights reserved.
//

#ifndef __McEntee_Lab7__supervisor__
#define __McEntee_Lab7__supervisor__
using namespace std;

class Supervisor : public Employee {
public:
    Supervisor(string theName,
            float thePayRate,
            bool isSalaried,
               string theDept);
    
    float pay(float hoursWorked) const;
    
    bool getSalaried() const;
    void setSalaried(bool & salaried);
    
    string getDept() const;
    void setDept(const string & dept);
    
protected:
    bool salaried;
    string dept;
};

#endif /* defined(__McEntee_Lab7__supervisor__) */
