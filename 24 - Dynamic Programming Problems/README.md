<h1 align='center'>DYNAMIC - PROGRAMMING - PROBLEMS</h1>

Dynamic Programming (DP) is a powerful algorithmic technique used to solve optimization problems by breaking them down into smaller subproblems. DP is particularly useful when the problem involves overlapping subproblems, where the same subproblems are solved multiple times. By solving each subproblem just once and storing its solution (memoization), DP significantly reduces the computational cost and improves efficiency.

### Key Concepts:
- **Overlapping Subproblems**: When the problem can be divided into subproblems that are solved multiple times, dynamic programming ensures that each subproblem is solved once and its result is reused.
- **Optimal Substructure**: The optimal solution to the problem can be constructed from optimal solutions of its subproblems.
- **Memoization** (Top-Down): This approach involves solving a problem recursively and storing the results of subproblems to avoid redundant calculations.
- **Tabulation** (Bottom-Up): This method solves the problem iteratively by filling a table from the base case up to the final solution.

### Common Types of DP Problems:
- **1D DP**: Problems where you solve for each state of a single dimension.
- **2D DP**: Problems that involve solving for each state across two dimensions (e.g., matrix problems).
- **Knapsack Problems**: These involve optimizing a value within certain constraints, often solved using DP.
- **Sequence Alignment**: Problems related to finding the longest common subsequence, shortest path, or palindromes.

### Real-World Applications:
- **Fibonacci Sequence**: A classic example where the solution is built from previous values.
- **Shortest Path Problems**: Algorithms like Floyd-Warshall and Bellman-Ford are used in dynamic programming for finding shortest paths.
- **Resource Allocation Problems**: Problems like knapsack and coin change fall under this category.

In this repository, you will find a variety of dynamic programming problems ranging from simple to complex, demonstrating how DP can be applied to different types of challenges. The problems are designed to enhance your understanding and provide you with the tools needed to approach optimization problems efficiently.


## Repository Content

<p>
<img src="https://img.shields.io/badge/problems%20count-30-orange?logo=leetcode" alt="LeetCode">
<img src="https://img.shields.io/badge/problems%20count-16-darkgreen?logo=geeksforGeeks" alt="GeeksforGeeks">
<img src="https://img.shields.io/badge/total%20problems%20count-40-blue" alt="Problem Count"> 
</p>

| No | Problem Name | Description | LeetCode | GFG |
|----|--------------|-------------|----------|-----|
| 01 | [Example - Nth Fibonacci Number](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/01%20-%20Example%20%7C%20Nth%20Fibonacci%20Number) | Calculate the Nth Fibonacci number using dynamic programming. | Non | [Link](https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card) |
| 02 | [Min Cost Climbing Stairs](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/02%20-%20Min%20Cost%20Climbing%20Stairs) | Find the minimum cost to reach the top of the stairs. | [Link](https://leetcode.com/problems/min-cost-climbing-stairs/description/) | Non |
| 03 | [Climbing Stairs](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/03%20-%20Climbing%20Stairs) | Calculate the number of ways to climb a given number of stairs. | [Link](https://leetcode.com/problems/climbing-stairs/description/) | Non |
| 04 | [Ways to Reach the N'th Stair](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/04%20-%20Ways%20to%20Reach%20the%20N'th%20Stair) | Determine the number of ways to reach the Nth stair. | Non | [Link](https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1) |
| 05 | [Coin Change](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/05%20-%20Coin%20Change) | Find the minimum number of coins needed to make a certain amount. | [Link](https://leetcode.com/problems/coin-change/description/) | Non |
| 06 | [Max Sum without Adjacents](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/06%20-%20Max%20Sum%20without%20Adjacents) | Calculate the maximum sum of non-adjacent elements. | Non | [Link](https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1) |
| 07 | [House Robber](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/07%20-%20House%20Robber) | Determine the maximum amount of money you can rob without robbing adjacent houses. | [Link](https://leetcode.com/problems/house-robber/description/) | Non |
| 08 | [Maximum The Cut Segments](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/08%20-%20Maximum%20The%20Cut%20Segments) | Maximize the number of segments of given lengths that can be cut from a rod. | Non | [Link](https://www.geeksforgeeks.org/problems/cutted-segments1642/1) |
| 09 | [Dis-arrangement of Balls](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/09%20-%20Dis-arrangement%20of%20Balls) | Find the number of ways to disarrange a set of balls. | Non | [Link](https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card) |
| 10 | [Painting the Fence](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/10%20-%20Painting%20the%20Fence) | Determine the number of ways to paint a fence with given constraints. | Non | [Link](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1) |
| 11 | [0-1 Knapsack Problem](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/11%20-%200-1%20Knapsack%20Problem) | Solve the 0-1 knapsack problem using dynamic programming. | Non | [Link](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card) |
| 12 | [Combination Sum IV](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/12%20-%20Combination%20Sum%20IV) | Find the number of combinations that add up to a target sum. | [Link](https://leetcode.com/problems/combination-sum-iv/description/) | [Link](https://www.geeksforgeeks.org/problems/4-combination-sum/1) |
| 13 | [Perfect Squares](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/13%20-%20Perfect%20Squares) | Determine the least number of perfect square numbers that sum up to a given number. | [Link](https://leetcode.com/problems/perfect-squares/description/) | [Link](https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1) |
| 14 | [Minimum Cost for Tickets](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/14%20-%20Minimum%20Cost%20for%20Tickets) | Calculate the minimum cost of tickets for a given period. | [Link](https://leetcode.com/problems/minimum-cost-for-tickets/description/) | Non |
| 15 | [Largest Square Formed in a Matrix](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/15%20-%20Largest%20Square%20Formed%20in%20a%20Matrix) | Find the largest square of 1's formed in a binary matrix. | [Link](https://leetcode.com/problems/maximal-square/) | [Link](https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1) |
| 16 | [Minimum Score Triangulation of Polygon](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/16%20-%20Minimum%20Score%20Triangulation%20of%20Polygon) | Minimize the score of triangulation of a polygon. | [Link](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/) | Non |
| 17 | [Minimum Sideway Jumps](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/17%20-%20Minimum%20Sideway%20Jumps) | Find the minimum number of sideway jumps needed to reach the end. | [Link](https://leetcode.com/problems/minimum-sideway-jumps/description/) | Non |
| 18 | [Reducing Dishes](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/18%20-%20Reducing%20Dishes) | Maximize the sum of satisfaction of dishes. | [Link](https://leetcode.com/problems/reducing-dishes/description/) | Non |
| 19 | [Longest Increasing Subsequence](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/19%20-%20Longest%20Increasing%20Subsequence) | Find the longest increasing subsequence in an array. | [Link](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [Link](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card) |
| 20 | [Russian Doll Envelopes](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/20%20-%20Russian%20Doll%20Envelopes) | Determine the maximum number of envelopes you can nest. | [Link](https://leetcode.com/problems/russian-doll-envelopes/description/) | Non |
| 21 | [Maximum Height by Stacking Cuboids](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/21%20-%20Maximum%20Height%20by%20Stacking%20Cuboids) | Find the maximum height by stacking cuboids. | [Link](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/) | Non |
| 22 | [Pizza with 3n Slices](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/22%20-%20Pizza%20with%203n%20Slices) | Maximize the sum of selected slices from a circular pizza. | [Link](https://leetcode.com/problems/pizza-with-3n-slices/description/) | Non |
| 23 | [Number of Dice Rolls With Target Sum](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/23%20-%20Number%20of%20Dice%20Rolls%20With%20Target%20Sum) | Find the number of ways to get a target sum with a given number of dice rolls. | [Link](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/) | Non |
| 24 | [Partition Equal Subset Sum](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/24%20-%20Partition%20Equal%20Subset%20Sum) | Determine if the array can be partitioned into two subsets with equal sum. | [Link](https://leetcode.com/problems/partition-equal-subset-sum/description/) | [Link](https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1) |
| 25 | [Minimum Swaps To Make Sequences Increasing](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/25%20-%20Minimum%20Swaps%20To%20Make%20Sequences%20Increasing) | Find the minimum number of swaps to make two sequences increasing. | [Link](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/) | Non |
| 26 | [Longest Arithmetic Subsequence](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/26%20-%20Longest%20Arithmetic%20Subsequence) | Find the longest arithmetic subsequence in an array. | [Link](https://leetcode.com/problems/longest-arithmetic-subsequence/description/) | [Link](https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1) |
| 27 | [Longest Arithmetic Subsequence of Given Difference](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/27%20-%20Longest%20Arithmetic%20Subsequence%20of%20Given%20Difference) | Find the longest arithmetic subsequence with a given difference. | [Link](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/) | Non |
| 28 | [Unique Binary Search Trees](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/28%20-%20Unique%20Binary%20Search%20Trees) | Calculate the number of unique binary search trees that can be formed with a given number of nodes. | [Link](https://leetcode.com/problems/unique-binary-search-trees/description/) | [Link](https://www.geeksforgeeks.org/problems/unique-bsts-1587115621/1) |
| 29 | [Guess Number Higher or Lower II](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/29%20-%20Guess%20Number%20Higher%20or%20Lower%20II) | Minimize the maximum loss in a number guessing game. | [Link](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/) | Non |
| 30 | [Minimum Cost Tree From Leaf Values](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/30%20-%20Minimum%20Cost%20Tree%20From%20Leaf%20Values) | Find the minimum cost to build a tree from leaf values. | [Link](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/) | Non |
| 31 | [Best Time to Buy and Sell Stock](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/31%20-%20Best%20Time%20to%20Buy%20and%20Sell%20Stock) | Determine the best time to buy and sell stock to maximize profit. | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) | Non |
| 32 | [Best Time To Buy and Sell Stock II](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/32%20-%20Best%20Time%20To%20Buy%20and%20Sell%20Stock%20II) | Maximize profit by buying and selling stock multiple times. | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/) | Non |
| 33 | [Best Time To Buy and Sell Stock III](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/33%20-%20Best%20Time%20To%20Buy%20and%20Sell%20Stock%20III) | Maximize profit with at most three transactions. | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/) | Non |
| 34 | [Best Time To Buy and Sell Stock IV](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/34%20-%20Best%20Time%20To%20Buy%20and%20Sell%20Stock%20IV) | Maximize profit with at most k transactions. | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/) | Non |
| 35 | [Best Time To Buy and Sell Stock with Transaction Fee](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/35%20-%20Best%20Time%20To%20Buy%20and%20Sell%20Stock%20with%20Transaction%20Fee) | Maximize profit considering transaction fees. | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | Non |
| 36 | [Longest Common Subsequence](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/36%20-%20Longest%20Common%20Subsequence) | Find the longest common subsequence between two strings. | [Link](https://leetcode.com/problems/longest-common-subsequence/description/) | Non |
| 37 | [Longest Palindromic Subsequence](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/37%20-%20Longest%20Palindromic%20Subsequence) | Find the longest palindromic subsequence in a string. | [Link](https://leetcode.com/problems/longest-palindromic-subsequence/description/) | Non |
| 38 | [Edit Distance](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/38%20-%20Edit%20Distance) | Calculate the minimum number of operations required to convert one string to another. | [Link](https://leetcode.com/problems/edit-distance/description/) | Non |
| 39 | [Max Rectangle](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/39%20-%20Max%20Rectangle) | Find the maximum rectangle of 1's in a binary matrix. | Non | [Link](https://www.geeksforgeeks.org/problems/max-rectangle/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card) |
| 40 | [Wildcard Matching](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/24%20-%20Dynamic%20Programming%20Problems/40%20-%20Wildcard%20Matching) | Implement wildcard pattern matching with support for '?' and '*'. | [Link](https://leetcode.com/problems/wildcard-matching/description/) | [Link](https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1) |

---
Happy Coding! 😊