#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <tuple>

using namespace std;

typedef pair<int, int> edge;

// https://en.wikipedia.org/wiki/Prim%27s_algorithm
auto prim(vector<vector<edge>> &g) {
    size_t n = g.size();
    vector<int> pred(n, -1);
    vector<int> prio(n, INT_MAX);
    prio[0] = 0;
    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.push({prio[0], 0});
    long long tree_weight = 0;

    while (!q.empty()) {
        auto[w, u] = q.top();
        q.pop();

        if (prio[u] != w)
            continue;
        tree_weight += w;

        for (auto[v, weight] : g[u]) {
            if (prio[v] > weight) {
                prio[v] = weight;
                pred[v] = u;
                q.push({weight, v});
            }
        }
    }
    return make_tuple(tree_weight, pred);
}

int main() {
    vector<vector<edge>> g(3);
    g[0].push_back({1, 10});
    g[1].push_back({0, 10});
    g[1].push_back({2, 10});
    g[2].push_back({1, 10});
    g[2].push_back({0, 5});
    g[0].push_back({2, 5});

    auto[tree_weight, pred] = prim(g);
    cout << tree_weight << endl;
}
