#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
 
using namespace std;
 
struct Student {
  string name;
  int age;
  int id;
};
 
vector<Student> students;
vector<Student*> p_students;
 
string filename = "names.txt";
string delimiter = ":";
int find_age = 26;
size_t pos = 0;
int k = 1;
 
void read_students(){
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      Student tmp_student;
      tmp_student.age = atoi(line.substr(0, line.find(delimiter)).c_str());
      line.erase(0, line.find(delimiter) + delimiter.length());
      tmp_student.name = line;
      tmp_student.id = k;
      k++;
      students.push_back(tmp_student);
      //p_students.push_back(&tmp_student);
    }
    file.close();
  }
}
 
bool less_age(const Student* left, const Student* right) {
  return left->age < right->age;
}

Student* kobein(){
  int begin = 0;
  int end = p_students.size();
  int midle = 0;
  int x = 0;

  while((x = p_students[midle = (begin + end)/2]->age) != find_age){
    if(x < find_age)
      begin = midle;
    else
      end = midle;
  }
  return p_students[midle];
}
 
int main() {
  read_students();
  for (int i = 0; i < students.size(); i++) {
        p_students.push_back(&students[i]);
    }
  //print_students();
  //cout << students[1].name << endl;
  sort(p_students.begin(), p_students.end(), less_age);
  for (int i = 0; i < p_students.size(); i++) {
        cout << " " << p_students[i]->id << " " << p_students[i]->name << " " << p_students[i]->age << endl;
    }
  cout << endl;
  for (int i = 0; i < students.size(); i++) {
        cout << " " << students[i].id << " " << students[i].name << " " << students[i].age << endl;
    }
  cout << endl;
  cout << kobein()->name;
  //"id": 0, "name": "Adams", "age": 18
  //print_students();
  //cout << (*p_students[0]).name << endl;
  //cout << p_students[0]->name << endl;

  
}