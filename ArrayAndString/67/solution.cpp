class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        
        int i=a.length()-1, j=b.length()-1;
        
        for (; i >= 0 && j >=0; i--,j--) {
            int digit = static_cast<int>(a[i] - '0') + static_cast<int>(b[j] - '0');
            digit = carry ? digit+1 : digit;
            if (digit >= 2) { carry = true; res = res + myInt2bin(digit-2); }
            else { carry = false; res = res + myInt2bin(digit); }
        }
        
        for (; i >=0; i--) {
            int digit = carry ? static_cast<int>(a[i] - '0') + 1 : static_cast<int>(a[i] - '0');
            if (digit >= 2) { carry = true; res = res + myInt2bin(digit-2); }
            else { carry = false; res = res + myInt2bin(digit); }
        }
        
        for (; j >=0; j--) {
            int digit = carry ? static_cast<int>(b[j] - '0') + 1 : static_cast<int>(b[j] - '0');
            if (digit >= 2) { carry = true; res = res + myInt2bin(digit-2); }
            else { carry = false; res = res + myInt2bin(digit); }
        }
        
        if (carry) { res = res + "1"; }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
private:
    inline char myInt2bin(int a) {
        return a ? '1' : '0';
    }
};