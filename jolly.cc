#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 * Return "jolly" if the absolute values of the differences between successive
 * elements in the sequence of numbers v take on all integer values 1 through
 * n - 1, where n is the length of the sequence. Otherwise, return "not jolly".
 */
std::string is_jolly (const std::vector<int>& v)
{
    int i; 
    int num_diffs = v.size() - 1;
    int diffs[num_diffs];
    bool all_diffs_taken;

    for (i = 0; i < num_diffs; ++i)
        diffs[i] = 0;
    
    for (i = 0; i < num_diffs; ++i) {
        int diff = abs(v[i] - v[i + 1]);
        if (1 <= diff && diff <= num_diffs)
            diffs[diff - 1] = 1;
    }

    i = 0;
    all_diffs_taken = true;

    while (all_diffs_taken && i < num_diffs)
        all_diffs_taken = diffs[i++];

    return (all_diffs_taken) ? "Jolly" : "Not jolly";
}

int main ()
{
    int i, n, element;
    std::string input;
    std::vector<int> v;

    std::getline(std::cin, input);

    while (!input.empty()) {
        v.clear();

        std::stringstream ss(input);
        ss >> n;
        i = 0;

        while (i++ < n) {
            ss >> element;
            v.push_back(element);
        }

        std::cout << is_jolly(v) << std::endl;
        std::getline(std::cin, input);
    }

    return 0;
}
