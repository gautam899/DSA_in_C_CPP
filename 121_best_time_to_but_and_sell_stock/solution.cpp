#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = INT_MIN; //Keep track of the minimimum of the currecnt element
        for(int i=0;i<prices.size();i++){
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};

int main(){
    // vector<int> prices = {7,1,5,3,6,4}; // 5
    vector<int> prices = {7,6,5,4,3,2,1}; // 0
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout<<"The maximum profit that can be made is: "<< ans;
    return 0;
}