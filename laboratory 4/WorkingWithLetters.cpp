#include <iostream>
#include <string>

using namespace std;

string ChangeCapitalLetters(string str) {
  const char delta = 'a' - 'A';
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + delta;
    }
  }
  return str;
}

bool IsLetter(char symbol) {
  return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

bool AreGoodSymbols(string str) {
  for (auto symbol : str) {
    if (symbol < ' ' || symbol > '~') {
      return false;
    }
  }
  return true;
}