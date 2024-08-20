class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int magority_element = -1;
        int counter = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(counter == 0){
                magority_element = nums[i];
            }

            if(magority_element == nums[i]){
                counter++;
            }else{
                counter--;
            }
            
        }
    return magority_element;
    }
};
