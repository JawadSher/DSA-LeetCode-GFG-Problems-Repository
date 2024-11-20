#include <iostream>
#include <map>
#include <map>
using namespace std;

int main() {
  
  // creation of Ordered Map
  map<string, int> m;

  // insertion
    // Approach 1
    pair<string, int> p = make_pair("Hello", 1);
    m.insert(p);

    // Approach 2
    pair<string, int> p2("World", 2);
    m.insert(p2);

    // Approach 3
    pair<string, int> p3{"NewWorld", 3};
    m.insert(p3);

    // Approach 4
    m["World"] = 4;

  
  cout << "-------- Searching --------" << endl;
  // Searching
    // Approach 1
    cout << "Value of 'World' Key : "<< m["World"] << endl;

    // Approach 2
    cout << "Value of 'World' Key : " <<m.at("NewWorld") << endl;

    // Search for Un-known key
    // cout << m.at("unknown") << endl; // output : error
    // cout << m["unknown"] << endl; // output : 0

    // But now change the order at see what it returns.
    cout << "Value of 'unknown' Key : " << m["unknown"] << endl; // output : 0
    cout << "Value of 'unknown' Key : " << m.at("unknown") << endl; // output : 0

  // Updation
    m["World"] = 5;

  cout << "-------- Checking Size --------" << endl;
  // Size
  cout << "Size of map : " << m.size() << endl;

  cout << "-------- Check Presence --------" << endl;
  // Check Presence
  cout << "Is 'World' Key Value Present or Not : "<< m.count("World") << endl; // true
  cout << "Is 'Unknown' Key Value Present or Not : "<< m.count("Unknown") << endl; // false

  // Erase
  m.erase("World");
  cout << "Size of map : " << m.size() << endl;

  cout << "-------- For Loop Iteration --------" << endl;
  // Iteration
  for(auto i : m) cout << "Iterting Key Value Pair : " << i.first << " " << i.second << endl;

  cout << "-------- Iterators --------" << endl;
  // Iterators
  map<string, int> :: iterator it = m.begin();

  while(it != m.end()){
    cout << "Iterting Key Value Pair : " << it->first << " " << it->second << endl;
    it++;
  }
  return 0;
}
