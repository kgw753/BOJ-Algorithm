#include<bits/stdc++.h>
using namespace std;

int main(){
    int N = 1;
    vector<int> answer;
    while(true){
        cin >> N;
        if(N == 0) break;

        vector<int> numbers;
        int num;
        int zero = 0;
        for(int i = 0; i < N; i++){
            cin >> num;
            numbers.push_back(num);

            if(num == 0) zero++;
        }

        sort(numbers.begin(), numbers.end());

        for(int i = 0; i < min(2, zero); i++){
            int tmp = numbers[i];
            numbers[i] = numbers[i + zero];
            numbers[i + zero] = tmp;
        }

        int num1 = 0;
        int num2 = 0;

        for(int num: numbers){
            if(zero == 1 && num == 0){
                num2 = num2 * 10;
                continue;
            }
            int tmp1 = num1 * 10 + num;
            int tmp2 = num2 * 10 + num;
            if(tmp1 >= tmp2) num2 = tmp2;
            else num1 = tmp1;
        }

        answer.push_back(num1 + num2);
    }

    for(int ans: answer){
        cout << ans << "\n";
    }
}