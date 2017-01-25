#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
const int INF = 0x3FFFFFFF;

int cal_len(vector<int>& arr, int i, int j) {
    int ans = 0;
    while(i < j) {
        ans += arr[j] - arr[i];
        i++; 
        j--;
    }
    return ans;
}

int main() {
    int V, P;
    cin >> V >> P;
    vector<int> arr(V+1);
    for(int i=1; i<=V; ++i)
        cin >> arr[i];
    vector<vector<int> > dp(P+1, vector<int>(V+1, INF));
    vector<vector<int> > cost(V+1, vector<int>(V+1, 0));
    dp[0][0] = 0;
    
    for(int i=1; i<=V; ++i) {
        for(int j=i; j<=V; ++j) {
            cost[i][j] = cal_len(arr, i, j);
        }
    }


    for(int i=1; i<=P; ++i) {
        for(int j=i; j<=V; ++j) {
            for(int k=0; k<j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[k+1][j]);
            }
        }
    }
    
    cout << dp[P][V] << endl;

    return 0;
}