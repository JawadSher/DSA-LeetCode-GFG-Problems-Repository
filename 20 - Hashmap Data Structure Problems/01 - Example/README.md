<h1 align='center'>Hashmap - Data Structure - Example</h1>

A **Hashmap** is a data structure that stores key-value pairs and provides efficient methods for insertion, deletion, and search operations based on keys. The key-value pair concept is essential for many real-world applications such as caching, databases, counting occurrences, and more.

### Key Concepts of Hashmaps

- **Key-Value Pair:** Each entry in a hashmap consists of a unique key and an associated value. 
- **Hash Function:** The key is passed through a hash function, which maps it to an index in an array. This index is where the value will be stored.
- **Collision:** When two keys hash to the same index, a collision occurs. Several strategies (like chaining or open addressing) are used to handle this.

### Why Use Hashmaps?

- **Efficient Searching:** Hashmaps allow for quick lookups. Instead of searching through a list or array, the hashmap provides direct access to the value associated with a key using its hash.
- **Insertion and Deletion:** Hashmaps allow for fast insertion and deletion of key-value pairs. This makes them ideal for situations where you need to frequently add, remove, or update data.
- **No Duplicates for Keys:** Keys in a hashmap are unique, meaning no two entries can have the same key, but they can have the same value.


### Hashmap Operations in C++

In the provided C++ code, we use **`unordered_map`** from the C++ Standard Library, which is an implementation of a hashmap. Here’s a breakdown of the code:

```cpp
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // Creation of Unordered Map
    unordered_map<string, int> um;

    // Insertion (Multiple Approaches)
    um.insert(make_pair("Hello", 1));  // Approach 1
    um.insert({"World", 2});  // Approach 2
    um["NewWorld"] = 3;  // Approach 3
    um["World"] = 4;  // Approach 4

    cout << "-- Searching --" << endl;
    // Searching
    cout << "Value of 'World' Key : " << um["World"] << endl;  // Access value using the key
    cout << "Value of 'World' Key : " << um.at("NewWorld") << endl;  // at() with exception if key doesn't exist
    cout << "Value of 'unknown' Key : " << um["unknown"] << endl;  // Default value if key doesn't exist (0)

    // Updation
    um["World"] = 5;

    cout << "-- Checking Size --" << endl;
    // Size of hashmap
    cout << "Size of unordered_map : " << um.size() << endl;

    cout << "-- Check Presence --" << endl;
    // Check if a key exists in the hashmap
    cout << "Is 'World' Key Present : " << um.count("World") << endl;  // True if key exists
    cout << "Is 'Unknown' Key Present : " << um.count("Unknown") << endl;  // False if key doesn't exist

    // Erase
    um.erase("World");
    cout << "Size of unordered_map after erase: " << um.size() << endl;

    cout << "-- For Loop Iteration --" << endl;
    // Iterating over all key-value pairs
    for (auto i : um) cout << "Key: " << i.first << ", Value: " << i.second << endl;

    cout << "-- Iterators --" << endl;
    // Using iterator to iterate
    unordered_map<string, int>::iterator it = um.begin();
    while (it != um.end()) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        it++;
    }

    return 0;
}
```

#### Example Output
Here is an example output for the provided C++ code using `unordered_map`:

```text
-- Searching --
Value of 'World' Key : 4
Value of 'NewWorld' Key : 3
Value of 'unknown' Key : 0
-- Checking Size --
Size of unordered_map : 3
-- Check Presence --
Is 'World' Key Present : 1
Is 'Unknown' Key Present : 0
Size of unordered_map after erase: 2
-- For Loop Iteration --
Key: Hello, Value: 1
Key: NewWorld, Value: 3
-- Iterators --
Key: Hello, Value: 1
Key: NewWorld, Value: 3
```

### Explanation of Output:

1. **Searching**:
   - For the key `"World"`, the value `4` is returned.
   - For the key `"NewWorld"`, the value `3` is returned.
   - For the key `"unknown"`, since it doesn't exist in the map, it returns the default value `0` (because of the use of `[]` operator).
   
2. **Updation**:
   - The value for the `"World"` key is updated to `5`.

3. **Checking Size**:
   - The size of the `unordered_map` is `3` after inserting the keys `"Hello"`, `"World"`, and `"NewWorld"`.

4. **Check Presence**:
   - The key `"World"` exists in the map, so `count("World")` returns `1`.
   - The key `"Unknown"` does not exist, so `count("Unknown")` returns `0`.

5. **Erase**:
   - The key `"World"` is erased, so the new size of the map is `2`.

6. **Iteration (For Loop)**:
   - Iterates over all remaining key-value pairs in the unordered_map and prints them out:
     - `"Hello" : 1`
     - `"NewWorld" : 3`

7. **Iteration (Iterator)**:
   - Uses an iterator to iterate over the `unordered_map` and prints the key-value pairs:
     - `"Hello" : 1`
     - `"NewWorld" : 3`
       
---
### Time and Space Complexities of Hashmaps

#### 1. **Time Complexity:**

- **Insertion:** `O(1)` average case, since the hash function directly computes the index.
    - Worst case: `O(n)` if many keys hash to the same index (collisions), but this is rare with a good hash function and load factor management.
- **Search:** `O(1)` average case.
    - Worst case: `O(n)` if collisions occur, but it's also rare.
- **Deletion:** `O(1)` average case.
    - Worst case: `O(n)` in case of a large number of collisions.
  
In the worst case, where collisions are frequent, the time complexity can degrade to `O(n)` because the hashmap becomes a linked list (if chaining is used).

#### 2. **Space Complexity:**
   - **Space Complexity:** `O(n)`, where `n` is the number of key-value pairs stored in the hashmap. This is because each key-value pair is stored in memory, and additional space is required for internal storage (array of buckets).
   - The space complexity can also be influenced by the load factor and the number of buckets in the hashmap. A high load factor may require resizing the hashmap, which could temporarily use more space.


### Why is a Hashmap Better than Other Data Structures?

- **Arrays:** Arrays require searching through every element (`O(n)`) for a key or value. Hashmaps offer `O(1)` search time in the average case.
- **Linked Lists:** Linked lists also have an `O(n)` search time for a given value. Hashmaps provide direct access based on the key.
- **Trees:** Binary search trees (BST) can provide `O(log n)` search times. However, hashmaps are usually faster for lookups, as they offer `O(1)` time in the average case.
- **Dictionaries (Python):** Similar to hashmaps, Python dictionaries are implemented using hashmaps under the hood, offering efficient key-value pair storage.

---
### Explain of Hash Table
A **Hash Table** (or **Hash Map**) is a data structure that stores key-value pairs and enables efficient lookups, insertions, and deletions. It operates based on a **hash function**, which computes an index (or "hash") from a key, and stores the corresponding value in the array at that index. The primary strength of a hash table lies in its ability to provide average **constant time complexity** (`O(1)`) for operations like searching, insertion, and deletion.

#### Basic Components of a Hash Table
1. **Keys**: Unique identifiers used to access the values.
2. **Values**: The data associated with each key.
3. **Hash Function**: A function that computes an index (hash) for each key, based on the key's value.
4. **Buckets**: The array where the key-value pairs are stored, with each index in the array representing a bucket.
5. **Collisions**: When two keys hash to the same index, a collision occurs. This is managed using techniques like **chaining** or **open addressing**.

#### How Hash Table Works

1. **Inserting Elements**:
   - The hash function computes an index from the key.
   - The key-value pair is stored at the corresponding index (bucket).
   - If the index is already occupied (collision), the collision resolution strategy is used.

2. **Searching for Elements**:
   - The hash function computes the index for the given key.
   - If the key exists at that index, the value is returned.
   - If the key is not found at the computed index, the collision resolution method checks other buckets.

3. **Deleting Elements**:
   - The hash function computes the index for the key.
   - If the key is found, it is deleted.
   - If the key is not found at the index, the collision resolution method checks other buckets.

###- Collision Resolution Strategies

1. **Chaining**:
   - Each bucket in the hash table is a list (or another container).
   - When a collision occurs, the key-value pair is simply added to the list at the corresponding index.
   - **Advantages**: Simple to implement, and it allows for an arbitrary number of elements per bucket.
   - **Disadvantages**: If many elements hash to the same index, the performance degrades to `O(n)` for search, insertion, and deletion.

   **Example of Chaining:**
   Suppose we have a hash table with 5 buckets, and we use a hash function that maps keys to indices as follows:

   | Key    | Hash Function | Bucket Index |
   |----|----|----|
   | "apple"| 2             | 2            |
   | "banana"| 3            | 3            |
   | "cherry"| 2            | 2            |

   After inserting the above key-value pairs into the hash table, the buckets will look like this:

   ```
   Bucket 0: []
   Bucket 1: []
   Bucket 2: [("apple", value1), ("cherry", value2)]
   Bucket 3: [("banana", value3)]
   Bucket 4: []
   ```

2. **Open Addressing**:
   - When a collision occurs, the hash table searches for the next available bucket using a probe sequence (like linear probing, quadratic probing, or double hashing).
   - **Advantages**: More memory-efficient than chaining, as it uses a single array to store all elements.
   - **Disadvantages**: Performance can degrade if the table becomes too full or if there are many collisions.

   **Example of Linear Probing (Open Addressing)**:
   Suppose we have a hash table with 5 buckets, and we use linear probing for collision resolution. Our keys are "apple," "banana," and "cherry."

   ```
   Bucket 0: ["apple"]
   Bucket 1: [empty]
   Bucket 2: [empty]
   Bucket 3: ["banana"]
   Bucket 4: ["cherry"]
   ```

   If "banana" hashes to index 3 but is already occupied, we look at the next index (4). If that index is also full, we continue searching linearly for the next available slot.

#### Time and Space Complexity of Hash Tables

##### 1. **Average Case Time Complexity**:
   - **Insertions**: `O(1)`
   - **Search**: `O(1)`
   - **Deletion**: `O(1)`
   - These operations are constant time because the hash function directly maps keys to their respective buckets.

#### 2. **Worst Case Time Complexity**:
   - In case of many collisions (e.g., when all keys hash to the same bucket), the time complexity can degrade to `O(n)` for operations like search, insert, and delete, especially in the case of chaining where elements are stored in a list.

#### 3. **Space Complexity**:
   - The space complexity is **O(n)**, where `n` is the number of key-value pairs in the hash table. The space complexity depends on the number of buckets in the hash table and how well the hash function distributes keys across the buckets.

#### Why Use Hash Tables?

1. **Efficiency**:
   - Hash tables provide **average O(1)** time complexity for common operations such as **insertions, lookups, and deletions**.
   - This makes them ideal for scenarios where fast access to data is required.

2. **Key-Value Mapping**:
   - Hash tables allow you to efficiently map unique keys to specific values, which is useful in many real-world applications such as caching, indexing, and database management.

3. **Avoiding Linear Search**:
   - Without hash tables, we often need to perform a **linear search** through a list to find a specific element, which can be slow (O(n) time complexity). Hash tables provide a much faster alternative.

4. **Dynamic Resizing**:
   - Many hash table implementations dynamically resize when the load factor (the ratio of the number of elements to the number of buckets) becomes too high. This helps maintain efficient performance as the number of stored elements grows.

#### Example Use Cases for Hash Tables

1. **Caching**:
   - **Web Caching**: A hash table can store recently accessed web pages, where the key is the URL and the value is the content of the page.
   
2. **Dictionary Implementations**:
   - **Word Lookup**: In a dictionary application, hash tables can be used to store words (keys) and their definitions (values), allowing for fast lookups.

3. **Counting Elements**:
   - Hash tables are commonly used for counting occurrences of elements in a collection, like counting word frequency in a text document.

#### Code Example: Basic Hash Table in C++

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> hashTable;

    // Inserting key-value pairs
    hashTable["apple"] = 5;
    hashTable["banana"] = 3;
    hashTable["orange"] = 4;

    // Searching for a value using key
    cout << "apple: " << hashTable["apple"] << endl; // Output: 5

    // Checking if a key exists
    if (hashTable.find("banana") != hashTable.end()) {
        cout << "banana found" << endl; // Output: banana found
    }

    // Updating the value for an existing key
    hashTable["banana"] = 7;
    cout << "banana: " << hashTable["banana"] << endl; // Output: 7

    // Deleting a key-value pair
    hashTable.erase("orange");

    // Iterating through hash table
    cout << "Hash table contents:" << endl;
    for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
```

#### Output:

```
apple: 5
banana found
banana: 7
Hash table contents:
apple: 5
banana: 7
```



#### Summary:
- A **hash table** is a data structure that stores key-value pairs, with efficient **O(1)** time complexity for insertions, lookups, and deletions on average.
- The **hash function** is used to map keys to an index in the underlying array (buckets).
- **Collisions** are handled using techniques like **chaining** or **open addressing**.
- Hash tables are **memory-efficient** and provide fast access to data, making them ideal for scenarios requiring quick lookups, like caching and dictionary implementations.

---
### Why Use `unordered_map` (Hashmap) in C++?

- **Efficient Search Operations:** Hashmaps offer constant time complexity for insertions, deletions, and lookups in the average case, which makes them more efficient than other data structures like arrays or linked lists.
- **No Sorting Required:** `unordered_map` doesn't maintain any order of keys, but if the order isn't important, this is an advantage as it allows faster performance for key operations.

In summary, hashmaps are crucial in scenarios where fast lookups, insertions, and deletions are needed. They are particularly useful for caching, counting occurrences of items, and associating unique keys with specific values in an efficient manner.
