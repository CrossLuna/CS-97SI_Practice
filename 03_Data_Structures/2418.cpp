#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	map<string, int> mm;
	int cnt = 0;
	string str;
	while(getline(cin, str)) {
		if(mm.find(str) != mm.end()) {
			mm[str]++;
		}
		else {
			mm[str] = 1;
		}
		cnt++;
	}
	for(map<string, int>::iterator it = mm.begin(); it != mm.end(); ++it){
		printf("%s %.4f\n",(it->first).c_str() , 100.0*static_cast<double>(it->second)/cnt);
	}
	return 0;
}