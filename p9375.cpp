#include<bits/stdc++.h>
using namespace std;
int tc, n, c;
string item, type;
vector<int> answer;

int main(){
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> n;
        map<string, int> m;
        for(int j = 0; j < n; j++){
            cin >> item >> type;
            m[type]++;
        }
        int r = 1;
        for(auto t: m) r *= t.second + 1; // '������ ��' �� ���ϰ� ����
        answer.push_back(r - 1);    // '��� ������ ��' �� ��
    }
    for(int a: answer) cout << a << "\n";
}