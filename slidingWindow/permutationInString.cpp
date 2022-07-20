#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    unordered_map<char, int> mp;
    for(auto x: s1) {
        mp[x]++;
    }
    int i = 0, j = 0, count = mp.size();
    while(j < n) {
        if(mp.find(s2[j]) != mp.end()) {
            mp[s2[j]]--;
            if(mp[s2[j]] == 0)
                count--;
        }
        if(j - i + 1 < m)       // extend window size till m
            j++;
        else if(j - i + 1 == m) {       // if window size is reached, evaluate
            // check if a permutation is found
            if(count == 0)
                return true;
            // otherwise slide the window
            if(mp.find(s2[i]) != mp.end()) {
                mp[s2[i]]++;
                if(mp[s2[i]] == 1)
                    count++;
            }
            i++, j++;
        }
    }
    return false;        
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << checkInclusion(s1, s2);
    
    return 0;
}