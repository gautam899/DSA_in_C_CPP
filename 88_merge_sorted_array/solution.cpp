#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge_sorted_array(vector<int> &nums1, int m, vector<int> &nums2, int n){
	// In order to merge two sorted array we know both the arrays are sorted in non-decreasing order the largest element will be at the end of each array. So we start comparing from the last of each array. This way we would not have to make space of each new element like we would have to do if we started from the beginning.
        int i,j,k;
        i = m-1;
        j = n-1;
        k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else {
                nums1[k--] = nums2[j--];
            }
        }
        while(i>=0){
            nums1[k--] = nums1[i--];
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    Solution sol;
    sol.merge_sorted_array(v1,3,v2,3);
    for(int i=0;i<v1.size();i++){
    	cout<< v1[i] << " ";
    }
    return 0;
}
