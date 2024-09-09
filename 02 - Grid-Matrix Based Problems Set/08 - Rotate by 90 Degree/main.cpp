#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public:
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int j = 0; j < n; j++){
            int top = 0;
            int bottom = n - 1;
            
            while(top < bottom){
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    } 
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
