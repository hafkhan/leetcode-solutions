#include <iostream>
#include <string>
#include <vector>

typedef uint8_t u_char;

using namespace std;
string minWindow(string s, string t) 
{
    if(s.size() < t.size() || t == "")
    {
        return "";
    }
    int s_table[128] = {0};
    int t_table[128] = {0};
    int distinct_chars = 0;
    for(int i = 0; i < t.size(); i++)
    {
        u_char c = t[i];
        if(t_table[c] == 0)
            distinct_chars++;
        t_table[c]++;
    }
    int left_index = 0;
    int right_index = 0;
    int distinct_t = 0;
    int min_window = INT_MAX; 
    int final_left_index = 0;
    for(right_index = 0; right_index < s.size(); right_index++)
    {
        u_char c = s[right_index];
        s_table[c]++;

        if(t_table[c] > 0 && t_table[c] == s_table[c])
        {
            //cout << "distinct : " << distinct_t << endl;

            distinct_t++;
        }
        while(distinct_t == distinct_chars)
        {
            if(right_index - left_index + 1 < min_window)
            {
                min_window = right_index - left_index + 1;
                final_left_index = left_index;
            }
            //cout << "left idx = " << left_index << " char: " << s << " "  << t  << " min : " << min_window << endl;
            u_char c2 = s[left_index];
            s_table[c2]--;
            if(t_table[c2] > 0 && (s_table[c2] < t_table[c2]))
            {
                distinct_t--;
            }
            left_index++;
        }
    }
    if(min_window == INT_MAX) 
        return ""; 
    else
        return s.substr(final_left_index, min_window);
}


int main()
{
    cout << minWindow("aassasdfdddffff","asdf") << endl;
    return 0;
}