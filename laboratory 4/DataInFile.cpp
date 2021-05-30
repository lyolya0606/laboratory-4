#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

map<string, int> DataInFile() {
  map<string, int> words;
  ifstream file;
  ofstream existFile;
  string path = "generalWords.txt";
  file.open(path);

  if (!file.is_open()) {
    existFile.open(path);
    existFile.close();
    file.open(path);
  }

  while (!file.eof()) {
    string str;
    int number;
    file >> str >> number;

    if (str == "") {
      continue;
    }

    if (str.length() > 0) {
      words[str] = number;
    }  
  }
  file.close();
  return words;
}
