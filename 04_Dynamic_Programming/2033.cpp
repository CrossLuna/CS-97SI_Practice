#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    string str;
    while(cin >> str) {
        if (str == "0") break;
        vector<int> arr(str.size()+1);
        arr[0] = 1;
        arr[1] = 1;
        str.insert(0, "0");
        for(int i=2; i<arr.size(); ++i) {
            string s = str.substr(i-1, 2);
            int co = atoi(s.c_str());
            if(10 <= co && co <= 26)
                arr[i] += arr[i-2];
            if(str[i] != '0')
                arr[i] += arr[i-1];
        }

        cout << arr.back() << endl;
    }
    return 0;
}