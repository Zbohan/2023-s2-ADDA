#include "BigNumCalc.h"
#include <algorithm>
#include <stdexcept>

// Convert a string representation of a number to a list of integers.
std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> number;
    for (char c : numString) {
        // Ensure the character is a digit before processing.
        if (isdigit(c)) {
            number.push_back(c - '0'); // Convert char to int and add to list.
        }
    }
    return number;
}

// Add two big numbers represented as lists.
std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int carry = 0;

    // Iterate over both numbers until all digits are processed or until carry is left.
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

        result.push_front(sum % 10); // Store current digit.
        carry = sum / 10; // Update carry.
    }
    return result;
}

// Subtract num2 from num1.
std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int borrow = 0;

    // Iterate over the digits of num1.
    while (it1 != num1.rend()) {
        int difference = *it1 - borrow;
        if (it2 != num2.rend()) {
            difference -= *it2;
            ++it2;
        }

        // Handle borrow.
        if (difference < 0) {
            difference += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_front(difference); // Store current digit.
        ++it1;
    }

    // Remove leading zeros.
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

// Multiply num1 by num2 (assuming num2 is one-digit long).
std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    if (num2.size() != 1) {
        throw std::invalid_argument("num2 must be one-digit long");
    }

    std::list<int> result;
    int multiplier = num2.front(); // Retrieve the single-digit multiplier.
    int carry = 0;

    // Iterate over the digits of num1.
    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int product = (*it) * multiplier + carry;
        result.push_front(product % 10); // Store current digit.
        carry = product / 10; // Update carry.
    }

    // Process any remaining carry.
    while (carry) {
        result.push_front(carry % 10);
        carry /= 10;
    }

    return result;
}
