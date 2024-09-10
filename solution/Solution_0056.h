#pragma once

#include "SolutionBase.h"

class Solution_0056 : public SolutionBase {
public:
     Solution_0056() {}

  virtual void RunTest() {
      std::vector<std::vector<int>> intervels{ {2,3 }, { 5,5 }, {2, 2}, {3, 4}, {5,5} };
      std::vector<std::vector<int>> res = merge(intervels);
      for (int i = 0; i < res.size(); ++i) {
          printf("[%d, %d] ", res[i][0], res[i][1]);
      }
      printf("done\n");
  }

private:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
      std::vector<std::vector<int>> res;
      if (intervals.empty()) {
          return res;
      }
      if (1 == intervals.size()) {
          res.emplace_back(intervals[0]);
          return res;
      }

      unsigned char buf[10001] = { 0 };
      int max = 0;
      for (const auto& vec : intervals) {
          if (vec[1] > max) {
              max = vec[1];
          }
          int start = vec[0];
          // 2 意味着区间起始
          buf[start] = (buf[start] == 1 ? 1 : 2);
          memset(buf + start + 1, 1, vec[1] - start);
      }

      bool b_has_left = false;
      std::vector<int> temp;
      for (int i = 0; i <= max; ++i) {
          if ((2 == buf[i] || 0 == buf[i]) && b_has_left && temp.size() == 1) {
              temp.emplace_back(i - 1);
              res.emplace_back(temp);
              temp.clear();
              b_has_left = false;
              if (2 == buf[i]) {
                  b_has_left = true;
                  temp.emplace_back(i);
              }
              continue;
          }

          if (2 == buf[i] && !b_has_left && temp.empty()) {
              b_has_left = true;
              temp.emplace_back(i);
              continue;
          }
      }
          if ((buf[max] == 2 ||  buf[max] == 1 )&& b_has_left && temp.size() == 1) {
              temp.emplace_back(max);
              res.emplace_back(temp);
          }

      return res;
  }
};
