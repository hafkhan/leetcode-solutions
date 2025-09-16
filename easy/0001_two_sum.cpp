#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    // // o(n2)
    // int len = nums.size();
    // for(int i = 0; i < len; i++)
    // {
    //     for(int j = 0; j < len; j++)
    //     {
    //         if(i != j)
    //         {
    //             int sumVal = nums[i] + nums[j];
    //             if(sumVal == target)
    //             {
    //                 return {i, j};
    //             }
    //         }
    //     }
    // }
    // return {};
    // o(n)
    unordered_map<int,int> keyVal;
    for(int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];
        if(keyVal.find(remain) != keyVal.end())
        {
            return{keyVal[remain], i};
        }
        else
        {
            keyVal[nums[i]] = i;
        }
    }
    return {};
}

int main()
{
    std::vector<int> test = {3,2,4};
    int target = 6;

    auto result = twoSum(test, target);
    for(auto a : result)
    {
        std::cout << a << " ";
    }
    std::cout << endl;
    return 0;
}