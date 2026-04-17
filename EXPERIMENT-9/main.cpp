#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<vector<int>> q; // {city, cost, stops}
        q.push({src, 0, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int city = current[0], cost = current[1], stops = current[2];

            if (stops > k) continue;

            for (auto& neighbor : graph[city]) {
                int nextCity = neighbor.first;
                int price = neighbor.second;
                if (cost + price < minCost[nextCity]) {
                    minCost[nextCity] = cost + price;
                    q.push({nextCity, cost + price, stops + 1});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
