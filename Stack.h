//
// Created by MathewBravo on 2023-08-16.
//

#ifndef NEEDCODE_STACK_H
#define NEEDCODE_STACK_H

#include <stack>
#include <string>
#include <algorithm>
#include <queue>

using std::string, std::stack, std::vector;

class Stack {
public:
    bool isValid(string s);
    class MinStack {
        stack<int> mainStack;
        stack<int> minStack;
    public:
        MinStack();
        void push(int val);
        void pop();
        int top();
        int getMin();
    };
    int search(vector<int>& nums, int target);
    int evalRPN(vector<string>& tokens);

};


#endif //NEEDCODE_STACK_H
