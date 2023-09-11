#include "BigNumCalc.h"
#include <algorithm>
#include <stdexcept>

// Convert string to a list of integers
std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> number;
    for (char c : numString) {
        if (isdigit(c)) {
            number.push_back(c - '0');
        }
    }
    return number;
}

// Add two big numbers
std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }

        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Subtract num2 from num1
std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend()) {
        int difference = *it1 - borrow;
        if (it2 != num2.rend()) {
            difference -= *it2;
            ++it2;
        }

        if (difference < 0) {
            difference += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_front(difference);
        ++it1;
    }

    // Remove leading zeros
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

// Multiply num1 by num2 (assuming num2 is one-digit long)
std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    if (num2.size() != 1) {
        throw std::invalid_argument("num2 must be one-digit long");
    }

    std::list<int> result;
    int multiplier = num2.front();
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int product = (*it) * multiplier + carry;
        result.push_front(product % 10);
        carry = product / 10;
    }

    while (carry) {
        result.push_front(carry % 10);
        carry /= 10;
    }

    return result;
}
