// Description : Convert string binary number into decimal by using the <<, >> operators.
#include <iostream>
#include <string>

using namespace std;

int binary_to_integer(const string& binary_str) {
  int result = 0;
  for (char c : binary_str){
      result = (result << 1) | (c - '0');
  }
  return result;
}

int main() {
  string binary_str = "1101";
  int integer_value = binary_to_integer(binary_str);
  cout << binary_str << " in binary is " << integer_value << " in decimal." << endl;
  return 0;
}


