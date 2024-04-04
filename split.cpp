#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, string delimeter) {
  vector<string> res;
  int pos;

  while ((pos = str.find(delimeter)) != string::npos) {
    res.push_back(str.substr(0, pos));
    str.erase(0, pos + delimeter.length());
  }

  res.push_back(str);
  return res;
}

int main() {
  string str = "우드드득 최고최고 화이팅!!";
  vector<string> res = split(str, " ");

  for (string s : res)
    cout << s << "\n";
}