#include <iostream>
using namespace std;

class Queue{
  public:
    int *arr;
    int size;
    int rear;
    int front;

  Queue(int s = 100){
    this -> size = s;
    arr = new int[size];
    rear = 0;
    front = 0;
  }

  bool isEmpty(){
    return front == rear;
  }

  bool isFull(){
    if(front == 0 && rear == size-1) return true;
    else return false;
  }

  void getSize(){
    cout << "Size of Queue is : " << rear - front <<endl ;
  }

  void getFront(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl; 
      return;
    }
    cout << "First value is : " << arr[front] << endl;
  }

  void getRear(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl; 
      return;
    }
    cout << "Last value is : " << arr[rear-1] << endl;
  }

  void push(int val){
    if(isFull()) cout << "Queue is Full" << endl;
    
    arr[rear++] = val; 
  }

  void pop(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }else {
      int element = arr[front];
      arr[front++] = -1;
      cout << "Poped Element : " << element << endl;

      if(front == rear) rear = 0, front = 0;
    }
  }

  ~Queue(){
    delete [] arr;
  }
};

int main() {
  // creation of Queue
  Queue q(10);

  // Pushing Element to Queue
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  // pop Element from Queue
  q.pop();
  q.pop();

  // Size of Queue
  q.getSize();

  // front value of Queue
  q.getFront();

  // last value of Queue
  q.getRear();


  
  return 0;
}
