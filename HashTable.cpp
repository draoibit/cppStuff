//
//  main.cpp
//  DSLab5_McEntee
//
//  Created by Rory McEntee on 2/9/14.
//  Copyright (c) 2014 Rory McEntee. All rights reserved.
//


//Based off of this implementation @ http://www.onextrabit.com/view/502c152965e7d250c5000001
//uses djb2 hash function
//contains exists, insert, and remove functions

#include <iostream>
#include <string.h>

template <typename T>
class SimpleHash {
private:
    
    T * hashData;
    int *status_arr;
    
    unsigned int m_size;
    
    unsigned int djb2(const char* key) {
        unsigned int hash = 10007;
        
        for (unsigned int i = 0; i < strlen(key); i++)
            hash = ((hash << 5) + hash) + (unsigned int)key[i];
        
        return hash % m_size;
    }
    
public:
    SimpleHash(unsigned int size): m_size(size) {
        // init hash table data given table size
        hashData = new T[m_size];
        status_arr = new int[size];
    }
    
    void set(const char* key, const T& value) {
        unsigned int index = djb2(key);
        hashData[index] = value;
        status_arr[index] = 1;
    }
    
    T getSalaries(const char* key) {
        unsigned int index = djb2(key);
        return hashData[index];
    }
    
    
    T exists(const char* key)
    {
        bool exists;
        unsigned int index = djb2(key);
        if (status_arr[index] == 1)
            exists = true;
        else 
            exists = false;
        return exists;
    }
    
    void remove(const char* key)
    {
        int index = djb2(key);
        status_arr[index] = 0;
        hashData[index] = -1;
    }
};





int main() {
    
    SimpleHash<float> alisonHash(50);
    
    alisonHash.set("Alison", 30000);
    alisonHash.set("Rory", 35000);
    alisonHash.set("Hao", 50000);
    alisonHash.set("Sherri", 80000);
    
    std::cout <<  "Alison makes $" << alisonHash.getSalaries("Alison") << std::endl;
    std::cout << "Rory makes $" << alisonHash.getSalaries("Rory") << std::endl;
    std::cout <<  "Hao makes $" << alisonHash.getSalaries("Hao") << std::endl;
    std::cout << "Sherri makes $" << alisonHash.getSalaries("Sherri") << std::endl;
    
    std::cout << "Does Rory have a job?" << std::endl;
    
    
    if (alisonHash.exists("Rory")) {
        std::cout << "Rory gets hired because he is a hard working individual." << std::endl;
    } else {
        std::cout << "Rory gets fired because he has trouble with data structures." << std::endl;
    }
    
    std::cout << "Does Rory have a job three months later?" << std::endl;
    
    alisonHash.remove("Rory");
    
    if (alisonHash.exists("Rory")) {
        std::cout << "Rory gets hired because he is a hard working individual." << std::endl;
    } else {
        std::cout << "Rory gets fired because he has trouble with data structures." << std::endl;
    }
    
    alisonHash.set("Rory", 35000);
    
    std::cout << "Does Rory have a job six months later?" << std::endl;
    
    if (alisonHash.exists("Rory")) {
        std::cout << "Rory gets hired again because he improves his skills." << std::endl;
    } else {
        std::cout << "Rory still doesn't have a job and lives in a cardboard box." << std::endl;
    }
    
    
    std::cout << "Rory makes $" << alisonHash.getSalaries("Rory") << std::endl;
    
    
    
    return 0;
}