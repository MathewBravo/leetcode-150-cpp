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
