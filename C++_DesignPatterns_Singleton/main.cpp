//
//  main.cpp
//  C++_DesignPatterns_Singleton
//
//  Created by Ferenc Szalma on 9/2/16.
//  Copyright © 2016 Ferenc Szalma. All rights reserved.
//

#include <iostream>
using namespace std;


class NonSingleton {
public:
    NonSingleton(){}
    NonSingleton(const NonSingleton & rhs){ // Copy constr
        n = rhs.n;
    }
    NonSingleton & operator=(const NonSingleton & rhs){ // Copy assignment operator
        n = rhs.n;
        return *this;
    }
    NonSingleton(const int n) : n(n) {} // Contruct from int
private:
    int n;
};

class Singleton
{
public:
    static Singleton & createSingleton() // Factory
    {
        static Singleton instance;
        return instance;
    }
    Singleton * print()
    {
        cout << "Print from singleton.   " << endl << n << endl;
        return this;
    }
    Singleton * increase() {
        ++n;
        return this;
    }
    
private:
    Singleton() // Private constructor called by createSingleton factory
    {
        n = 1;
        cout << "Creating a singleton" << endl;
    };
    Singleton(const Singleton &); // Define but don't implement copy constructor!
    Singleton & operator=(const Singleton &); // Define but don't implement copy assignment!
    
    int n;
};


int main(int argc, const char * argv[]) {
    NonSingleton ns(1);
    NonSingleton ns2 = ns;
    
    Singleton * sp =  &Singleton::createSingleton(); // Bind singleton to a pointer
    sp->print()->increase()->print();
    return 0;
}
