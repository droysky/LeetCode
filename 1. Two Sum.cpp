#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> valueIndex;
    for (int i = 0; i < (int)nums.size(); ++i) {
      auto it = valueIndex.find(target - nums[i]);
      if (it != valueIndex.end()) {
        return {it->second, i};
      }
      valueIndex[nums[i]] = i;
    }
    throw invalid_argument("not found");
  }
};

int main() {
  Solution s;
  vector<int> answer = s.twoSum({1, 2, 3, 5, 11, 22, 55}, 66);

  for (const int index : answer) {
    cout << index << " ";
  }
  return 0;
}
