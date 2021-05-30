#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "WorkingWithLetters.h"

using namespace std;

void SearchingSimilarWords(map<string, int> &m, string word, int toAdd) {
  map<string, int>::iterator it = m.find(word);
  if (it != m.end()) {
    (it->second) += toAdd;  

  } else {
    m[word] = toAdd;
  }
}

bool HasString(map<string, int> words, string str) {
  for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
    if (it->first == str) {
      return true;
    }
  }
  return false;
}

void SearchForWorld(string str, map<string, int> &words, map<string, int> m = {}) {
  int start = -1;
  int end = -1;
  for (int i = 0; i < str.length(); i++) {
    if (IsLetter(str[i])) {
      if (start == -1) {
        start = i;
      }
      if (i == str.length() - 1) {
        end = i + 1;
        int number = 1;
        string oneWord = str.substr(start, end - start);
        string wordInSmallLeters = ChangeCapitalLetters(oneWord);
        if (HasString(m, wordInSmallLeters) || m.size() == 0) {
          if (HasString(m, wordInSmallLeters)) {
            number = m[wordInSmallLeters];            
          }
          SearchingSimilarWords(words, wordInSmallLeters, number);
        }
      }

    } else {
      if (start != -1) {
        end = i;
        int number = 1;
        string oneWord = str.substr(start, end - start);
        string wordInSmallLeters = ChangeCapitalLetters(oneWord);
        if (HasString(m, wordInSmallLeters) || m.size() == 0) {
          if (HasString(m, wordInSmallLeters)) {
            number = m[wordInSmallLeters];
          }
          SearchingSimilarWords(words, wordInSmallLeters, number);
        }
      }
      start = -1;
    }
  }
}





