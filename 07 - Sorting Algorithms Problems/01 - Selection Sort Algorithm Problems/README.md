<h1 align='center'>SELECTION - SORT - ALGORITHM - PROBLEMS</h1>

Welcome to the **Selection Sort Algorithm Problems** repository! This repository is dedicated to solving and understanding problems based on the **Selection Sort algorithm**, a fundamental sorting algorithm widely used in computer science.

### Repository Content
<p>
<img src="https://img.shields.io/badge/problems%20count-01-orange?logo=leetcode" alt="LeetCode">
<img src="https://img.shields.io/badge/problems%20count-00-darkgreen?logo=geeksforGeeks" alt="GeeksforGeeks">
<img src="https://img.shields.io/badge/total%20problems%20count-01-blue" alt="Problem Count"> 
</p>

| No | Problem Name | Description | Leetcode | GFG |
|---|-------|-------------------|---|---|
| 01 | [Sort Colors](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/07%20-%20Sorting%20Algorithms%20Problems/01%20-%20Selection%20Sort%20Algorithm%20Problems/01%20-%20Sort%20Colors) | Sort an array with 0s, 1s, and 2s without using the library sort function. The goal is to group all the 0s, 1s, and 2s together, maintaining their relative order. | [Link](https://leetcode.com/problems/sort-colors/) | Non |

## About Selection Sort

Selection Sort is an in-place, comparison-based sorting algorithm. It divides the input list into two parts: 
1. **The sorted portion** (initially empty).
2. **The unsorted portion** (initially containing all elements).

The algorithm repeatedly selects the smallest (or largest, for descending order) element from the unsorted portion and places it at the end of the sorted portion.

### Algorithm Steps:
1. Start with the first element as the current minimum.
2. Traverse through the unsorted portion to find the smallest element.
3. Swap the smallest element with the first element of the unsorted portion.
4. Move the boundary of the sorted portion one element to the right.
5. Repeat until the entire array is sorted.

### Characteristics:
- **Time Complexity:**  
  - Best Case: \(O(n^2)\)  
  - Average Case: \(O(n^2)\)  
  - Worst Case: \(O(n^2)\)  
- **Space Complexity:** \(O(1)\) (in-place sorting)
- **Stability:** Not stable by default.

---
Happy Coding 😊
