#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k, payment = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        payment += nums[i];
    }
    sort(nums.rbegin(), nums.rend());
    for (int i = k - 1; i < n; i+=k) payment -= nums[i];
    cout << payment;
    return 0;
}