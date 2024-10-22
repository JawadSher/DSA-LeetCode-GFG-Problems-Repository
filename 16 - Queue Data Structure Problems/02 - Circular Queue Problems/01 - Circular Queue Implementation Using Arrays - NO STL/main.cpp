#include <iostream>
using namespace std;

class circularQueue {
  public:
    int *arr;
    int size;
    int rear;
    int front;

  circularQueue(int s = 100) {
    this->size = s;
    arr = new int[size];
    rear = -1;
    front = -1;
  }

  bool isEmpty() {
    return front == -1;
  }

  bool isFull() {
    return (front == 0 && rear == size - 1) || (rear == (front - 1) % size);
  }

  void getSize() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    if (rear >= front)
      cout << "Size of Queue is : " << rear - front + 1 << endl;
    else
      cout << "Size of Queue is : " << (size - front) + (rear + 1) << endl;
  }

  void getFront() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "First value is : " << arr[front] << endl;
  }

  void getRear() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "Last value is : " << arr[rear] << endl;
  }

  void push(int val) {
    if (isFull()) {
      cout << "Queue is Full" << endl;
      return;
    }
    if (front == -1) { // First element to be inserted
      front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
      rear = 0; // Wrap around
    } else {
      rear++;
    }
    arr[rear] = val;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }

    int element = arr[front];
    arr[front] = -1;
    cout << "Popped Element : " << element << endl;

    if (front == rear) { // Queue is empty after pop
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0; // Wrap around
    } else {
      front++;
    }
  }

  ~circularQueue() {
    delete[] arr;
  }
};

int main() {
  circularQueue cq(10);

  cq.push(10);
  cq.push(20);
  cq.push(30);
  cq.push(40);
  cq.push(50);

  cq.pop();
  cq.pop();

  cq.getSize();
  cq.getFront();
  cq.getRear();

  return 0;
}
