/*
 //  Lab6_McEntee.cpp
 //
 //
 //  Created by Rory McEntee on 1/28/14.
 //  Copyright (c) 2014 Rory McEntee. All rights reserved.
 //
 I implemented a simple stack using an array and the three push, pop, and isEmpty functions.
 
 In order to get the min function in O(1) time, I mirror the array with a second equally sized array.
 When I push an int onto the second stack, if there is now 2 ints in the array, the values are compared,
 and the smaller value is kept or placed on top of the stack. Now I can return the smallest value on the
 second stack.
 
 
 */
#include <iostream>
using namespace std;
#define max 10


class stack {
private:
    int alisonarray[max];
    int minarray[max];
    int top = -1;
    
public:
    stack(){
    }
    
    void push(int i){
        if (top < max-1){
            
            cout << i << " has been added to the stack." << endl;
            top++;
            alisonarray[top] = minarray[top] = i;
            
            if (top > 0) {
                if (minarray[top] > minarray[top - 1]) {
                    minarray[top] = minarray[top - 1];
                    minarray[top - 1] = i;
                }
            }
        }
        
        else{
            cout << "The stack is full" << endl;
        }
    }
    
    void getMin() {
        cout << "The smallest element in the stack is " << minarray[top] << endl;
    }
    
    void pop(){
        if (top==-1){
            cout<<"The stack is empty.\n";
            return;
        }
        else {
            int i, j;
            int data = alisonarray[top];
            cout << data << " which is the top value has been popped."<< endl;
            alisonarray[top]=NULL;
            
            for (i = top; i > 0; i--) {
                if (data == minarray[i]) {
                    minarray[i] = NULL;
                    for (j = i; j < top; j++) {
                        minarray[j] = minarray[j + 1];
                        break;
                    }
                }
            }
            top--;
        }
    }
    
    bool isEmpty() {
        if (top == -1) {
            cout << "The stack is empty" << endl;
            return true;
        }
        else {
            cout << "The stack is not empty" << endl;
            return false;
        }
    }
    
};

int main(){
    
    stack alison;
    alison.isEmpty();
    alison.push(9);
    alison.isEmpty();
    alison.push(5);
    alison.getMin();
    alison.push(2);
    alison.getMin();
    alison.push(7);
    alison.getMin();
    alison.push(1);
    alison.getMin();
    alison.pop();
    alison.getMin();
    alison.push(6);
    alison.getMin();
    alison.pop();
    alison.getMin();
    alison.pop();
    alison.getMin();
    alison.pop();
    alison.getMin();
    alison.pop();
    alison.getMin();
    alison.pop();
    alison.pop();
    return 0;
    
}