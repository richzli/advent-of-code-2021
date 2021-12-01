#include "../template.hpp"

int main() {
    vi nums;
    int num, sum = 0, idx = 3, count = 0;
    rep(i,0,3) {
        cin >> num;
        sum += num;
        nums.pb(num);
    }
    while (cin >> num) {
        nums.pb(num);
        if (sum < sum - nums[idx-3] + num) {
            ++count;
        }
        sum = sum - nums[idx-3] + num;
        ++idx;
    } 
    cout << count;
}