#include <iostream>
#include <string>
#include <vector>

bool is_bulb_on (int n)
{
    bool bulb_on = false;
    int i = 1;
    
    while (i <= n) {
        if (!(n % i))
            bulb_on = (bulb_on) ? false : true;
        ++i;
    }

    return bulb_on;
}

int main ()
{
    std::vector<int> bulbs;
    std::vector<std::string> results;

    int bulb;
    std::cin >> bulb;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (bulb) {
        bool bulb_on = is_bulb_on(bulb);
        results.push_back((bulb_on) ? "yes" : "no");

        std::cin >> bulb;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
    }

    for (int i = 0; i < results.size(); ++i)
        std::cout << results.at(i) << std::endl;

    return 0;
}