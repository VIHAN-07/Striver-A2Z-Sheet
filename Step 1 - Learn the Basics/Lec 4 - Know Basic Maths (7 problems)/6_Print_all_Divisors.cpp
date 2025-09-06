#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Method 1: Brute force - check all numbers from 1 to n
void printDivisorsBruteForce(int n) {
    cout << "Divisors of " << n << " (Brute Force): ";
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Method 2: Optimized - check only up to sqrt(n)
void printDivisorsOptimized(int n) {
    cout << "Divisors of " << n << " (Optimized): ";
    vector<int> divisors;
    
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divisors.push_back(i);  // Add the divisor
            if(i != n/i) {  // Avoid duplicate for perfect squares
                divisors.push_back(n/i);  // Add the corresponding divisor
            }
        }
    }
    
    // Sort the divisors
    sort(divisors.begin(), divisors.end());
    
    for(int div : divisors) {
        cout << div << " ";
    }
    cout << endl;
}

// Method 3: Return divisors as vector
vector<int> getDivisors(int n) {
    vector<int> divisors;
    
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n/i) {
                divisors.push_back(n/i);
            }
        }
    }
    
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Function to count number of divisors
int countDivisors(int n) {
    int count = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i * i == n) {
                count++;  // Perfect square case
            } else {
                count += 2;  // Both i and n/i are divisors
            }
        }
    }
    return count;
}

// Function to find sum of divisors
long long sumOfDivisors(int n) {
    long long sum = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;  // Add the divisor
            if(i != n/i) {
                sum += n/i;  // Add the corresponding divisor
            }
        }
    }
    return sum;
}

// Function to find proper divisors (excluding the number itself)
void printProperDivisors(int n) {
    cout << "Proper divisors of " << n << ": ";
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Function to check if a number is perfect (sum of proper divisors equals the number)
bool isPerfectNumber(int n) {
    if(n <= 1) return false;
    
    long long sum = 1;  // 1 is always a proper divisor
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n/i && i != 1) {  // Avoid adding sqrt(n) twice and don't add n itself
                sum += n/i;
            }
        }
    }
    
    return sum == n;
}

// Function to find common divisors of two numbers
void printCommonDivisors(int a, int b) {
    cout << "Common divisors of " << a << " and " << b << ": ";
    int maxNum = max(a, b);
    
    for(int i = 1; i <= maxNum; i++) {
        if(a % i == 0 && b % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int number;
    
    cout << "=== PRINT ALL DIVISORS PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    if(number <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }
    
    cout << "\nNumber: " << number << endl;
    
    // Different methods to print divisors
    printDivisorsBruteForce(number);
    printDivisorsOptimized(number);
    
    // Additional information
    cout << "\n=== DIVISOR ANALYSIS ===" << endl;
    cout << "Total number of divisors: " << countDivisors(number) << endl;
    cout << "Sum of all divisors: " << sumOfDivisors(number) << endl;
    printProperDivisors(number);
    cout << "Is perfect number: " << (isPerfectNumber(number) ? "Yes" : "No") << endl;
    
    // Vector of divisors
    vector<int> divisors = getDivisors(number);
    cout << "\nDivisors stored in vector: ";
    for(int div : divisors) {
        cout << div << " ";
    }
    cout << endl;
    
    // Test with multiple numbers
    cout << "\n=== TESTING WITH DIFFERENT NUMBERS ===" << endl;
    int testNumbers[] = {1, 6, 12, 28, 36, 100};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        int n = testNumbers[i];
        cout << n << " -> Divisors: " << countDivisors(n) << ", Sum: " << sumOfDivisors(n);
        cout << (isPerfectNumber(n) ? " (Perfect)" : "") << endl;
    }
    
    // Common divisors example
    cout << "\n=== COMMON DIVISORS EXAMPLE ===" << endl;
    printCommonDivisors(12, 18);
    printCommonDivisors(24, 36);
    
    // Perfect numbers information
    cout << "\n=== PERFECT NUMBERS INFO ===" << endl;
    cout << "Perfect numbers: 6, 28, 496, 8128, ..." << endl;
    cout << "6 = 1 + 2 + 3 (sum of proper divisors)" << endl;
    cout << "28 = 1 + 2 + 4 + 7 + 14 (sum of proper divisors)" << endl;
    
    // Time complexity note
    cout << "\n=== TIME COMPLEXITY ===" << endl;
    cout << "Brute Force: O(n)" << endl;
    cout << "Optimized: O(√n)" << endl;
    
    return 0;
}
