#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> gen_prime(int N) { // N >= 3
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for(int c = 5; c <= N; ++c) {
        bool is_prime = true;
        for(vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            if((*it) * (*it) > c) break;
            if(c % (*it) == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) {
            primes.push_back(c);
        }
    }
    return primes;
}

int main() {
    vector<int> primes = gen_prime(1000000);
    int N;
    while(cin >> N) {
        if(N == 0) break;
        for(vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            int target = N - (*it);
            if(binary_search(it, primes.end(), target)) {
                cout << N << " = " << *it << " + " << target << endl;
                break;
            }
        }
    }
    return 0;
}
