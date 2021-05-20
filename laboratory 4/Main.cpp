#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "FormattingInput.h"
#include "Beginning.h"

using namespace std;

void WorkingWithWords();
void CheckingTests();

enum actionWithText {
  TEXT_WORK = 1,
  TEXT_TEST
};

enum endOfProgram {
  QUIT = 1,
  CONTINUE
};


int main() {
  Greeting();
  int userChoice = 0;
  bool stop;

  do {
    do {
      Menu();
      userChoice = GetInt();

      switch (userChoice) {

      case TEXT_WORK:
        WorkingWithWords();
        stop = true;
        break;

      case TEXT_TEST:
        CheckingTests();
        stop = true;
        break;

      default:
        cout << "There is no such choice!" << endl;
        stop = false;
      }

    } while (stop == false);

    do {
      cout << endl << "Press 1 to finish" << endl;
      cout << "Press 2 to continue" << endl;
      userChoice = GetInt();

      if (userChoice != QUIT && userChoice != CONTINUE) {
        cout << "There is no such choice!" << endl;
      }
    } while (userChoice != QUIT && userChoice != CONTINUE);

  } while (userChoice != QUIT);

  return 0;
}

