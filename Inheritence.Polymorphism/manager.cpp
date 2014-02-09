//
//  manager.cpp
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

Manager::Manager(string theName,
                 float thePayRate,
                 bool isSalaried)
: Employee(theName, thePayRate)
{
    salaried = isSalaried;
}

bool Manager::getSalaried() const
{
    return salaried;
}

void Manager::setSalaried(const bool & salaried)
{
    this->salaried = salaried;
}

float Manager::pay(float hoursWorked) const
{
    if (salaried)
        return payRate;
    /* else */
    return Employee::pay(hoursWorked);
}