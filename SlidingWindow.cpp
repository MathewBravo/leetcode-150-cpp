//
// Created by MathewBravo on 2023-08-16.
//

#include <unordered_map>
#include "SlidingWindow.h"

int SlidingWindow::maxProit(vector<int> &prices) {
    int max_profit = 0;
    int minPrice = 2147483647;

    for (auto price: prices){
        if(price < minPrice) {
            minPrice = price;
        }else{
            int poten_prof = price - minPrice;
            if(poten_prof > max_profit){
                max_profit = poten_prof;
            }
        }
    }

    return max_profit;
}

int SlidingWindow::lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int start = 0;

    std::unordered_map<char, int> charIndexMap;

    for(int end = 0; end < s.size(); end++) {
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = std::max(start, charIndexMap[s[end]] + 1);
        }

        charIndexMap[s[end]] = end;

        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int SlidingWindow::characterReplacement(string s, int k) {
    vector<int> counts(26, 0);
    int left = 0, right = 0, max_count = 0, max_length = 0;

    for (right = 0; right < s.length(); right++) {
        counts[s[right] - 'A']++;
        max_count = std::max(max_count, counts[s[right] - 'A']);

        if (right - left + 1 - max_count > k) {
            counts[s[left] - 'A']--;
            left++;
        }

        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

bool SlidingWindow::checkInclusion(string s1, string s2) {
    return false;
}
