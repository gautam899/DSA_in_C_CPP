#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> helper(vector<int> &v) {
    	/*
	// This problem can be solved in various ways.
	// 1. Use a visited/frequency array to keep track of how many 
	// times the element is visited. Freq 0 is missing and freq 2 is repeated.
	// 2. We can use the array itself to negate the value at index corresponding 
	// to the value at the current index. (A better solution)
	int n = v.size();
	int repeated, missing;
	for(int i=0;i<n;i++) {
	    int val = abs(v[i]);
	    if(v[val-1] > 0){
	    	v[val-1] = -v[val-1];
	    }
	    else {
	    	repeated = val;
	    }
	}

	// Second pass. Whatever is left positive is the missing.
	for(int i=0;i<n;i++) {
	   if(v[i] > 0) {
	   	missing = i+1;
	   }
	}
	return {repeated, missing};
	*/

	/****************   Approach 2 ******************/
	// The most optimal way of doing this problem is to use the XORing of all elements.
        int xor_all = 0;
        vector<int> ans;
        int n = v.size();
        for(int i=0;i<n;i++){
            xor_all ^= v[i];
            xor_all ^= (i+1);
        }
        // All the even occuring elements will cancel out and only remaining will
        // be the missing ^ repeating.
        // Find the position of first right most set bit.
        int right_most_set = xor_all & ~(xor_all -1);
        // Divide the numbers in two groups. The one with this bit set and one which this bit not set.
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(v[i] & right_most_set){
                x^=v[i];
            }
            else{
                y^=v[i];
            }
            
            if((i+1) & right_most_set){
                x^=(i+1);
            }else{
                y^=(i+1);
            }
        }
        // cout<<x<<" "<<y;
        // Now we have out set of answers x,y but we still do not know which one is missing and repeating.
        //
        int xcnt=0,missing,repeating;
        for(int i=0;i<n;i++){
            if(v[i] == x){
                xcnt++;
            }
        }
        
        if(xcnt==0){
            ans = {y,x};
        }else{
            ans = {x,y};
        }
        return ans;
    }

    /*
     * Let's take an example
     * [1,3,3]
     * First pass: 
     * i=0 a[0] = 1. Mark a[1-1] = a[0] = 1 = -1.
     * Updated array: [-1,3,3]
     * i=1 a[1] = 3, Mark a[3-1] = a[2] = 3 as -3
     * Updated array: [-1,3,-3]
     * i=2 a[2] = 3 a[2] = -3, already negative i.e means somewhere before we have had val as 3 already because of which we
     * ended up in a[3-1] again.
     */
};

int main() {
    Solution sol;
    vector<int> v = { 4,3,6,2,1,1 };
    vector<int> ans = sol.helper(v);
    cout << "Repeated: " << ans[0] << "\n";
    cout << "Missing: " << ans[1] << "\n";
    return 0;
}
