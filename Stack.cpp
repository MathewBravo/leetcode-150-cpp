//
// Created by MathewBravo on 2023-08-16.
//

#include <unordered_set>
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

int Stack::evalRPN(vector<string> &tokens) {
    std::stack<int> operands;
    std::unordered_set<string> operators({"+", "-", "/", "*"});
    for (auto& token: tokens){
        if (operators.count(token) == 0){
            int tok = std::stoi(token);
            operands.push(tok);
        }else{
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            if(token == "+"){
                operands.push(op1 + op2);
            }else if (token == "-"){
                operands.push(op1 - op2);
            }else if (token == "/"){
                operands.push(op1 / op2);
            }else if (token == "*"){
                operands.push(op1 * op2);
            }
        }
    }
    return operands.top();
}

void generateParenthesis(int open, int close, string current, vector<string> &result){
    if (open == 0 && close == 0){
        result.push_back(current);
        return;
    }
    if(open > 0){
        generateParenthesis(open - 1, close, current + "(", result);
    }

    if(close > open){
        generateParenthesis(open, close - 1, current + ")", result);
    }
}


vector<string> Stack::generateParenthesis(int n) {
    vector<string> result;
    ::generateParenthesis(n,n, "", result);
    return result;
}

vector<int> Stack::dailyTemperature(vector<int> &temperatures) {
    stack<int> temp_indices;
    vector<int> result(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++){
        while(!temp_indices.empty() && temperatures[i] > temperatures[temp_indices.top()]){
            int prevIndex = temp_indices.top();
            temp_indices.pop();
            result[prevIndex] = i - prevIndex;
        }
        temp_indices.push(i);
    }
    return result;
}

int Stack::largestRectangleArea(vector<int> &heights) {
    stack<int> indices;
    int max_area = 0;
    for (int i = 0; i < heights.size(); i++){
        while(!indices.empty() && heights[i] < heights[indices.top()]){
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? i : i - indices.top() - 1;
            max_area = std::max(max_area, height * width);
        }
        indices.push(i);
    }
    while(!indices.empty()) {
        int height = heights[indices.top()];
        indices.pop();
        int width = indices.empty() ? heights.size() : heights.size() - indices.top() - 1;
        max_area = std::max(max_area, height * width);
    }
    return max_area;
}

int Stack::carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<std::pair<int, double>> cars;

    cars.reserve(position.size());
    for (int i =0; i < position.size(); i++){
        cars.emplace_back(position[i], (double)(target-position[i])/speed[i]);
    }

    sort(cars.rbegin(), cars.rend());

    stack<double> time_of_arrival;
    int fleets = 0;
    for (const auto& car : cars){
        double arrivalTime = car.second;

        if(time_of_arrival.empty() || arrivalTime > time_of_arrival.top()){
            fleets++;
            time_of_arrival.push(arrivalTime);
        }
    }
    return fleets;
}

