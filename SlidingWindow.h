//
// Created by MathewBravo on 2023-08-16.
//

#ifndef NEEDCODE_SLIDINGWINDOW_H
#define NEEDCODE_SLIDINGWINDOW_H

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::vector, std::string;


class SlidingWindow {
public:
    int maxProit(vector<int>& prices);
    int lengthOfLongestSubstring(string s);
    int characterReplacement(string s, int k);
    bool checkInclusion(string s1, string s2);
};


#endif //NEEDCODE_SLIDINGWINDOW_H
