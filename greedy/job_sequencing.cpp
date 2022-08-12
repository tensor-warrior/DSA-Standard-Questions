/*
1) Sort all jobs in decreasing order of profit. 

2) Iterate on jobs in decreasing order of profit.For each job , do the following: 
    a-> Find a time slot i, such that slot is empty and (i <= deadline-1) and (i is greatest).
    Put the job in this slot and mark this slot filled. 

    b-> If no such i exists, then ignore the job. 
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Job {
    int job_id;
    int deadline;
    int profit;
};

vector<int> job_sequencing(Job jobs[], int N) {
    sort(jobs, jobs+N, [](Job &j1, Job &j2) {
        return j1.profit > j2.profit;
    });

    int max_dl = 0;
    for(int i {}; i < N; i++)
        max_dl = max(max_dl, jobs[i].deadline);

    int slots[max_dl] = {0};
    int profit = 0;
    int count = 0;

    for(int i {}; i < N; i++) {
        int pos = jobs[i].deadline-1;

        while(slots[pos] && pos >= 0) {
            pos--;
        }

        if(pos >= 0) {
            slots[pos]++;
            count++;
            profit += jobs[i].profit;
        }
    }

    return {count, profit};
}

int main(void) {
    Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 1, 15}
    };

    int N = sizeof(jobs)/sizeof(jobs[0]);

    vector<int> res = job_sequencing(jobs, N);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}