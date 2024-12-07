<h1 align="center">Painting - The Fence</h1>

## Problem Statement

**Problem URL :** [Painting the Fence](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

![image](https://github.com/user-attachments/assets/14d11f15-2a03-470f-9395-2cee54e1486e)

### Problem Explanation

The problem asks us to calculate the number of ways to paint a fence with `n` posts and `k` available colors, subject to the constraint that **no more than two consecutive posts can be painted with the same color**.

- **Inputs:**
  - `n`: The number of posts in the fence. The value of `n` can range from 1 to 300.
  - `k`: The number of available colors for painting the posts. The value of `k` can range from 1 to 100,000.

- **Outputs:**
  - The output is the number of valid ways to paint the fence with `n` posts, using `k` colors, such that **no more than two consecutive posts are painted with the same color**.

- **Constraint:**
  - No more than two consecutive posts should have the same color.

### Problem Clarification:

You are asked to determine how many valid ways you can color the fence. This means that you need to compute the number of different ways you can assign colors to the posts while respecting the condition that **at no point should more than two consecutive posts have the same color**.

### Key Points:

1. **Valid Painting:**  
   If you paint a post with a certain color, the following post can either be:
   - Painted the same color as the previous post (but this can only be done for two consecutive posts, not more).
   - Painted a different color from the previous post.

2. **Invalid Painting:**  
   It is **invalid** if:
   - Three consecutive posts are painted with the same color.

### Example 1:

**Input:**
- `n = 3`
- `k = 2`

**Explanation:**
- You have 3 posts, and 2 colors to use. The valid ways to paint the posts are:

1. **RRB**: The first two posts are painted with color R, and the third post is painted with color B.
2. **RBR**: The first and third posts are painted with color R, and the second post is painted with color B.
3. **RBB**: The first post is painted with color R, and the second and third posts are painted with color B.
4. **BRR**: The first post is painted with color B, and the second and third posts are painted with color R.
5. **BRB**: The first and third posts are painted with color B, and the second post is painted with color R.
6. **BBR**: The first two posts are painted with color B, and the third post is painted with color R.

Thus, the total number of valid ways to paint the fence is **6**.

**Output:**
- `6`


### Example 2:

**Input:**
- `n = 2`
- `k = 4`

**Explanation:**
- You have 2 posts, and 4 colors to use. The valid ways to paint the posts are:

- For the first post, you can choose any of the 4 colors.
- For the second post, you can again choose any of the 4 colors, since there are no restrictions on having two consecutive posts painted the same color in this case (because we have only two posts).

So the total number of valid ways to paint the fence is **4 × 4 = 16**.

**Output:**
- `16`

### Constraints to Note:

- **At least 1 post (`n ≥ 1`) and at least 1 color (`k ≥ 1`)**: This ensures the problem is always solvable as long as there is at least one post and one color available.
- **No more than two consecutive posts can have the same color**: This restricts how the colors can be used for the posts. It enforces a limit on how we assign colors for the posts.


#### Conditions:
- **n**: Number of posts (1 ≤ n ≤ 300)
- **k**: Number of colors available (1 ≤ k ≤ 10^5)
- The goal is to calculate the number of valid ways to paint the fence, ensuring that no three consecutive posts are painted with the same color.

### Solution Strategy:

The key observation here is that for any post `n`, there are two possible cases for the last two posts:

1. **Last two posts are the same color**: In this case, the `(n-1)`th post and `n`th post must be the same color. To calculate this, we look at the possible ways to paint the first `n-2` posts and then choose a color for the `(n-1)`th and `n`th posts from `k-1` colors (since it must differ from the `(n-2)`th post).
   
2. **Last two posts are different colors**: Here, the `(n-1)`th post and `n`th post must be different. We calculate how to paint the first `n-1` posts and then choose a color for the `n`th post from `k-1` options (since it must differ from the `(n-1)`th post).

### Formula Used:
To find the number of ways to paint the fence for `n` posts, we use the following recursive formula:

`f(n) = f(n-1) * (k-1) + f(n-2) * (k-1)`

- **f(n-1) * (k-1)**: This is the case where the last two posts are **different colors**.
- **f(n-2) * (k-1)**: This is the case where the last two posts are **the same color**.

### Explanation of the Formula:

1. **f(n-2) * (k-1)**: 
   - We are considering the situation where the last two posts are the **same color**. To do this, you first calculate the number of ways to paint the first `n-2` posts. Then, you choose a color for the last two posts from `k-1` available colors (since it cannot be the same as the color of the `n-2`th post).

2. **f(n-1) * (k-1)**: 
   - This case considers the situation where the last two posts are **different colors**. To do this, you first calculate the number of ways to paint the first `n-1` posts, and then choose a color for the `n`th post from `k-1` available colors (since it must be different from the color of the `(n-1)`th post).

### Examples:

#### Example 1: n = 3, k = 2 (2 Colors, 3 Posts)
- **f(3) = f(2) * (k-1) + f(1) * (k-1)**
  - **f(1)**: 2 ways to paint one post (either color 1 or color 2).
  - **f(2)**: 4 ways to paint two posts (RR, RB, BR, BB).
  
  `f(3) = f(2) * 1 + f(1) * 1 = 4 * 1 + 2 * 1 = 6`

- **Answer**: There are 6 ways to paint 3 posts with 2 colors (RRB, RBR, RBB, BRR, BRB, BBR).



#### Example 2: n = 4, k = 3 (3 Colors, 4 Posts)

- **f(4) = f(3) * (k-1) + f(2) * (k-1)**
  - **f(3)**: 18 ways to paint three posts.
  - **f(2)**: 9 ways to paint two posts.
  
 `f(4) = f(3) * 2 + f(2) * 2 = 18 * 2 + 9 * 2 = 54`

- **Answer**: There are 54 ways to paint 4 posts with 3 colors.



#### Example 3: n = 5, k = 3 (3 Colors, 5 Posts)

- **f(5) = f(4) * (k-1) + f(3) * (k-1)**
  - **f(4)**: 54 ways to paint four posts.
  - **f(3)**: 18 ways to paint three posts.
  
  `f(5) = f(4) * 2 + f(3) * 2 = 54 * 2 + 18 * 2 = 144`

- **Answer**: There are 144 ways to paint 5 posts with 3 colors.


### Key Takeaways:
1. **Same Color for the Last Two Posts**: This case is calculated using `f(n-2) * (k-1)` because we look at how to paint the first `n-2` posts, then select a color for the last two posts.
   
2. **Different Colors for the Last Two Posts**: This case is calculated using `f(n-1) * (k-1)` because we calculate the number of ways to paint the first `n-1` posts, then choose a color for the `n`th post that is different from the `(n-1)`th post.

By using this recursive approach, you can compute the number of ways to paint the fence for any number of posts `n` and colors `k`, without violating the rule of having no more than two consecutive posts of the same color.


This approach is **space-efficient** because we don't need to store all the values for every post from 1 to `n`, but only the last two values (`f(n-1)` and `f(n-2)`) at each step.

### Summary:
- The problem is to determine the number of valid ways to paint a fence with `n` posts using `k` colors, with the condition that no more than two consecutive posts can have the same color.
- This problem involves combinatorial thinking and dynamic programming approaches to keep track of the different valid configurations.

---

## Recursive Approach (caused TLE)
This problem involves calculating the number of ways to paint a fence with `n` posts and `k` colors such that no more than two consecutive posts have the same color.

#### Recursive Breakdown:
1. **Base Case 1**: When there is only 1 post (`n = 1`), you can paint it using any of the `k` colors. So, the answer is `k`.
2. **Base Case 2**: When there are 2 posts (`n = 2`), you can paint them in two ways:
   - Both posts have the same color, or
   - Both posts have different colors.
   The number of ways to paint two posts is the sum of these two possibilities:
   - The first post has `k` colors, and the second post has `(k-1)` colors (to avoid using the same color as the first post).
   
   Thus, the total ways to paint 2 posts is:  
 `f(2) = k + (k * (k-1))`
3. **Recursive Case**: For `n > 2`:
   - The first two posts can be painted in one of two ways:
     1. **Same Color for the Last Two Posts**: The first `n-2` posts can be painted in `f(n-2)` ways, and the last two posts will use any color except the one used for the `(n-2)`th post, giving `(k-1)` choices for the last two posts.
     2. **Different Colors for the Last Two Posts**: The first `n-1` posts can be painted in `f(n-1)` ways, and the last post can have any color except the one used for the `(n-1)`th post, giving `(k-1)` choices for the last post.
     
   The total ways to paint `n` posts can be calculated as:
   ` f(n) = f(n-1) * (k-1) + f(n-2) * (k-1`


### Source Code

```cpp
class Solution {
  public:
    // Helper function to add two numbers
    int add(int a, int b){
        return (a + b);  // returns the sum of a and b
    }
    
    // Helper function to multiply two numbers
    int multi(int a, int b){
        return (a * b);  // returns the product of a and b
    }
    
    // Recursive function to calculate the number of ways to paint the fence
    int solve(int n, int k){
        // Base case: If there's only one post, there are k ways to paint it
        if(n == 1) return k;
        
        // Base case: If there are two posts, there are k + k*(k-1) ways to paint them
        if(n == 2) return add(k, multi(k, k-1));
        
        // Recursive case: Calculate the number of ways for n posts
        // The formula f(n) = f(n-1)*(k-1) + f(n-2)*(k-1)
        int ans = add(multi(solve(n-2, k), k-1), multi(solve(n-1, k), k-1));
        return ans;  // return the final result
    }

    // Public function to start the computation for countWays
    int countWays(int n, int k) {
        return solve(n, k);  // calls the solve function to calculate the number of ways
    }
};
```
### Source Code Explanation

```cpp
class Solution {
```
- Declares a class named `Solution`. The class will contain the functions used to solve the problem of counting ways to paint the fence.

#### Method to Add Two Numbers:

```cpp
    int add(int a, int b){
        return (a + b);
    }
```
- This method, `add()`, takes two integers `a` and `b` as inputs and returns their sum. It is used to perform addition in later calculations.

#### Method to Multiply Two Numbers:

```cpp
    int multi(int a, int b){
        return (a * b);
    }
```
- This method, `multi()`, takes two integers `a` and `b` as inputs and returns their product. It is used to multiply values in the recursive calculations.

#### Recursive Solve Method:

```cpp
    int solve(int n, int k){
```
- This is a recursive function `solve()` that calculates the number of ways to paint `n` posts using `k` colors.
- The function takes two parameters: `n` (the number of posts) and `k` (the number of colors).

##### Base Case for `n == 1`:

```cpp
        if(n == 1) return k;
```
- If there is only 1 post (`n == 1`), you can paint it in any of the `k` colors. Hence, the function directly returns `k`.

##### Base Case for `n == 2`:

```cpp
        if(n == 2) return add(k, multi(k, k-1));
```
- If there are 2 posts (`n == 2`), the function calculates:
  - The first post can be painted in `k` ways.
  - The second post must have a different color, so it can be painted in `k-1` ways.
- The result is `k + k*(k-1)`, which is calculated using the `add()` and `multi()` methods.

##### Recursive Case for `n > 2`:

```cpp
        int ans = add(multi(solve(n-2, k), k-1), multi(solve(n-1, k), k-1));
```
- For `n > 2`, the function recursively computes the number of ways to paint the fence:
  - **Case 1 (Same Color for Last Two Posts)**: `solve(n-2, k)` gives the number of ways to paint the first `n-2` posts. The last two posts must be painted the same color, so there are `k-1` choices for the second post.
  - **Case 2 (Different Colors for Last Two Posts)**: `solve(n-1, k)` gives the number of ways to paint the first `n-1` posts. The last post must have a different color than the previous one, so there are `k-1` choices for it.
- The results of both cases are added together using the `add()` method to get the total number of ways to paint `n` posts.

```cpp
        return ans;
    }
```
- The function returns the calculated result `ans`.

#### Public Method to Count the Ways:

```cpp
    int countWays(int n, int k) {
        return solve(n, k);
    }
```
- The `countWays()` function is the public method that calls the `solve()` function with parameters `n` (the number of posts) and `k` (the number of colors). It returns the result from `solve()`, which is the total number of ways to paint the fence.

### Example Output:

For `n = 3` and `k = 2`:

- **Base Case 1**: `solve(1, 2)` returns `2`
- **Base Case 2**: `solve(2, 2)` returns `2 + 2 * (2-1) = 4`
- **Recursive Case**: `solve(3, 2)` = `solve(2, 2) * 1 + solve(1, 2) * 1 = 4 * 1 + 2 * 1 = 6`

So, the output for `countWays(3, 2)` is `6`.

### Time and Space Complexity:

#### **Time Complexity**:
- **Time Complexity** is `O(n)`. This is because we are solving the problem recursively, and the recursive calls will calculate the result for each value of `n` once.
- Each recursive call solves the problem for smaller values of `n`, and no subproblem is recalculated.

#### **Space Complexity**:
- **Space Complexity** is `O(n)`. This is due to the recursion stack. Each recursive call adds a new frame to the stack, and the maximum depth of recursion is `n`, so the space required for the recursion stack is `O(n)`.

---

## Top-Down Approach (DP)
The problem asks for the number of ways to paint a fence with `n` posts and `k` colors such that no two adjacent posts are painted with the same color. We can use a **Top-Down dynamic programming approach** with **memoization** to solve the problem efficiently.

### Key Points:
- **Recursive Nature**: The problem has a recursive structure, where the solution to the problem of painting `n` posts can be broken down into smaller subproblems of painting `n-1` and `n-2` posts.
- **Memoization**: To avoid redundant calculations, we store the results of subproblems in a memoization array (`dp`) so that each subproblem is solved only once.

### Steps to Solve Using Top-Down Approach:

1. **Define the Base Cases**:
   - If there's only one post (`n == 1`), it can be painted in `k` ways.
   - If there are two posts (`n == 2`), they can be painted in `k * k` ways, as the first post has `k` options and the second post has `k-1` options to avoid matching the first post.

2. **Recursive Case**:
   - For `n > 2`, the number of ways to paint `n` posts can be found using the following recurrence relation:
     `D(n) = (D(n-1) * (k-1)) + (D(n-2) * (k-1))`

     Here:
     - `D(n-1) * (k-1)` represents the scenario where the last post has a different color from the previous post (i.e., the last post is painted differently from the `n-1`th post).
     - `D(n-2) * (k-1)` represents the case where the last two posts have the same color.

3. **Memoization**:
   - We use a memoization array (`dp`) to store the results of subproblems to avoid recomputation.

### Source Code
```cpp
class Solution {
  public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
    
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
    
    // Recursive function with memoization to calculate the number of ways to paint the fence
    // n: number of posts, k: number of colors, dp: memoization array
    int solve(int n, int k, vector<int>& dp){
        // Base case 1: If there is only one post, there are k ways to paint it with k colors
        if(n == 1) return k;

        // Base case 2: If there are two posts, there are k * k ways to paint them
        if(n == 2) return add(k, multi(k, k-1));
        
        // If the result for the current number of posts is already computed (cached), return it
        if(dp[n] != -1) return dp[n];
        
        // Recursive case: Use the recurrence relation to calculate the number of ways to paint n posts
        // D(n) = (D(n-1) * (k-1)) + (D(n-2) * (k-1))
        dp[n] = add(multi(solve(n-2, k, dp), k-1), multi(solve(n-1, k, dp), k-1));
        
        // Return the result for the current number of posts
        return dp[n];
    }

    // Main function to initialize the DP array and call the solve function
    int countWays(int n, int k) {
        // Create a memoization array to store the result for each number of posts (initially -1)
        vector<int> dp(n+1, -1);
        
        // Call the solve function to calculate and return the result
        return solve(n, k, dp);
    }
};
```

### Source Code Explanation
Certainly! Below is the **line-by-line explanation** of the given code:

```cpp
class Solution {
  public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
```
- **`add` function**: This is a helper function that takes two integers `a` and `b` as input, adds them, and returns their sum.

```cpp
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
```
- **`multi` function**: This is another helper function that takes two integers `a` and `b` as input, multiplies them, and returns their product.

```cpp
    // Recursive function with memoization to calculate the number of ways to paint the fence
    // n: number of posts, k: number of colors, dp: memoization array
    int solve(int n, int k, vector<int>& dp){
```
- **`solve` function**: This is the main recursive function responsible for calculating the number of ways to paint the fence with `n` posts and `k` colors. It uses a memoization array `dp` to store intermediate results and avoid redundant calculations.

```cpp
        // Base case 1: If there is only one post, there are k ways to paint it with k colors
        if(n == 1) return k;
```
- **Base case 1**: If there is only one post (`n == 1`), there are `k` ways to paint it (since there are `k` colors available). So, it directly returns `k`.

```cpp
        // Base case 2: If there are two posts, there are k * k ways to paint them
        if(n == 2) return add(k, multi(k, k-1));
```
- **Base case 2**: If there are two posts (`n == 2`), the first post can be painted in `k` ways, and the second post can be painted in `k-1` ways to ensure it's different from the first. Therefore, the result is `k + k * (k-1)`, which is computed using the helper functions `add` and `multi`.

```cpp
        // If the result for the current number of posts is already computed (cached), return it
        if(dp[n] != -1) return dp[n];
```
- **Memoization check**: If the result for `n` posts has already been computed and stored in the `dp` array (i.e., `dp[n] != -1`), the function simply returns the cached result to avoid redundant computation.

```cpp
        // Recursive case: Use the recurrence relation to calculate the number of ways to paint n posts
        // D(n) = (D(n-1) * (k-1)) + (D(n-2) * (k-1))
        dp[n] = add(multi(solve(n-2, k, dp), k-1), multi(solve(n-1, k, dp), k-1));
```
- **Recursive case**: If the result hasn't been computed yet, the function calculates the result for `n` posts using the recurrence relation:
  - `D(n) = (D(n-1) * (k-1)) + (D(n-2) * (k-1))`
  - This means that the number of ways to paint `n` posts can be computed by:
    - **`(D(n-1) * (k-1))`**: The number of ways to paint `n-1` posts and then painting the `n`th post a different color from the `n-1`th post.
    - **`(D(n-2) * (k-1))`**: The number of ways to paint `n-2` posts and then painting the last two posts with different colors.
  - The results of both cases are multiplied by `(k-1)` (since the last post cannot be the same color as the adjacent posts) and summed using the `add` function.

```cpp
        // Return the result for the current number of posts
        return dp[n];
    }
```
- After calculating the result for `n` posts, it stores the result in the `dp` array and returns it.

```cpp
    // Main function to initialize the DP array and call the solve function
    int countWays(int n, int k) {
        // Create a memoization array to store the result for each number of posts (initially -1)
        vector<int> dp(n+1, -1);
```
- **`countWays` function**: This is the main function that is called to compute the number of ways to paint the fence with `n` posts and `k` colors.
  - It initializes a memoization array `dp` of size `n+1` (to store the results for `0` to `n` posts) with all values set to `-1` (indicating that no results have been computed yet).

```cpp
        // Call the solve function to calculate and return the result
        return solve(n, k, dp);
    }
};
```
- After initializing the `dp` array, the `countWays` function calls the `solve` function to compute the result and return it.

### Example Walkthrough:

- **Example 1**: `n = 3, k = 2`
  - `solve(3, 2)` is called.
  - Base cases are handled, and for `n > 2`, the recurrence relation is applied.
  - The result will be computed using the memoization array, and the final result will be returned.

- **Example 2**: `n = 4, k = 3`
  - `solve(4, 3)` is called.
  - The recursive function calculates the ways to paint `4` posts using `3` colors.

### Time and Space Complexity:

#### Time Complexity:
- **Time Complexity**: `O(n)` because we are using memoization, and each subproblem is solved only once. Each recursive call works in constant time after the result is cached.

#### Space Complexity:
- **Space Complexity**: `O(n)` for the `dp` array used for memoization, and `O(n)` for the recursion stack (due to recursive calls).

### Conclusion:

- This **Top-Down Dynamic Programming approach** efficiently calculates the number of ways to paint the fence by recursively breaking down the problem and using memoization to avoid redundant calculations.

---

## Bottom-Up Approach (DP)
In the **bottom-up approach**, we start solving the problem from the smallest subproblems and build up to the solution of the original problem. This is done using dynamic programming (DP) by progressively solving smaller subproblems and using the results of these subproblems to solve larger ones.

Here’s how the bottom-up approach works in this problem of painting a fence with `n` posts and `k` colors:

1. **Problem Breakdown**: 
   - If we know how to paint 1 or 2 posts, we can use that knowledge to figure out how to paint more posts.
   - For `n = 1` and `n = 2`, the number of ways to paint them is straightforward.
   - For `n > 2`, the problem is solved iteratively by using the results of previous subproblems (i.e., how to paint `n-1` and `n-2` posts) and combining them to find the result for `n`.

2. **Base Cases**:
   - For `n = 1`: There are exactly `k` ways to paint a single post.
   - For `n = 2`: The number of ways to paint two posts is `k * k`. This is because the first post can be painted in `k` ways, and the second post can be painted in `k` ways as well.

3. **Recursive Formula**:
   - For `n > 2`, the number of ways to paint the fence with `n` posts (`dp[n]`) is based on the results of smaller subproblems:
     - The `n`-th post can either be painted the same color as the previous post or a different color.
     - If the `n`-th post is the same color as the `(n-1)`-th post, then the number of ways to paint the fence is the same as the number of ways to paint `n-1` posts (`dp[n-1]`).
     - If the `n`-th post is painted a different color than the `(n-1)`-th post, then the number of ways to paint the fence is based on the number of ways to paint `n-2` posts (`dp[n-2]`), since the last two posts must be painted differently.
   - The formula is: 
    `p[n] = (dp[n-1] * (k-1)) + (dp[n-2] * (k-1))`

   - The factor `(k-1)` comes from the fact that the new post must be painted in a different color from the previous one.

4. **Iterative Calculation**:
   - We calculate the number of ways for each `n` starting from `3` up to `n` using the recursive relation.
   - We use a dynamic programming array `dp[]` to store the intermediate results, which avoids redundant calculations and ensures efficient computation.

5. **Final Answer**:
   - The final result, which is the number of ways to paint `n` posts with `k` colors, will be stored in `dp[n]`.


### Source Code

```cpp
class Solution {
  public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
    
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
    
    // Function to calculate the number of ways to paint the fence with n posts and k colors
    int solve(int n, int k){
        // Initialize a dynamic programming (DP) array to store the number of ways to paint i posts
        // dp[i] will store the number of ways to paint i posts
        vector<int> dp(n+1, -1);
        
        // Base case: For 1 post, there are k ways to paint it using k colors
        dp[1] = k;
        
        // Base case: For 2 posts, there are k * k ways to paint them
        dp[2] = add(k, multi(k, k-1));
        
        // Fill the DP array iteratively for posts from 3 to n
        // Use the recurrence relation:
        // dp[i] = (dp[i-1] * (k-1)) + (dp[i-2] * (k-1))
        for(int i = 3; i <= n; i++){
            // Calculate the number of ways to paint i posts:
            dp[i] = add(multi(dp[i-2], k-1), multi(dp[i-1], k-1));
        }
        
        // Return the result for the nth post
        return dp[n];
    }
    
    // Main function to compute the number of ways to paint the fence
    int countWays(int n, int k) {
        // Call the solve function to compute the result
        return solve(n, k);
    }
};
```
### source Code Explanation

```cpp
class Solution {
  public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
```
- **Line 2-4**: This is a helper function that takes two integers `a` and `b`, adds them together, and returns the result. The function name is `add`, and it helps make the code cleaner and more modular. Instead of repeating the addition operation in the main part of the code, we use this helper function.

```cpp
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
```
- **Line 6-8**: This is another helper function, `multi`, that multiplies two integers `a` and `b` and returns their product. Similar to the `add` function, this function is used to modularize the multiplication operation.

```cpp
    // Function to calculate the number of ways to paint the fence with n posts and k colors
    int solve(int n, int k){
        // Initialize a dynamic programming (DP) array to store the number of ways to paint i posts
        // dp[i] will store the number of ways to paint i posts
        vector<int> dp(n+1, -1);
```
- **Line 10-12**: The `solve` function is the core of the dynamic programming approach. 
    - `n`: The number of posts.
    - `k`: The number of colors available.
    - A **vector** `dp[]` is initialized to store the number of ways to paint `i` posts, where `i` varies from `1` to `n`. 
    - The vector is initialized with `-1` for all positions, which acts as a placeholder to signify that those values are not yet computed. The `+1` ensures that we can use indices from `1` to `n`.

```cpp
        // Base case: For 1 post, there are k ways to paint it using k colors
        dp[1] = k;
```
- **Line 14**: This is the base case for when there's only one post (`n = 1`). There are exactly `k` ways to paint it, as any of the `k` colors can be used. So, `dp[1] = k`.

```cpp
        // Base case: For 2 posts, there are k * k ways to paint them
        dp[2] = add(k, multi(k, k-1));
```
- **Line 16**: This is the base case for when there are two posts (`n = 2`).
    - The first post can be painted in `k` ways.
    - The second post can also be painted in `k` ways, but it can either be the same color as the first post or a different color.
    - If the second post is painted a different color, there are `k-1` choices for it.
    - Thus, the total number of ways to paint two posts is:
      [
      dp[2] = k + k * (k-1)
      ]
      The result is computed by calling the helper functions: `add(k, multi(k, k-1))`. First, the product of `k` and `k-1` is computed (`multi(k, k-1)`), and then the sum with `k` is calculated (`add(k, ...)`).

```cpp
        // Fill the DP array iteratively for posts from 3 to n
        // Use the recurrence relation:
        // dp[i] = (dp[i-1] * (k-1)) + (dp[i-2] * (k-1))
        for(int i = 3; i <= n; i++){
```
- **Line 18-19**: We now start the iteration for `i = 3` to `n` to fill the `dp[]` array for the cases where there are more than two posts.
    - We will use the recurrence relation to calculate the number of ways to paint `i` posts based on the results of `i-1` and `i-2` posts.

```cpp
            // Calculate the number of ways to paint i posts:
            dp[i] = add(multi(dp[i-2], k-1), multi(dp[i-1], k-1));
```
- **Line 21**: This line applies the recurrence relation to calculate the number of ways to paint `i` posts:
    - **`dp[i-1] * (k-1)`**: This represents the case where the `i`-th post is painted a different color from the `(i-1)`-th post.
    - **`dp[i-2] * (k-1)`**: This represents the case where the `i`-th post is painted a different color from the `(i-1)`-th post and `(i-2)`-th post.
    - These two parts are added together to get the total number of ways to paint `i` posts. The result is stored in `dp[i]`.

```cpp
        }
        
        // Return the result for the nth post
        return dp[n];
    }
```
- **Line 23-25**: The loop continues for all values of `i` from 3 to `n`. After the loop finishes, `dp[n]` will contain the number of ways to paint `n` posts using `k` colors, and the function returns that value.

```cpp
    // Main function to compute the number of ways to paint the fence
    int countWays(int n, int k) {
        // Call the solve function to compute the result
        return solve(n, k);
    }
};
```
- **Line 27-30**: The `countWays` function is the main entry point for this class.
    - It takes two arguments: `n` (number of posts) and `k` (number of colors).
    - The function calls `solve(n, k)` to calculate the result and return it.

### Example Walkthrough

Let's walk through an example with `n = 3` posts and `k = 2` colors:

1. **Base Cases**:
   - For `n = 1`: 
     `dp[1] = 2`
   - For `n = 2`: 
    `dp[2] = 2 + 2 * (2-1) = 2 + 2 = 4`
  
2. **For `n = 3`**:
   - Using the recurrence relation:
     `dp[3] = (dp[2] * (2-1)) + (dp[1] * (2-1))`

   - Substituting the values:
     `dp[3] = (4 * 1) + (2 * 1) = 4 + 2 = 6`
   
   So, there are 6 ways to paint the fence with 3 posts using 2 colors.

### Time and Space Complexity

- **Time Complexity**:
  - The algorithm iterates from `i = 3` to `n`, and for each iteration, the number of ways to paint `i` posts is calculated in constant time (using the `multi` and `add` functions). Therefore, the time complexity is **O(n)**, where `n` is the number of posts.

- **Space Complexity**:
  - The space complexity is dominated by the space used for the DP array `dp[]`, which has a size of `n + 1`. Therefore, the space complexity is **O(n)**.

---

## Space Optimized Approach (DP)
In dynamic programming (DP), we typically maintain a table (`dp[]`) to store the results of subproblems. For this problem, where we are calculating the number of ways to paint a fence with `n` posts and `k` colors, a straightforward DP approach would require an array to store the results for every post. However, we can observe that the result for the `i`-th post depends only on the results of the previous two posts: `i-1` and `i-2`. This allows us to reduce the space complexity significantly.

### Optimization:
- **Original Space Complexity**: The naive DP solution would require an array `dp[]` of size `n`, so the space complexity is **O(n)**.
- **Optimized Space Complexity**: Since only the previous two values are required to compute the current value, we only need to store `prev1` and `prev2` (representing `dp[i-1]` and `dp[i-2]` respectively). This reduces the space complexity to **O(1)**, as we no longer need a full array to store intermediate results.

Thus, the space optimization technique reduces memory usage significantly while still maintaining the same time complexity.

### Source Code

```cpp
class Solution {
public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
    
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
    
    // Function to calculate the number of ways to paint the fence with n posts and k colors
    int solve(int n, int k){
        // Base case: When there is only 1 post, there are k ways to paint it with k colors
        if(n == 1) return k;

        // Base case: When there are 2 posts, there are k * k ways to paint them
        // The first post can be painted with any of the k colors, and the second post can be painted with any of the k colors
        if(n == 2) return add(k, multi(k, k-1));
        
        // Initializing the values for the first two posts (prev1 and prev2)
        int prev2 = k;  // Ways to paint the first post
        int prev1 = add(k, multi(k, k-1));  // Ways to paint two posts

        // Iteratively calculate the number of ways to paint posts from 3 to n
        for(int i = 3; i <= n; i++){
            // Calculate the number of ways to paint the i-th post:
            // - multi(prev2, k-1): the previous post (i-1) is painted with a different color
            // - multi(prev1, k-1): the current post (i) is painted with a different color from the previous post (i-1)
            int current = add(multi(prev2, k-1), multi(prev1, k-1));

            // Update the values for the next iteration:
            prev2 = prev1;  // Move prev1 to prev2
            prev1 = current;  // Move the current value to prev1
        }

        // Return the result for the nth post, which is stored in prev1
        return prev1;
    }

    // Main function to compute the number of ways to paint the fence
    int countWays(int n, int k) {
        // Call the solve function to compute the result
        return solve(n, k);
    }
};
```
### Source Code Explanation

#### 1. **Helper Function: `add`**

```cpp
int add(int a, int b){
    return (a + b);  // Returns the sum of a and b
}
```

- **Purpose**: This function is simply a helper to add two integers `a` and `b` together. It returns their sum.
- **Example**:
    - `add(3, 5)` will return `8`.

#### 2. **Helper Function: `multi`**

```cpp
int multi(int a, int b){
    return (a * b);  // Returns the product of a and b
}
```

- **Purpose**: This function is a helper to multiply two integers `a` and `b` together. It returns their product.
- **Example**:
    - `multi(3, 5)` will return `15`.

#### 3. **Function: `solve`**

```cpp
int solve(int n, int k){
```

- **Purpose**: This is the main function where the dynamic programming logic is implemented to solve the problem of calculating the number of ways to paint a fence with `n` posts and `k` colors.

##### **Base Cases**:
1. **Base Case 1** (For `n = 1`):
```cpp
if(n == 1) return k;
```
   - **Explanation**: When there is only 1 post, there are `k` possible ways to paint it since we have `k` colors to choose from.
   - **Example**: If `n = 1` and `k = 3`, the result is `3`.

2. **Base Case 2** (For `n = 2`):
```cpp
if(n == 2) return add(k, multi(k, k-1));
```
   - **Explanation**: When there are 2 posts, the first post can be painted in `k` ways (any of the `k` colors), and the second post can be painted in `k-1` ways (since it needs to be a different color from the first post). Thus, the total number of ways to paint 2 posts is `k + k * (k - 1)`.
   - **Example**: If `n = 2` and `k = 3`, the result is `3 + 3 * (3 - 1) = 3 + 6 = 9`.

##### **Initialization**:
```cpp
int prev2 = k;  // Ways to paint the first post
int prev1 = add(k, multi(k, k-1));  // Ways to paint two posts
```
   - **Explanation**:
     - `prev2 = k`: The number of ways to paint the first post (1 post) is just `k`, as we have `k` colors to choose from.
     - `prev1 = k + k * (k-1)`: The number of ways to paint two posts is calculated as `k + k * (k-1)`.

##### **Iterative Calculation for `n > 2`**:
```cpp
for(int i = 3; i <= n; i++){
    int current = add(multi(prev2, k-1), multi(prev1, k-1));
    prev2 = prev1;  // Move prev1 to prev2
    prev1 = current;  // Move the current value to prev1
}
```

   - **Explanation**:
     - We are calculating the number of ways to paint the `i`-th post iteratively from 3 to `n`.
     - For each post `i`, there are two possibilities:
       - **Case 1**: The `i`-th post is painted a different color from the `(i-1)`-th post. This contributes `multi(prev2, k-1)` to the total number of ways.
       - **Case 2**: The `i`-th post is painted a different color from the `(i-1)`-th post. This contributes `multi(prev1, k-1)` to the total number of ways.
     - The total number of ways to paint the `i`-th post is the sum of these two possibilities.
     - We then update `prev2` and `prev1` to the new values for the next iteration.

   - **Example** (for `n = 4` and `k = 3`):
     - **For i = 3**:
       - `prev2 = 3` (ways to paint 1 post).
       - `prev1 = 9` (ways to paint 2 posts).
       - Calculate `current = add(multi(3, 2), multi(9, 2)) = add(6, 18) = 24`.
     - **For i = 4**:
       - `prev2 = 9`.
       - `prev1 = 24`.
       - Calculate `current = add(multi(9, 2), multi(24, 2)) = add(18, 48) = 66`.

##### **Final Result**:
```cpp
return prev1;
```
   - **Explanation**: After iterating through all the posts from 3 to `n`, the result for `n` posts is stored in `prev1`. So, we return `prev1` as the final result.

#### 4. **Main Function: `countWays`**

```cpp
int countWays(int n, int k) {
    return solve(n, k);
}
```

- **Purpose**: This is the main function that simply calls the `solve` function to compute and return the result for `n` posts and `k` colors.

### Example Walkthrough

Let’s walk through the code with an example where `n = 4` and `k = 3`:

1. **For `n = 1`**:
   - `dp[1] = 3` (3 ways to paint 1 post with 3 colors).
   
2. **For `n = 2`**:
   - `dp[2] = k + k * (k - 1) = 3 + 3 * (3 - 1) = 3 + 6 = 9` (9 ways to paint 2 posts).

3. **For `n = 3`**:
   - Using the formula:
     `     dp[3] = (dp[2] * (k-1)) + (dp[1] * (k-1)) = (9 * 2) + (3 * 2) = 18 + 6 = 24`
   - So, `dp[3] = 24` (24 ways to paint 3 posts).

4. **For `n = 4`**:
   - Using the formula:
     `     dp[4] = (dp[3] * (k-1)) + (dp[2] * (k-1)) = (24 * 2) + (9 * 2) = 48 + 18 = 66`

   - So, `dp[4] = 66` (66 ways to paint 4 posts).

### Time and Space Complexity

- **Time Complexity**: The function iterates from 3 to `n`, so the time complexity is **O(n)**.
- **Space Complexity**: Since we are only using a few variables (`prev1` and `prev2`), the space complexity is **O(1)** (constant space).

This makes the solution efficient in both time and space.
