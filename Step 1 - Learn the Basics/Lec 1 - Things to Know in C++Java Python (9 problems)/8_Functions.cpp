#include<iostream>
using namespace std;

// Function declarations
int add(int a, int b);
int multiply(int a, int b);
bool isPrime(int n);
void printPattern(int n);

int main() {
    // Functions in C++
    
    int x = 10, y = 5;
    
    // Function calls
    cout << "Sum of " << x << " and " << y << ": " << add(x, y) << endl;
    cout << "Product of " << x << " and " << y << ": " << multiply(x, y) << endl;
    
    int num;
    cout << "Enter a number to check if prime: ";
    cin >> num;
    
    if(isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    
    cout << "Pattern for n=5:" << endl;
    printPattern(5);
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

bool isPrime(int n) {
    // Numbers less than 2 are not prime
    if(n < 2) return false;
    
    // Check if any number from 2 to sqrt(n) divides n
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    return true;  // No divisors found, it's prime
}

void printPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
