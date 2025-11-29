#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){

            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            } else {
                // [1,3],[2,6]
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},
                                     {2,6},
                                     {8,10},
                                     {15,18}};
    vector<vector<int>> ans = sol.merge(intervals);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
}
