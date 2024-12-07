class Solution {
  public:
    // Function to calculate the number of derangements for n items
    int countDer(int n) {
        // Base case: For n = 1, there is no valid dearrangement
        if(n == 1) return 0;

        // Base case: For n = 2, there is exactly one valid dearrangement: {2, 1}
        if(n == 2) return 1;

        // Recursive relation for derangement:
        // totalRelations = (n-1) * (countDer(n-1) + countDer(n-2))
        // Explanation:
        // - (n-1): Choose a position for the first item (other than its original position).
        // - countDer(n-1): Solve the subproblem for the remaining (n-1) items.
        // - countDer(n-2): Solve the subproblem for (n-2) items when swapping is involved.
        int totalRelations = (n-1) * (countDer(n-1) + countDer(n-2));
        
        // Return the total number of derangements for n items
        return totalRelations;
    }
};
