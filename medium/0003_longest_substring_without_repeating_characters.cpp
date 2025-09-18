#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int maxLen = 0;
    vector<int> values(256,-1);
    int windowLeft = 0;

    for(int i = 0; i < s.length(); i++)
    {
        unsigned char c = s[i];
        if(values[c] >= windowLeft)
        {
            windowLeft = values[c] + 1;
        }
        values[c] = i;
        maxLen = max(maxLen, i - windowLeft + 1);
    }
    return maxLen;
}

int main()
{
    vector<string> tests = {
        "abcabcbb",  // 3 ("abc")
        "bbbbb",     // 1 ("b")
        "pwwkew",    // 3 ("wke")
        "",          // 0
        " ",         // 1
        "tmmzuxt"    // 5 ("mzuxt")
    };
    for (auto& s : tests) {
        cout << "\"" << s << "\" -> " << lengthOfLongestSubstring(s) << "\n";
    }
    return 0;
}