#include<iostream>
#include<algorithm>
using namespace std;

// Method 1: Using while loop
int reverseNumberWhile(int n) {
    int reversed = 0;
    int temp = abs(n);  // Work with absolute value
    
    while(temp > 0) {
        int digit = temp % 10;      // Extract last digit
        reversed = reversed * 10 + digit;  // Add digit to reversed number
        temp /= 10;                 // Remove last digit
    }
    
    return (n < 0) ? -reversed : reversed;  // Restore sign
}

// Method 2: Using for loop
int reverseNumberFor(int n) {
    int reversed = 0;
    
    for(int temp = abs(n); temp > 0; temp /= 10) {
        reversed = reversed * 10 + (temp % 10);
    }
    
    return (n < 0) ? -reversed : reversed;
}

// Method 3: Using string (alternative approach)
int reverseNumberString(int n) {
    bool isNegative = (n < 0);
    string str = to_string(abs(n));
    
    // Reverse the string
    reverse(str.begin(), str.end());
    
    int reversed = stoi(str);
    return isNegative ? -reversed : reversed;
}

// Function to extract individual digits
void extractDigits(int n) {
    cout << "Digits of " << n << " from right to left: ";
    int temp = abs(n);
    
    if(temp == 0) {
        cout << "0";
    } else {
        while(temp > 0) {
            cout << temp % 10 << " ";
            temp /= 10;
        }
    }
    cout << endl;
}

int main() {
    int number;
    
    cout << "=== REVERSE A NUMBER PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "\nOriginal number: " << number << endl;
    cout << "Reversed (while loop): " << reverseNumberWhile(number) << endl;
    cout << "Reversed (for loop): " << reverseNumberFor(number) << endl;
    cout << "Reversed (string method): " << reverseNumberString(number) << endl;
    
    // Extract digits demonstration
    cout << "\n=== DIGIT EXTRACTION ===" << endl;
    extractDigits(number);
    
    // Test with multiple numbers
    cout << "\n=== TESTING WITH DIFFERENT NUMBERS ===" << endl;
    int testNumbers[] = {123, 456, 1000, 7, -789, 0, 12021};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        cout << "Original: " << testNumbers[i] << " -> Reversed: " << reverseNumberWhile(testNumbers[i]) << endl;
    }
    
    // Note about integer overflow
    cout << "\n=== IMPORTANT NOTE ===" << endl;
    cout << "Be careful with large numbers as reversed number might cause integer overflow!" << endl;
    cout << "Example: Reversing 1463847412 might exceed int range." << endl;
    
    return 0;
}
