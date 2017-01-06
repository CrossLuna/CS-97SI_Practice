#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    const double PI = acos(-1.0);
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        printf("Scenario #%d:\n", i);
        double R;
        int n;
        scanf("%lf %d", &R, &n);
        
        double r = R/( 1 + 1.0/(sin(PI/n)));
        printf("%.3f\n\n", r);
    }
    return 0;
}
