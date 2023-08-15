//
// Created by MathewBravo on 2023-08-15.
//

#ifndef NEEDCODE_ARRAYSHASHING_H
#define NEEDCODE_ARRAYSHASHING_H

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::string, std::vector;

class ArraysHashing {
    bool containsDuplicate(vector<int>& nums);
    bool isAnagram(string s, string t);
    vector<int> twoSum(vector<int>&nums, int target);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    vector<int> topKFrequent(vector<int>& nums, int k);
};


#endif //NEEDCODE_ARRAYSHASHING_H
