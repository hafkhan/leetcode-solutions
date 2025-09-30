#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> lowerPart;
    priority_queue<int, vector<int>, std::greater<int>> upperPart; 
    vector<int> allData;
    void refineHeaps()
    {
        if(lowerPart.size() > 0 & upperPart.size() > 0)
        {
            if(lowerPart.top() > upperPart.top())
            {
                int lowMax = lowerPart.top();
                int highMin = upperPart.top();
                lowerPart.pop();
                upperPart.pop();
                lowerPart.push(highMin);
                upperPart.push(lowMax);
            }
        }
    }
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        //cout << " ----- " << lowerPart.size() << " ----- " << upperPart.size() << endl;
        if(lowerPart.size() == upperPart.size())
        {
            lowerPart.push(num);
            refineHeaps();
        }
        else
        {
            upperPart.push(num);
            refineHeaps();
        }
    }
    
    double findMedian() {
        double median = 0.0;
        // cout << " ----- " << lowerPart.size() << " ----- " << upperPart.size() << endl;
        if(lowerPart.size() == upperPart.size())
        {
            double ltop = lowerPart.top();
            double rtop = upperPart.top();
            median = (ltop + rtop) / 2.0;
        }
        else
        {
            median = lowerPart.top();
        }
        return median;
    }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout << medianFinder.findMedian()  << endl;// return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout << medianFinder.findMedian() << endl; // return 2.0
    return 0;
}