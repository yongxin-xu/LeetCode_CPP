#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int> > pq;
        for (auto &stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push((x<=y)?y-x:x-y);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};

int main() {
    Solution s;
    vector<int> a = {2,7,4,1,8,1};
    int ret = s.lastStoneWeight(a);
    cout << ret << endl;
}