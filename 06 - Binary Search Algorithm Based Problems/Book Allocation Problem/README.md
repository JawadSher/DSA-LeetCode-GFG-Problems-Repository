
## Book Allocation Problem

The **book allocation problem** is a classic algorithmic problem often used to teach concepts like binary search and partitioning. The problem involves distributing a given number of books among a set number of students in such a way that the maximum number of pages any student has to read is minimized. The key challenge is to ensure that the workload is balanced as evenly as possible.

### Detailed Problem Statement

Given:

-   `n` books, each with a certain number of pages.
-   `s` students.

The goal is to allocate books to students such that:

1.  Each student gets at least one book.
2.  The books assigned to a student are contiguous (i.e., each student reads a sequence of books).
3.  The maximum number of pages assigned to any student is minimized.

### Constraints

-   Each book can only be assigned to one student.
-   The number of students (`s`) is less than or equal to the number of books (`n`).

### Example

Consider `n = 4` books with pages `[10, 20, 30, 40]` and `s = 2` students.

Possible ways to allocate the books:

1.  Student 1 reads books [10, 20], and Student 2 reads books [30, 40].
    -   Maximum pages any student reads = max(30, 70) = 70.
2.  Student 1 reads books [10, 20, 30], and Student 2 reads book [40].
    -   Maximum pages any student reads = max(60, 40) = 60.

Among all possible allocations, the allocation where Student 1 reads books [10, 20, 30] and Student 2 reads book [40] minimizes the maximum number of pages any student has to read (which is 60 pages).

## Problem Statement

Given `n` books with `pages` array where `pages[i]` denotes the number of pages in the `i-th` book and `s` students, the task is to allocate all books to the students such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

## Solution Explanation

The provided code is a solution to the book allocation problem. It involves two main functions: `is_possible` and `book_allocation`. Here's a detailed explanation of each part:

### Function: `is_possible`

This function checks if it is possible to allocate books such that no student reads more than `mid` pages.


```
int is_possible(int books[], int n, int s, int mid) {
    int stdnt_count = 1; // Start with the first student
    int page_sum = 0; // Sum of pages assigned to the current student
    
    for(int i = 0; i < n; i++) {
        if(page_sum + books[i] <= mid) {
            page_sum += books[i]; // Assign book to the current student
        } else {
            stdnt_count++; // Move to the next student
            if(page_sum + books[i] > mid && stdnt_count > s) {
                return false; // If pages exceed mid and students exceed the limit, return false
            }
            page_sum = books[i]; // Assign the book to the new student
        }
    }
    return true; // Return true if allocation is possible
}
``` 

### Function: `book_allocation`

This function finds the minimum number of pages a student has to read by using binary search.

```
int book_allocation(int books[], int n, int s) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += books[i]; // Calculate total sum of pages
    }
    
    int start = 0;
    int end = sum;
    int ans = -1;
    int mid;
    
    while(start <= end) {
        mid = start + (end - start) / 2;
        
        if(is_possible(books, n, s, mid)) {
            ans = mid;
            end = mid - 1; // Try to minimize the maximum pages
        } else {
            start = mid + 1; // Increase the minimum limit of pages
        }
    }
    return ans;
}
``` 

### Main Function

```
int main() {
    int books[4] = {10, 20, 30, 40};
    int students = 2;
    int minimum_pages = book_allocation(books, 4, students);
    cout << "Minimum Number of Pages can be: " << minimum_pages;
    return 0;
}
``` 

### Explanation

1.  **Initialization**:
    
    -   `books` array contains the number of pages in each book.
    -   `students` is the number of students.
2.  **Total Pages Calculation**:
    
    -   Calculate the total sum of pages in all books to set the range for binary search.
3.  **Binary Search**:
    
    -   Use binary search to find the minimum number of pages by iteratively checking if a given middle point (`mid`) is a possible solution.
    -   Adjust the search range based on whether the current `mid` is a feasible solution.
4.  **Result**:
    
    -   The final answer (`ans`) gives the minimum number of pages that can be allocated to a student without exceeding the limit.

## Time Complexity Analysis

### Explanation

The time complexity of the provided solution can be broken down as follows:

1.  **Sum Calculation**:
    
    -   Calculating the total sum of pages in the `book_allocation` function takes `O(n)` time because it involves iterating through all `n` books.
2.  **Binary Search**:
    
    -   The binary search is performed over the range from 0 to the sum of pages (`sum`), which gives us a range of `O(sum)`.
3.  **Feasibility Check (`is_possible` function)**:
    
    -   Each call to `is_possible` checks whether a given mid value can be a valid solution. This involves iterating through all `n` books, giving a time complexity of `O(n)`.

The binary search splits the range into half repeatedly, resulting in `O(log(sum))` iterations. For each iteration, the `is_possible` function is called, which takes `O(n)` time.

### Combined Time Complexity

The combined time complexity of the solution is: O(n+n⋅log⁡(sum))O(n + n \cdot \log(\text{sum}))O(n+n⋅log(sum))

Here, `n` is for the initial sum calculation, and `n \cdot \log(\text{sum})` is for the binary search with feasibility checks.

Since `sum` is the total number of pages, in the worst case, `sum` can be `n \cdot \text{max(books)}` where `max(books)` is the maximum number of pages in a single book. Therefore, the time complexity can also be written as: O(n⋅log⁡(n⋅max(books)))O(n \cdot \log(n \cdot \text{max(books)}))O(n⋅log(n⋅max(books)))

### Detailed Steps in Binary Search

1.  **Initial Setup**:
    
    -   Compute the total sum of pages (`sum`).
    -   Set `start = 0` and `end = sum`.
    -   Initialize `ans = -1`.
2.  **Binary Search Loop**:
    
    -   Calculate `mid = start + (end - start) / 2`.
    -   Check if it is possible to allocate books such that no student reads more than `mid` pages using the `is_possible` function.
        -   If true, update `ans` to `mid` and move the end pointer (`end = mid - 1`) to search for a smaller possible maximum.
        -   If false, move the start pointer (`start = mid + 1`) to search for a larger possible maximum.
3.  **Result**:
    
    -   The final value of `ans` is the minimum possible value of the maximum number of pages any student has to read.

## Conclusion

This solution leverages binary search to efficiently find the optimal allocation of books to students, ensuring the workload is balanced. The detailed time complexity analysis confirms that the solution is efficient even for large inputs.
