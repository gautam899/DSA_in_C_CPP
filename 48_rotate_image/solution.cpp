#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    void rotate_image(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<r;c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
        for(int r=0;r<rows;r++){
            reverse(matrix[r].begin(),matrix[r].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    Solution sol;
    sol.rotate_image(matrix);
    for(int r=0;r<matrix.size();r++){
        for(int c=0;c<matrix[0].size();c++){
            cout<<matrix[r][c]<<" "; 
        }
        cout<<"\n";
    }

}