#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  int romanToInt(string str) {
    map<char, int> dictionary = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};

    int result = 0;
    for (int i = 0; i < static_cast<int>(str.length()); i++) {
      if (dictionary[str[i + 1]] <= dictionary[str[i]]) {
        result += dictionary[str[i]];
      } else {
        result -= dictionary[str[i]];
      }
    }
    return result;
  }
};

int main() {
  Solution s;

  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;
  cout << s.romanToInt("ICMXCIV") << endl;
  return 0;
}
