#include <bits/stdc++.h>
using namespace std;
int N;
string str, input;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  cin >> N;
  cin >> str;

  int pos = str.find('*');
  string prefix = str.substr(0, pos);
  string suffix = str.substr(pos + 1);

  for (int i = 0; i < N; i++) {
    cin >> input;

    if (prefix.size() + suffix.size() > input.size()) {
      cout << "NE\n";
    } else {
      if (prefix == input.substr(0, pos) &&
          suffix == input.substr(input.size() - suffix.size()))
        cout << "DA\n";
      else
        cout << "NE\n";
    }
  }
}