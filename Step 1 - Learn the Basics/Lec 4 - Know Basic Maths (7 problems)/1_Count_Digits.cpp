#include<iostream>
#include<cmath>
using namespace std;

// Method 1: Using while loop
int countDigitsWhile(int n) {
    if(n == 0) return 1;  // Special case for 0
    
    int count = 0;
    int temp = abs(n);  // Handle negative numbers
    
    while(temp > 0) {
        count++;
        temp /= 10;
    }
    return count;
}

// Method 2: Using for loop
int countDigitsFor(int n) {
    if(n == 0) return 1;
    
    int count = 0;
    for(int temp = abs(n); temp > 0; temp /= 10) {
        count++;
    }
    return count;
}

// Method 3: Using string conversion
int countDigitsString(int n) {
    string str = to_string(abs(n));
    return str.length();
}

// Method 4: Using logarithm (mathematical approach)
int countDigitsLog(int n) {
    if(n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

int main() {
    int number;
    
    cout << "=== COUNT DIGITS PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "\nNumber: " << number << endl;
    cout << "Number of digits (while loop): " << countDigitsWhile(number) << endl;
    cout << "Number of digits (for loop): " << countDigitsFor(number) << endl;
    cout << "Number of digits (string method): " << countDigitsString(number) << endl;
    cout << "Number of digits (log method): " << countDigitsLog(number) << endl;
    
    // Test with multiple numbers
    cout << "\n=== TESTING WITH DIFFERENT NUMBERS ===" << endl;
    int testNumbers[] = {0, 5, 42, 123, 9876, -567, 1000000};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        cout << "Number: " << testNumbers[i] << " -> Digits: " << countDigitsWhile(testNumbers[i]) << endl;
    }
    
    return 0;
}
