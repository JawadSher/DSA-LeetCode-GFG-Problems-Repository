#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
  
  // creation of Unordered Map
  unordered_map<string, int> um;

  // insertion
    // Approach 1
    pair<string, int> p = make_pair("Hello", 1);
    um.insert(p);

    // Approach 2
    pair<string, int> p2("World", 2);
    um.insert(p2);

    // Approach 3
    pair<string, int> p3{"NewWorld", 3};
    um.insert(p3);

    // Approach 4
    um["World"] = 4;

  
  cout << "-------- Searching --------" << endl;
  // Searching
    // Approach 1
    cout << "Value of 'World' Key : "<< um["World"] << endl;

    // Approach 2
    cout << "Value of 'World' Key : " <<um.at("NewWorld") << endl;

    // Search for Un-known key
    // cout << um.at("unknown") << endl; // output : error
    // cout << um["unknown"] << endl; // output : 0

    // But now change the order at see what it returns.
    cout << "Value of 'unknown' Key : " << um["unknown"] << endl; // output : 0
    cout << "Value of 'unknown' Key : " << um.at("unknown") << endl; // output : 0

  // Updation
    um["World"] = 5;

  cout << "-------- Checking Size --------" << endl;
  // Size
  cout << "Size of unordered_map : " << um.size() << endl;

  cout << "-------- Check Presence --------" << endl;
  // Check Presence
  cout << "Is 'World' Key Value Present or Not : "<< um.count("World") << endl; // true
  cout << "Is 'Unknown' Key Value Present or Not : "<< um.count("Unknown") << endl; // false

  // Erase
  um.erase("World");
  cout << "Size of unordered_map : " << um.size() << endl;

  cout << "-------- For Loop Iteration --------" << endl;
  // Iteration
  for(auto i : um) cout << "Iterting Key Value Pair : " << i.first << " " << i.second << endl;

  cout << "-------- Iterators --------" << endl;
  // Iterators
  unordered_map<string, int> :: iterator it = um.begin();

  while(it != um.end()){
    cout << "Iterting Key Value Pair : " << it->first << " " << it->second << endl;
    it++;
  }
  return 0;
}
