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
