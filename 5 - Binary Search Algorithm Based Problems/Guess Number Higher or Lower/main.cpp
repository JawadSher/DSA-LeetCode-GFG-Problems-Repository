class Solution {
public:
    int guessNumber(int n) {
        int start = 0;
        int end = n;

        while(start <= end){
            int mid = start + (end - start)/2;

            int value = guess(mid);

            if(value == 0){
                return mid;
            }else if(value == -1){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};
