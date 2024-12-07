class Solution {
  public:
    // Function to calculate the maximum money the thief can rob
    int maximizeMoney(int N , int K) {
        // If there are no houses, the thief cannot rob any money
        if (N == 0) return 0;

        // If there is only one house, the maximum money is the amount in that house
        if (N == 1) return K;

        // For more than one house, calculate the maximum money the thief can rob
        // The thief can rob every alternate house, so the number of houses he can rob is ceil(N / 2)
        return (N + 1) / 2 * K;  // This is equivalent to ceil(N / 2) * K
    }
};
