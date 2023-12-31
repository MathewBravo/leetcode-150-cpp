//
// Created by MathewBravo on 2023-08-15.
//

#ifndef NEEDCODE_TWOPOINTERS_H
#define NEEDCODE_TWOPOINTERS_H

#include <string>
#include <vector>
#include <algorithm>

using std::string, std::vector;

class TwoPointers {
    bool isPalindrome(string s);
    vector<int> twoSum(vector<int> &num, int target);
    int trap(vector<int>& height);
    vector<vector<int>> threeSum(vector<int>&nums);
    int maxArea(vector<int>&height);
};


#endif //NEEDCODE_TWOPOINTERS_H
