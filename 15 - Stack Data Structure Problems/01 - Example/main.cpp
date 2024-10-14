#include <iostream>
#include <stack>
using namespace std;

int main() {
  // creation of stack
  stack<int> s;

  // push Operation
  s.push(3);
  s.push(5);
  s.push(6);
  s.push(8);

  // pop operation
  s.pop();

  // printing top element
  cout<< "Top Element : "<< s.top() << endl;

  // Empty Operation
  if(s.empty()){
    cout<< "Stack is Empty" << endl;
  }else{cout << "Stack is Not Empty" <<endl; }

  // size operation
  cout<< "Size of stack is : " << s.size() << endl;
  return 0;
}
