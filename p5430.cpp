#include<bits/stdc++.h>
using namespace std;
int T, N, num;
string p, input;
deque<int> numbers;
int main(){
    cin >> T;
    while(T--){
        cin >> p >> N >> input;
        num = 0;
        numbers.clear();
        for(int i = 0; i < input.length(); i++){
            if(input[i] == '[' || input[i] == ']') continue;
            if(input[i] >= '0' && input[i] <= '9') num = (num * 10) + (input[i] - '0');
            else{
                numbers.push_back(num);
                num = 0;
            }
        }
        if(num != 0) numbers.push_back(num);
        
        bool err = false, rev = false;
        for(int i = 0; i < p.length(); i++){
            if(p[i] == 'R') rev = !rev;
            else{
                if(numbers.empty()){
                    err = true;
                    break;
                }
                if(rev) numbers.pop_back();
                else numbers.pop_front();
            }
        }
        if(err) cout << "error\n";
        else{
            if(rev) reverse(numbers.begin(), numbers.end());
            cout << '[';
            for(int i = 0; i < numbers.size(); i++){
                cout << numbers[i];
                if(i != numbers.size() - 1) cout << ',';
            }
            cout << "]\n";
        }
    }
}