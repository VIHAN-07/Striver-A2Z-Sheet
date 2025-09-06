#include<iostream>
#include<cmath>
using namespace std;

// Function to check if a number is Armstrong number
bool isArmstrong(int n) {
    if(n < 0) return false;  // Negative numbers are not Armstrong numbers
    
    int original = n;
    int digits = 0;
    int temp = n;
    
    // Count number of digits
    while(temp > 0) {
        digits++;
        temp /= 10;
    }
    
    int sum = 0;
    temp = n;
    
    // Calculate sum of digits raised to power of number of digits
    while(temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    
    return sum == original;
}

// Alternative method using string for digit counting
bool isArmstrongString(int n) {
    if(n < 0) return false;
    
    string str = to_string(n);
    int digits = str.length();
    int sum = 0;
    
    for(char c : str) {
        int digit = c - '0';  // Convert char to int
        sum += pow(digit, digits);
    }
    
    return sum == n;
}

// Function to find all Armstrong numbers in a range
void findArmstrongInRange(int start, int end) {
    cout << "Armstrong numbers between " << start << " and " << end << ": ";
    bool found = false;
    
    for(int i = start; i <= end; i++) {
        if(isArmstrong(i)) {
            cout << i << " ";
            found = true;
        }
    }
    
    if(!found) {
        cout << "None found";
    }
    cout << endl;
}

// Function to calculate power without using pow()
long long power(int base, int exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Armstrong check without using pow() function
bool isArmstrongNoPow(int n) {
    if(n < 0) return false;
    
    int original = n;
    int digits = 0;
    int temp = n;
    
    // Count digits
    while(temp > 0) {
        digits++;
        temp /= 10;
    }
    
    long long sum = 0;
    temp = n;
    
    // Calculate sum using custom power function
    while(temp > 0) {
        int digit = temp % 10;
        sum += power(digit, digits);
        temp /= 10;
    }
    
    return sum == original;
}

// Function to generate next Armstrong number
int nextArmstrong(int n) {
    n++;
    while(!isArmstrong(n)) {
        n++;
    }
    return n;
}

int main() {
    int number;
    
    cout << "=== ARMSTRONG NUMBERS PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "\nNumber: " << number << endl;
    cout << "Is Armstrong (with pow): " << (isArmstrong(number) ? "Yes" : "No") << endl;
    cout << "Is Armstrong (string method): " << (isArmstrongString(number) ? "Yes" : "No") << endl;
    cout << "Is Armstrong (without pow): " << (isArmstrongNoPow(number) ? "Yes" : "No") << endl;
    
    // Explain the calculation
    if(number >= 0) {
        cout << "\n=== CALCULATION BREAKDOWN ===" << endl;
        string str = to_string(number);
        int digits = str.length();
        cout << "Number of digits: " << digits << endl;
        cout << "Calculation: ";
        
        int sum = 0;
        for(int i = 0; i < str.length(); i++) {
            int digit = str[i] - '0';
            int digitPower = pow(digit, digits);
            sum += digitPower;
            cout << digit << "^" << digits;
            if(i < str.length() - 1) cout << " + ";
        }
        cout << " = " << sum << endl;
        cout << "Original number: " << number << endl;
        cout << "Equal? " << (sum == number ? "Yes (Armstrong)" : "No (Not Armstrong)") << endl;
    }
    
    // Examples of Armstrong numbers
    cout << "\n=== EXAMPLES OF ARMSTRONG NUMBERS ===" << endl;
    cout << "1-digit: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 (all single digits)" << endl;
    cout << "3-digit: 153 (1³ + 5³ + 3³ = 1 + 125 + 27 = 153)" << endl;
    cout << "3-digit: 371 (3³ + 7³ + 1³ = 27 + 343 + 1 = 371)" << endl;
    cout << "4-digit: 1634 (1⁴ + 6⁴ + 3⁴ + 4⁴ = 1 + 1296 + 81 + 256 = 1634)" << endl;
    
    // Find Armstrong numbers in different ranges
    cout << "\n=== ARMSTRONG NUMBERS IN RANGES ===" << endl;
    findArmstrongInRange(1, 10);
    findArmstrongInRange(100, 999);
    findArmstrongInRange(1000, 9999);
    
    // Test specific numbers
    cout << "\n=== TESTING SPECIFIC NUMBERS ===" << endl;
    int testNumbers[] = {0, 1, 9, 153, 370, 371, 407, 1634, 8208, 9474};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        bool result = isArmstrong(testNumbers[i]);
        cout << testNumbers[i] << " -> " << (result ? "Armstrong" : "Not Armstrong") << endl;
    }
    
    // Find next Armstrong number
    if(number >= 0) {
        cout << "\nNext Armstrong number after " << number << ": " << nextArmstrong(number) << endl;
    }
    
    cout << "\n=== NOTE ===" << endl;
    cout << "Armstrong numbers are also called Narcissistic numbers or Pluperfect digital invariants." << endl;
    
    return 0;
}
