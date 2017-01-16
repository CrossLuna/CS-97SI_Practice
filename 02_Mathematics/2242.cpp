#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);

struct Point{
    double x;
    double y;
};

double dist_2(Point& a, Point& b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double dist(Point& a, Point& b) {
    return sqrt(dist_2(a, b));
}

int main() {
    Point pa, pb, pc;
    while(cin >> pa.x) {
        cin >> pa.y >> pb.x >> pb.y >> pc.x >> pc.y;
        double ea = dist(pb, pc);
        double eb = dist(pa, pc);
        double ec = dist(pa, pb);
        double denom1 = ea + eb + ec;
        double denom2 = -ea + eb + ec;
        double denom3 = ea - eb + ec;
        double denom4 = ea + eb - ec;
        double R = ea * eb * ec / sqrt(denom1 * denom2 * denom3 * denom4);
        printf("%.2f\n", PI * R * 2);
    }
}