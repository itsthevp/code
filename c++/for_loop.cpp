#include <iostream>
using namespace std;

int main() {
    int list[] = {1,2,3,4,5,6,7,8,9,10};

    // Standard For Loop
    for (short i = 0; i <= 10; i++) {
        cout << i << " ";
    }

    /**
     * Range based For Loop
     * allows iteration over arrays and containers
     * doesn't need an index var
     * can be used with any object that behaves like a range
    */

    for(int element: list) {
        cout << element << " ";
    }

    /**
     * In the above for-loop,
     * In each iteration, copy of the list's element will be created into element
     * To avoid that, we can declare element as reference
     * caution: It will allow to modify the value of element in the array
    */
    
    for(int &element: list) {
        element = 3;            // all elements of the list will be changed to 3 forever
        cout << element << " ";
    }
    for(int element: list) {
        cout << element << " "; // all will be 3 only
    }

    /**
     * To avoid this, we can use 'const int &' or 'const auto &'
    */

    /**
     * Internal Details:
     * Range based for loop doesn't require end condition because,
     * that is provided as the end iterator through the end function.
     * This 'end' function is provided by all ranges.
     * For arrays, the standard library provided the global end function.
    */

   // Range Based For Loop Internally Expanse To

    auto begin = std::begin(list);
    auto end = std::end(list);
    for(;begin != end; ++begin) {
        auto v = *begin;
        cout << v << " ";
    }

   return 0;
}