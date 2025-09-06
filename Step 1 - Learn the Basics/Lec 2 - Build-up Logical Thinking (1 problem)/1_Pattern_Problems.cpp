#include<iostream>
using namespace std;

void pattern1(int n) {
    // Square pattern
    cout << "Pattern 1 - Square:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern2(int n) {
    // Right triangle
    cout << "Pattern 2 - Right Triangle:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3(int n) {
    // Number triangle
    cout << "Pattern 3 - Number Triangle:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4(int n) {
    // Inverted triangle
    cout << "Pattern 4 - Inverted Triangle:" << endl;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5(int n) {
    // Right-aligned triangle
    cout << "Pattern 5 - Right-aligned Triangle:" << endl;
    for(int i = 1; i <= n; i++) {
        // Print spaces
        for(int j = 1; j <= n - i; j++) {
            cout << "  ";
        }
        // Print stars
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern6(int n) {
    // Pyramid
    cout << "Pattern 6 - Pyramid:" << endl;
    for(int i = 1; i <= n; i++) {
        // Print spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for(int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern7(int n) {
    // Diamond
    cout << "Pattern 7 - Diamond:" << endl;
    // Upper half
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower half
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern8(int n) {
    // Hollow square
    cout << "Pattern 8 - Hollow Square:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void pattern9(int n) {
    // Number pyramid
    cout << "Pattern 9 - Number Pyramid:" << endl;
    for(int i = 1; i <= n; i++) {
        // Print spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print numbers ascending
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        // Print numbers descending
        for(int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern10(int n) {
    // Binary pattern
    cout << "Pattern 10 - Binary Pattern:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if((i + j) % 2 == 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size for patterns: ";
    cin >> n;
    cout << endl;
    
    // Display all patterns
    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
    pattern6(n);
    pattern7(n);
    pattern8(n);
    pattern9(n);
    pattern10(n);
    
    return 0;
}
