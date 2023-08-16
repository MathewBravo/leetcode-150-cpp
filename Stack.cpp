//
// Created by MathewBravo on 2023-08-16.
//

#include "Stack.h"

bool Stack::isValid(string s) {
    stack<char> parenTrack;
    for (auto ch : s){
        switch (ch) {
            case '(': case '[':case '{':
                parenTrack.push(ch);
                break;
            case ')':
                if (parenTrack.empty() || parenTrack.top() != '('){
                    return false;
                }else{
                    parenTrack.pop();
                }
                break;
            case ']':
                if (parenTrack.empty() || parenTrack.top() != '['){
                    return false;
                }else{
                    parenTrack.pop();
                }
                break;
            case '}':
                if (parenTrack.empty() || parenTrack.top() != '{'){
                    return false;
                }else{
                    parenTrack.pop();
                }
                break;
            default:
                continue;
        }
    }
    if (parenTrack.empty()){
        return true;
    }else{
        return false;
    }
}

// MIN STACK START

Stack::MinStack::MinStack() {
}

int Stack::MinStack::getMin() {
    if (!minStack.empty()) {
        return minStack.top();
    }

    return -1;
}

void Stack::MinStack::push(int val) {
    mainStack.push(val);
    if (minStack.empty() || val <= minStack.top()) {
        minStack.push(val);
    }
}

void Stack::MinStack::pop() {
    if (!mainStack.empty()) {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
}

int Stack::MinStack::top() {
    if (!mainStack.empty()) {
        return mainStack.top();
    }

    return -1;
}

// MIN STACK END

int Stack::search(vector<int> &nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    if(it != nums.end() && *it == target){
        return std::distance(nums.begin(), it);
    }else{
        return -1;
    }
}
