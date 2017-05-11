#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    string str;
    cin >>str;
    vector<int> dp (N, 0);
    for(int i=N-1; i>=0; --i) {
        vector<int> new_dp(N, 0);
        for(int j=i; j<N; ++j) {
            if(str[i] == str[j]) {
                if(j - i > 2) {
                    new_dp[j] = dp[j-1];
                }
            }
            else {
                new_dp[j] = min(dp[j], new_dp[j-1]) + 1;
            }
        }
        swap(new_dp, dp);
    }
    cout << dp.back() << endl;
    return 0;
}