#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Method 1: Simple trial division
bool isPrimeSimple(int n) {
    if(n <= 1) return false;  // Numbers <= 1 are not prime
    if(n <= 3) return true;   // 2 and 3 are prime
    if(n % 2 == 0 || n % 3 == 0) return false;  // Divisible by 2 or 3
    
    // Check for divisors from 5 onwards
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

// Method 2: Basic approach - check all numbers up to sqrt(n)
bool isPrimeBasic(int n) {
    if(n < 2) return false;
    
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

// Method 3: Optimized - check only odd numbers after 2
bool isPrimeOptimized(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;  // Even numbers > 2 are not prime
    
    for(int i = 3; i * i <= n; i += 2) {  // Check only odd numbers
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

// Sieve of Eratosthenes - find all primes up to n
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}

// Function to print all primes up to n
void printPrimesUpTo(int n) {
    cout << "Prime numbers up to " << n << ": ";
    vector<bool> isPrime = sieveOfEratosthenes(n);
    
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Function to count primes up to n
int countPrimesUpTo(int n) {
    if(n < 2) return 0;
    
    vector<bool> isPrime = sieveOfEratosthenes(n);
    int count = 0;
    
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            count++;
        }
    }
    
    return count;
}

// Function to find next prime number
int nextPrime(int n) {
    if(n < 2) return 2;
    
    n++;
    while(!isPrimeOptimized(n)) {
        n++;
    }
    
    return n;
}

// Function to find previous prime number
int previousPrime(int n) {
    if(n <= 2) return -1;  // No prime before 2
    
    n--;
    while(n >= 2 && !isPrimeOptimized(n)) {
        n--;
    }
    
    return n >= 2 ? n : -1;
}

// Function to check if a number is a twin prime
bool isTwinPrime(int n) {
    if(!isPrimeOptimized(n)) return false;
    
    return isPrimeOptimized(n + 2) || isPrimeOptimized(n - 2);
}

// Function to find prime factorization
void primeFactorization(int n) {
    cout << "Prime factorization of " << n << ": ";
    
    // Handle factor 2
    while(n % 2 == 0) {
        cout << "2 ";
        n /= 2;
    }
    
    // Handle odd factors
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    
    // If n is still > 2, then it's a prime
    if(n > 2) {
        cout << n << " ";
    }
    
    cout << endl;
}

int main() {
    int number;
    
    cout << "=== CHECK FOR PRIME PROBLEM ===" << endl;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "\nNumber: " << number << endl;
    
    // Different methods to check prime
    cout << "\n=== PRIME CHECK RESULTS ===" << endl;
    cout << "Is prime (simple method): " << (isPrimeSimple(number) ? "Yes" : "No") << endl;
    cout << "Is prime (basic method): " << (isPrimeBasic(number) ? "Yes" : "No") << endl;
    cout << "Is prime (optimized method): " << (isPrimeOptimized(number) ? "Yes" : "No") << endl;
    
    // Additional information
    if(number > 0) {
        cout << "\n=== ADDITIONAL INFORMATION ===" << endl;
        
        if(!isPrimeOptimized(number)) {
            primeFactorization(number);
        }
        
        cout << "Next prime after " << number << ": " << nextPrime(number) << endl;
        
        int prev = previousPrime(number);
        if(prev != -1) {
            cout << "Previous prime before " << number << ": " << prev << endl;
        }
        
        cout << "Is twin prime: " << (isTwinPrime(number) ? "Yes" : "No") << endl;
    }
    
    // Test with multiple numbers
    cout << "\n=== TESTING WITH DIFFERENT NUMBERS ===" << endl;
    int testNumbers[] = {1, 2, 3, 4, 17, 25, 29, 97, 100, 101};
    int size = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for(int i = 0; i < size; i++) {
        bool result = isPrimeOptimized(testNumbers[i]);
        cout << testNumbers[i] << " -> " << (result ? "Prime" : "Not Prime") << endl;
    }
    
    // Sieve demonstration
    cout << "\n=== PRIME NUMBERS UP TO 50 ===" << endl;
    printPrimesUpTo(50);
    cout << "Count of primes up to 50: " << countPrimesUpTo(50) << endl;
    
    // Twin primes up to 100
    cout << "\n=== TWIN PRIMES UP TO 100 ===" << endl;
    cout << "Twin prime pairs: ";
    for(int i = 2; i <= 98; i++) {
        if(isPrimeOptimized(i) && isPrimeOptimized(i + 2)) {
            cout << "(" << i << ", " << i + 2 << ") ";
        }
    }
    cout << endl;
    
    // Important prime facts
    cout << "\n=== PRIME NUMBER FACTS ===" << endl;
    cout << "1. The only even prime number is 2" << endl;
    cout << "2. All primes > 3 can be written as 6k ± 1" << endl;
    cout << "3. Twin primes are pairs of primes that differ by 2" << endl;
    cout << "4. Goldbach's conjecture: Every even number > 2 is sum of two primes" << endl;
    
    // Time complexity information
    cout << "\n=== TIME COMPLEXITY ===" << endl;
    cout << "Basic check: O(√n)" << endl;
    cout << "Sieve of Eratosthenes: O(n log log n)" << endl;
    
    return 0;
}
