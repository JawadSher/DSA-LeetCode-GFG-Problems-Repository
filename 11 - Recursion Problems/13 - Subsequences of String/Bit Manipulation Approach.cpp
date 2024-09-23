#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve(string input_str, vector<string> &answer){
  int n = input_str.length();
  int total_subsequences = (1 << n);

  cout<< total_subsequences <<endl;

  for(int mask = 0; mask < total_subsequences; mask++){
    string subsequence = "";

    for(int i = 0; i < n; i++){
      if(mask & (1 << i)){
        subsequence += input_str[i];
      }
    }

    if(!subsequence.empty()){
      answer.push_back(subsequence);
    }
  }
}

void subsequence(string &input_str){
  vector<string> answer;

  solve(input_str, answer);

  sort(answer.begin(), answer.end());

  cout<<"Sub-Sequences of given String : ";
  for(int i = 0; i < answer.size(); i++){
    cout<<answer[i]<< " ";
  }cout<<endl;
}

int main() {
  string input_str = "ABCD";
  
  subsequence(input_str);

  return 0;
}
