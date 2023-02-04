#include <iostream>
using namespace std;

int main() {
    char name[50];
    cout << "What's your name ?" << endl;
    // cin >> name; // Will read until first space is encountered
    cin.getline(name, 50);
    cout << "Your name is: " << name;
    return 0;
}