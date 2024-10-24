// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public:
    // Default Constructor
    Goat()                          { name = ""; age = 0; color = ""; }
    // Constructor with name by itself
    Goat(string n) { name = n; age = 0; color = ""; }
    // Constructor with name AND age
    Goat(string n, int a) { name = n; age = a; color = ""; }
    // Constructor with all of the parameters
    Goat(string n, int a, string c) { name = n; age = a; color = c; }
    

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    //Overloaded < operator for the std::list
    bool operator<(const Goat &other) const {
        return this->age < other.age;
    }
    // Helper function which will help with formatting output
    string description() const {
        return name + " (" + to_string(age) + ", " + color + ")";
    }
};

#endif
