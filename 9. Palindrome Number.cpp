#include <iostream>
#include <limits>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int newNum = 0;
    int current = x;
    while (current > 0) {
      int a = current % 10;
      current /= 10;

      if (newNum < INT_MAX / 10 ||
          (newNum == INT_MAX / 10 && a <= INT_MAX % 10)) {
        newNum = newNum * 10 + a;
      } else {
        return false;
      }
    }
    return newNum == x;
  }
};

int main() {
  Solution s;
  cout << boolalpha << s.isPalindrome(12313211) << endl;
}
