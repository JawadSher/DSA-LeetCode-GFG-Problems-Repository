#include <iostream>
using namespace std;

class NStacks {
    int *arr;      // Array to store elements of all stacks
    int *top;      // Array to store indexes of top elements of stacks
    int *next;     // Array to store next entry in all stacks and free list
    int n, s;      // n: total size of array, s: number of stacks
    int freeSpot;  // To store the beginning index of the free spots

public:
    // Constructor to initialize N stacks in a single array
    NStacks(int N, int S) {
        this->n = N;
        this->s = S;
        arr = new int[n];     // Array of size n to store elements
        top = new int[s];     // Array to store tops of stacks
        next = new int[n];    // Array to maintain the free spots

        // Initialize all stacks as empty (top = -1)
        fill(top, top + s, -1);

        // Initialize all spots as free and create free list
        freeSpot = 0;
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;  // End of free list
    }

    // Function to push an element onto stack 'stackNum'
    bool push(int value, int stackNum) {
        // check for overflow
        if (freeSpot == -1) {
            return false;  // No free space left
        }

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // insert element into array
        arr[index] = value;

        // update next to point to the previous top element
        next[index] = top[stackNum - 1];

        // update top to point to the current index
        top[stackNum - 1] = index;

        return true;
    }

    // Function to pop an element from stack 'stackNum'
    int pop(int stackNum) {
        // check underflow condition
        if (top[stackNum - 1] == -1) return -1;  // Stack is empty

        int index = top[stackNum - 1];

        // update top to point to the next element in the stack
        top[stackNum - 1] = next[index];

        // link the popped index back to the free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    int numOfStacks = 3, sizeOfArray = 6;
    NStacks stacks(sizeOfArray, numOfStacks);  // NStacks(total array size, number of stacks)

    // Push elements onto different stacks
    cout << stacks.push(10, 1) << endl;  // Expected: 1 (true)
    cout << stacks.push(20, 2) << endl;  // Expected: 1 (true)
    cout << stacks.push(30, 1) << endl;  // Expected: 1 (true)
    cout << stacks.push(40, 3) << endl;  // Expected: 1 (true)
    cout << stacks.push(50, 2) << endl;  // Expected: 1 (true)
    cout << stacks.push(60, 3) << endl;  // Expected: 1 (true)

    // Try pushing when array is full
    cout << stacks.push(70, 1) << endl;  // Expected: 0 (false) - Overflow

    // Pop elements from stacks
    cout << stacks.pop(1) << endl;  // Expected: 30
    cout << stacks.pop(2) << endl;  // Expected: 50
    cout << stacks.pop(3) << endl;  // Expected: 60

    // Pop again from stack 1
    cout << stacks.pop(1) << endl;  // Expected: 10

    // Try popping from empty stack
    cout << stacks.pop(1) << endl;  // Expected: -1 (Underflow)
}
