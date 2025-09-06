#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;

int main() {
    cout << "=== C++ STL ALGORITHMS & ADVANCED CONTAINERS ===" << endl << endl;
    
    // 1. SET - Unique elements in sorted order
    cout << "1. SET (Unique sorted elements):" << endl;
    set<int> uniqueNumbers = {5, 2, 8, 2, 1, 9, 5, 3};  // Duplicates will be removed
    
    cout << "Set elements: ";
    for(int x : uniqueNumbers) {
        cout << x << " ";  // Automatically sorted: 1 2 3 5 8 9
    }
    cout << endl;
    
    // Set operations
    uniqueNumbers.insert(7);
    uniqueNumbers.erase(2);
    
    cout << "After insert(7) and erase(2): ";
    for(int x : uniqueNumbers) {
        cout << x << " ";
    }
    cout << endl;
    
    // Find in set
    if(uniqueNumbers.find(8) != uniqueNumbers.end()) {
        cout << "8 is present in set" << endl;
    }
    cout << "Set size: " << uniqueNumbers.size() << endl;
    cout << endl;
    
    // 2. MAP - Key-Value pairs
    cout << "2. MAP (Key-Value pairs):" << endl;
    map<string, int> studentGrades;
    
    // Insert elements
    studentGrades["Alice"] = 95;
    studentGrades["Bob"] = 87;
    studentGrades["Charlie"] = 92;
    studentGrades.insert({"David", 89});
    
    cout << "Student grades:" << endl;
    for(auto pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Access and modify
    cout << "Alice's grade: " << studentGrades["Alice"] << endl;
    studentGrades["Alice"] = 98;  // Update grade
    cout << "Alice's updated grade: " << studentGrades["Alice"] << endl;
    
    // Check if key exists
    if(studentGrades.find("Bob") != studentGrades.end()) {
        cout << "Bob's record found" << endl;
    }
    cout << endl;
    
    // 3. STACK - Last In First Out (LIFO)
    cout << "3. STACK (LIFO):" << endl;
    stack<int> stk;
    
    // Push elements
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    cout << "Stack operations:" << endl;
    cout << "Top element: " << stk.top() << endl;
    cout << "Stack size: " << stk.size() << endl;
    
    cout << "Popping elements: ";
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl << endl;
    
    // 4. QUEUE - First In First Out (FIFO)
    cout << "4. QUEUE (FIFO):" << endl;
    queue<string> q;
    
    // Push elements
    q.push("First");
    q.push("Second");
    q.push("Third");
    
    cout << "Queue operations:" << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;
    
    cout << "Processing queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;
    
    // 5. PRIORITY QUEUE - Max heap by default
    cout << "5. PRIORITY QUEUE (Max Heap):" << endl;
    priority_queue<int> pq;
    
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    
    cout << "Priority queue (max to min): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(30);
    minPq.push(10);
    minPq.push(50);
    minPq.push(20);
    
    cout << "Min priority queue (min to max): ";
    while(!minPq.empty()) {
        cout << minPq.top() << " ";
        minPq.pop();
    }
    cout << endl << endl;
    
    // 6. STL ALGORITHMS
    cout << "6. STL ALGORITHMS:" << endl;
    vector<int> data = {1, 5, 3, 9, 2, 8, 4, 7, 6};
    
    cout << "Original: ";
    for(int x : data) cout << x << " ";
    cout << endl;
    
    // Sort
    sort(data.begin(), data.end());
    cout << "Sorted: ";
    for(int x : data) cout << x << " ";
    cout << endl;
    
    // Lower bound and upper bound
    int val = 5;
    auto lb = lower_bound(data.begin(), data.end(), val);
    auto ub = upper_bound(data.begin(), data.end(), val);
    
    cout << "Lower bound of " << val << " at index: " << distance(data.begin(), lb) << endl;
    cout << "Upper bound of " << val << " at index: " << distance(data.begin(), ub) << endl;
    
    // Count
    vector<int> nums = {1, 2, 2, 3, 2, 4, 2};
    int countOf2 = count(nums.begin(), nums.end(), 2);
    cout << "Count of 2 in [1,2,2,3,2,4,2]: " << countOf2 << endl;
    
    // Sum
    int sum = 0;
    for(int x : nums) sum += x;
    cout << "Sum of elements: " << sum << endl;
    
    return 0;
}
