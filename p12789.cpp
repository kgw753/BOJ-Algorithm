#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, curr = 1;
  cin >> N;
  int arr[N];

  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }

  stack<int> st;

  for(int i = 0; i < N; i++){
    if(st.empty() || arr[i] < st.top()){
      st.push(arr[i]);
    } else if(arr[i] > st.top()){
      
      break;
    }

    while(!st.empty() && curr == st.top()){
      st.pop();
      curr++;
    }
  }

  if(st.empty()) cout << "Nice" << "\n";
  else cout << "Sad" << "\n";
}