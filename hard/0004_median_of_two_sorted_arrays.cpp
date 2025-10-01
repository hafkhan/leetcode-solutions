#include <iostream>
#include <vector>
#include <string>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    int m = nums1.size();
    int n = nums2.size();
    double result = 0.0;
    int lo = 0;
    int hi = m;
    int totalLeft = (m + n + 1) / 2;
    while (lo <= hi)
    {
        int i = lo + (hi - lo) / 2;
        int j = totalLeft - i;
        int leftA = ((i == 0) ? INT_MIN : nums1[i - 1]);
        int rightA = ((i == m) ? INT_MAX : nums1[i]);
        int leftB = ((j == 0) ? INT_MIN : nums2[j - 1]);
        int rightB = ((j == n) ? INT_MAX : nums2[j]);
        if (leftA <= rightB && rightA >= leftB)
        {
            // cout << "A: "<< leftA<< " " << rightA << endl << "B: "<< leftB<< " " << rightB << endl;
            if ((m + n) % 2 == 0)
            {
                double Amax = max(leftA, leftB);
                double Bmin = min(rightA, rightB);
                result = (Amax + Bmin) / 2.0;
            }
            else
            {
                result = max(leftA, leftB);
            }
            break;
        }
        else if (leftA > rightB)
        {
            hi = i - 1;
        }
        else
        {
            lo = i + 1;
        }
    }
    return result;
}
int main()
{
    vector<int> num1= {};
    vector<int> num2 = {2};
    cout << findMedianSortedArrays(num2,num1);
    return 0;
}