#include<iostream>
#include<vector>
using namespace std;

// O(1) - Constant Time Complexity
int getFirstElement(vector<int>& arr) {
    return arr[0];  // Always takes same time regardless of array size
}

// O(n) - Linear Time Complexity
int linearSearch(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {  // Time increases linearly with array size
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// O(n^2) - Quadratic Time Complexity
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {          // Nested loops = O(n^2)
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// O(log n) - Logarithmic Time Complexity
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Divide search space by half each time
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    /*
    Time Complexity Analysis:
    
    O(1) - Constant: Operations that take same time regardless of input size
    O(log n) - Logarithmic: Divide and conquer algorithms
    O(n) - Linear: Single loop through data
    O(n log n) - Linearithmic: Efficient sorting algorithms
    O(n^2) - Quadratic: Nested loops
    O(2^n) - Exponential: Recursive algorithms with multiple branches
    
    Space Complexity:
    - Amount of extra memory used by algorithm
    - O(1) - Constant extra space
    - O(n) - Linear extra space (arrays, recursion stack)
    */
    
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    // O(1) example
    cout << "First element (O(1)): " << getFirstElement(arr) << endl;
    
    // O(n) example
    cout << "Linear search for 7 (O(n)): " << linearSearch(arr, 7) << endl;
    
    // O(log n) example
    cout << "Binary search for 7 (O(log n)): " << binarySearch(arr, 7) << endl;
    
    // O(n^2) example
    vector<int> unsorted = {64, 34, 25, 12, 22, 11, 90};
    cout << "Before bubble sort: ";
    for(int x : unsorted) cout << x << " ";
    cout << endl;
    
    bubbleSort(unsorted);
    cout << "After bubble sort (O(n^2)): ";
    for(int x : unsorted) cout << x << " ";
    cout << endl;
    
    return 0;
}
