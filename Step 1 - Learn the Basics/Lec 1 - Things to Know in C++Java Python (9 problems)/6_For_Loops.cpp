#include<iostream>
using namespace std;

int main() {
    // For loops in C++
    
    // Basic for loop
    cout << "Numbers 1 to 10: ";
    for(int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop with different increment
    cout << "Even numbers 2 to 20: ";
    for(int i = 2; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // Reverse for loop
    cout << "Numbers 10 to 1: ";
    for(int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    // Single for loop - multiplication table
    int num;
    cout << "Enter a number for multiplication table: ";
    cin >> num;
    
    for(int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    
    // Actual nested for loop example - printing a pattern
    cout << "\nNested for loop - Star pattern:" << endl;
    for(int i = 1; i <= 5; i++) {        // Outer loop
        for(int j = 1; j <= i; j++) {    // Inner loop (nested)
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
