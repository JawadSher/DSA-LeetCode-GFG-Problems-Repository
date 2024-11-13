class Solution{
    public:
    void maxHeapify(vector<int> &v, int n, int i){
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        if(leftIndex < n && v[largest] < v[leftIndex]) largest = leftIndex;
        if(rightIndex < n && v[largest] < v[rightIndex]) largest = rightIndex;
        
        if(largest != i){
            swap(v[largest], v[i]);
            maxHeapify(v, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> mergeHeap(n + m);
        
        for(int i = 0; i < n; i++){
            mergeHeap[i] = a[i];
        }
        
        for(int i = 0; i < m; i++){
            mergeHeap[n+i] = b[i];
        }
        
        for(int i = m+n / 2 -1; i >= 0; i--){
            
            maxHeapify(mergeHeap, n+m, i);
        }
        
        return mergeHeap;
    }
};
