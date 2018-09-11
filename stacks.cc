#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 * Return a sequence of flips that would get the given list of pancakes into 
 * sorted order, with the smallest pancake on top and the largest on the 
 * bottom. The pancake at the top of the pancake stack is first in the list.
 */
std::string get_flip_sequence (std::vector<int> pancakes)
{
    std::string flip_seq;

    std::vector<int> sorted_list(pancakes);
    std::sort(sorted_list.begin(), sorted_list.end());
    
    int i = 0;
    int stack_size = pancakes.size();
    int cur_idx;
    std::vector<int>::iterator cur_pos;

    while (i < stack_size) {
        int pancake_to_place = sorted_list[stack_size - 1 - i];
        
        if (pancakes[stack_size - 1 - i] != pancake_to_place) {
            
            if (pancakes[0] != pancake_to_place) {
                cur_pos = std::find(pancakes.begin(), pancakes.end(), pancake_to_place);
                cur_idx = cur_pos - pancakes.begin();
                flip_seq += std::to_string(stack_size - cur_idx) + " ";
                std::reverse(pancakes.begin(), pancakes.begin() + cur_idx + 1);
            }

            flip_seq += std::to_string(i + 1) + " ";
            std::reverse(pancakes.begin(), pancakes.end() - i);
        }

        i++;
    }

    flip_seq += "0";
    return flip_seq;
}

int main ()
{
    int pancake;

    std::string pancake_input;
    std::string flip_seq;
    std::vector<int> pancakes;

    std::getline(std::cin, pancake_input);

    while (!pancake_input.empty()) {
        pancakes.clear();
        std::stringstream ss(pancake_input);

        while (ss >> pancake)
            pancakes.push_back(pancake);

        flip_seq = get_flip_sequence(pancakes);
        std::cout << pancake_input << std::endl;
        std::cout << flip_seq << std::endl;
        
        std::getline(std::cin, pancake_input);
    }

    return 0;
}