#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string,vector<string>> myMap;
    for(auto val : strs)
    {
        array<int,26> count = {0};
        for(auto c : val)
        {
            count[c - 'a']++;  
        }
        string key;
        for(auto x : count)
        {
            key += to_string(x) + "#";
        }
        myMap[key].push_back(val);
    }
    for(auto val : myMap)
    {
        result.push_back(val.second);
    }
    return result;
}


int main()
{
    vector<string> test = {"tea","eat","it","ti","hello","hell","lleh","lelho"};
    auto res = groupAnagrams(test);
    for(auto val : res)
    {
        cout << "{";
        for(auto x : val)
        {
            cout << x << ",";
        }
        cout << "},";
    }
    return 0;
}