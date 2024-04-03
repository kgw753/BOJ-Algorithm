#include <bits/stdc++.h>
using namespace std;
#define NINE 9
#define MAX 104

set<int> st;
int N = 9;

int main() {

  int input, sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> input;
    st.insert(input);
    sum += input;
  }

  int offset = sum - 100;

  for (int h : st) {
    int target = abs(offset - h);

    if (st.find(target) != st.end()) {
      st.erase(h);
      st.erase(target);

      for (int item : st)
        cout << item << "\n";

      return 0;
    }
  }
}