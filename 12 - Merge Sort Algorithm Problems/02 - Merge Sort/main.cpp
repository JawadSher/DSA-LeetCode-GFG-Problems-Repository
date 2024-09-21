class Solution
{
    public:
    void merge(int arr[], int s, int e)
    {
        int mid = s + (e - s)/2;
        
        int left = mid - s + 1;
        int right = e - mid;
        
        int *temp = new int[left + right];
        
        int i = s;
        int j = mid+1;
        int k = 0;
        
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(int x = 0; x < left+right; x++){
            arr[s+x] = temp[x];
        }
        
        delete []temp;
        
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        if(s >= e) return;
        int mid = s + (e - s) /2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        
        merge(arr, s, e);
    }
};
