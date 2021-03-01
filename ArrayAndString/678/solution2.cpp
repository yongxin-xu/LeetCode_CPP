#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*') ++left;
            else --left;
            if (left < 0) return false;
        }
        if (left == 0) return true;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') ++right;
            else --right;
            if (right < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = "(*)";
    cout << s.checkValidString(str) << endl;
    return 0;
}