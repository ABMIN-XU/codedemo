#include<bits/stdc++.h>
using namespace std;
int bfs(const vector<vector<int>> &graph, int start, int target) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == target) {
            return dist;
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1; 
}
int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };
    int start = 0;
    int target = 5;
    int distance = bfs(graph, start, target);
    if (distance != -1) {
        cout << "Shortest distance from " << start << " to " << target << " is " << distance << endl;
    } else {
        cout << "No path from " << start << " to " << target << endl;
    }
    return 0;
}