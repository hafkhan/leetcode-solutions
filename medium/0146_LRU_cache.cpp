#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
class LRUCache {
private:
    unordered_map<int,vector<int>> myCache;
    map<int,int> accessMap;
    int capacity;
    int time = 0;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        myCache.reserve(capacity);
    }
    
    int get(int key) 
    {
        auto findRes = myCache.find(key);
        if(findRes != myCache.end())
        {
            auto sec = findRes->second;
            //cout << "----- : " << key << "    " << sec[1] << endl;
            accessMap.erase(sec[1]);
            myCache[key] = std::vector<int>({sec[0], time});
            accessMap[time] = key;
            time++;
            return sec[0];
        }
        else
        {
            time++;
            return -1;
        }
    }
    
    void put(int key, int value) 
    {
        if(myCache.size() < capacity)
        {
            auto findRes = myCache.find(key);
            if(findRes == myCache.end())
            {
                myCache.emplace(key,vector<int>({value,time}));
                accessMap[time] = key;
            }
            else
            {
                accessMap.erase(findRes->second[1]);
                findRes->second = std::vector<int>({value,time});
                accessMap[time] = key;
            }
        }
        else
        {
            auto findRes = myCache.find(key);
            if(findRes == myCache.end())
            {
                int keyToDelete = accessMap.begin()->second;
                accessMap.erase(accessMap.begin());
                myCache.erase(keyToDelete);
                myCache[key] = vector<int>({value,time});
                accessMap[time] = key;
            }
            else
            {
                accessMap.erase(findRes->second[1]);
                myCache[key] = std::vector<int>({value,time});
                accessMap[time] = key;
            }
        }
        time++;
    }
};


int main()
{
    LRUCache myCach(2);
    myCach.put(2,1);
    myCach.put(1,1);
    myCach.put(2,3);
    myCach.put(4,1);
    cout << myCach.get(1) << endl;
    cout << myCach.get(2) << endl;
    return 0;
}