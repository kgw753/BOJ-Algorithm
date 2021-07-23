#include<bits/stdc++.h>
using namespace std;
int N, num, SET = 0;
char order[11];
vector<int> ans;
int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%s %d", order, &num);
        if(order[0] == 'a' && order[1] == 'l') SET = (1 << 22) - 1;
        else if(order[0] == 'e') SET = 0;
        else if(order[0] == 'a' && order[1] == 'd') SET |= (1 << num);
        else if(order[0] == 'r') SET &= ~(1 << num);
        else if(order[0] == 'c') printf("%d\n", (SET & (1 << num)) ? 1 : 0);
        else if(order[0] == 't') (SET & 1 << num) ? SET &= ~(1 << num) : SET |= (1 << num);
    }
}