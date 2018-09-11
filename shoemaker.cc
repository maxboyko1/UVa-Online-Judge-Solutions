#include <algorithm>
#include <iostream>
#include <vector>

struct Job {
    int num;
    int time;
    int fine;
};


bool compare_wait_fines (const Job& job1, const Job& job2)
{
    return job1.time * job2.fine < job2.time * job1.fine;
}

int main ()
{
    int i, T, N; 
    std::cin >> T;

    while (T--) {
        std::cin >> N;
        
        std::vector<Job> jobs (N);
        
        for (i = 0; i < N; ++i) {
            jobs[i].num = i + 1;
            std::cin >> jobs[i].time >> jobs[i].fine;
        }

        std::stable_sort(jobs.begin(), jobs.end(), compare_wait_fines);

        for (i = 0; i < N - 1; ++i)
            std::cout << jobs[i].num << " ";
        std::cout << jobs[i].num << std::endl;

        jobs.clear();

        if (T) 
            std::cout << std::endl;
    }

    return 0;
}