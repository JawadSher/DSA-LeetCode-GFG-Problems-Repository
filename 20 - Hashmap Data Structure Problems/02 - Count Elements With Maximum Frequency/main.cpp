class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for(auto i : nums) freqMap[i]++;

        int maxFreq = 0;

        for(auto pair : freqMap) maxFreq = max(maxFreq, pair.second);

        int totalCount = 0;
        for (auto pair : freqMap) if (pair.second == maxFreq) totalCount += pair.second;
            
        return totalCount;
    }
};
