#include <iostream>
#include "SlidingWindow.h"

int main() {
    SlidingWindow *sw = new SlidingWindow();
    auto result = sw->lengthOfLongestSubstring("abcabcbb");
    std::cout << result;
}

