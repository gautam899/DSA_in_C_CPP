#include<stdio.h>
#include<stdlib.h>

int findDuplicate(int *arr){
    int slow = *(arr+0);
    int fast = *(arr+0);
    do {
    	slow = *(arr + slow);
	fast = *(arr + *(arr + fast));
    } while(slow != fast);
    slow = *(arr + 0); // Point the slow pointer back to the head node.
    while(fast != slow) {
    	slow = *(arr+slow);
	fast = *(arr+fast);
    }
    return slow;
}

int main() {
    int nums[] = {1,3,4,2,2};
    int ans = findDuplicate(nums);
    printf("The duplicate numbers is %d", ans);
    return 0;
}
