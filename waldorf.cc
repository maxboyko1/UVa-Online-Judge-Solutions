#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
 * Return the position in the grid where the given word occurs (row first, 
 * column second). If the word occurs more than once, return the position
 * that is uppermost, and if there are multiple uppermost locations, return
 * the one that is furthest to the left.
 */
std::string find_word (const std::vector<std::string>& grid, std::string word)
{
    int i, j, k;
    
    const int word_len = word.length();
    const int m = grid.size();
    const int n = (m) ? grid[0].length() : 0;

    const int vert[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int hori[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool word_found = false;
    
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    i = 0;

    while (!word_found && i < m) {
        j = 0;
        while (!word_found && j < n) {
            if (word[0] == grid[i][j]) {
                k = 0;
                while (!word_found && k < 8) {
                    int vert_end = i + vert[k] * (word_len - 1);
                    int hori_end = j + hori[k] * (word_len - 1);
                    bool in_vert_range = 0 <= vert_end && vert_end < m;
                    bool in_hori_range = 0 <= hori_end && hori_end < n;

                    if (in_vert_range && in_hori_range) {
                        int pos = 1;
                        word_found = true;

                        while (word_found && pos < word_len) {
                            int vert_pos = i + pos * vert[k];
                            int hori_pos = j + pos * hori[k];

                            word_found = word[pos] == grid[vert_pos][hori_pos];
                            ++pos;
                        }
                    }
                    ++k;
                }
            }
            ++j;
        }
        ++i;
    }

    return std::to_string(i) + " " + std::to_string(j);
}

int main ()
{
    int T, m, n, k;
    std::string word; 
    std::string input; 
    std::string gridline;
    std::vector<std::string> grid;

    std::cin >> T;

    while (T--) {
        std::cin >> m >> n;
        std::cin.ignore();

        while (m--) {
            std::getline(std::cin, input);
            gridline = input.substr(0, n);
            std::transform(gridline.begin(), gridline.end(), gridline.begin(), ::tolower);
            grid.push_back(gridline);
        }

        std::cin >> k;
        std::cin.ignore();

        while (k--) {
            std::getline(std::cin, word);
            std::cout << find_word(grid, word) << std::endl;
        }

        if (T) std::cout << std::endl;
    }

    return 0;
}
