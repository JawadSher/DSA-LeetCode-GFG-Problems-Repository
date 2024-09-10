<h1 align='center'>Count - Primes - in - Range</h1>

## Problem Statement

**Problem URL :** [Count Primes in Range](https://www.geeksforgeeks.org/problems/count-primes-in-range1604/1)

![image](https://github.com/user-attachments/assets/212e922c-a1b3-4224-b259-7325d8ffb493)
![image](https://github.com/user-attachments/assets/8ce19314-dfaf-4b07-b30d-b44c8ffc99ae)

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        if (R <= 1){
            return 0;
        }
        
        vector<bool>prime (R+1, true);
        
        prime[0] = prime[1] = false;
        
        for(int i = 2; i * i <= R; i++){
            if(prime[i]){
                for(int j = i * i; j <= R; j += i){
                    prime[j] = false;
                }
            }
        }
        
        int count = 0;
        for(int i = max(L, 2); i <= R; i++){
            if(prime[i]) count++;
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}

```

## Problem Solution Explanation
This code is designed to count how many prime numbers exist in the range `[L, R]` using a method based on the **Sieve of Eratosthenes**. Below is a detailed explanation of how this code works, step-by-step, using simple language and an example.

1. **Prime Number Basics**:
   - A **prime number** is a number greater than 1 that has no divisors other than 1 and itself. Examples include 2, 3, 5, 7, etc.
   - For a number to be **non-prime**, it should be divisible by a smaller number.

2. **Understanding the Problem**:
   - The function `countPrimes` counts how many prime numbers exist between `L` and `R`, where `L` is the lower bound and `R` is the upper bound.

#### 1. **Input**
In the main function, the code takes multiple test cases `t`. For each test case, two integers `L` and `R` are given, and the program needs to find how many prime numbers exist in that range.

```cpp
cin >> t; 
while (t--) { 
    int L, R; 
    cin >> L >> R;
    Solution ob; 
    int ans = ob.countPrimes(L, R); 
    cout << ans << "\n";
}
```

#### 2. **The `countPrimes` Function**

This is where the main logic happens.

```cpp
int countPrimes(int L, int R) {
    if (R <= 1) {
        return 0;
    }
```

- The function starts by checking if `R` is less than or equal to 1. Any number less than or equal to 1 cannot be prime, so if `R <= 1`, the function directly returns 0 (meaning no primes exist in that range).

#### 3. **Prime Array Initialization**

```cpp
vector<bool> prime(R + 1, true);
prime[0] = prime[1] = false;
```

- We create a **boolean array** called `prime` where each index represents whether a number is prime. 
  - For example, `prime[5] == true` means 5 is considered prime, and `prime[6] == false` means 6 is not prime.
- Initially, all numbers are marked as prime (`true`). 
  - However, we know that 0 and 1 are not prime, so `prime[0]` and `prime[1]` are set to `false`.

#### 4. **Sieve of Eratosthenes Logic**

```cpp
for (int i = 2; i * i <= R; i++) {
    if (prime[i]) {
        for (int j = i * i; j <= R; j += i) {
            prime[j] = false;
        }
    }
}
```

- This part of the code implements the **Sieve of Eratosthenes**, which is an efficient algorithm to find all primes up to a certain limit.
- Here's how it works:
  - Start with `i = 2`, the smallest prime number.
  - If `i` is prime, mark all its multiples as non-prime (because multiples of `i` are divisible by `i`).
  - Continue this for numbers `i` such that `i * i <= R`.
  - Example: For `R = 10`, the sieve will:
    - Mark 4, 6, 8, and 10 as non-prime (because they are multiples of 2).
    - Mark 9 as non-prime (because it's a multiple of 3).

#### 5. **Counting the Primes in Range**

```cpp
int count = 0;
for (int i = max(L, 2); i <= R; i++) {
    if (prime[i]) count++;
}
```

- After the sieve has marked all non-prime numbers, this loop counts how many prime numbers exist between `L` and `R`.
- `max(L, 2)` ensures that the counting starts from 2 (since 2 is the smallest prime number).
- Example: If `L = 10` and `R = 20`, after marking non-primes, it will check numbers 10 to 20 and count how many are still marked as prime.

#### 6. **Returning the Result**

```cpp
return count;
```

- Finally, the function returns the count of prime numbers in the given range `[L, R]`.

### Example Walkthrough

Let’s run through an example to make it clearer.

**Example 1:**

- Input: `L = 10`, `R = 20`
- Process:
  1. We initialize a `prime` array for numbers 0 to 20.
  2. Using the Sieve of Eratosthenes:
     - For `i = 2`, mark multiples of 2 (i.e., 4, 6, 8, 10, 12, 14, 16, 18, 20) as non-prime.
     - For `i = 3`, mark multiples of 3 (i.e., 9, 12, 15, 18) as non-prime.
     - For `i = 5`, mark multiples of 5 (i.e., 25, which is beyond 20, so no further marking).
  3. After marking, the primes between 10 and 20 are: 11, 13, 17, 19.
  4. So the count is `4`.

**Output**:
```
4
```

### Key Points:
1. **Efficiency**: The Sieve of Eratosthenes is efficient, marking non-primes by starting with small primes like 2, 3, etc.
2. **Prime Checking**: After the sieve, we just need to check which numbers in the range `[L, R]` are still marked as prime.
3. **Edge Case Handling**: The code handles edge cases like when `R <= 1` or when `L` is less than 2 properly.

### Conclusion:
This code is a good example of how the Sieve of Eratosthenes can be used to efficiently count prime numbers in a given range. It first marks all non-primes up to `R` and then counts the primes in the range `[L, R]`.
