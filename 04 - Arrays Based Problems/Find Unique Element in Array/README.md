# Source Code Explanation

### Finding the Unique Element in an Array

This C++ program demonstrates how to find the unique element in an array where every other element appears exactly twice. It uses the XOR (exclusive OR) operation to achieve this.

#### Code Breakdown

1.  **Unique Element Function (`unique_element`)**
    
    -   This function takes an array and its size as parameters.
    -   It initializes a variable `element` to 0. This variable will store the result of the XOR operations.
    -   It iterates through the array, performing the XOR operation between `element` and each element of the array.
    -   The XOR operation has the property that a⊕a=0a \oplus a = 0a⊕a=0 and a⊕0=aa \oplus 0 = aa⊕0=a. Therefore, pairs of identical numbers will cancel each other out, leaving only the unique element.
    
    
    ```
    int unique_element(int arr[], int n){
        int element = 0;
        for(int i = 0; i < n; i++){
            element = element ^ arr[i];
        }
        
        return element;
    }
    ``` 
    
2.  **Main Function (`main`)**
    
    -   It defines an array `new_array` containing integers where every element except one appears twice.
    -   It calls the `unique_element` function with this array and stores the result in `unique_num`.
    -   It prints the unique element found in the array.
    
    
    ```
    int main(){
        int new_array[5] = {10, 20, 30, 20, 10};
        int unique_num = unique_element(new_array, 5);
        cout << "Unique Element in array is : " << unique_num;
        
        return 0;
    }
    ``` 
    

#### How the XOR Operation Works

The XOR operation has some useful properties for this problem:

-   a⊕a=0a \oplus a = 0a⊕a=0: Any number XORed with itself is 0.
-   a⊕0=aa \oplus 0 = aa⊕0=a: Any number XORed with 0 is the number itself.
-   XOR is commutative and associative, meaning the order of operations does not matter.

Given the array `{10, 20, 30, 20, 10}`:

-   Start with `element = 0`.
-   XOR each element with `element`:
    -   0⊕10=100 \oplus 10 = 100⊕10=10
    -   10⊕20=3010 \oplus 20 = 3010⊕20=30
    -   30⊕30=030 \oplus 30 = 030⊕30=0
    -   0⊕20=200 \oplus 20 = 200⊕20=20
    -   20⊕10=3020 \oplus 10 = 3020⊕10=30
-   After processing all elements, `element` will hold the value of the unique element, which is `30` in this case.

The program effectively finds the unique element in the array by leveraging the properties of the XOR operation.
