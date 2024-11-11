#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  // Creating Max and Min Heap using STL.

  // ------ Creation of Max Heap ------
  cout << "------ Creation of Max Heap ------" << endl;
  priority_queue<int> max_pq;  // Max-Heap by default

  // Adding elements to the Max-Heap
  max_pq.push(4);
  max_pq.push(2);
  max_pq.push(5);
  max_pq.push(3);

  // Displaying the top element of the Max-Heap
  cout << "Element at Top : " << max_pq.top() << endl;  // Should display the maximum element
  max_pq.pop();  // Removes the top (maximum) element
  cout << "Element at Top : " << max_pq.top() << endl;  // Displays the new top element after pop

  // Displaying the size of the Max-Heap
  cout << "Size of priority queue : " << max_pq.size() << endl;

  // Checking if the Max-Heap is empty
  if (max_pq.empty())
    cout << "Priority queue is empty" << endl;
  else
    cout << "Priority queue is not empty" << endl;

  // ------ Creation of Min Heap ------
  cout << endl << "------ Creation of Min Heap ------" << endl;
  priority_queue<int, vector<int>, greater<int>> min_pq;  // Min-Heap

  // Adding elements to the Min-Heap
  min_pq.push(4);
  min_pq.push(2);
  min_pq.push(5);
  min_pq.push(3);

  // Displaying the top element of the Min-Heap
  cout << "Element at Top : " << min_pq.top() << endl;  // Should display the minimum element
  min_pq.pop();  // Removes the top (minimum) element
  cout << "Element at Top : " << min_pq.top() << endl;  // Displays the new top element after pop

  // Displaying the size of the Min-Heap
  cout << "Size of priority queue : " << min_pq.size() << endl;

  // Checking if the Min-Heap is empty
  if (min_pq.empty())
    cout << "Priority queue is empty" << endl;
  else
    cout << "Priority queue is not empty" << endl;

  return 0;
}
