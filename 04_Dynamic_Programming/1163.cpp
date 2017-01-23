#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> dp(N, 0);
    for(int layer = 1; layer <= N; ++layer) {
        vector<int> ndp(N, 0);
        for(int i=0; i<layer; ++i) {
            int n;
            cin >> n;
            ndp[i] = dp[i] + n;
            if(i != 0) {
                ndp[i] = max(ndp[i], dp[i-1] + n);
            }
        }
        swap(dp, ndp);
    }

    int m = dp[0];
    for(int i=1; i<N; i++) {
        m = max(m, dp[i]);
    }
    cout << m << endl;

    return 0;
}