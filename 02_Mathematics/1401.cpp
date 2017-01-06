#include <cstdio>
using namespace std;

typedef long long LL;

int main() {
    int N;
    scanf("%d", &N);
    while(N-->0) {
        LL base = 5;
        int n;
        int ans = 0;
        scanf("%d", &n);
        while(n >= base) {
            ans += n/base;
            base *= 5;
        }
        printf("%d\n", ans);
    }
    return 0;
}

