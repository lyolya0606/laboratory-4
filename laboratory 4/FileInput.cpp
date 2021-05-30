#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

ifstream OpenFileInput(void);

void FileInput(vector<string> &lines) {
  string str;
  ifstream file;

  file = OpenFileInput();

  while (!file.eof()) {
    getline(file, str);
    lines.push_back(str);
  }
  cout << "Read data:" << endl;

  for (int i = 0; i < lines.size(); i++) {
    cout << lines[i] << endl;
  }
  file.close();
}
