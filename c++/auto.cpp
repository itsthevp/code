#include <iostream>
#include <typeinfo>
using namespace std;

/**
 * 'auto' indicates storage class of a variable in C & pre-C++11
 * Meaning has been changed in C++ 11
 * Now, 'auto' allows the compiler to automatically infer the type from initializer
 * It is like,
 * auto a = 5; Here, 'a' will be inferred as 'int' automatically by compiler
 * auto a = 5.5f; Here, 'a' will be inferred as 'float' automatically by compiler
 * Hence, using auto you don't need to specify type of variable during declaration
 * 
 * So, while using 'auto' initializer is important
 * auto <identifier> = <initializer>
 * that means initializer is always needed while declaring variable with auto 
*/

int main() {
    // auto a; NOT ALLOWED, while using 'auto', Initializer needs to be present
    auto ai = 5;        // 'ai' will be inferred as int
    cout << "ai: " << typeid(ai).name() << endl;

    auto af = 5.5f;     // 'af' will be inferred as float
    cout << "af: " << typeid(af).name() << endl;

    auto ab = 5 > 6;    // 'ab' will be inferred as bool
    cout << "ab: " << typeid(ab).name() << endl;
    
    auto aif = ai + af; // 'aif' will be inferred as float (int + float => float)
    cout << "aif: " << typeid(aif).name() << endl;

    // qualifier like const gets discarded when using auto
    const int i = 5;
    auto j = i;                 // 'j' will be int but not const, primitive, it's copy by value
    j++;                        // only 'j' is going to be incremented
    cout << i << j << endl;     // i => 5, j => 6

    auto k = &i;                // here, 'k' is const int*, means value at address is constant (address can be changed to point something else), qualifiers preserved
    // also while using 'auto', '*' is not required if rvalue is address
    // auto *k = &i; (Wrong) auto will automatically infer k as const int*
    // So, avoid using auto while initializing via references or pointers to minimize confusion and increase readability 

    cout << i << " | " << *k << " | " << *k++ << endl;  // First two will be 5 only, third one can be 5 / garbage

    auto &l = i;                // here l will be same as i, const int, means creating reference using auto, qualifiers will be preserved

    // Initializer List
    // It is constructed automatically by the compiler from a list of comma separated elements which are enclosed in braces.
    // We can use 'auto' to construct an initializer list
    auto list = {1,2,3,4};      // type of list is std::initializer_list<int>
    cout << "list: " << typeid(list).name() << endl;
    

    // Also remember, Initializer list is created only when {..,..,..} is on RHS
    // auto list {1,2,3,4}; This is an error.
    
    return 0;
}