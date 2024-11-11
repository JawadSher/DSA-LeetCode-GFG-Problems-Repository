#include <iostream>
#include <algorithm>  // For STL heap functions
#include <vector>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1; // Initialize array with -1 at index 0 (1-based indexing)
        size = 0;    // Initial size of heap is 0
    }

    // Insert a new element into the heap
    void insert(int value) {
        size++;
        int index = size;
        arr[index] = value;

        // Heapify up to maintain max heap property
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;  // Move up to parent
            } else {
                return;
            }
        }
    }

    // Delete the root element from the heap
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Replace root with the last element
        arr[1] = arr[size];
        size--;

        // Heapify down to maintain max heap property
        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    // Print the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify for max heap
void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) largest = left;
    if (right <= n && arr[largest] < arr[right]) largest = right;

    if (largest != i) {
        swap(arr[largest], arr[i]);
        max_heapify(arr, n, largest);
    }
}

// Heapify for min heap
void min_heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) smallest = left;
    if (right < n && arr[smallest] > arr[right]) smallest = right;

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        min_heapify(arr, n, smallest);
    }
}

// Sort a max heap (ascending order)
void maxHeapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2; i > 0; i--) {
        max_heapify(arr, n, i);
    }

    // Sort
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        max_heapify(arr, i - 1, 1);
    }
}

// Sort a min heap (descending order)
void minHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Max Heap after insertions:" << endl;
    h.print();
    h.deleteFromHeap();
    cout << "Max Heap after deletion:" << endl;
    h.print();

    cout << endl;

    // Max Heap Creation using array
    int max_arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--) {
        max_heapify(max_arr, n, i);
    }

    cout << "Heapify array - Max Heap" << endl;
    for (int i = 1; i <= n; i++) {
        cout << max_arr[i] << " ";
    }
    cout << endl;

    maxHeapSort(max_arr, n);
    cout << "Printing max sorted heap (Ascending Order)" << endl;
    for (int i = 1; i <= n; i++) {
        cout << max_arr[i] << " ";
    }
    cout << endl << endl;

    // Min Heap Creation using array
    int min_arr[5] = {54, 53, 55, 52, 50};
    int m = 5;
    for (int i = m / 2 - 1; i >= 0; i--) {
        min_heapify(min_arr, m, i);
    }

    cout << "Heapify array - Min Heap" << endl;
    for (int i = 0; i < m; i++) {
        cout << min_arr[i] << " ";
    }
    cout << endl;

    minHeapSort(min_arr, m);
    cout << "Printing min sorted heap (Descending Order)" << endl;
    for (int i = 0; i < m; i++) {
        cout << min_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
