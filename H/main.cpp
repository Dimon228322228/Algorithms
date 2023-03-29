#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k, payment = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < n; i++) cout << i << ": " << nums[i] << "\t";

    for (int i = 0; i < (n / k) * k; i += k)
        for (int j = 0; j < k - 1; j++) {
            payment += nums[i + j];
            cout << nums[i+j] << "  " << i + j << "\n";
            cout << i << " " << j << "\n";
        }

    for (int i = (n / k) * k; i < n; i++) {
        payment += nums[i];
        cout << nums[i] << "  " << i<< "\n";
        cout << i << " " << "\n";
    }

    cout << payment;
    return 0;
}