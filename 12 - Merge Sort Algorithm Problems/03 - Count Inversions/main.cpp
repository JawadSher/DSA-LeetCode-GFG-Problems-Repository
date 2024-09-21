class Solution {
  public:
  
    long long inversions = 0;
    
    void merge(vector<long long> &arr, long long s, long long e){
        long long mid = s + (e - s)/2;
        
        long long left = mid - s + 1;
        long long right = e - mid;
        
        long long i = s;
        long long j = mid+1;
        long long k = 0;
        
        long long *temp = new long long[left+right];
        
        while(i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(long long i = 0; i < left+right; i++){
            arr[s+i] = temp[i];
        }
        
        delete [] temp;
    };
    
    void mergeSort(vector<long long> &arr, long long s, long long e){
        if(s >= e) return;
        
        long long mid = s + (e - s) /2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        
        merge(arr, s, e);
    };
    
    long long int inversionCount(vector<long long> &arr) {
        inversions = 0;
        
        int s = 0;
        int e = arr.size() -1;
        
        mergeSort(arr, s, e);
        
        return inversions;
    }
};
