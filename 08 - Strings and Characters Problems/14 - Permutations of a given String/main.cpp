#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
        void permute(string& S, int l, int r, set<string>& ans){
            
            if(l == r){
                ans.insert(S);
            }else{
                
            
                for(int i = l; i <= r; i++){
                    
                    swap(S[l], S[i]);
                    
                    permute(S, l+1, r, ans);
                    
                    swap(S[l], S[i]);
                }
            }
            
        }
	public:
		vector<string>find_permutation(string S)
		{
		   int n = S.length();
		   set<string> ans;
		   int l = 0;
		   int r = n-1;
		   permute(S, l, r, ans);
		   vector<string> result(ans.begin(), ans.end());
		   return result;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
