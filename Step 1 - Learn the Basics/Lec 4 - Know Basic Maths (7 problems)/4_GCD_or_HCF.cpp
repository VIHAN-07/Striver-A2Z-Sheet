#include<iostream>
#include<algorithm>
using namespace std;

// Method 1: Euclidean Algorithm for GCD
int gcdEuclidean(int a, int b) {
    a = abs(a);  // Handle negative numbers
    b = abs(b);
    
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Method 2: Recursive GCD
int gcdRecursive(int a, int b) {
    if(b == 0) return abs(a);
    return gcdRecursive(b, a % b);
}

// Method 3: Using built-in function (C++14 and later)
int gcdBuiltIn(int a, int b) {
    // Using standard library gcd function (C++17) or __gcd (GCC specific)
    // For compatibility, we'll use our Euclidean method
    return gcdEuclidean(abs(a), abs(b));
}

// LCM using GCD formula: LCM(a,b) = (a * b) / GCD(a,b)
long long lcmUsingGcd(int a, int b) {
    return (abs((long long)a * b)) / gcdEuclidean(a, b);
}

// Method 4: Brute force GCD (less efficient)
int gcdBruteForce(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    int gcd = 1;
    int minVal = min(a, b);
    
    for(int i = 1; i <= minVal; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    
    return gcd;
}

// Function to find GCD of multiple numbers
int gcdMultiple(int arr[], int n) {
    int result = arr[0];
    for(int i = 1; i < n; i++) {
        result = gcdEuclidean(result, arr[i]);
        if(result == 1) break;  // Early termination
    }
    return result;
}

// Function to find LCM of multiple numbers
long long lcmMultiple(int arr[], int n) {
    long long result = arr[0];
    for(int i = 1; i < n; i++) {
        result = lcmUsingGcd(result, arr[i]);
    }
    return result;
}

// Function to check if two numbers are coprime
bool areCoprime(int a, int b) {
    return gcdEuclidean(a, b) == 1;
}

int main() {
    int a, b;
    
    cout << "=== GCD AND LCM PROBLEM ===" << endl;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "\nNumbers: " << a << " and " << b << endl;
    
    // Calculate GCD using different methods
    cout << "\n=== GCD CALCULATIONS ===" << endl;
    cout << "GCD (Euclidean Algorithm): " << gcdEuclidean(a, b) << endl;
    cout << "GCD (Recursive): " << gcdRecursive(a, b) << endl;
    cout << "GCD (Built-in): " << gcdBuiltIn(a, b) << endl;
    cout << "GCD (Brute Force): " << gcdBruteForce(a, b) << endl;
    
    // Calculate LCM
    cout << "\n=== LCM CALCULATION ===" << endl;
    cout << "LCM: " << lcmUsingGcd(a, b) << endl;
    
    // Check if coprime
    cout << "\n=== COPRIME CHECK ===" << endl;
    cout << "Are " << a << " and " << b << " coprime? " << (areCoprime(a, b) ? "Yes" : "No") << endl;
    
    // Multiple numbers example
    cout << "\n=== MULTIPLE NUMBERS EXAMPLE ===" << endl;
    int numbers[] = {12, 18, 24, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Numbers: ";
    for(int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "GCD of all numbers: " << gcdMultiple(numbers, size) << endl;
    cout << "LCM of all numbers: " << lcmMultiple(numbers, size) << endl;
    
    // Test cases
    cout << "\n=== TEST CASES ===" << endl;
    int testCases[][2] = {{48, 18}, {17, 13}, {100, 25}, {7, 14}, {0, 5}};
    int testSize = sizeof(testCases) / sizeof(testCases[0]);
    
    for(int i = 0; i < testSize; i++) {
        int x = testCases[i][0];
        int y = testCases[i][1];
        cout << "GCD(" << x << ", " << y << ") = " << gcdEuclidean(x, y);
        cout << ", LCM(" << x << ", " << y << ") = " << lcmUsingGcd(x, y) << endl;
    }
    
    cout << "\n=== KEY FORMULAS ===" << endl;
    cout << "1. GCD(a, b) * LCM(a, b) = a * b" << endl;
    cout << "2. LCM(a, b) = (a * b) / GCD(a, b)" << endl;
    cout << "3. GCD(a, 0) = a" << endl;
    cout << "4. Two numbers are coprime if GCD = 1" << endl;
    
    return 0;
}
