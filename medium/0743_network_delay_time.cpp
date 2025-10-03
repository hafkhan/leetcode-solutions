#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;
int traverse(vector<int> &meet, vector<vector<pair<int, int>>> &myGraph, const int start)
{
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> myHeap;

    myHeap.push({0, start});
    meet[start] = 0;
    while (!myHeap.empty())
    {
        auto [weight, node] = myHeap.top();
        myHeap.pop();
        if (weight != meet[node])
            continue;
        for (auto [v, w] : myGraph[node])
        {
            if (meet[node] + w < meet[v])
            {
                meet[v] = meet[node] + w;
                myHeap.push({meet[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < meet.size(); i++)
    {
        if (meet[i] >= INT_MAX / 4)
            return -1;
        ans = max(ans, meet[i]);
    }
    return ans;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> myGraph(n + 1);
    for (auto val : times)
    {
        pair<int, int> newWeight = {val[1], val[2]};
        myGraph[val[0]].push_back(newWeight);
    }
    vector<int> meet(n + 1, INT_MAX / 4);
    return traverse(meet, myGraph, k);
}

int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;

    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}