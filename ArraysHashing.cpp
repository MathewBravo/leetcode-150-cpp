//
// Created by MathewBravo on 2023-08-15.
//

#include <queue>
#include <unordered_set>
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

vector<int> ArraysHashing::topKFrequent(vector<int> &nums, int k) {
    std::unordered_map<int, int> counter;
    for (auto num : nums){
       counter[num]++;
    }

    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b){
        return a.second > b.second;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> min_heap(compare);

    for (const auto& pair : counter) {
        min_heap.emplace(pair);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    std::vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().first);
        min_heap.pop();
    }
    std::reverse(result.begin(), result.end());

    return result;

}

bool ArraysHashing::isValidSudoku(vector<vector<char>> &board) {
    std::vector<std::unordered_set<int>> row(9), col(9), box(9);
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            char piece = board[i][j];
            if (piece == '.') continue;

            int val = piece - '0';

            if (row[i].find(val) != row[i].end()) return false;
            row[i].insert(val);

            if (col[j].find(val) != col[j].end()) return false;
            col[j].insert(val);

            int box_index = (i / 3) * 3 + (j /3);

            if(box[box_index].find(val) != box[box_index].end()) return false;
            box[box_index].insert(val);
        }
    }
    return true;
}

int ArraysHashing::longestConsecutive(vector<int> &nums) {
    if(nums.size() <=1){
        return nums.size();
    }

    std::unordered_set<int> num_map;

    for (int num : nums){
        num_map.insert(num);
    }

    int longestStreak = 0;

    for (int num : nums){
        if (!num_map.count(num-1)){
            int currentNum = num, currentStreak = 1;

            while(num_map.count(currentNum + 1)){
                currentNum++;
                currentStreak++;
            }

            longestStreak = longestStreak > currentStreak ? longestStreak : currentStreak;
        }
    }

    return longestStreak;
}
