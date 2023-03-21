#include <iostream>
#include <string>
#include <vector>
using namespace std::literals;

class Solution {
 public:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (!strs.size()) {
      return "";
    }

    std::string prefixStr = strs[0];

    for (int i = 1; i < static_cast<int>(strs.size()); ++i) {
      std::string s = strs[i];

      if (s.size() == 0 || prefixStr == "") {
        return "";
      }

      prefixStr = prefixStr.substr(0, std::min(prefixStr.size(), s.size()));

      for (int j = 0; j < static_cast<int>(s.size()) &&
                      j < static_cast<int>(prefixStr.size());
           ++j) {
        if (s[j] != prefixStr[j]) {
          prefixStr = prefixStr.substr(0, j);
          break;
        }
      }
    }
    return prefixStr;
  }
};

int main() {
  Solution s;
  std::cout << s.longestCommonPrefix({"flower"s, "flow"s, "flight"s})
            << std::endl;
}
