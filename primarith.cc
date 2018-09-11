#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/*
 * Return a vector of the given length containing the digits of n, in order
 * from highest to lowest order. If the number of digits is n is lower than
 * the specified vector length, the vector is pre-padded with zeroes to reach 
 * the specified length. 
 */
std::vector<int> split_into_digits (unsigned int n, int vec_len)
{
    int actual_len = floor(log10(n)) + 1;
    int divisor = pow(10, actual_len - 1);
    int digit_pos = vec_len;
    int digit;

    std::vector<int> digits;

    while (digit_pos) {
        if (digit_pos > actual_len) {
            digits.push_back(0);
        } else {
            digit = n / divisor;
            digits.push_back(digit);
            n -= digit * divisor;
            divisor /= 10;
        }

        --digit_pos;
    }

    return digits;
}

/*
 * Given two integers a and b, calculate how many carry operations will be
 * necessary to add the two numbers digit-by-digit, then return the 
 * appropriate message.
 */
std::string get_carry_message (unsigned int a, unsigned int b)
{
    int a_length = floor(log10(a)) + 1;
    int b_length = floor(log10(b)) + 1;
    int max_length = fmax(a_length, b_length);

    std::vector<int> a_digits = split_into_digits(a, max_length);
    std::vector<int> b_digits = split_into_digits(b, max_length);

    int carry_count = 0;
    int i;

    for (i = 0; i < max_length; ++i) {
        int a_digit = a_digits[i];
        int b_digit = b_digits[i];
        int sum = a_digit + b_digit;
        
        if (sum >= 10)
            ++carry_count;
    }

    if (!carry_count)
        return "No carry operation.";
    else if (carry_count == 1)
        return "1 carry operation.";
    else
        return std::to_string(carry_count) + " carry operations.";
}

int main () 
{
    unsigned int a, b;
    std::string msg;
    std::vector<std::string> messages;

    std::cin >> a >> b;
    std::cin.ignore();

    while (a || b) {
        msg = get_carry_message(a, b);
        messages.push_back(msg);
        std::cin >> a >> b;
        std::cin.ignore();
    }

    for (int i = 0; i < messages.size(); ++i)
        std::cout << messages[i] << std::endl;

    return 0;    
}
