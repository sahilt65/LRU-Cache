#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);
        return it->second;
    }
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cacheList.erase(it);
        }
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
        if (cacheList.size() > capacity) {
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }
    }
};

int main(){
    LRUCache l = LRUCache(2);
    l.put(1, 1);
    l.put(2, 2);
    int el = l.get(1);
    cout<<"Element at 1 : "<<el<<endl;
    l.put(3, 3);
    el = l.get(2);
    cout<<"Element at 2 : "<<el<<endl;
    l.put(4, 4);
    el = l.get(1);
    cout<<"Element at 1 : "<<el<<endl;
    el = l.get(3);
    cout<<"Element at 3 : "<<el<<endl;
    el = l.get(4);
    cout<<"Element at 4 : "<<el<<endl;





}