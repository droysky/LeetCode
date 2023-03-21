#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(const string& s) {
    stack<char, vector<char>> buff;
    for (char ch : s) {
      if (ch == '(') {
        buff.push(')');
      } else if (ch == '[') {
        buff.push(']');
      } else if (ch == '{') {
        buff.push('}');
      } else {
        if (buff.empty()) {
          return false;
        }
        if (buff.top() != ch) {
          return false;
        }
        buff.pop();
      }
    }
    return buff.empty();
  }
};

int main() {
  Solution s;
  cout << boolalpha << s.isValid("()[]{}") << endl;
}
