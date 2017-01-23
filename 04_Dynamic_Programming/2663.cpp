#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
int main() {
    int n;
    vector<ULL> dp;
    dp.push_back(1);
    dp.push_back(0);
    dp.push_back(3);
    for(int i=3; i<=30; i++) {
        if(i % 2 != 0)
            dp.push_back(0);
        else {
            ULL sum = 3 * dp[i-2];
            for(int j = i-4; j >= 0; j -= 2) {
                sum += 2 * dp[j];
            }
            dp.push_back(sum);
        }
    }
    while (cin >> n) {
        if(n == -1) break;
        cout << dp[n] << endl;
    }
    return 0;
}