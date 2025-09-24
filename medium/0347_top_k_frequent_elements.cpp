#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int, int> values;
    vector<vector<int>> resultValues;
    vector<int> result;
    result.reserve(k);
    for (auto item : nums) 
    {
        auto iter = values.find(item);
        if (iter != values.end()) {
            iter->second = ++iter->second;
        } else {
            values[item] = 1;
        }
    }
    for (auto item : values) 
    {
        //cout << "-----" << item.first << "    " << item.second << endl;
        resultValues.push_back({item.second, item.first});
    }
    std::sort(resultValues.begin(), resultValues.end(),[](const vector<int> & a, const vector<int> & b)
    {
        return a[0] > b[0];
    }
    );
    for(int i = 0; i < k; i++)
    {
        result.push_back(resultValues[i][1]);
    }
    return result;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto result = topKFrequent(nums,k);
    for(auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}