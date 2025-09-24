#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class MinStack {
private:
    vector<vector<int>> myStack;
    int minVal;
    int head = 0;

public:
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(head == 0)
        {
            minVal = val;
        }
        else
        {
            minVal = myStack[head-1][1];
            if(val < minVal)
            {
                minVal = val;
            }
        }
        myStack.push_back({val, minVal});
        head++;
    }
    
    void pop() {
        myStack.pop_back();
        head--;
    }
    
    int top() {
        return myStack[head-1][0];
    }
    
    int getMin() {
        return myStack[head-1][1];
    }
};

int main()
{
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;
    return 0;
}