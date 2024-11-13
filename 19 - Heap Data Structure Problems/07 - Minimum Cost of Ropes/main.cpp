class Solution {
  public:
    
    long long minCost(vector<long long>& arr) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
    }
};
