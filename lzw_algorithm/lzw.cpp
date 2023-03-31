#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string s0 = "abcde";
string s = "abacabadabacabae"; //01025039864
string s_ = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

map<string, int> mp;
string tmp = "";
string tmp_ = "";
string s2 = "";
string s_2 = "";

int main(){
	int next = 'z' + 1;
	
	for(char& c : s_){
	string tm(1,c);
	mp[tm] = (int)c;
	}
	
	int index = 0;
	while (index < s_.length()){
	int flag = 0;
	
	while ((mp.find(s_.substr(index, flag + 1)) != mp.end()) and (index + flag < s_.length())){
		flag++;
	}
	if (flag == 0){
		cout << mp[s_.substr(index, flag + 1)];
		index += flag + 1;
	} else {
		cout << mp[s_.substr(index, flag)];
		mp[s_.substr(index, flag)];
		next++;
		index += flag;
	}
	}
	return 0;
}
