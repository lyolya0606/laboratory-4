#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "WorkingWithLetters.h"

using namespace std;

void SearchingSimilarWords(map<string, int> &m, string str, int tmp = 1) {
  map<string, int>::iterator it = m.find(str);
  if (it != m.end()) {
    (it->second) += tmp;  

  } else {
    if (tmp > 1) {
      m[str] = tmp;
    } else {
      m[str] = 1;
    }
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
        string oneWord = str.substr(start, end - start);
        string wordInSmallLeters = ChangeCapitalLetters(oneWord);
        if (HasString(m, wordInSmallLeters) || m.size() == 0) {
          if (HasString(m, wordInSmallLeters)) {
            int number = m[wordInSmallLeters];
            SearchingSimilarWords(words, wordInSmallLeters, number - 1);
          }
          SearchingSimilarWords(words, wordInSmallLeters);
        }
      }

    } else {
      if (start != -1) {
        end = i;
        string oneWord = str.substr(start, end - start);
        string wordInSmallLeters = ChangeCapitalLetters(oneWord);// this is a word
        if (HasString(m, wordInSmallLeters) || m.size() == 0) {
          if (HasString(m, wordInSmallLeters)) {
            int number = m[wordInSmallLeters];
            SearchingSimilarWords(words, wordInSmallLeters, number - 1);

          }
          SearchingSimilarWords(words, wordInSmallLeters);
        }
      }
      start = -1;
    }
  }
}





