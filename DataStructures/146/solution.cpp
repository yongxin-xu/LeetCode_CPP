#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) 
            return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) 
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }

private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

int main() {
    LRUCache *cache = new LRUCache( 2 /* capacity */ );
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // returns 1
    cache->put(3, 3);    // evicts key 2
    cache->get(2);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cache->get(1);       // returns -1 (not found)
    cache->get(3);       // returns 3
    cache->get(4);       // returns 4
    return 0;
}