//
// Created by MathewBravo on 2023-08-23.
//

#include "BitWise.h"

int BitWise::singleNumber(vector<int> &nums) {
    int single = 0;
    for (const auto &num: nums){
        single ^= num;
    }
    return single;
}

int BitWise::hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

vector<int> BitWise::countBits(int n) {
    vector<int> result(n+1, 0);
    for (int i = 1; i <= n; i++){
        result[i] = result[ i >> 1] + (i & 1);
    }
    return result;
}

uint32_t BitWise::reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

int BitWise::missingNumber(vector<int> &nums) {
    int xorResult = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        xorResult ^= nums[i];
    }

    for (int i = 0; i <= n; i++) {
        xorResult ^= i;
    }

    return xorResult;
}
