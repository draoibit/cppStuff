//
//  employee.cpp
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

Employee::Employee(string theName, float thePayRate)
{
    name = theName;
    payRate = thePayRate;
}

string Employee::getName() const
{
    return name;
}

void Employee::setName(const string & name)
{
    this->name = name;
}

float Employee::getPayRate() const
{
    return payRate;
}

void Employee::setPayRate(const float & payRate)
{
    this->payRate = payRate;
}

float Employee::pay(float hoursWorked) const
{
    return hoursWorked * payRate;
}
