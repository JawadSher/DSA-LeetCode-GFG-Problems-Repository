# Guess Number Higher or Lower

## Problem Statement

You are playing a guessing game with the computer. The computer picks a number between 1 and `n`, and you have to guess what the number is. 
You call a pre-defined API `int guess(int num)`, which returns three possible results:

-   Returns `-1` if your guess is higher than the picked number.
-   Returns `1` if your guess is lower than the picked number.
-   Returns `0` if your guess is correct.

You need to implement a function `int guess(int n)` that finds the correct number using the least number of guesses.

## Provided Solution

The provided code implements a binary search to efficiently guess the number.

## Solution Class

### guessNumber Method

This method takes an integer `n` as input and returns the number picked by the computer.

```
class Solution {
public:
    int guessNumber(int n) {
        int start = 0;
        int end = n;

        while(start <= end){
            int mid = start + (end - start)/2;

            int value = guess(mid);

            if(value == 0){
                return mid;
            }else if(value == -1){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};
``` 

## Explanation

1.  **Initialization**:
    
    -   `start` is initialized to 0.
    -   `end` is initialized to `n`.
2.  **Binary Search Loop**:
    
    -   The loop continues while `start` is less than or equal to `end`.
3.  **Mid Calculation**:
    
    -   `mid` is calculated as the middle index between `start` and `end`.
4.  **Guess Function Call**:
    
    -   The `guess(mid)` function is called to get feedback on the current guess.
5.  **Feedback Handling**:
    
    -   If `guess(mid)` returns `0`, it means the guess is correct, and `mid` is returned.
    -   If `guess(mid)` returns `-1`, it means the guess is higher than the picked number, so `end` is updated to `mid - 1`.
    -   If `guess(mid)` returns `1`, it means the guess is lower than the picked number, so `start` is updated to `mid + 1`.
6.  **Return Statement**:
    
    -   The method returns `-1` if the number is not found, though in this context, the loop guarantees that the correct number will be found, making this line more of a safeguard.

### Summary

This code efficiently finds the number picked by the computer using a binary search approach, which ensures the number of guesses is minimized. The binary search divides the range of possible numbers in half with each guess, leading to a logarithmic time complexity, making it very efficient for large values of `n`.
