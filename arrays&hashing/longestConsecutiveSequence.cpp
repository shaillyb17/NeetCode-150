#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(!nums.size())    return 0;
    set<long> numSet(nums.begin(), nums.end());
    vector<int> arr(numSet.begin(), numSet.end());
    int n = numSet.size();
    long maxLen = 0, k = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != (arr[i - 1] + 1)) {
            maxLen = max(maxLen, k);
            k = 1;
        }
        else
            k++;
    }
    maxLen = max(maxLen, k);
    return maxLen;
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    cout << longestConsecutive(v);
    return 0;
}