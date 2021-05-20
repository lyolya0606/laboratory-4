#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

void SearchForWorld(string str, map<string, int> &words, map<string, int> m = {});
bool HasString(map<string, int> words, string str);
void SearchingSimilarWords(map<string, int> &m, string str, int tmp = 1);
