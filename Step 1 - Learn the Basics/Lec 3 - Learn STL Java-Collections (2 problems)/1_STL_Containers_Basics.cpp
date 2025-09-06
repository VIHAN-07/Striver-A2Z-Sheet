#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    cout << "=== C++ STL CONTAINERS ===" << endl << endl;
    
    // 1. VECTOR - Dynamic Array
    cout << "1. VECTOR (Dynamic Array):" << endl;
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Basic operations
    vec.push_back(60);  // Add element at end
    vec.pop_back();     // Remove last element
    
    cout << "Vector elements: ";
    for(int x : vec) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;
    cout << "Element at index 2: " << vec[2] << endl;
    cout << endl;
    
    // 2. STRING - Character sequence
    cout << "2. STRING:" << endl;
    string str = "Hello World";
    
    cout << "Original string: " << str << endl;
    cout << "Length: " << str.length() << endl;
    cout << "Character at index 6: " << str[6] << endl;
    
    // String operations
    str += " C++";  // Concatenation
    cout << "After concatenation: " << str << endl;
    
    // Substring
    string sub = str.substr(6, 5);  // From index 6, length 5
    cout << "Substring: " << sub << endl;
    
    // Find
    size_t pos = str.find("World");
    if(pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }
    cout << endl;
    
    // 3. PAIR - Store two values together
    cout << "3. PAIR:" << endl;
    pair<int, string> student = {101, "Alice"};
    pair<int, int> coordinates = make_pair(10, 20);
    
    cout << "Student ID: " << student.first << ", Name: " << student.second << endl;
    cout << "Coordinates: (" << coordinates.first << ", " << coordinates.second << ")" << endl;
    cout << endl;
    
    // 4. ARRAY OPERATIONS
    cout << "4. ARRAY WITH STL:" << endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Sort array
    sort(arr, arr + n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Binary search (array must be sorted)
    int target = 25;
    bool found = binary_search(arr, arr + n, target);
    cout << "Binary search for " << target << ": " << (found ? "Found" : "Not Found") << endl;
    cout << endl;
    
    // 5. VECTOR OPERATIONS
    cout << "5. ADVANCED VECTOR OPERATIONS:" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    cout << "Original vector: ";
    for(int x : numbers) cout << x << " ";
    cout << endl;
    
    // Sort vector
    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector: ";
    for(int x : numbers) cout << x << " ";
    cout << endl;
    
    // Reverse vector
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed vector: ";
    for(int x : numbers) cout << x << " ";
    cout << endl;
    
    // Find maximum and minimum
    auto maxIt = max_element(numbers.begin(), numbers.end());
    auto minIt = min_element(numbers.begin(), numbers.end());
    cout << "Maximum: " << *maxIt << endl;
    cout << "Minimum: " << *minIt << endl;
    
    // Find element
    auto it = find(numbers.begin(), numbers.end(), 5);
    if(it != numbers.end()) {
        cout << "Found 5 at position: " << distance(numbers.begin(), it) << endl;
    }
    cout << endl;
    
    // 6. ITERATORS
    cout << "6. ITERATORS:" << endl;
    vector<string> fruits = {"apple", "banana", "cherry", "date"};
    
    cout << "Using iterator: ";
    for(vector<string>::iterator it = fruits.begin(); it != fruits.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Using auto keyword: ";
    for(auto it = fruits.begin(); it != fruits.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Using range-based loop: ";
    for(const string& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;
    
    return 0;
}
