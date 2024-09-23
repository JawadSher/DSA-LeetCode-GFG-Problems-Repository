#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve(string input_str, string output, vector<string> &answer, int index){
  if(index >= input_str.length()){
    if(output.length() > 0){
      answer.push_back(output);
    }

    return;
  }

  solve(input_str, output, answer, index+1);
  
  int character = input_str[index];
  output.push_back(character);

  solve(input_str, output, answer, index+1);
}

void subsequence(string &input_str){
  string output;
  vector<string> answer;
  int index = 0;

  solve(input_str, output, answer, index);

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
