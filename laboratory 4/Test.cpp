#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "WorkingWithWords.h"

using namespace std;

bool Test1() {
  string str = "Hello, world, hello, World";
  map<string, int> words;
  map<string, int> correctWords;
  SearchForWorld(str, words);

  correctWords["hello"] = 2;
  correctWords["world"] = 2;

  if (words["hello"] == correctWords["hello"] && words["world"] == correctWords["world"]) {
    return true;
  } else {
    cout << "Test 1 failed" << endl
      << "Expected data:" << endl;
    for (map<string, int >::const_iterator it = correctWords.begin(); it != correctWords.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl << "Result data:" << endl;
    for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    return false;
  }
}

bool Test2() {
  string str = "We really really really love programming";
  map<string, int> words;
  map<string, int> correctWords;
  SearchForWorld(str, words);

  correctWords["we"] = 1;
  correctWords["really"] = 3;
  correctWords["love"] = 1;
  correctWords["programming"] = 1;

  if (words["we"] == correctWords["we"] && words["really"] == correctWords["really"] &&
    words["love"] == correctWords["love"] && words["programming"] == correctWords["programming"]) {
    return true;
  } else {
    cout << "Test 2 failed" << endl
      << "Expected data:" << endl;
    for (map<string, int >::const_iterator it = correctWords.begin(); it != correctWords.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl << "Result data:" << endl;
    for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    return false;
  }
}

bool Test3() {
  string str = "She and she and she are students";
  map<string, int> words;
  map<string, int> correctWords;
  SearchForWorld(str, words);

  correctWords["she"] = 3;
  correctWords["and"] = 2;
  correctWords["are"] = 1;
  correctWords["students"] = 1;

  if (words["she"] == correctWords["she"] && words["and"] == correctWords["and"] &&
    words["are"] == correctWords["are"] && words["students"] == correctWords["students"]) {
    return true;
  } else {
    cout << "Test 3 failed" << endl
      << "Expected data:" << endl;
    for (map<string, int >::const_iterator it = correctWords.begin(); it != correctWords.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl << "Result data:" << endl;
    for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    return false;
  }
}

bool Test4() {
  string str = "The weather is so so good good";
  map<string, int> words;
  map<string, int> correctWords;
  SearchForWorld(str, words);

  correctWords["the"] = 1;
  correctWords["weather"] = 1;
  correctWords["is"] = 1;
  correctWords["so"] = 2;
  correctWords["good"] = 2;

  if (words["weather"] == correctWords["weather"] && words["is"] == correctWords["is"] &&
    words["so"] == correctWords["so"] && words["good"] == correctWords["good"] &&
    words["the"] == correctWords["the"]) {
    return true;
  } else {
    cout << "Test 4 failed" << endl
      << "Expected data:" << endl;
    for (map<string, int >::const_iterator it = correctWords.begin(); it != correctWords.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl << "Result data:" << endl;
    for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    return false;
  }
}

bool Test5() {
  string str = "people, People are are are very kind";
  map<string, int> words;
  map<string, int> correctWords;
  SearchForWorld(str, words);

  correctWords["people"] = 2;
  correctWords["are"] = 3;
  correctWords["very"] = 1;
  correctWords["kind"] = 1;

  if (words["people"] == correctWords["people"] && words["are"] == correctWords["are"] &&
    words["very"] == correctWords["very"] && words["kind"] == correctWords["kind"]) {
    return true;
  } else {
    cout << "Test 5 failed" << endl
      << "Expected data:" << endl;
    for (map<string, int >::const_iterator it = correctWords.begin(); it != correctWords.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl << "Result data:" << endl;
    for (map<string, int >::const_iterator it = words.begin(); it != words.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
    return false;
  }
}

void CheckingTests() {
  int counter = 0;
  const int ALL_TESTS_PASSED = 5;

  if (Test1()) {
    counter++;
  }
  if (Test2()) {
    counter++;
  }
  if (Test3()) {
    counter++;
  }
  if (Test4()) {
    counter++;
  }
  if (Test5()) {
    counter++;
  }
  if (counter == ALL_TESTS_PASSED) {
    cout << "All tests passed successfully!" << endl;
  }
}