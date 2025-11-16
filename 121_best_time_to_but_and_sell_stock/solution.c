#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max_profit(int *prices, int n){
    int mini = *prices;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int x = *(prices+i) - mini;
        if(x > ans){
            ans = x;
        }
        if(*(prices+i) < mini){
            mini = *(prices+i);
        }
    }
    return ans;
}
int main(){
    // int prices[] = {7,6,5,4,3,2,1}; // 0
    int prices[] = {7,1,5,3,6,4}; // 5
    int n = sizeof(prices)/sizeof(prices[0]);
    int ans = max_profit(prices, n);
    printf("The maximum profit that can be earned is %d", ans);
}