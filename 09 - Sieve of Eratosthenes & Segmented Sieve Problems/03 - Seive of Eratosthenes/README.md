<h1 align='center'>Sieve - Of - Eratosthenes</h1>

## Problem Statement

**Problem URL :** [Sieve of Eratosthenes](https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/a86949e5-6a99-4947-8a71-6efdc6b8f972)
![image](https://github.com/user-attachments/assets/603dfe62-ea35-4e0a-a7d6-da979fc29f6c)

## Problem Solution
```cpp
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> primes(N+1, true);
        vector<int> result;
        
        primes[0] = primes[1] = false;
        
        for(int i = 2; i * i <= N; i++){
            if(primes[i]){
                
                for(int j = i*i; j <= N; j += i){
                    primes[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= N; i++){
            if(primes[i]){
                result.push_back(i);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
```

## Problem Solution Explanation
Certainly! Let's go through the code line by line with detailed explanations.

#### Class Definition

```cpp
class Solution {
public:
```

- **Class Definition**: We define a class `Solution` which contains the method `sieveOfEratosthenes`.

#### Method: `sieveOfEratosthenes`

```cpp
vector<int> sieveOfEratosthenes(int N) {
```

- **Method Declaration**: `sieveOfEratosthenes` is a method that takes an integer \( N \) and returns a vector of integers containing all prime numbers less than or equal to \( N \).

```cpp
vector<int> primes(N + 1, true);  // Step 1
```

- **Initialization of `primes` Vector**: Creates a boolean vector `primes` of size \( N + 1 \) (index 0 to \( N \)) initialized to `true`. This vector will be used to mark whether each number is prime.

```cpp
vector<int> result;  // Step 2
```

- **Initialization of `result` Vector**: Creates an empty vector `result` to store the prime numbers that will be found.

```cpp
primes[0] = primes[1] = false;  // Step 3
```

- **Marking Non-Primes**: Sets `primes[0]` and `primes[1]` to `false` because 0 and 1 are not prime numbers.

```cpp
for (int i = 2; i * i <= N; i++) {  // Step 4
```

- **Outer Loop**: Loops through each number \( i \) starting from 2 up to the square root of \( N \). We only need to check up to \( \sqrt{N} \) because a larger factor of \( N \) must be paired with a smaller factor that has already been checked.

```cpp
if (primes[i]) {  // Step 5
```

- **Check If `i` Is Prime**: If `primes[i]` is `true`, then \( i \) is a prime number.

```cpp
for (int j = i * i; j <= N; j += i) {  // Step 6
```

- **Inner Loop**: Marks all multiples of \( i \), starting from \( i \times i \), as non-prime. We start from \( i \times i \) because all smaller multiples of \( i \) will have already been marked by smaller prime factors.

```cpp
primes[j] = false;  // Step 7
```

- **Mark Non-Prime**: Sets `primes[j]` to `false`, indicating that `j` is not a prime number.

```cpp
for (int i = 2; i <= N; i++) {  // Step 8
```

- **Collecting Primes**: After marking non-prime numbers, loop through the `primes` vector to collect all numbers that are still marked as `true`.

```cpp
if (primes[i]) {  // Step 9
```

- **Check If `i` Is Still Prime**: If `primes[i]` is `true`, then \( i \) is a prime number.

```cpp
result.push_back(i);  // Step 10
```

- **Add to Result**: Adds the prime number \( i \) to the `result` vector.

```cpp
return result;  // Step 11
```

- **Return the Result**: Returns the vector `result` containing all the prime numbers up to \( N \).

#### Main Function

```cpp
int main() {
    int t;
    cin >> t;  // Step 1
```

- **Read Number of Test Cases**: Reads the integer \( t \), which denotes the number of test cases.

```cpp
while (t--) {  // Step 2
```

- **Loop Through Test Cases**: Processes each test case.

```cpp
int N;
cin >> N;  // Step 3
```

- **Read Value of \( N \)**: Reads the integer \( N \) for the current test case.

```cpp
Solution ob;  // Step 4
```

- **Create Solution Object**: Creates an instance of the `Solution` class.

```cpp
vector<int> primes = ob.sieveOfEratosthenes(N);  // Step 5
```

- **Call Method**: Calls the `sieveOfEratosthenes` method to get all primes up to \( N \).

```cpp
for (auto prime : primes) {  // Step 6
```

- **Loop Through Primes**: Loops through each prime number in the `primes` vector.

```cpp
cout << prime << " ";  // Step 7
```

- **Print Prime**: Prints each prime number followed by a space.

```cpp
cout << endl;  // Step 8
```

- **Print New Line**: Prints a newline character after all primes for the current test case.

```cpp
return 0;  // Step 9
```

- **Return from Main**: Ends the `main` function and returns 0, indicating successful execution.

### Example Execution

For the input:
```
1
30
```

The program will output:
```
2 3 5 7 11 13 17 19 23 29 
```

This shows all prime numbers up to 30.
