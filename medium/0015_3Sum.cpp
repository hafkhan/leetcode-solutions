#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int i = 0;
    int numSize = nums.size();
    while(i < nums.size() - 2)
    {
        if (nums[i] <= 0)
        {
            int value = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == value)
                {
                    result.push_back(std::vector<int>({nums[i], nums[j], nums[k]}));
                    j++;
                    if (j < k)
                    {
                        while (nums[j] == nums[j - 1] && j < k)
                        {
                            j++;
                        }
                    }
                }
                else if (nums[j] + nums[k] > value)
                {
                    k--;
                    if(j < k)
                    {
                        while(nums[k] == nums[k + 1] && j < k)
                        {
                            k--;
                        }
                    }
                }
                else
                {
                    j++;
                    if (j < k)
                    {
                        while (nums[j] == nums[j - 1] && j < k)
                        {
                            j++;
                        }
                    }
                }
            }
        }
        else
        {
            break;
        }
        i++;
        if(i < numSize - 2)
        {
            while(nums[i] == nums[i - 1] && i < numSize - 2)
            {
                i++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto result = threeSum(nums);
    for (auto tuples : result)
    {
        for (auto val : tuples)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}