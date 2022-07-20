#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize != 0)
        return false;
    map<int, int> mp;
    for(auto x: hand)
        mp[x]++;
    while(mp.size()) {
        int start = mp.begin()->first;
        for(int i = 0; i < groupSize; i++) {
            if(mp[start + i] == 0)
                return false;
            --mp[start + i];
            if(mp[start + i] < 1)
                mp.erase(start + i);
        }
    }
    return true;
}

int main(){
    int n;	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int k; cin >> k;
    cout << isNStraightHand(v, k);
    return 0;
}