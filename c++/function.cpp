#include <iostream>

int sum(int, int);

int main() {
    int x, y;
    std::cout << "Enter x and y::" << std::endl;
    std::cin >> x >> y;
    std::cout << "Sum: " << sum(x,y) << std::endl;
    return 0;
}

int sum(int x, int y) {
    return x+y;
}