#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    // DYNAMIC PROGRAMMING APPROACH
    // int n = nums.size();
    // vector<int> dp(n, 10001); // set all targets to infinity
    // dp[n - 1] = 0;  // set goal to 0, i.e., 0 steps to reach target if starting from target
    // for(int i = n - 2; i >= 0; i--) {   // start from back
    //     for(int j = 1; j <= nums[i]; j++) {     // check for complete jump rannge
    //         dp[i] = min(dp[i], 1 + dp[min(n - 1, i + j)]);      // 
    //     }
    // }
    // return dp[0];
    //  O(n*n) & O(n)
    
    // BFS or GREEDY APPROACH
    int i = 0, jumps = 0, maxReachable = 0, lastJumpedPos = 0, n = nums.size();
    while(lastJumpedPos < n - 1) {
        maxReachable = max(maxReachable, i + nums[i]);
        if(i == lastJumpedPos) {
            lastJumpedPos = maxReachable;
            jumps++;
        }
        i++;
    }
    return jumps;
    // O(n) & O(1)
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    cout << jump(v);
    return 0;
}