class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        priority_queue<pair<double, int>> pq;
        pq.push({ (double)1.0, start });

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            graph[edge[0]].push_back({ edge[1], succProb[i] });
            graph[edge[1]].push_back({ edge[0], succProb[i] });
        }

        vector<bool> visited(n, false);

        while (!pq.empty()) {
            auto [prob, pos] = pq.top();
            pq.pop();
            if (pos == end)
                return prob;
            if (visited[pos])
                continue;
            visited[pos] = true;
            for (auto next : graph[pos])
                pq.push({ prob * next.second, next.first });
        }

        return 0;
    }
};