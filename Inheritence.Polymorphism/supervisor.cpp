//
//  supervisor.cpp
//  McEntee_Lab7
//
//  Created by Rory McEntee on 1/30/14.
//  Copyright (c) 2014 Rory McEntee. All rights reserved.
//

#include <iostream>
#include "employee.h"
#include "manager.h"
#include "supervisor.h"
using namespace std;

Supervisor::Supervisor(string theName,
                 float thePayRate,
                 bool isSalaried,
                 string theDept)
: Employee(theName, thePayRate)
{
    salaried = isSalaried;
    dept = theDept;
}

bool Supervisor::getSalaried() const
{
    return salaried;
}

void Supervisor::setSalaried(bool & salaried)
{
    this->salaried = salaried;
}


string Supervisor::getDept()const {
    return dept;
}


void Supervisor::setDept(const string & dept) {
    this->dept = dept;
}

float Supervisor::pay(float hoursWorked) const
{
    if (salaried)
        return payRate;
    /* else */
    return Employee::pay(hoursWorked);
}