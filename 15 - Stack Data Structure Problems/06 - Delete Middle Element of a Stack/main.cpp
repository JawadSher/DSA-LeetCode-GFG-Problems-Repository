class Solution {
  private:
    void helper(stack<int>& inputStack, int count, int size){
        // base case
        if(count == size/2){
            inputStack.pop();
            return;
        }
        
        int storeNum = inputStack.top();
        inputStack.pop();
        
        helper(inputStack, count+1, size);
        
        inputStack.push(storeNum);
        
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& inputStack, int size) {
        int count = 0;
        
        
        return helper(inputStack, count, size);
        
    }
};
