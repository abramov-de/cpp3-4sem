#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

class Ch{
public:
  Ch(char cc, int nn)
    : c(cc)
    , n(nn)
    , left(NULL)
    , right(NULL) {}
  char c;
  int n;
  Ch* left;
  Ch* right;
};

map<char, int> m;
vector<Ch> chs;
//Ch root;

bool comp(const Ch left, const Ch right) {
  return left.n > right.n;
}



int main() {

  for(char& с : s) {
    m[с] = 0;
  }

  map <char, int> :: iterator it = m.begin();

  for(char& с : s) {
    m[с]++;
  }

  for (int i = 0; it != m.end(); it++, i++) { 
    cout << i << ") Ключ " << it->first << ", значение " << it->second <<   endl;
    //chs[i] = {it->first, it->second};
    Ch f(it->first, it->second);
    chs.push_back(f);
}

  sort(chs.begin(), chs.end(), comp);
  for (int i = 0; i < chs.size(); i++) {
    cout << i << ": " << chs[i].c << " " << chs[i].n << endl;
  }
  
  Ch tmp_ch(0,0);
  while(chs.size() > 2){
    tmp_ch.right = &chs[chs.size()-1];
    tmp_ch.left = &chs[chs.size()-2];
    tmp_ch.n = tmp_ch.left->n + tmp_ch.right->n;
    chs.pop_back();
    chs.pop_back();
    chs.push_back(tmp_ch);
    sort(chs.begin(), chs.end(), comp);
  }

  Ch root(0,0);
  root.right = &chs[chs.size()-1];
  root.left = &chs[chs.size()-2];
  root.n = root.left->n + root.right->n;
  chs.pop_back();
  chs.pop_back();

  while(root.left != NULL){
    root = *root.left;
    cout << "0";
  }

  cout << ": " << int(root.c);

  //cout << root.left->c;
  //find_left(&root);
  //cout << m[' '] << endl; // 68

}