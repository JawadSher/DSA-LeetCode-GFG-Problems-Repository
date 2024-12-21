<h1 align="center">Fractional - Knapsack</h1>

## Problem Statement

**Problem URL :** [Fractional Knapsack](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/fb79717a-26f3-4381-af40-9771c1429716)

### Problem Explanation
The problem you're referring to is the **Fractional Knapsack Problem**, which is a classic problem in optimization. Here, you are given a knapsack with a certain capacity and a set of items. Each item has a value and a weight. The goal is to maximize the total value in the knapsack without exceeding its capacity.

**Key points:**
- You can take fractions of items (i.e., you don’t have to take the whole item if it exceeds the remaining capacity).
- The challenge is to maximize the total value without exceeding the knapsack’s capacity.

### Problem Description:
You are given:
1. A list of `n` items, each with a `value[i]` and `weight[i]`.
2. A `capacity` of the knapsack.
  
You are required to fill the knapsack in such a way that the **total value is maximized**, while not exceeding the knapsack’s capacity. You can take fractions of the items if necessary.

### Example:
**Input:**
- `value[] = {60, 100, 120}`
- `weight[] = {10, 20, 30}`
- `capacity = 50`

**Steps to solve the problem:**
1. First, calculate the **value per unit weight** for each item:
   - Item 1: ( frac{60}{10} = 6 )
   - Item 2: ( frac{100}{20} = 5 )
   - Item 3: ( frac{120}{30} = 4 )

2. Sort the items by **value per unit weight** in descending order:
   - Sorted order: Item 1 → Item 2 → Item 3

3. Fill the knapsack with items in this sorted order, and take fractions as needed:
   - First, take the full Item 1 (weight = 10, value = 60). Remaining capacity = 50 - 10 = 40.
   - Next, take the full Item 2 (weight = 20, value = 100). Remaining capacity = 40 - 20 = 20.
   - Finally, take a fraction of Item 3 (weight = 20, value = 120). We can take only 20 units from this item, which gives a fraction of ( frac{20}{30} times 120 = 80 ).

4. The total value of the knapsack is ( 60 + 100 + 80 = 240 ).

**Output:** The maximum value that can be obtained is 240.

### Greedy Approach (Step by Step):

The **Greedy Approach** for solving the Fractional Knapsack Problem can be summarized in the following steps. Let’s break down the greedy approach used in the code you previously shared:

### 1. **Calculate Value per Unit Weight:**
For each item, calculate the value-to-weight ratio. This ratio helps determine the **"value density"** of the item (how much value we get per unit of weight).

For item (i):
`
{value per unit weight} = frac{{value}[i]}{{weight}[i]}
`

**Example:**
```cpp
val = [60, 100, 120`wt = [10, 20, 30
````
For each item:
- Item 1: ( frac{60}{10} = 6.0 )
- Item 2: ( frac{100}{20} = 5.0 )
- Item 3: ( frac{120}{30} = 4.0 )

### 2. **Sort Items by Value per Unit Weight:**
Sort the items in descending order based on their value per unit weight. This ensures that we prioritize the most valuable items (i.e., those that give the most value per unit weight).

Sorted items by value per unit weight:
- Item 1 (6.0)
- Item 2 (5.0)
- Item 3 (4.0)

### 3. **Greedily Select Items:**
Start filling the knapsack from the sorted list, taking items in the order of highest value per unit weight.

#### **a. Take Full Items (if capacity allows):**
If the knapsack has enough capacity to accommodate the current item, take the full item, and reduce the remaining capacity accordingly.

#### **b. Take Fraction of Item (if capacity doesn’t allow):**
If the knapsack doesn’t have enough capacity to take the full item, take the fraction of the item that can fit in the remaining capacity. The value added will be proportional to the weight that we take.

For each item, we:
- If the item’s weight is less than or equal to the remaining capacity, we add the full value of the item.
- If the item’s weight is greater than the remaining capacity, we add the fractional value based on the remaining capacity.

### 4. **Return the Total Value:**
Once the knapsack is filled, return the total value accumulated.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to solve the Fractional Knapsack problem
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Create a vector to store pairs where each pair consists of the per unit value
        // and the corresponding (value, weight) pair for each item
        vector<pair<double, pair<int, int>>> v;
        
        // Step 1: Calculate the per unit value (value/weight) for each item and store it
        for(int i = 0; i < val.size(); i++){
            double perUnitValue = 1.0 * val[i] / wt[i];  // Calculate per unit value for the item
            v.push_back({perUnitValue, {val[i], wt[i]}});  // Store the per unit value along with the (value, weight) pair
        }
        
        // Step 2: Sort the vector 'v' in decreasing order based on per unit value
        sort(v.begin(), v.end(), [](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b){
            return a.first > b.first;  // Comparator to sort by per unit value in descending order
        });
        
        // Step 3: Initialize the total value of the knapsack to 0
        double totalValue = 0.0;

        // Step 4: Start filling the knapsack
        for(int i = 0; i < val.size(); i++){
            int currentWeight = v[i].second.second;  // Get the weight of the current item
            int currentValue = v[i].second.first;  // Get the value of the current item
            double perUnitValue = v[i].first;      // Get the per unit value of the current item
            
            // Step 5: Check if the current item can be fully added to the knapsack
            if(capacity >= currentWeight) {
                totalValue += currentValue;  // Add the full value of the item
                capacity -= currentWeight;   // Decrease the remaining capacity of the knapsack
            } else {
                // If the current item cannot be fully added, add the fractional part of it
                totalValue += capacity * perUnitValue;  // Add the value for the fractional weight
                break;  // Once the knapsack is full, break out of the loop
            }
        }
        
        // Step 6: Return the total value of the knapsack
        return totalValue;
    }
};

```

## Problem Solution Explanation
#### **Step 1: Initialize a vector `v`**
```cpp
vector<pair<double, pair<int, int>>> v;
```
- **Purpose**: `v` is a vector of pairs where each element is a pair of:
  - `double`: the per unit value (value/weight) of an item.
  - `pair<int, int>`: contains the value and weight of the item.

#### **Step 2: Calculate the per unit value for each item**
```cpp
for(int i = 0; i < val.size(); i++){
    double perUnitValue = 1.0 * val[i] / wt[i];  // Calculate per unit value for the item
    v.push_back({perUnitValue, {val[i], wt[i]}});  // Store the per unit value along with the (value, weight) pair
}
```
- **Purpose**: This loop calculates the **value per unit weight** for each item.
  - For each item, `perUnitValue` is calculated as the value of the item divided by its weight (`val[i] / wt[i]`).
  - The pair is then pushed into the vector `v` with the first element as the per unit value and the second element as the pair `(value, weight)`.

**Example**:
Let’s assume we have:

```cpp
val = [60, 100, 120`wt = [10, 20, 30
````
For each item, the per unit value would be:
- Item 1: ( frac{60}{10} = 6.0 )
- Item 2: ( frac{100}{20} = 5.0 )
- Item 3: ( frac{120}{30} = 4.0 )

`v` will look like this after the loop:

```cpp
v = [(6.0, (60, 10)), (5.0, (100, 20)), (4.0, (120, 30))
````

#### **Step 3: Sort items by per unit value in descending order**
```cpp
sort(v.begin(), v.end(), [](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b){
    return a.first > b.first;  // Comparator to sort by per unit value in descending order
});
```
- **Purpose**: Sort the vector `v` in **descending order** of the per unit value. This ensures that we first consider the most valuable items (items that give the most value per unit of weight).
  - A lambda function is used as the comparator to sort by the first element of each pair (`a.first > b.first`), which is the per unit value.

**Example**:
After sorting, `v` will look like this:
```cpp
v = [(6.0, (60, 10)), (5.0, (100, 20)), (4.0, (120, 30))
````

#### **Step 4: Initialize the total value of the knapsack**
```cpp
double totalValue = 0.0;
```
- **Purpose**: Initialize `totalValue` to 0. This variable will store the accumulated value of the items placed in the knapsack.

#### **Step 5: Start filling the knapsack**
```cpp
for(int i = 0; i < val.size(); i++){
    int currentWeight = v[i].second.second;  // Get the weight of the current item
    int currentValue = v[i].second.first;  // Get the value of the current item
    double perUnitValue = v[i].first;      // Get the per unit value of the current item
```
- **Purpose**: Iterate through each item in the sorted vector `v`. For each item, extract the weight (`currentWeight`), value (`currentValue`), and per unit value (`perUnitValue`).

**Example**:
- For the first item in the sorted vector `v`:
  - `currentWeight = 10`, `currentValue = 60`, `perUnitValue = 6.0`.

#### **Step 6: Add items to the knapsack**
```cpp
if(capacity >= currentWeight) {
    totalValue += currentValue;  // Add the full value of the item
    capacity -= currentWeight;   // Decrease the remaining capacity of the knapsack
} else {
    // If the current item cannot be fully added, add the fractional part of it
    totalValue += capacity * perUnitValue;  // Add the value for the fractional weight
    break;  // Once the knapsack is full, break out of the loop
}
```
- **Purpose**: Check if the current item can be fully added to the knapsack based on the remaining capacity:
  - If the current item’s weight is less than or equal to the remaining capacity of the knapsack, add the full value of the item and update the remaining capacity.
  - If the item’s weight is more than the remaining capacity, add only the fractional value (based on how much of the item can fit) and then stop since the knapsack is full.

**Example**:
Let’s assume the capacity of the knapsack is 50.
- For the first item (weight = 10, value = 60), we can add the full item:
  - `totalValue += 60`, and `capacity -= 10` → `totalValue = 60`, `capacity = 40`.
- For the second item (weight = 20, value = 100), we can add the full item:
  - `totalValue += 100`, and `capacity -= 20` → `totalValue = 160`, `capacity = 20`.
- For the third item (weight = 30, value = 120), we can add only a fraction (capacity = 20):
  - `totalValue += 20 * 4.0 = 80`, and the knapsack is full (`capacity = 0`).

#### **Step 7: Return the total value**
```cpp
return totalValue;
```
- **Purpose**: Return the total accumulated value of the items in the knapsack.

### Time Complexity:
- **Sorting the vector** takes (O(n log n)), where (n) is the number of items.
- **Iterating through the items** takes (O(n)).
Thus, the overall time complexity is dominated by the sorting step, so the time complexity is **(O(n log n))**.

### Space Complexity:
- The space complexity is (O(n)) because we store the items and their per unit values in the vector `v`.
