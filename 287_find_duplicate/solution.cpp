#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute force is to use some data structure to store the frequency of elements and then find out the repeated number. The optimal approach is to use the floyd's algorithm which is used to find out the starting point of the cycle.
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast); // This is a do while loop because if the while condition is being put in the beginning then the while loop's body will never execute.
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,4,2,2};
    int ans = sol.findDuplicate(nums);
    cout << "The duplicate in nums is: " << ans;
    return 0;
}
