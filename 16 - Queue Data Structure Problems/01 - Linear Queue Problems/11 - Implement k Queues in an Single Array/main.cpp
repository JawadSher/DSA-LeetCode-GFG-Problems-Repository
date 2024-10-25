#include <iostream>
using namespace std;

class kQueue{
  public:
    int *arr;
    int k;
    int n;
    int *front;
    int *rear;
    int freeSpot;
    int *next;

    kQueue(int n, int k){
      this -> n = n;
      this -> k = k;
      arr = new int[n];
      front = new int[k];
      rear = new int[k];
      next = new int[n];
      freeSpot = 0;

      for(int i = 0; i < k; i++){
        front[i] = -1;
        rear [i] = -1;
      }

      for(int i = 0; i < n-1; i++){
        next[i] = i + 1;
      }
      next[n-1] = -1;
    }

    void enQueue(int data, int qn){
      // overflow 
      if(freeSpot == -1){
        cout << "No empty space is available" << endl;
        return;
      }

      // find first free index;
      int index = freeSpot;

      // update freeSpot;
      freeSpot = next[index];

      // check wheather first element
      if(front[qn-1] == -1){
        front[qn-1] = index;
      }else{
        // link new element to the prev element
        next[rear[qn-1]] = index;
      }

      // update next;
      next[index] = -1;

      // update rear;
      rear[qn-1] = index;

      // push element;
      arr[index] = data;

    }

    int deQueue(int qn){
      // underflow
      if(front[qn-1] == -1){
        cout << "Queue underflow" <<endl;
        return -1;
      }

      // find index to pop
      int index = front[qn-1];

      // update front pointer
      front[qn-1] = next[index];

      // next freeSpot
      next[index] = freeSpot;
      freeSpot = index;

      return arr[index];
    }
};

int main() {
  kQueue q(10, 3);

  q.enQueue(10, 1);
  q.enQueue(15, 1);
  q.enQueue(20, 2);
  q.enQueue(25, 1);
  q.enQueue(30, 2);
  q.enQueue(35, 3);

  cout << "Element poped from q1 : " << q.deQueue(1) <<endl;
  cout << "Element poped from q1 : " << q.deQueue(1) <<endl;
  cout << "Element poped from q2 : " << q.deQueue(2) <<endl;
  cout << "Element poped from q3 : " << q.deQueue(3) <<endl;
  return 0;
}
