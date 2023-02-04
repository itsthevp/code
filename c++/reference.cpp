#include <iostream>
using namespace std;

void swap_using_ref(int &, int &);
void swap_using_ptr(int *, int *);
void print_int_using_ref(int &);
void print_int_using_ptr(int *);

int main() {
    // Reference is just a another mnemonic for a identifier, it doesn't have its own memory like a pointer
    // Reference needs referent (means you can't declare reference without reference)
    // Reference can read /write value of it's referent
    // Reference can't be nullptr
    // Reference throughout its lifetime, remains bound to it's referent 

    int x = 5;
    int &r = x;

    cout << "Referent: " << &x << endl;
    cout << "Reference: " << &r << endl;

    r += 1;
    cout << "Referent: " << r << endl;

    int y = 10;
    r = y;

    cout << "Reference Value: " << r << endl;
    r += 1;
    cout << "Second Referent Value: " << y << endl;
    cout << "First Referent Value: " << x << endl;

    // Means reference can take value of another referent but subsequent modification using reference will
    // affect the value of it's first referent only, and second referent won't be affected at all.

    cout << "x: " << x << " y: " << y << endl;
    swap_using_ref(x, y);
    cout << "x: " << x << " y: " << y << endl;
    swap_using_ptr(&x, &y);
    cout << "x: " << x << " y: " << y << endl;

    return 0;
}

void swap_using_ptr(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

void swap_using_ref(int &x, int &y) {
    int temp = y;
    y = x;
    x = temp;
}

void print_int_using_ptr(int *p) {
    // As pointer can be nullptr, we have to check otherwise program will crash on runtime if it encounters nullptr
    if(p != nullptr)
        cout << "Value: " << *p << endl;
}

void print_int_using_ref(int &r) {
    // Here, we need to not worry as reference can't be null ever
    cout << "Value: " << r << endl;
}

/*
* So, when to usage of reference or pointer is totally depends on the use case.
*/