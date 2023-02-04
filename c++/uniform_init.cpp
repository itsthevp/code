#include <iostream>
#include <string>

/*
* c++98
* For scaler types: initialized with = or ()
* For vector types: initialized with {}

*c++11 introduced uniform initialization
* For both scaler and vector using {}
* Benefits:
* Uniform Syntax
* Forces initializations of both scaler and vector types
* Prevents bug when initializing incompatible types through compiler warnings and errors (like narrowing conversions)
*/

/*
* Types of Initializations
1. Value Init => T obj{};
2. Direct Init => T obj{v};
3. Copy Init => T obj = v;  Avoid these while using user defined objects
*/

int main() {
    using namespace std;

    int a1; // Uninitialized + a1 will have garbage value
    int a2 = 1; // Copy init
    int a3(5); // Direct init

    string s1;
    string s2("c++"); // Direct Init

    char d1[8]; // Uninitialized
    char d2[8] = {'\0'}; // Copy init
    char d3[8] = {'a', 'b', 'c', 'd'}; // Aggregate Init
    char d4[8] = {"abcd"}; // Copy init

    // Uniform Init

    int b1{}; // Value init + b1 will have default int value
    /*
    Most vexing parse
    int b2(); // b2 won't have default value here, Instead It will be treated as function
    but with uniform init, this is gone
    */
    int b3{5}; // Direct init

    char e1[8]{}; // This will auto initialize elements of d1 with default values
    char e2[8]{"Hello"}; // Direct init
    char e3[8]{'a', 'b', 'c', 'd'}; // Copy init

    // Uniform init also works with heap based objects
    // On value init, objects in the heap will have default value

    int* p = new int; // Legacy, Uninitialized, garbage value
    int* q = new int{}; // Value init + will have default int value in heap
    char* r = new char[8]; // Legacy, Uninitialized, garbage elements
    char* s = new char[8]{}; // Value init + will have default char value for all elements
    char* t = new char[8]{"Hello"}; // This is also possible in uniform init which was not possible earlier

    cout << b1;
    return 0;
}

/*
* Recommendations:
- For primitive types, stick with assignments because that may seem more natural
- For user-defined things, always use uniform syntax
*/