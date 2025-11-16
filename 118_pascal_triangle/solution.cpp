#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for(int i=0;i<numRows;i++){
            res[i].resize(i+1);
            // The first and the last column of all the rows will be one.
            res[i][0] = res[i][i] = 1;
            // Process from the first column to the last column.
            for(int j=1;j<i;j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

int main(){
   Solution sol;
   vector<vector<int>> ans = sol.generate(5);
   for (const auto& row : ans) {
        for (const auto& val : row) {
            cout << std::setw(3) << val;
        }
        cout << '\n';
   }
}
