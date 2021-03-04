class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // for those not on the boundaries
        // a[i][i] = a[i-1][i-1] + a[i-1][i]; 
        vector<vector<int> > res;
        
        for (int n = 1; n <= numRows; n++) {
            vector<int> row;
            for (int i = 0; i < n; i++) {
                if (i == 0 || i == n - 1) row.push_back(1);
                else row.push_back(res[n-2][i-1] + res[n-2][i]);
            }
            res.push_back(row);
        }
        
        
        return res;
    }
};