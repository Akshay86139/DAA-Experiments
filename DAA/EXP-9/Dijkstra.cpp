// Name: AKSHAY KUMAR
// Roll No: 25/DA/008
// Algorithm: Dijkstra's Shortest Path Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    vector<int> dist = dijkstra(V, adj, 0);

    cout << "Name: AKSHAY KUMAR" << endl;
    cout << "Roll No: 25/DA/008" << endl;
    cout << "\nShortest distances from source 0:\n";

    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
