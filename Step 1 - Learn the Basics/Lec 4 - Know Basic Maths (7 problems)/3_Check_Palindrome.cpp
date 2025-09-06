#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

// Method 1: Using number reversal
bool isPalindromeReverse(int n) {
    if(n < 0) return false;  // Negative numbers are not palindromes
    
    int original = n;
    int reversed = 0;
    
    while(n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    
    return original == reversed;
}

// Method 2: Using string conversion
bool isPalindromeString(int n) {
    if(n < 0) return false;
    
    string str = to_string(n);
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    
    return str == reversed;
}

// Method 3: Two pointer approach with string
bool isPalindromeTwoPointer(int n) {
    if(n < 0) return false;
    
    string str = to_string(n);
    int left = 0;
    int right = str.length() - 1;
    
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

// Method 4: Mathematical approach without full reversal
bool isPalindromeMath(int n) {
    if(n < 0) return false;
    if(n < 10) return true;  // Single digit numbers are palindromes
    
    // Find number of digits
    int digits = 0;
    int temp = n;
    while(temp > 0) {
        digits++;
        temp /= 10;
    }
    
    // Check digits from both ends
    for(int i = 0; i < digits / 2; i++) {
        // Get leftmost digit
        int leftDigit = n / pow(10, digits - 1 - i);
        leftDigit = leftDigit % 10;
        
        // Get rightmost digit
        int rightDigit = n % 10;
        n /= 10;
        
        if(leftDigit != rightDigit) {
            return false;
        }
    }
    
    return true;
}

// Function to check if a string is palindrome
bool isStringPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int main() {
    int number;
    
    cout << "=== CHECK PALINDROME PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "\nNumber: " << number << endl;
    cout << "Is palindrome (reverse method): " << (isPalindromeReverse(number) ? "Yes" : "No") << endl;
    cout << "Is palindrome (string method): " << (isPalindromeString(number) ? "Yes" : "No") << endl;
    cout << "Is palindrome (two pointer): " << (isPalindromeTwoPointer(number) ? "Yes" : "No") << endl;
    
    // Test with multiple numbers
    cout << "\n=== TESTING WITH DIFFERENT NUMBERS ===" << endl;
    int testNumbers[] = {121, 123, 1221, 12321, 0, 7, 1001, -121, 10};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        bool result = isPalindromeReverse(testNumbers[i]);
        cout << testNumbers[i] << " -> " << (result ? "Palindrome" : "Not Palindrome") << endl;
    }
    
    // String palindrome example
    cout << "\n=== STRING PALINDROME EXAMPLES ===" << endl;
    string testStrings[] = {"radar", "hello", "level", "madam", "programming"};
    int strSize = sizeof(testStrings) / sizeof(testStrings[0]);
    
    for(int i = 0; i < strSize; i++) {
        bool result = isStringPalindrome(testStrings[i]);
        cout << "\"" << testStrings[i] << "\" -> " << (result ? "Palindrome" : "Not Palindrome") << endl;
    }
    
    cout << "\n=== KEY POINTS ===" << endl;
    cout << "1. Negative numbers are typically not considered palindromes" << endl;
    cout << "2. Single digit numbers (0-9) are palindromes" << endl;
    cout << "3. Leading zeros are ignored (e.g., 100 reversed is 1, not 001)" << endl;
    
    return 0;
}
