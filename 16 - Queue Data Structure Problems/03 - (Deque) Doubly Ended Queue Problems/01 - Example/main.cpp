#include <iostream>
#include <deque>
using namespace std;

int main() {
  // deque creation
  deque<int> dq;

  // push back
  dq.push_back(10);
  dq.push_back(20);
  dq.push_back(30);
  dq.push_back(40);

  cout << "Size of Deque is : " << dq.size() << endl;

  cout << "Front Value : " << dq.front() <<endl;
  cout << "Last Value : " << dq.back() <<endl;

  // push front
  dq.push_front(5);
  dq.push_front(9);

  cout << "After push front - Front Value : " << dq.front() <<endl;
  cout << "After push front - Last Value : " << dq.back() <<endl;

  // pop back
  dq.pop_back();

  cout << "After pop back - Front Value : " << dq.front() <<endl;
  cout << "After pop back - Last Value : " << dq.back() <<endl;

  // pop front
  dq.pop_front();
  cout << "After pop front - Front Value : " << dq.front() <<endl;
  cout << "After pop front - Last Value : " << dq.back() <<endl;

  // Check Empty
  if(dq.empty()) cout << "Deque is Empty" <<endl;
  else cout << "Deque is Not Empty" <<endl;

  // Check Size
  cout << "Size of Deque is : " << dq.size() << endl;
  return 0;
}
