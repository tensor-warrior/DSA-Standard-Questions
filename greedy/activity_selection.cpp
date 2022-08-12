/*
Our objective is to complete maximum number of activities. So, choosing the activity which is
going to finish first will leave us maximum time to adjust the later activities. This is the
intuition that greedily choosing the activity with earliest finish time will give us an optimal
solution. By induction on the number of choices made, making the greedy choice at every step
produces an optimal solution, so we chose the activity which finishes first. If we sort elements
based on their starting time, the activity with least starting time could take the maximum duration
for completion, therefore we won't be able to maximise number of activities.

Three components of greedy:
1. Objective: What to optimize
2. Hypothesis: Optimizes a single case
3. Induction: Mathematical induction
*/

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int activity_selection(vector<int> start, vector<int> end, int n) {
    vector<pair<int,int>> vec;

    for(int i {}; i < n; i++)
        vec.push_back({start[i], end[i]});

    sort(vec.begin(), vec.end(), [](pair<int,int> p1, pair<int,int> p2) {
        return p1.second < p2.second;
    });

    int thresh = -1;
    int count = 0;

    for(auto &v: vec) {
        cout << v.first << " " << v.second << endl;

        if(v.first > thresh) {
            count++;
            thresh = v.second;
        }
    }

    return count;
}

int main(void) {
    vector<int> start = {2, 1, 4, 9, 1};
    vector<int> end = {9, 5, 4, 10, 3};

    int res = activity_selection(start, end, 5);
    cout << res << endl;

    return 0;
}