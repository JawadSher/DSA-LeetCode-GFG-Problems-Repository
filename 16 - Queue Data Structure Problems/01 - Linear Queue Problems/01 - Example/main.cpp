#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Creation of Queue
  queue<int> q;

  // Push Element to Queue
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  // Size of Queue
  cout<< "Size of Queue : " << q.size() << endl;

  // Remove Element from Queue
  q.pop();

  // Get the Front Element
  cout<< "Front Element : " << q.front() <<endl;

  // Size of Queue
  cout<< "After Pop - Size of Queue : " << q.size() << endl;

  // Check is Queue empty or not
  if(q.empty()) cout << "Queue is Empty" <<endl;
  else cout << "Queue is Not Empty" <<endl;

  return 0;
}
