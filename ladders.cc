#include <iostream>
#include <string>
#include <vector>

/*
 * Return whether or not the initial string can be transformed into the target
 * by adding, changing or deleting just one letter.
 */
bool is_valid_step (std::string initial, std::string target)
{
    int i, j;
    int len_diff;
    int word_len;
    bool mod_used;
    bool add_used;
    bool del_used;

    len_diff = initial.length() - target.length();
    if (len_diff < -1 || len_diff > 1)
        return false;

    if (!len_diff) {
        word_len = initial.length();
        mod_used = false;

        for (i = 0; i < word_len; ++i) {
            if (initial[i] != target[i]) {
                if (!mod_used)
                    mod_used = true;
                else return false;
            }
        }
    
    } else if (len_diff < 0) {
        word_len = target.length();
        add_used = false;
        i = 0; j = 0;

        while (j < word_len) {
            if (initial[i] != target[j]) {
                if (!add_used) {
                    if (j < word_len && initial[i] != target[++j])
                        return false;
                    add_used = true;
                    
                } else {
                    return false;
                }
            }
            ++i; ++j;
        }

    } else {
        word_len = initial.length();
        del_used = false;
        i = 0; j = 0;

        while (i < word_len) {
            if (initial[i] != target[j]) {
                if (!del_used) {
                    if (i < word_len && initial[++i] != target[j])
                        return false;
                    del_used = true;

                } else {
                    return false;
                }
            }
            ++i; ++j;
        }
    }

    return true;
}

int main ()
{
    int i;
    int cur_len;
    int max_len;
    std::string word;
    std::vector<std::string> ladder;

    std::getline(std::cin, word);

    while (!word.empty()) {
        ladder.push_back(word);
        std::getline(std::cin, word);
    }

    cur_len = 1;
    max_len = 1;

    for (i = 0; i < ladder.size() - 1; ++i) {
        if (is_valid_step(ladder[i], ladder[i + 1])) {
            ++cur_len;
        } else {
            if (cur_len > max_len)
                max_len = cur_len;
            cur_len = 1;
        }
    }

    if (cur_len > max_len)
        max_len = cur_len;

    std::cout << max_len << std::endl;

    return 0;
}
