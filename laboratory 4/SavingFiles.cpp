#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "FormattingInput.h"

using namespace std;

ofstream OpenFileOutput(void);

void SavingFilesAlphabet(map<string, int> words) {
  ofstream file;
  file.open("alphabet.txt");

  for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
    file << it->first << " " << it->second << endl;
  }

  file.close();
}


void SavingFilesByQuantity(map<string, int> words) {
  ofstream file;
  file.open("byQuantity.txt");

  vector<pair<string, int>> v;
  for (map<string, int>::const_iterator it = words.begin(); it != words.end(); ++it) { // ???
    v.push_back(pair(it->first, it->second));
  }

  sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) { // ???
    return a.second > b.second;
  });
  
  for (auto p : v) {
    file << p.first << " " << p.second << endl;
  }  
}

void SavingFilesInput(vector<string> lines) {
  cout << endl << "Press 1 if you want to save your input in the file" << endl
    << "Press 2 if you DON'T want to save your input in the file" << endl;
  int choice = GetInt();
  const int SAVING = 1;
  const int NOT_SAVING = 2;

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    for (int i = 0; i < lines.size(); i++) {
      file << lines[i] << endl;
    }

    file.close();
  } 
}

void SavingFilesGeneral(map<string, int> words) {
  ofstream file;
  file.open("generalWords.txt");

  for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
    file << it->first << " " << it->second << endl;
  }
  file << endl;

  file.close();
}