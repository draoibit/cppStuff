//
//  manager.h
//  McEntee_Lab7
//
//  Created by Rory McEntee on 1/30/14.
//  Copyright (c) 2014 Rory McEntee. All rights reserved.
//

#ifndef __McEntee_Lab7__MANAGER_H__
#define __McEntee_Lab7__MANAGER_H__
using namespace std;

class Manager : public Employee {
public:
    Manager(string theName,
            float thePayRate,
            bool isSalaried);
    
    bool getSalaried() const;
    void setSalaried(const bool & salaried);
    
    float pay(float hoursWorked) const;
    
protected:
    bool salaried;
};

#endif /* not defined _MANAGER_H */
