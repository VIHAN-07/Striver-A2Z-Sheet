#include<iostream>
using namespace std;

int main() {
    // Arrays basics in C++
    
    // Declare and initialize array
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Print array elements
    cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Taking array input from user
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    int userArr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> userArr[i];
    }
    
    // Find sum of array elements
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += userArr[i];
    }
    
    cout << "Sum of array elements: " << sum << endl;
    
    return 0;
}
