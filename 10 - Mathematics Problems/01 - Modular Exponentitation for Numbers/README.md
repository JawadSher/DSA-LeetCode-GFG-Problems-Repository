<h1 align='center'></h1>

## Problem Statement

**Problem URL :** [Modular Exponentiation for Large Numbers](https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1)

![image](https://github.com/user-attachments/assets/d5aeb935-2c12-4107-9655-b8be753654fd)

## Problem Solution
```cpp
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    int result = 1;
		    
		    while(n>0){
		        
    		    if(n&1){
    		        
    		        result = (1LL * (result) * (x)%M) %M;
    		    }
    		    
    		    x = (1LL * (x)%M * (x)%M) %M;
    		    n = n >> 1;
		    }
		    
		    return result;
		}
};
```

## Problem Solution Explanation
code is an implementation of **Modular Exponentiation**, which efficiently computes \( x^n \mod M \) (i.e., the result of raising \( x \) to the power \( n \), modulo \( M \)). It uses the **Exponentiation by Squaring** method, which reduces the time complexity from \( O(n) \) to \( O(\log n) \).

Let’s break down the code line by line and explain it with an example.

### Code Walkthrough

```cpp
class Solution
{
    public:
        long long int PowMod(long long int x, long long int n, long long int M)
        {
            int result = 1;
```

1. **Class Declaration:**
   - The function `PowMod` is declared inside the `Solution` class. The function takes three parameters:
     - \( x \) (base),
     - \( n \) (exponent),
     - \( M \) (modulus).
     
2. **Variable Initialization:**
   - `result` is initialized to 1, which will store the intermediate results during the computation of \( x^n \mod M \).

---

```cpp
            while(n > 0)
            {
```

3. **Loop Until \( n \) Becomes Zero:**
   - The loop runs while \( n \) (exponent) is greater than 0. In each iteration, the exponent is divided by 2 (right-shifted) as part of the binary exponentiation technique.

---

```cpp
                if(n & 1)
                {
                    result = (1LL * result * x % M) % M;
                }
```

4. **Check if the Current Bit of \( n \) is Odd:**
   - The condition `(n & 1)` checks if the least significant bit of \( n \) is 1 (i.e., if \( n \) is odd). This is a fast way to determine whether \( n \) is odd or even using bitwise operations.
   
5. **Update the Result (When \( n \) is Odd):**
   - If \( n \) is odd, multiply `result` by \( x \) and take the modulus \( M \). This ensures that the result never exceeds the value \( M \) during the intermediate steps.
   - `1LL` is used to explicitly promote the expression to a `long long` data type to avoid overflow during multiplication.

---

```cpp
                x = (1LL * x % M * x % M) % M;
                n = n >> 1;
```

6. **Square the Base \( x \):**
   - After handling the current bit of \( n \), we square \( x \) and apply the modulus \( M \). This reduces the exponentiation by squaring, a key part of the binary exponentiation technique.
   
7. **Right Shift \( n \):**
   - The operation `n = n >> 1` divides \( n \) by 2. This reduces the exponent by discarding the least significant bit. Each loop iteration processes one bit of the exponent.

---

```cpp
            }

            return result;
        }
};
```

8. **Return the Final Result:**
   - After the loop finishes (when \( n \) becomes 0), the final value of `result` is the value of \( x^n \mod M \).

### Example Walkthrough

Let’s walk through an example: Find \( 3^13 \mod 7 \).

- **Initial values:** 
  - \( x = 3 \)
  - \( n = 13 \)
  - \( M = 7 \)
  - \( result = 1 \)

#### Step-by-Step Calculation:

- **First iteration:**
  - \( n = 13 \) (odd), so \( result = (result \times x) \% M = (1 \times 3) \% 7 = 3 \)
  - Square \( x: x = (x \times x) \% M = (3 \times 3) \% 7 = 9 \% 7 = 2 \)
  - Right shift \( n: n = n >> 1 = 13 >> 1 = 6 \)

- **Second iteration:**
  - \( n = 6 \) (even), so we don’t change `result`.
  - Square \( x: x = (x \times x) \% M = (2 \times 2) \% 7 = 4 \)
  - Right shift \( n: n = n >> 1 = 6 >> 1 = 3 \)

- **Third iteration:**
  - \( n = 3 \) (odd), so \( result = (result \times x) \% M = (3 \times 4) \% 7 = 12 \% 7 = 5 \)
  - Square \( x: x = (x \times x) \% M = (4 \times 4) \% 7 = 16 \% 7 = 2 \)
  - Right shift \( n: n = n >> 1 = 3 >> 1 = 1 \)

- **Fourth iteration:**
  - \( n = 1 \) (odd), so \( result = (result \times x) \% M = (5 \times 2) \% 7 = 10 \% 7 = 3 \)
  - Square \( x: x = (x \times x) \% M = (2 \times 2) \% 7 = 4 \)
  - Right shift \( n: n = n >> 1 = 1 >> 1 = 0 \)

- **Final result:** 
  - The loop ends because \( n = 0 \).
  - The result is 3, so \( 3^{13} \mod 7 = 3 \).

### Key Concepts

1. **Binary Exponentiation:** 
   - The algorithm breaks down the exponent \( n \) by dividing it into binary bits, allowing you to square the base \( x \) and reduce the number of multiplications.

2. **Efficiency:** 
   - Instead of performing \( n \) multiplications (as in the naive approach), the algorithm performs \( O(\log n) \) multiplications, making it much faster.

3. **Modulo Arithmetic:** 
   - Modular arithmetic ensures that the intermediate results never exceed \( M \), which helps in keeping the numbers small and avoiding overflow.

### Time Complexity

- **Time Complexity:** \( O(\log n) \) because the exponent \( n \) is halved in each iteration (right-shift operation).
- **Space Complexity:** \( O(1) \) because the algorithm uses only a few variables regardless of the input size.

### Conclusion

The code efficiently computes \( x^n \mod M \) using the method of **modular exponentiation** through binary exponentiation, squaring the base and halving the exponent at each step.
