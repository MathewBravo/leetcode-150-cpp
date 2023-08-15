//
// Created by MathewBravo on 2023-08-15.
//

#include "ArraysHashing.h"

bool ArraysHashing::containsDuplicate(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    auto il = std::adjacent_find(nums.begin(), nums.end());
    return il != nums.end();
}

bool ArraysHashing::isAnagram(string s, string t) {
    std::sort(t.begin(), t.end());
    std::sort(s.begin(), s.end());
    return t == s;
}

vector<int> ArraysHashing::twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if(hash.count(complement)) return {hash[complement], i};
        hash[nums[i]] = i;
    }
    return {-1,-1};
}

vector<vector<string>> ArraysHashing::groupAnagrams(vector<string> &strs) {
    std::unordered_map<string, vector<string>> stringMap;
    for (auto s : strs){
        string stringAsKey = s;
        std::sort(stringAsKey.begin(), stringAsKey.end());
        if(stringMap.count(stringAsKey)){
            stringMap[stringAsKey].push_back(s);
        }else{
            stringMap[stringAsKey] = {s};
        }
    }
    vector<vector<string>> result;
    result.reserve(stringMap.size());
    for (const auto& res: stringMap){
        result.push_back(res.second);
    }
    return result;
}
