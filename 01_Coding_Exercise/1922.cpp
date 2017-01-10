#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

int main() {
    int N;
    const int dist = 4500;
    while(cin >> N) {
        if(N == 0) break;
        int ans = -1;
        while(N-->0) {
            int V, T;
            cin >> V >> T;
            if(T < 0) continue;
            if(ans < 0) {
                ans = ceil(dist * 36.0/(V * 10.0) + T);
            }
            else {
                int tmp_ans = ceil(dist * 36.0/(V * 10.0) + T);
                ans = min(ans, tmp_ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
