#include<bits/stdc++.h>
using namespace std;
string input, del;
string go(string str){
    for(int i = 0; i <= str.length() - del.length(); i++){
        if(del == str.substr(i, del.length())) {
            if(str.length() == del.length()) return "FRULA";
            else return go(str.erase(i, del.length()));
        }
    }
    return str;
}
int main(){
    cin >> input >> del;
    cout << go(input) <<"\n";
}