#include<iostream>
using namespace std;

int main() {
    // While loops in C++
    
    // Basic while loop
    int i = 1;
    cout << "Numbers 1 to 5 using while loop: ";
    while(i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
    
    // Do-while loop
    int j = 1;
    cout << "Numbers 1 to 5 using do-while loop: ";
    do {
        cout << j << " ";
        j++;
    } while(j <= 5);
    cout << endl;
    
    // While loop for input validation
    int num;
    cout << "Enter a positive number: ";
    cin >> num;
    
    while(num <= 0) {
        cout << "Invalid! Enter a positive number: ";
        cin >> num;
    }
    
    cout << "You entered: " << num << endl;
    
    // Count digits using while loop
    int temp = num;
    int count = 0;
    while(temp > 0) {
        count++;
        temp /= 10;
    }
    
    cout << "Number of digits in " << num << ": " << count << endl;
    
    return 0;
}
