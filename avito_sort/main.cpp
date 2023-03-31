#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



using namespace std;

vector<string> split1 (string s, string start, string end){
  size_t pos = 0, start_len = start.length(), end_len = end.length();
  std:: string token;
  vector<string> res;
  while ((pos = s.find(start)) != std::string::npos){
    s.erase(0, pos +start.length());
    pos = s.find(end);
    token = s.substr(0, pos);
    s.erase(0, pos + end.length());
    res.push_back(token);
    
  }
  return res;
}

int main() {
    std::ifstream inFile;
    inFile.open("avito1.txt"); 

    std::stringstream strStream;
    strStream << inFile.rdbuf(); 
    std::string str = strStream.str(); 
  
    string start = "target=\"_blank\" rel=\"noopener\" title=\"";
    string end = "\" itemProp=\"url\" data-marker=\"item-title\"";
    string start2 = "<meta itemProp=\"price\" content=\"";
    string end2 = "\"/><meta itemProp=\"availability\" content=";
    
    vector<string> v2 = split1(str, start, end);
    for (auto i : v2) cout << i << endl;

    vector<string> v4 = split1(str, start2, end2);
    vector<int> v5;

  cout << endl;
  for(int i = 0; i < v2.size(); i++){
    vector<string> v3 = split1(v2[i], ", ", " ");
    //cout << v3[0] << endl;
    //cout << v4[i] << endl;
    
    v5.push_back(atoi(v4[i].c_str()) / atoi(v3[0].c_str()));
  }

    for (auto i : v5) cout << i << endl;
    int x = 0;
    for (int i = 0; i < v5.size(); ++i){
      if (v5[i] < v5[x]) x = i;
    }

  cout << endl << v5[x] << endl << x << endl;

  string start5 = "<div class=\"iva-item-titleStep-pdebR\"><a href=\"/dolgoprudnyy/kvartiry/";
  string end5 = " target=\"_blank\" rel=\"noopener\" title=";
  vector<string> v6 = split1(str, start5, end5);
  cout << "https://www.avito.ru/dolgoprudnyy/kvartiry/" + v6[x];
    return 0;
}
