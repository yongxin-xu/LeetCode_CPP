#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        if (s.length() == 0) { return true; }
        return helper(s, 0, 0);
    }

private:
    bool helper(string s, int pos, int left) {
        if (s.length() == pos && left == 0) { return true; }
        if (s.length() == pos && left > 0) { return false; }
        if (left < 0) { return false; }
        if (s[pos] == '(') {
            return helper(s, pos+1, left+1);
        } else if (s[pos] == ')') {
            return helper(s, pos+1, left-1);
        } else /* star */ {
            if (left == 0) {
                return helper(s, pos+1, left+1) ||
                       helper(s, pos+1, left);       
            } else {
                return helper(s, pos+1, left+1) ||
                    helper(s, pos+1, left-1) ||
                    helper(s, pos+1, left);
            }
        }
    }
};

int main() {
    Solution s;
    string str = "(*)";
    cout << s.checkValidString(str) << endl;
    return 0;
}