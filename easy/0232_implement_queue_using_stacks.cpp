#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <ranges>

using namespace std;

class MyQueue {
private:
    stack<int> head;
    stack<int> tail;
    void modifyStacks()
    {
        vector<int> tempStack;
        while(!head.empty())
        {
            tempStack.push_back(head.top());
            head.pop();
        }
        while(!tail.empty())
        {
            tail.pop();
        }
        for(auto iter = tempStack.begin(); iter != tempStack.end(); iter++)
        {
            tail.push(*iter);
        }
        for(auto iter = tempStack.rbegin(); iter != tempStack.rend(); iter++)
        {
            head.push(*iter);
        }
    }
    void modifyStacksTail()
    {
        vector<int> tempStack;
        while(!tail.empty())
        {
            tempStack.push_back(tail.top());
            tail.pop();
        }
        while(!head.empty())
        {
            head.pop();
        }
        for(auto iter = tempStack.begin(); iter != tempStack.end(); iter++)
        {
            head.push(*iter);
        }
        for(auto iter = tempStack.rbegin(); iter != tempStack.rend(); iter++)
        {
            tail.push(*iter);
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        if(head.size() == 0 && tail.size() == 0)
        {
            head.push(x);
            tail.push(x);
        }
        else
        {
            head.push(x);
            modifyStacks();
        }
    }
    
    int pop() {
        int val = tail.top();
        tail.pop();
        modifyStacksTail();
        return val;
    }
    
    int peek() {
        return tail.top();
    }
    
    bool empty() {
        if(head.size() == 0)
            return true;
        return false;
    }
};


int main()
{
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl;// return false
    return 0;
}