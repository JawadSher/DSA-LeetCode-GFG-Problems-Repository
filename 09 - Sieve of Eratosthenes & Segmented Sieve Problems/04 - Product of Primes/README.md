<h1 align='center'>Product - of - Primes</h1>

## Problem Statement

**Problem URL :** [Product of Primes](https://www.geeksforgeeks.org/problems/product-of-primes5328/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/7cd21f51-dedd-4490-9802-9d1aaacdbbb1)


## Algorithm Explanation
We'll start with some **really basic ideas** to build up to understanding the **Segmented Sieve**. Ready?

#### Step 1: What Are Prime Numbers?

A **prime number** is a number greater than 1 that has no divisors other than 1 and itself. In simpler terms:
- **Prime examples:** 2, 3, 5, 7, 11, 13, etc.
- **Non-prime examples:** 4 (because 2 divides 4), 6 (because 2 and 3 divide 6), 8 (because 2 divides 8), etc.

Do you feel comfortable with prime numbers so far? If yes, let's go to the next step. If not, feel free to ask for more examples!

---

#### Step 2: What Is the Sieve of Eratosthenes?

The **Sieve of Eratosthenes** is a way to find **all prime numbers up to a certain number**. Let's say you want to find all prime numbers up to 20. How do we do that?

Here’s the **simplified process**:

1. **Start with a list** of numbers from 2 up to the maximum number you want (let's say 20). These are our candidates to check if they’re prime.
   
   ```
   2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
   ```

2. The first number (2) is **prime**, so we circle it.
   
   Now, cross out (mark) all the multiples of 2 (because they’re not prime).
   
   ```
   2, 3, ~4~, 5, ~6~, 7, ~8~, 9, ~10~, 11, ~12~, 13, ~14~, 15, ~16~, 17, ~18~, 19, ~20~
   ```

3. Move to the next unmarked number, which is 3. It’s **prime**, so circle it.
   
   Now, cross out all multiples of 3.
   
   ```
   2, 3, ~4~, 5, ~6~, 7, ~8~, ~9~, ~10~, 11, ~12~, 13, ~14~, ~15~, ~16~, 17, ~18~, 19, ~20~
   ```

4. The next unmarked number is 5. It’s **prime**, so circle it. No need to mark multiples here because 5's multiples are already crossed out.

   Keep doing this until all numbers are either circled (prime) or crossed out.

At the end, you’ll be left with:
- **Primes:** 2, 3, 5, 7, 11, 13, 17, 19

How are you feeling about this? Does this explanation of the **Sieve of Eratosthenes** make sense so far?

---

#### Step 3: Why Is the Classic Sieve a Problem for Large Numbers?

Now, the classic sieve works great for smaller numbers, like finding primes up to 100 or even 1,000. But if we want to find primes in **really large ranges**, say between **10 billion and 10 billion + 1,000**, the sieve becomes slow and uses too much memory.

Imagine trying to create a list of all numbers up to **10 billion**. That’s a huge amount of memory! This is where the **Segmented Sieve** comes to the rescue.

### Step 4: Segmented Sieve - Basic Idea

The **Segmented Sieve** is just a smart way to handle large ranges without using too much memory.

##### Let’s Think of a Simple Example:
- Say we want to find prime numbers between 30 and 50. We don’t want to create a list of all numbers up to 50, especially if we’re working with much larger ranges.
- Instead, we split the work:
  1. First, find all **small primes** up to \( \sqrt{50} \), which is about 7. So, we only need to deal with primes **up to 7**.
  2. Then, use those small primes to find the primes between 30 and 50.

---

#### Let’s Do This Step by Step:

1. **Find primes up to \( \sqrt{50} \).**
   - We apply the classic sieve to numbers up to 7 (since \( \sqrt{50} \approx 7 \)).
   - The primes up to 7 are: **2, 3, 5, 7**.

2. **Use those primes to find primes in the range [30, 50].**
   - We create a list of numbers from 30 to 50: 
   
     ```
     30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50
     ```
   
   - Now, using our small primes (2, 3, 5, 7), we **cross out multiples** of each one:
     
     - Multiples of 2:
       ```
       30, ~31~, ~32~, ~33~, ~34~, ~35~, ~36~, ~37~, ~38~, ~39~, ~40~, ~41~, ~42~, ~43~, ~44~, ~45~, ~46~, ~47~, ~48~, ~49~, ~50~
       ```

     - Multiples of 3:
       ```
       30, ~31~, ~32~, ~33~, ~34~, ~35~, ~36~, ~37~, ~38~, ~39~, ~40~, ~41~, ~42~, ~43~, ~44~, ~45~, ~46~, ~47~, ~48~, ~49~, ~50~
       ```

     - Multiples of 5:
       ```
       30, ~31~, ~32~, ~33~, ~34~, ~35~, ~36~, ~37~, ~38~, ~39~, ~40~, ~41~, ~42~, ~43~, ~44~, ~45~, ~46~, ~47~, ~48~, ~49~, ~50~
       ```

     - Multiples of 7:
       ```
       30, ~31~, ~32~, ~33~, ~34~, ~35~, ~36~, ~37~, ~38~, ~39~, ~40~, ~41~, ~42~, ~43~, ~44~, ~45~, ~46~, ~47~, ~48~, ~49~, ~50~
       ```

3. **Remaining numbers are primes**:
   - After crossing out multiples of 2, 3, 5, and 7, the numbers that remain uncrossed are primes:
     - 31, 37, 41, 43, 47

---

#### Why Is This Approach Better?

Instead of checking **every single number** up to 50 (or much larger numbers), we:
- **Divide the range** into smaller parts.
- **Use a smaller sieve** to handle primes up to \( \sqrt{R} \).
- This saves memory and makes the process faster for large ranges.

---

#### Quick Recap:
1. We use the **classic sieve** for small primes up to \( \sqrt{R} \).
2. Then, we use those small primes to mark non-primes in the range [L, R].
3. The numbers that aren’t marked are the primes in that range.

---

How are you feeling now? Does this step-by-step explanation help clear things up? If you'd like, we can keep going at this pace and explore more examples together!
  
## Problem Solution
```cpp
class Solution{
private :
    vector<int> sieve(int n){
        vector<bool> isPrime(n+1, true);
        
        isPrime[0] = isPrime[1] = false;
        
        vector<int> primes;
        
        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        return primes;
        
    }
public:
    long long primeProduct(long long L, long long R){
        const long long MOD = 1e9 + 7;
        
        int limit = sqrt(R);
        vector<int> primes = sieve(limit);
        
        vector<bool> isPrime(R - L + 1, true);
        long long result = 1;
        
        if (L == 1) isPrime[0] = false;
        
        for(int prime : primes){
            long long start = max((long long) (prime * prime), (L + prime - 1) / prime * prime);
            
            for(long long i = start; i <= R; i += prime){
                isPrime[i - L] = false;
            }
        }
        
        for(int i = 0; i <= R - L; i++){
            if(isPrime[i]){
                result = (result * (L + i)) % MOD;
            }
        }
        
        
        return result;
    }
};
```

## Problem Solution Explanation
Let’s go through the `Solution` class methods with detailed explanations and examples.

### Example 1: Generating Primes using `sieve`

**Input:**
```cpp
int N = 10;
```

**Code:**
```cpp
vector<int> primes = sieve(N);
```

**Explanation:**

1. **Initialize the `isPrime` Vector:**
   ```cpp
   vector<bool> isPrime(N + 1, true);
   ```
   - `isPrime` is initialized to `true` for indices from `0` to `10`. So initially, all numbers are assumed to be prime.

2. **Set 0 and 1 as Non-Primes:**
   ```cpp
   isPrime[0] = isPrime[1] = false;
   ```
   - `0` and `1` are not prime numbers.

3. **Sieve of Eratosthenes Algorithm:**
   ```cpp
   for (int i = 2; i * i <= N; i++) {
       if (isPrime[i]) {
           for (int j = i * i; j <= N; j += i) {
               isPrime[j] = false;
           }
       }
   }
   ```
   - For `i = 2`: Marks multiples of `2` (i.e., `4`, `6`, `8`, `10`) as non-prime.
   - For `i = 3`: Marks multiples of `3` (i.e., `9`) as non-prime.

4. **Collect the Primes:**
   ```cpp
   for (int i = 2; i <= N; i++) {
       if (isPrime[i]) {
           primes.push_back(i);
       }
   }
   ```
   - The primes collected are `2`, `3`, `5`, and `7`.

**Output:**
```cpp
primes = [2, 3, 5, 7];
```

### Example 2: Calculating the Product of Primes in Range using `primeProduct`

**Input:**
```cpp
long long L = 10;
long long R = 20;
```

**Code:**
```cpp
long long result = primeProduct(L, R);
```

**Explanation:**

1. **Generate Primes up to sqrt(R):**
   ```cpp
   int limit = sqrt(R);
   vector<int> primes = sieve(limit);
   ```
   - Here, `limit` is `sqrt(20) ≈ 4.47`, so `limit` is `4`.
   - Primes up to `4` are `2` and `3`.

2. **Initialize `isPrime` Vector for Range [L, R]:**
   ```cpp
   vector<bool> isPrime(R - L + 1, true);
   ```
   - `isPrime` vector for the range `[10, 20]` is initialized to `true`.

3. **Mark Non-Primes in the Range [L, R]:**
   ```cpp
   for (int prime : primes) {
       long long start = max((long long) (prime * prime), (L + prime - 1) / prime * prime);
       for (long long i = start; i <= R; i += prime) {
           isPrime[i - L] = false;
       }
   }
   ```
   - For `prime = 2`: Start from `10` (first multiple of `2` in range), mark `10`, `12`, `14`, `16`, `18` as non-prime.
   - For `prime = 3`: Start from `12` (first multiple of `3` in range), mark `12`, `15`, `18` as non-prime.

4. **Calculate the Product of Primes:**
   ```cpp
   long long result = 1;
   for (int i = 0; i <= R - L; i++) {
       if (isPrime[i]) {
           result = (result * (L + i)) % MOD;
       }
   }
   ```
   - Collect prime numbers in range `[10, 20]`: `11`, `13`, `17`, `19`.
   - Product: `11 * 13 * 17 * 19 = 41917`.
   - `result` is computed as `41917 % 1000000007` which is `41917`.

**Output:**
```cpp
result = 41917;
```

### Summary

- **`sieve` Method Example:** Generates primes up to `10`, yielding `[2, 3, 5, 7]`.
- **`primeProduct` Method Example:** Calculates the product of primes in range `[10, 20]`, yielding `41917`.

This detailed walkthrough shows how the methods are used to generate primes and calculate products within a given range efficiently.
