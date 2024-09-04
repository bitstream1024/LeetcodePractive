#pragma once

#include "SolutionBase.h"

#include <algorithm>

typedef std::unordered_map<char, int> MyCharMap;

static bool compare(const std::string& a, const std::string& b) {
    return a.length() > b.length();
}

class Solution_0318 : public SolutionBase
{
public:

    virtual void RunTest()
    {
        std::vector<std::string> wordList{ "a","ab","abc","d","cd","bcd","abcd" };
        int res = maxProduct(wordList);
        printf("RunTest %d\n", res);
    }

private:
    int maxProduct(std::vector<std::string>& words) {

        // sort words
        sort(words.begin(), words.end(), compare);

        int res = 0;
        bool bFound = false;
        int qSize = 0;
        for (int i = 0; i < words.size(); ++i) {
            std::unordered_map<char, int> srcMap;
            makeMyMap(srcMap, words[i]);
            //printf("maxProduct %u\n", srcMap.size());
            if (words[i].length() <= qSize) {
                break;
            }
            for (int j = i + 1; j < words.size(); ++j) {
                if (isHaveSameCharac(srcMap, words[j])) {
                    continue;
                }
                int temp = words[i].length() * words[j].length();
                if (temp > res) {
                    res = temp;
                    qSize = floor(sqrt(1.f * res));
                }
                break;
            }
        }
        return res;
    }
    
    void makeMyMap(std::unordered_map<char, int> &map1, const std::string& str) {
        for (auto c : str) {
            if (map1.count(c) <= 0) {
                map1.insert(std::make_pair(c, 1));
            }
        }
    }

    bool isHaveSameCharac(const std::unordered_map<char, int> &map1, const std::string &str) {
        //printf("isHaveSameCharac %u\n", map1.size());
        for (auto c : str) {
            if (map1.count(c) > 0)
                return true;
        }
        return false;
    }
};
