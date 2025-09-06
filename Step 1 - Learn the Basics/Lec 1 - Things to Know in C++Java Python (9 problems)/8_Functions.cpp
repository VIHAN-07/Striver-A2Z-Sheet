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
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void printPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
