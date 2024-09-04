#pragma once

#include <algorithm>

#include "SolutionBase.h"

static bool compare(const std::string& a, const std::string& b) {
  return a.length() > b.length();
}

class Solution_0030 : public SolutionBase {
 public:
  Solution_0030() { m_mapWordCount.clear();}

  virtual void RunTest() {
    std::string str("barfoofoobarthefoobarman");
    std::vector<std::string> wordList{"bar", "foo", "the"};
    std::vector<int> res = findSubstring(str, wordList);
  }

 private:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string>& words) {
    std::vector<int> res;
    if (s.empty() || words.empty()) {
      return res;
    }
    int wordWidth = words[0].length();
    int totalWwordLen = words.size() * wordWidth;
    if (totalWwordLen < s.length()) {
      return res;
    }

    for (const std::string& strWord : words) {
      if (m_mapWordCount.count(strWord) <= 0) {
        m_mapWordCount.insert(std::make_pair(strWord, 1));
      } else {
        ++m_mapWordCount.at(strWord);
      }
    }
    
    bool bSupport = false;
    for (int i = 0; i < s.length(); ++i) {
      bSupport = isSupport(s, i, wordWidth, totalWwordLen);
      if (bSupport) {
        res.emplace_back(i);
      }
    }
    return res;
  }

  bool isSupport(const std::string& s, const int& begin, const int& wordLen, const int& totalWordLen) {
    std::unordered_map<std::string, int> tempMap = m_mapWordCount;
    int curLen = totalWordLen;
    int leftLen = s.length();
    bool bSupport = true;
    std::string strTemp;
    for (int i = begin; i < s.length();) {
      if (leftLen < curLen) {
        bSupport = false;
        break;
      }
      strTemp = s.substr(i, wordLen);
      if (tempMap.count(strTemp) <= 0 || tempMap.at(strTemp) <= 0) {
        bSupport = false;
        break;
      }
      --tempMap.at(strTemp);
      i += wordLen;
      leftLen -= wordLen;
      curLen -= wordLen;
    }
    return bSupport;
  }

private:
  std::unordered_map<std::string, int> m_mapWordCount;
};
