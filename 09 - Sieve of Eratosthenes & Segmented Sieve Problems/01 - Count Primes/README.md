<h1 align='center'>Count - Primes</h1>

## Problem Statement

**Problem URL :** [Count Primes](https://leetcode.com/problems/count-primes/)

![image](https://github.com/user-attachments/assets/7c3a59f7-d068-4a50-b2df-a6ee717270ef)

## Problem Solution
```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = 0;
        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++) {
            if (prime[i]) count++;
        }

        return count;
    }
};
```

## Problem Solution Explanation
Certainly! Let's explore the **logic** behind the Sieve of Eratosthenes and why it works efficiently to find the count of prime numbers up to a given number \( n \). The focus here will be on the **conceptual understanding** of the algorithm rather than a line-by-line code breakdown.

### What is a Prime Number?

A **prime number** is a number greater than 1 that has no divisors other than 1 and itself. For example, the numbers 2, 3, 5, 7, 11, and 13 are primes. A **composite number** is a number that can be divided by smaller numbers (other than 1 and itself), such as 4, 6, 8, and 9.

### The Challenge of Finding Primes

If we want to know how many prime numbers exist less than a number \( n \), a brute-force approach would involve checking every number \( i \) from 2 to \( n-1 \) and determining if it is divisible by any number other than 1 and itself. However, this approach is inefficient because checking divisibility for each number can be computationally expensive as \( n \) grows larger.

### The Sieve of Eratosthenes: Intuitive Overview

The **Sieve of Eratosthenes** provides an efficient way to find all prime numbers less than \( n \). It avoids redundant checks by systematically "sieving out" composite numbers. Here’s how it works step-by-step:

#### Step 1: Create a List of Candidates
We start by assuming that every number between 2 and \( n-1 \) **might be prime**. We initialize a list where each number is marked as prime. As we move through the list, we systematically identify numbers that are composite and mark them as **not prime**.

#### Step 2: Start with the First Prime (2)
The first prime number is 2. Since 2 is prime, all multiples of 2 (like 4, 6, 8, 10, etc.) cannot be prime because they are divisible by 2. So, we "mark" all multiples of 2 as non-prime.

#### Step 3: Move to the Next Unmarked Number
The next unmarked number after 2 is 3, which is also prime. Now, we repeat the process: for the prime number 3, mark all of its multiples (like 6, 9, 12, etc.) as non-prime. Notice that some numbers (like 6) are already marked as non-prime because they are multiples of 2. This ensures that we don't perform redundant work.

#### Step 4: Repeat the Process
We continue this process for the next unmarked number (which is 5, then 7, and so on). Each time we find a prime, we mark all of its multiples as non-prime.

#### Step 5: Stop at the Square Root of \( n \)
Here’s an important insight: **we only need to repeat this process up to the square root of \( n \)**. Why? Because if a number \( i \) has a divisor greater than \( \sqrt{n} \), the corresponding other divisor must be smaller than \( \sqrt{n} \). This allows us to stop the process early and avoid unnecessary work.

For example:
- For \( n = 100 \), we only need to check numbers up to 10 (i.e., \( \sqrt{100} = 10 \)).
- Any composite number less than 100 will have a factor smaller than or equal to 10. So after marking multiples of numbers up to 10, all remaining unmarked numbers must be prime.

### Why Does This Work?

The key idea behind the Sieve of Eratosthenes is **elimination by smallest prime factors**. By marking multiples of small primes, we ensure that any composite number is eventually marked as non-prime.

For example, let’s consider marking multiples for small primes:
- Multiples of 2: 4, 6, 8, 10, 12, 14, ...
- Multiples of 3: 9, 12, 15, 18, 21, ...
- Multiples of 5: 25, 30, 35, 40, ...
- Multiples of 7: 49, 56, 63, 70, ...

After marking these multiples, any number that hasn’t been marked must be prime because it hasn’t been divisible by any smaller number. This method avoids the need to directly check for primality for every number, making the algorithm highly efficient.

### Efficiency of the Algorithm

1. **Reduced Workload**: The sieve only marks multiples of each prime once. Once a number is marked as composite, we don’t need to process it again. This dramatically reduces the workload compared to checking every number for primality.

2. **Early Termination**: By only processing numbers up to \( \sqrt{n} \), we avoid unnecessary calculations for larger numbers. This early termination is possible because composite numbers will always have factors smaller than \( \sqrt{n} \).

3. **Space Efficiency**: The algorithm uses a simple boolean array to keep track of prime numbers. For a large number \( n \), this is memory efficient compared to storing more complex data structures.

### Final Counting Step

After marking all non-prime numbers, the last step is simply to count how many numbers in the list are still marked as prime. This gives us the total count of prime numbers less than \( n \).

### Example Walkthrough (for \( n = 10 \))

Let’s see how the algorithm works for \( n = 10 \):

1. **Initial Setup**: Assume all numbers from 2 to 9 are prime.
   - List: `[true, true, true, true, true, true, true, true, true, true]`

2. **First Prime (2)**: 2 is prime. Mark all multiples of 2 (4, 6, 8) as non-prime.
   - List after marking multiples of 2: `[true, true, true, true, false, true, false, true, false, true]`

3. **Next Prime (3)**: 3 is prime. Mark all multiples of 3 (9) as non-prime.
   - List after marking multiples of 3: `[true, true, true, true, false, true, false, true, false, false]`

4. **Next Unmarked Number (5)**: 5 is prime. It has no multiples less than 10, so no further marking.

5. **Final Unmarked Numbers**: The unmarked numbers in the list are 2, 3, 5, and 7, which are all prime.

The prime count for \( n = 10 \) is 4.


### Code Breakdown
Let's break the code into key parts:

1. **Initial Check for Small Values:**
   ```cpp
   if (n <= 2) return 0;
   ```
   - If `n` is less than or equal to 2, there are no prime numbers, so the function returns `0`. This is because the smallest prime number is 2.

2. **Creating the `prime` Array:**
   ```cpp
   vector<bool> prime(n, true);
   prime[0] = prime[1] = false;
   ```
   - A boolean vector `prime` of size `n` is created and initialized with `true`, which means we assume all numbers are prime initially.
   - Then, `prime[0]` and `prime[1]` are set to `false` because 0 and 1 are not prime numbers.

3. **Sieve of Eratosthenes Algorithm:**
   ```cpp
   for (int i = 2; i * i < n; i++) {
       if (prime[i]) {
           for (int j = i * i; j < n; j += i) {
               prime[j] = false;
           }
       }
   }
   ```
   - The outer loop runs from `i = 2` to `sqrt(n)`. The goal is to mark all multiples of a prime number `i` as non-prime.
   - For each `i` (starting from 2), if `prime[i]` is `true`, that means `i` is a prime number. We then mark all multiples of `i` (starting from `i*i`) as non-prime by setting `prime[j] = false`. This is done in the inner loop where `j` increments by `i` (i.e., `j += i`).

4. **Counting the Prime Numbers:**
   ```cpp
   for (int i = 2; i < n; i++) {
       if (prime[i]) count++;
   }
   ```
   - Finally, we iterate through the `prime` array from `2` to `n-1`. For every index `i` where `prime[i]` is `true`, we increment the `count` because `i` is a prime number.

### Example: `n = 10`

Let's see how the code works for `n = 10`.

1. **Initialize the `prime` Array:**
   ```cpp
   prime = [false, false, true, true, true, true, true, true, true, true]
   ```
   - We initialize an array of size 10, where all entries (except for index 0 and 1) are set to `true` because we initially assume all numbers from 2 to 9 are prime.

2. **Applying the Sieve:**
   - **For `i = 2`:**
     - Since `prime[2]` is `true`, we mark all multiples of 2 (starting from `2*2 = 4`) as `false`:
     ```cpp
     prime = [false, false, true, true, false, true, false, true, false, true]
     ```
     - We mark `prime[4]`, `prime[6]`, `prime[8]` as `false` (non-prime).
   
   - **For `i = 3`:**
     - Since `prime[3]` is `true`, we mark all multiples of 3 (starting from `3*3 = 9`) as `false`:
     ```cpp
     prime = [false, false, true, true, false, true, false, true, false, false]
     ```
     - We mark `prime[9]` as `false` (non-prime).

   - **For `i = 4`:**
     - Since `prime[4]` is `false`, we skip this value.

   Now, the `prime` array looks like this:
   ```cpp
   prime = [false, false, true, true, false, true, false, true, false, false]
   ```

3. **Counting Primes:**
   - We count the number of `true` values in the `prime` array from index 2 to `n-1`:
     - `prime[2]`, `prime[3]`, `prime[5]`, and `prime[7]` are `true`, so the count is `4`.

Thus, the number of prime numbers less than 10 is **4** (which are 2, 3, 5, and 7).

### More Indepth Explanation of Logic

Let's clear up the confusion about these two lines of code:

### 1. `for (int i = 2; i * i < n; i++)`

This loop controls the main part of the **Sieve of Eratosthenes** algorithm. Here's a breakdown of each part of the loop:

- **`int i = 2;`**: 
  - This initializes `i` to 2, the first prime number.
  
- **`i * i < n;`**: 
  - This condition checks whether `i * i` is less than `n`. 
  - The reason we use `i * i` here is that once we've reached numbers greater than `sqrt(n)` (the square root of `n`), all non-prime numbers would already have been marked by smaller primes. This optimization helps reduce unnecessary checks.

  **Why `i * i`?**
  - If you think about marking non-prime numbers, for each prime number `i`, we need to mark all its multiples as non-prime. However, if you start from `i * i`, you'll mark the multiples that haven't already been marked by smaller primes.
  - For example, for `i = 5`, you can start marking multiples at `5 * 5 = 25` because all smaller multiples (like `5 * 2 = 10`, `5 * 3 = 15`, etc.) will have already been marked by smaller primes like 2 and 3.

- **`i++`**: 
  - This increments `i` by 1 after each iteration.

### Example for `i * i < n`:
If `n = 20`, we stop the loop when `i * i` becomes greater than or equal to `n`:
- When `i = 2`, `i * i = 4`, which is less than 20, so we proceed.
- When `i = 3`, `i * i = 9`, which is still less than 20, so we proceed.
- When `i = 4`, `i * i = 16`, which is still less than 20, so we proceed.
- When `i = 5`, `i * i = 25`, which is greater than 20, so the loop ends.

### 2. `for (int j = i * i; j < n; j += i)`

This loop marks the multiples of `i` as non-prime starting from `i * i`.

- **`int j = i * i;`**:
  - This initializes `j` to `i * i`, which means we're starting from the square of the prime `i`. We start at `i * i` because any smaller multiple of `i` (like `2 * i`, `3 * i`, etc.) would have already been marked as non-prime by smaller primes.
  
- **`j < n;`**:
  - This condition ensures that we only mark multiples of `i` that are less than `n`.

- **`j += i;`**:
  - This means that we increment `j` by `i` in each iteration, effectively moving to the next multiple of `i`.

### Example of `for (int j = i * i; j < n; j += i)` for `i = 2` and `n = 10`:
- When `i = 2`, we start marking multiples of 2 starting from `2 * 2 = 4`:
  - First, we mark `j = 4` as non-prime.
  - Next, `j += 2`, so `j = 6`, which we mark as non-prime.
  - Next, `j += 2`, so `j = 8`, which we mark as non-prime.
  - Now `j += 2`, so `j = 10`, but `10 >= n`, so we stop.

For `i = 3` and `n = 10`:
- When `i = 3`, we start marking multiples of 3 starting from `3 * 3 = 9`:
  - We mark `j = 9` as non-prime.
  - Now `j += 3`, so `j = 12`, but `12 >= n`, so we stop.


### Efficiency
- **Time Complexity**: The algorithm runs in **O(n log log n)** time, which is efficient for finding primes up to large values of `n`.
- **Space Complexity**: The space complexity is **O(n)** due to the `prime` array.

### Summary
- The Sieve of Eratosthenes efficiently marks non-prime numbers in the range [2, n) by iterating over each prime number and marking its multiples as non-prime.
- After running the sieve, the number of `true` values in the `prime` array gives the count of prime numbers less than `n`.
- **`i * i < n`**: We only need to check for primes up to the square root of `n` because larger factors will have already been handled.
- **`j = i * i`**: We start marking multiples from `i * i` because smaller multiples would have been marked already.

