#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int MINV = 0;

int find_max(vector<int>& arr) {
    int max_sofar = MINV;
    int max_ = MINV;
    for(int i=0; i<arr.size(); ++i) {
        max_ = max(max_ + arr[i], MINV);
        max_sofar = max(max_, max_sofar);
    }
    return max_sofar;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int> > m (N, vector<int>(N, 0));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> m[i][j];
        }
    }
    int ans = -127;

    for(int i=0; i<N; ++i) {
        for(int j=i; j<N; ++j) {
            vector<int> arr(N, 0);
            for (int k=0; k<N; ++k) {
                for(int r=i; r<=j; r++) {
                    arr[k] += m[r][k];
                }
            }
            ans = max(ans, find_max(arr));
        }
    }

    cout << ans << endl;
    return 0;
}