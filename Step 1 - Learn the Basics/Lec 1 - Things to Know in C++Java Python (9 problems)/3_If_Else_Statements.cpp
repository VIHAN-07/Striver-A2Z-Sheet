#include<iostream>
using namespace std;

int main() {
    // If-else statements in C++
    
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    // Simple if-else
    if(age >= 18) {
        cout << "You are an adult." << endl;
    } else {
        cout << "You are a minor." << endl;
    }
    
    // Nested if-else
    if(age < 13) {
        cout << "Category: Child" << endl;
    } else if(age < 20) {
        cout << "Category: Teenager" << endl;
    } else if(age < 60) {
        cout << "Category: Adult" << endl;
    } else {
        cout << "Category: Senior" << endl;
    }
    
    return 0;
}
