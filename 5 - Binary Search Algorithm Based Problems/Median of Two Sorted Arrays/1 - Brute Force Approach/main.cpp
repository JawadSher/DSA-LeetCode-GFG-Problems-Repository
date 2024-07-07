#include <iostream>
using namespace std;

double median_of_array(int nums_1[], int n, int nums_2[], int m) {
  int t_size = (n + m);
  int temp_array[t_size];

  int i = 0;
  int j = 0;
  int k = 0;

  // Merge nums_1 and nums_2 into temp_array in sorted order
  while (i < n && j < m) {
    if (nums_1[i] < nums_2[j]) {
      temp_array[k++] = nums_1[i++];
    } else {
      temp_array[k++] = nums_2[j++];
    }
  }

  // Copy remaining elements from nums_1 (if any)
  while (i < n) {
    temp_array[k++] = nums_1[i++];
  }

  // Copy remaining elements from nums_2 (if any)
  while (j < m) {
    temp_array[k++] = nums_2[j++];
  }

  // Calculate and return the median
  if (t_size % 2 == 1) {
    return temp_array[t_size / 2];
  } else {
    return (temp_array[t_size / 2] + temp_array[(t_size / 2) - 1]) / 2.0;
  }
}

int main() {
  int array_1[] = {1, 2, 3};
  int n = sizeof(array_1) / sizeof(array_1[0]);

  int array_2[] = {1, 2, 3, 4, 5};
  int m = sizeof(array_2) / sizeof(array_2[0]);

  double median = median_of_array(array_1, n, array_2, m);
  cout << "The median value is: " << median;

  return 0;
}
