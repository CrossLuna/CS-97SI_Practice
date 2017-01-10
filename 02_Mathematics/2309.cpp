#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T-->0) {
		unsigned r;
		cin >> r;
		if(r % 2 != 0) {
			cout << r << ' ' << r << endl;
			continue;
		}
		unsigned filter_one = r ^ (r & (r-1));
		unsigned one = filter_one;
		unsigned filter_low = 0;
		while(one) {
			filter_low |= one;
			one >>= 1;
		}

		unsigned filter_high = 0;
		one = filter_one;
		one <<= 1;
		while(one) {
			filter_high |= one;
			one <<= 1;
		}
		
		unsigned low = (r & filter_high) + 1;
		unsigned high = r | filter_low;
		cout << low << ' ' << high << endl;
	}
	return 0;
}