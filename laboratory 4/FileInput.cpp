#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "WorkingWithLetters.h"

using namespace std;

ifstream OpenFileInput(void);

void FileInput(vector<string> &lines) {
  string str;
  ifstream file;
  do {
    file = OpenFileInput();

    while (!file.eof()) {
      getline(file, str);
      if (!GoodSymbols(str)) {
        cout << "There are bad symbols in the file. Please, try again." << endl;
      } else {
        lines.push_back(str);
      }
    }
  } while (!GoodSymbols(str));
  cout << "Read data:" << endl;

  for (int i = 0; i < lines.size(); i++) {
    cout << lines[i] << endl;
  }
  file.close();
}
