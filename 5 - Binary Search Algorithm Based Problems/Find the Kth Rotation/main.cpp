class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start < end){
            int mid = start + (end - start)/2;
            
            if(arr[mid] < arr[end]){
                end = mid;
            }else if(arr[mid] > arr[end]){
                start = mid + 1;
            }else{
                end--;
            }
        }
        
        return start;
     
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
