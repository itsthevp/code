#include <iostream>
using namespace std;

int main() {
    const float PI = 3.1415f;
    /*
    * float *ptr = &PI;
    * Pointer to const NOT ALLOWED
    * Because if allowed, value can be changed through pointer.
    * Language states that:
    * If creating a pointer to const, then pointer also needs to be const
    * This essentially means that address which pointer is holding is not constant but,
    * value at that address is const
    */
    const float *ptr = &PI; // *ptr => value at address ptr is holding is constant
    /*
    * So here,
    * ptr = &(some_other_variable) is allowed but,
    * *ptr = some_value (means changing the value) is not allowed
    */
    float x = 5.5f;
    ptr = &x; // allowed (pointer's pointing address changed - allowed)
    // *ptr = 6; // Not allowed (changing value of variable, pointer is pointing, even though that variable is not constant)

    /*
    *   int a = 5;
    *   int *p = &a; (normal pointer)
    *   const int *p = &a; (*p => value, pointer is pointing, is 'const int', means value is constant)
    *   int *const p = &a; (p => address, pointer is holding, is 'int *const', means address is constant)
    *   const int *const p = &a; (p => address, pointer is holding, is 'const int' and '*const', means both address and value at that address is constant)
    */

    int a = 5;
    int *p = &a; // normal pointer, both address and value at address (if that variable itself is not constant) can be changed
    const int *q = &a; // value at address is constant, means you can't change value at address regardless of addressed variable is constant or not
    const int *const r = &a; // address and value both are constant, nothing can be changed

    // Bounding to variable: pointer < reference < (const type *const, const type &)

    // CONST WITH REFERENCES

    // By default ref to literal is not allowed like, 
    // int &z = 999;
    // But it is allowed if you declare ref also as constant
    const int &z = 999;
    // z = x; now, // changing referent is not allowed
}

/**
 * Use Cases
*/

void print_val_unsafe(int *v) {
    cout << *v << endl;
    // Here, value at v can be modifiable
    // like *v = some_value
    // which is not expected to be allowed
}

void print_val_safe(const int *v) {
    cout << *v << endl;
    // Now here, value at 'v' is safe and not modifiable here
}

void print_literal_unsafe(int &v) {
    cout << v << endl;
    // Here, if actual argument will be literal, then compiler won't allow
}

void print_literal_safe(const int &v) {
    cout << v << endl;
    // Here, it will be allowed because const will restrict change to literal
}