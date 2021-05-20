#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "FormattingInput.h"
#include "WorkingWithLetters.h"
#include "WorkingWithWords.h"
#include "Input.h"
#include "SavingFiles.h"
#include "Beginning.h"

using namespace std;

map<string, int> DataInFile(string path);

enum inputChoice {
  KEYBOARDINPUT = 1,
  FILEINPUT
};


//int CounterWords(string str) {
//  bool flag = false;
//  int counter = 0;
//  for (int i = 0; i < str.length() + 1; i++) {
//    if (IsLetter(str[i])) {
//      flag = true;
//    } else {
//      if (flag) {
//        counter++;
//        flag = false;
//      }
//    }
//  }
//  return counter;
//}

int ChoiceNumberOfWords(map<string, int> &m) {
  cout << endl << "There are " << m.size() << " different words in the text" << endl
    << "How many words do you want to write to the file?" << endl
    << "(you can enter a number from 0 to " << m.size() << ")" << endl;
  int userChoice = GetInt();
  while (userChoice < 0 || userChoice > m.size()) {
    cout << "You can't enter this number. Try again." << endl;
    userChoice = GetInt();
  }
  return userChoice;
}

void PrintMap(const map<string, int>& m) {
  for (map<string, int >::const_iterator it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}

void WorkingWithWords() {
  map<string, int> words;
  map<string, int> wordsAlphabet;
  map<string, int> selectedWords;
  map<string, int> wordsByQuantity;
  vector<string> lines;

  int userChoice = 0;
  bool stop;
  int choiceNumberOfWords = 0;
  
  do {

    MenuWorkText();
    userChoice = GetInt();

    switch (userChoice) {

    case KEYBOARDINPUT: {
      KeyboardInput(lines);
      for (auto s : lines) {
        SearchForWorld(s, words);
      }
      cout << endl << "Words and number of occurrences" << endl;
      PrintMap(words);

      choiceNumberOfWords = ChoiceNumberOfWords(words);
      int i = 0;
      string generalStr = "";

      for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
        if (i == choiceNumberOfWords) {
          break;
        }
        selectedWords[it->first] = it->second;
        generalStr += it->first;
        generalStr += " ";
        i++;
      }

      SavingFilesInput(lines);
      wordsAlphabet = DataInFile("alphabet.txt");
      SearchForWorld(generalStr, wordsAlphabet, selectedWords);
      SavingFilesAlphabet(wordsAlphabet);

      wordsByQuantity = DataInFile("byQuantity.txt");
      SearchForWorld(generalStr, wordsByQuantity, selectedWords); 
      SavingFilesByQuantity(wordsByQuantity);
      stop = true;
    }
      break;

    case FILEINPUT: {
      FileInput(lines);
      for (auto s : lines) {
        SearchForWorld(s, words);
      }
      cout << endl << "Words and number of occurrences" << endl;
      PrintMap(words);

      choiceNumberOfWords = ChoiceNumberOfWords(words);
      int i = 0;
      string generalStr = "";

      for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
        if (i == choiceNumberOfWords) {
          break;
        }
        selectedWords[it->first] = it->second;
        generalStr += it->first;
        generalStr += " ";
        i++;
      }

      SavingFilesInput(lines);
      wordsAlphabet = DataInFile("alphabet.txt");
      SearchForWorld(generalStr, wordsAlphabet, selectedWords);
      SavingFilesAlphabet(wordsAlphabet);

      wordsByQuantity = DataInFile("byQuantity.txt");
      SearchForWorld(generalStr, wordsByQuantity, selectedWords);
      SavingFilesByQuantity(wordsByQuantity);
      stop = true;
    }
      break;

    default:
      cout << "There is no such choice!" << endl;
      stop = false;
    }

  } while (stop == false);
}