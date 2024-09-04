#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> reversed(vector<int> arr){
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            swap(arr[i++], arr[j--]);
        }
        
        return arr;
    }
    vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        
        int carry = 0;
        vector<int> result;
        
        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            
            if(i >= 0) sum += arr1[i--];
            if(j >= 0) sum += arr2[j--];
            carry = sum / 10;
            result.push_back(sum % 10);
        }
        
        return reversed(result);
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.findSum(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
    }

    return 0;
}
