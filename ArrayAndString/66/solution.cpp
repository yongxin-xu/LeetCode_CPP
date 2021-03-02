#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rise = 1;
        int tmp = digits[digits.size()-1] + 1;
        if (tmp < 10) {
            digits[digits.size()-1] = tmp;   
        } else {
            digits[digits.size()-1] = 0;
            for (int i = digits.size()-2; i >= 0; i--) {
                tmp = digits[i] + 1;
                rise = (tmp == 10) ? 1 : 0;
                digits[i] = (rise) ? 0 : tmp;
                if (!rise) break;
            }
            if (rise)
                digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};