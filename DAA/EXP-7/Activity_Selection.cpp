#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }
    sort(activities.begin(), activities.end());

    int count = 1;
    int lastFinish = activities[0].first;

    for (int i = 1; i < n; i++) {
        int currStart = activities[i].second;
        int currFinish = activities[i].first;

        if (currStart >= lastFinish) {
            count++;
            lastFinish = currFinish;
        }
    }

    return count;
}
