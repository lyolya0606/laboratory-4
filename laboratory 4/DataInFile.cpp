#include <iostream>
#include <string>
#include <fstream>
#include <map>
//#include <utility>
#include "FormattingInput.h"

using namespace std;

bool CheckingDataInFile() {
  const int FILE_HAS_DATA = 0;
  ifstream file;
  file.open("alphabet.txt");
  string line = "";
  string stringGeneral = "";

  while (!file.eof()) {
    getline(file, line);
    stringGeneral += line;// += stringstream
  }
  if (stringGeneral.length() != FILE_HAS_DATA) {
    file.close();
    return true;
  } else {
    file.close();
    return false;
  }
}

map<string, int> DataInFile(string path) {
  map<string, int> words;
  ifstream file;
  ofstream existFile;
  //file.open("alphabet.txt");
  //file.open("byQuantity.txt");
  file.open(path);
  if (!file.is_open()) {
    existFile.open(path);
    existFile.close();
    file.open(path);
  }

  if (CheckingDataInFile()) {
    while (!file.eof()) {
      string str;
      int number;
      file >> str >> number;
     /* if (str == "") {
        break;
      }*/
      if (str.length() > 0) {
        words[str] = number;
      }
    }
    file.close();   
  }
  return words;
}
