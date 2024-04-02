#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int size1, size2;
  cin >> size1 >> size2;
  int arr1[size1], arr2[size2];

  for (int i = 0; i < size1; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < size2; i++) {
    cin >> arr2[i];
  }

  int p1 = 0, p2 = 0;

  while (p1 < size1 && p2 < size2) {
    if (arr1[p1] < arr2[p2]) {
      cout << arr1[p1++] << " ";
    } else {
      cout << arr2[p2++] << " ";
    }
  }

  while (p1 < size1) {
    cout << arr1[p1++] << " ";
  }
  while (p2 < size2) {
    cout << arr2[p2++] << " ";
  }
}