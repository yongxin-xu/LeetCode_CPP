#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int cnt;
        string ret = "";
        for (auto &oneShift : shift) {
            cnt = cnt + oneShift[1] * ((oneShift[0]==1) ? 1 : -1);
        }
        ret = shiftHelper(s, cnt);
        return ret;
    }

private:
    string shiftHelper(string &s, int cnt) {
        string ret;
        // convert left shift to right shift
        cnt = (cnt > 0) ? cnt % s.length() : s.length() - ((-cnt) % s.length());
        if (cnt == 0 || cnt == s.length()) { return s; }
        
        string newHead = s.substr(s.length()-cnt);
        string newTail = s.substr(0, s.length()-cnt);
        ret = newHead + newTail;
        return ret;
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    vector<vector<int> > shift = {{1,1}, {1,1}, {0,2}, {1,3}};
    cout << s.stringShift(str, shift) << endl;

    vector<vector<int> > shift2 = {{1,14}};
    cout << s.stringShift(str, shift2) << endl;

    vector<vector<int> > shift3 = {{0,7}};
    cout << s.stringShift(str, shift3) << endl;

    vector<vector<int> > shift4 = {{0,7}, {0,5}, {1,3}, {0,2}};
    cout << s.stringShift(str, shift4) << endl;
}