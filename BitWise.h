//
// Created by MathewBravo on 2023-08-23.
//

#ifndef NEEDCODE_BITWISE_H
#define NEEDCODE_BITWISE_H

#include <vector>
#include <bitset>
#include <cstdint>


using std::vector;

class BitWise {
    int singleNumber(vector<int>& nums);
    int hammingWeight(uint32_t n);
    vector<int> countBits(int n);
    uint32_t reverseBits(uint32_t n);
    int missingNumber(vector<int>& nums);
};


#endif //NEEDCODE_BITWISE_H
