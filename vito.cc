#include <algorithm>
#include <iostream>

int main()
{
    int i, r, s, T;
    int middle, total_dist;
    std::cin >> T;

    while (T--) {
        std::cin >> r;
        int houses[r];
        
        i = 0;
        while (i < r) {
            std::cin >> s;
            houses[i++] = s;
        }

        std::sort(houses, houses + r);
        middle = r / 2;
        total_dist = 0;

        for (i = 0; i < r; ++i)
            total_dist += abs(houses[middle] - houses[i]);

        std::cout << total_dist << std::endl;
    }

    return 0;
}