class Solution
{
    public:
    int partition (int arr[], int s, int e)
    {
        int pivot = arr[s];
        
        int count = 0;
        
        for(int i = s+1; i <= e; i++){
            if(arr[i] <= pivot){
                count++;
            }
        }
        
        int pivotIndex = s + count;
        
        swap(arr[pivotIndex], arr[s]);
        
        int i = s, j = e;
        
        while(i < pivotIndex && j > pivotIndex){
            while(arr[i] <= pivot){
                i++;
            }
            
            while(arr[j] > pivot){
                j--;
            }
            
            if(i < pivotIndex && j > pivotIndex){
                swap(arr[i++], arr[j--]);
            }
        }
        
        return pivotIndex;
    }
    
    public:
    void quickSort(int arr[], int s, int e)
    {
        if(s >= e) return;
        
        
        int index = partition(arr, s, e);
        
        quickSort(arr, s, index-1);
        quickSort(arr, index+1, e);
        
    }
    
};
