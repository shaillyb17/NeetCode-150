#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftBound(n);
    vector<int> rightBound(n);
    vector<int> minLim(n);
    int sum = 0, leftM = INT_MIN, rightM = INT_MIN;
    leftBound[0] = 0, rightBound[n-1] = 0;
    for(int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
        leftM = max(leftM, height[i-1]);
        leftBound[i] = leftM;
        rightM = max(rightM, height[j+1]);
        rightBound[j] = rightM;
    }
    for(int i = 0; i < n; i++) {
        minLim[i] = min(leftBound[i], rightBound[i]);
    }
    for(int i = 0; i < n; i++) {
        if(height[i] < minLim[i])
            sum += minLim[i] - height[i];
    }
    return sum;        
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)      cin >> v[i];
    cout << trap(v);
    return 0;
}