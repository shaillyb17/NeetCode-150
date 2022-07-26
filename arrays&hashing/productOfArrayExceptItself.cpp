#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1), right(n, 1);
    for(int i = 1; i < n; i++)
        left[i] = left[i-1] * nums[i-1];
    for(int i = n - 2; i >= 0; i--)
        right[i] = right[i+1] * nums[i+1];
    for(int i = 0; i < n; i++)
        left[i] *= right[i];
    return left;
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)      cin >> v[i];
    vector<int> res = productExceptSelf(v);
    for(int i = 0; i < n; i++)      cout << res[i];
    return 0;
}