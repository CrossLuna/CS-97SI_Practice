#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
struct Point{
    LL x;
    LL y;
};

int dx[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};


int main() {
    int T;
    cin >> T; 
    while(T-->0) {
        string str;
        cin >> str;
        LL ans = 0;
        Point currP, nextP;
        currP.x = 0;
        currP.y = 0;
        nextP.x = 0;
        nextP.y = 0;
        if(str.size() > 2) {
            for(int i=0; i<str.size()-1; ++i) { // neglect final '5'
                currP = nextP;
                nextP.x += dx[str[i] - '0'];
                nextP.y += dy[str[i] - '0'];
                ans += (currP.x * nextP.y - currP.y * nextP.x);
            }   
        }
        //cout << abs(ans/2.0) << endl;
        if(ans < 0)
            ans = -ans;
        if(ans % 2 == 0) {
            cout << ans/2 << endl;
        }
        else {
            cout << ans/2 << ".5" << endl;
        }
    }
    return 0;
}