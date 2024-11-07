<h1 align='center'>Merge - Two - BST's</h1>

## Problem Statement

**Problem URL :** [Merge Two BST's](https://www.geeksforgeeks.org/problems/merge-two-bst-s/1)

![image](https://github.com/user-attachments/assets/68d50382-01ab-49c0-9eea-96abde6f03e4)
![image](https://github.com/user-attachments/assets/c4e873a9-430b-4ad1-b643-aaf80c7ab99e)

## Problem Explanation
**Detailed Explanation of Problem Statement:**

You are given two binary search trees (BSTs). A BST is a tree data structure where, for each node:
- All values in the left subtree are less than the node’s value.
- All values in the right subtree are greater than the node’s value.

The task is to merge these two BSTs into a single sorted list. Specifically:
1. We need to extract the elements from both BSTs.
2. We must return a sorted list that contains all elements from both trees.

**Example:**
Imagine two BSTs:
- BST1: 1, 3, 5 (In-order traversal gives `[1, 3, 5]`)
- BST2: 2, 4, 6 (In-order traversal gives `[2, 4, 6]`)

The merged output should be a single sorted list: `[1, 2, 3, 4, 5, 6]`.



### Approach to Solve the Problem

**Step-by-Step Approach for Beginners:**

1. **Understand the Structure of BSTs**: Since we’re dealing with BSTs, remember that an in-order traversal of a BST (left-root-right) will give us a sorted list of elements.

2. **In-Order Traversal for Sorted Lists**:
   - Perform an in-order traversal on each BST. This will produce two sorted lists, one for each tree.
   - Store the results of each traversal in separate arrays (`bst1` and `bst2`).

3. **Merge Two Sorted Lists**:
   - Once you have two sorted arrays from both BSTs, the next task is to merge these arrays.
   - Use a technique similar to the "merge" step in merge sort to combine these two arrays into a single sorted list.

4. **Return the Merged List**:
   - Finally, return this merged list, which will have all elements from both BSTs in sorted order.

This approach leverages the fact that an in-order traversal of a BST yields a sorted sequence, and merging two sorted sequences can be done efficiently.

## Problem Solution
```cpp
class Solution {
  public:
    void inOrder(Node* root, vector<int> &bst){
        if(root == NULL) return;
        
        inOrder(root -> left, bst);
        bst.push_back(root -> data);
        inOrder(root -> right, bst);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> bst1, bst2;
        
        inOrder(root1, bst1);
        inOrder(root2, bst2);
        
        vector<int> merged;
        
        int i = 0;
        int j = 0;
        while(i < bst1.size() && j < bst2.size()){
            if(bst1[i] < bst2[j]){
                merged.push_back(bst1[i++]);
            }else{
                merged.push_back(bst2[j++]);
            }
        }
        
        while(i < bst1.size()){
            merged.push_back(bst1[i++]);
        }
        
        while(j < bst2.size()){
            merged.push_back(bst2[j++]);
        }
        
        return merged;
    }
};
```

## Problem Solution Explanation
Here is a detailed explanation of the source code line by line:


#### `class Solution {`
- **Line 1**: This line defines a class named `Solution`. This class encapsulates the logic for merging two binary search trees (BSTs).



#### `public:`
- **Line 2**: Marks the section where the methods and members of the `Solution` class are accessible from outside the class. In C++, members declared as `public` can be accessed by any code.



#### `void inOrder(Node* root, vector<int> &bst) {`
- **Line 3**: This line defines a method called `inOrder` that performs an in-order traversal of a binary tree. 
  - `Node* root`: The root node of the binary tree.
  - `vector<int>& bst`: A reference to a vector of integers where the node values will be stored in sorted order.



#### `if (root == NULL) return;`
- **Line 4**: Checks if the current node is `NULL` (i.e., the tree is empty or we've reached a leaf node). If so, the function returns without doing anything (base case for recursion).



#### `inOrder(root->left, bst);`
- **Line 5**: Recursively calls `inOrder` on the left child of the current node (`root->left`). This step ensures that the left subtree is processed first (in-order traversal: left subtree, current node, right subtree).



#### `bst.push_back(root->data);`
- **Line 6**: Adds the data value of the current node (`root->data`) to the vector `bst`. This happens after the left child has been processed (as part of the in-order traversal).



#### `inOrder(root->right, bst);`
- **Line 7**: Recursively calls `inOrder` on the right child of the current node (`root->right`). This processes the right subtree after the current node's value has been added to `bst`.

#### `vector<int> merge(Node *root1, Node *root2) {`
- **Line 8**: Defines the main method `merge`, which merges two BSTs (`root1` and `root2`).
  - `Node* root1`: The root node of the first BST.
  - `Node* root2`: The root node of the second BST.
  - This method will return a merged sorted vector containing the values of both BSTs.



#### `vector<int> bst1, bst2;`
- **Line 9**: Declares two empty vectors, `bst1` and `bst2`, to store the in-order traversals of `root1` and `root2` respectively.


#### `inOrder(root1, bst1);`
- **Line 10**: Calls the `inOrder` method to populate `bst1` with the sorted values from the first BST (`root1`).



#### `inOrder(root2, bst2);`
- **Line 11**: Calls the `inOrder` method to populate `bst2` with the sorted values from the second BST (`root2`).



#### `vector<int> merged;`
- **Line 12**: Declares an empty vector `merged` to store the final merged and sorted values from both BSTs.



#### `int i = 0; int j = 0;`
- **Line 13**: Declares two integer variables `i` and `j`, which are used as pointers to traverse the `bst1` and `bst2` vectors, respectively.



#### `while (i < bst1.size() && j < bst2.size()) {`
- **Line 14**: Starts a `while` loop that runs until one of the vectors (`bst1` or `bst2`) is completely traversed. The loop compares the elements of both vectors to merge them in sorted order.



#### `if (bst1[i] < bst2[j]) {`
- **Line 15**: Checks if the current element of `bst1` (`bst1[i]`) is smaller than the current element of `bst2` (`bst2[j]`).


#### `merged.push_back(bst1[i++]);`
- **Line 16**: If `bst1[i]` is smaller, it is added to the `merged` vector. The `i++` increments the pointer `i` to move to the next element in `bst1`.



#### `} else {`
- **Line 17**: If `bst2[j]` is smaller or equal to `bst1[i]`, the program enters this block to add the element from `bst2`.



#### `merged.push_back(bst2[j++]);`
- **Line 18**: Adds `bst2[j]` to `merged` and increments the pointer `j` to move to the next element in `bst2`.



#### `while (i < bst1.size()) {`
- **Line 19**: After the main `while` loop, this loop checks if there are any remaining elements in `bst1` (i.e., if `i` is still less than `bst1.size()`).



#### `merged.push_back(bst1[i++]);`
- **Line 20**: If there are remaining elements in `bst1`, they are added to `merged`. The `i++` increments the pointer `i` after adding each element.


#### `while (j < bst2.size()) {`
- **Line 21**: Similarly, this loop checks if there are any remaining elements in `bst2` (i.e., if `j` is still less than `bst2.size()`).

#### `merged.push_back(bst2[j++]);`
- **Line 22**: If there are remaining elements in `bst2`, they are added to `merged`. The `j++` increments the pointer `j` after adding each element.


#### `return merged;`
- **Line 23**: After the merging process is complete, the `merged` vector containing all the elements from both BSTs in sorted order is returned.


### Time and Space Complexity

**Time Complexity Analysis:**
1. **In-Order Traversal of Each BST**:
   - Traversing each tree takes `O(N)` time, where `N` is the number of nodes in the BST.
   - Since we traverse two trees, this part takes `O(N + M)`, where `N` and `M` are the sizes of `root1` and `root2`.

2. **Merging Two Sorted Arrays**:
   - Merging two sorted arrays of sizes `N` and `M` takes `O(N + M)` time.

**Overall Time Complexity**: `O(N + M) + O(N + M) = O(N + M)`.

**Space Complexity Analysis:**
1. **Auxiliary Space for Traversal Arrays**:
   - We store in-order traversals in two arrays (`bst1` and `bst2`), each taking `O(N)` and `O(M)` space.
   
2. **Merged Array**:
   - We need `O(N + M)` space to store the merged array.

**Overall Space Complexity**: `O(N + M)`.


### Additional Recommendations

For beginners:
- **Practice In-Order Traversal**: Mastering this traversal will help you understand BSTs better.
- **Study Merge Techniques**: This problem is similar to the merging step in merge sort, which is useful for solving problems involving two sorted lists.
- **Practice Complexity Calculations**: Try calculating time and space complexities for different parts of algorithms to improve your analytical skills.
