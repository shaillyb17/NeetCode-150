#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        return -1;
    int fuelStat = 0;
    int pitStop = 0;
    for(int i = pitStop; i < n; i++) {
        fuelStat += gas[i];
        fuelStat -= cost[i];
        if(fuelStat < 0) {
            pitStop = i + 1;
            fuelStat = 0;
        }
    }
    return pitStop;
}

int main(){
    int n;	cin >> n;
    vector<int> gas(n), cost(n);
    for(int i = 0; i < n; i++)      cin >> gas[i];
    for(int i = 0; i < n; i++)      cin >> cost[i];
    cout << canCompleteCircuit(gas, cost);
    return 0;
}