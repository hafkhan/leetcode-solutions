#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s)
{
    int par = 0;
    int bra = 0;
    int ako = 0;
    vector<int> order;
    for(auto c: s)
    {
        if(c == '{' || c == '[' || c == '(')
        {
            if(c == '(')
            {
                par++;
                order.push_back(0);
            }
            else if(c == '[')
            {
                bra++;
                order.push_back(1);
            }
            else if(c == '{')
            {
                ako++;
                order.push_back(2);
            }
        }
        else if(c == '}' || c == ']' || c == ')')
        {
            if(order.size() == 0)
            {
                return false;
            }
            if(c == ')')
            {
                if(order.back() == 0)
                {
                    par--;
                }
                else
                {
                    return false;
                }
            }
            else if(c == ']')
            {
                if(order.back() == 1)
                {
                    bra--;
                }
                else
                {
                    return false;
                }
            }
            else if(c == '}')
            {
                if(order.back() == 2)
                {
                    ako--;
                }
                else
                {
                    return false;
                }
            }
            order.pop_back();
        }
    }
    if(par == 0 && bra == 0 && ako == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    std::string ss("([()])");
    std::cout << isValid(ss) << std::endl;
    return 0;
}