#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1, sum = 0;
    vector<int> res(2);
    while(i < j) {
        sum = nums[i] + nums[j];
        if(sum < target)
            i++;
        else if(sum > target)
            j--;
        else {
            res[0] = i + 1;
            res[1] = j + 1;
            return res;
        }
    }
    return {};
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int t;      cin >> t;
    vector<int> res = twoSum(v, t);
    cout << res[0] << " " << res[1];
    return 0;
}