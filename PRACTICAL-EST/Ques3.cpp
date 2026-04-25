#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int x : nums) {
        res ^= x;
    }
    return res;
}

int main() {
    vector<int> nums = {2,2,1};
    cout << singleNumber(nums);
}