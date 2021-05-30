#include <iostream>
#include <string>
#include <vector>
#include "WorkingWithLetters.h"

using namespace std;

void KeyboardInput(vector<string> &lines) {
  const string END = "end";
  string str = "";
  cout << endl << "Enter the text. If you want to finish, write \"" << END << "\"" << endl;
  while (str != END) {
    getline(cin, str);
    if (str == END) {
      break;
    }
    if (!AreGoodSymbols(str)) {
      cout << "You entered bad symbols. Please, try again." << endl;
    } else {
      lines.push_back(str);
    }    
  }
}