//
// Created by MathewBravo on 2023-08-15.
//

#include "TwoPointers.h"

bool TwoPointers::isPalindrome(string s) {
    int left = 0, right = s.size();
    while (left <= right){
        if(!isalnum(s[left])){
            left++;
            continue;
        }
        if(!isalnum(s[right])){
           right--;
            continue;
        }
        if(tolower(s[left]) == tolower(s[right])){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
}

vector<int> TwoPointers::twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left <= right){
        if (numbers[left] + numbers[right] < target){
            left++;
        }else if(numbers[left] + numbers[right] > target){
            right--;
        }else{
            return {left+1, right+1};
        }
    }
    return {};
}

int TwoPointers::trap(vector<int> &height) {
    int left = 0, right = height.size()-1;
    int maxLeft = height[left], maxRight = height[right];
    int sum = 0;
    while (left < right){
        if (maxLeft < maxRight){
            left++;
            int water = maxLeft - height[left];
            if (water > 0){
               sum+=water;
            }
            maxLeft = std::max(maxLeft, height[left]);
        }else{
            right--;
            int water = maxRight - height[right];
            if (water > 0){
                sum+=water;
            }
            maxRight = std::max(maxRight, height[right]);
        }
    }
    return sum;
}

vector<vector<int>> TwoPointers::threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i-1] == nums[i]) {
            continue;
        }
        int left = i + 1, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum > 0) {
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});

                // Correct handling of duplicates
                while(left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                while(right > left && nums[right] == nums[right-1]) {
                    right--;
                }
                left++;
                right--;
            }
        }
    }
    return result;
}

int TwoPointers::maxArea(vector<int> &height) {
    int left = 0, right = height.size()-1, max_area = 0;
    while (left < right){
        int cur_area = height[left] < height[right] ? height[left] * (right - left) : height[right] * (right - left);
        max_area = max_area > cur_area ? max_area : cur_area;
        if (height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }
    return max_area;
}
