#include<bits/stdc++.h>

using namespace std;

int main(){


    string s,sub;
    bool flag = true;
    cin >> s;
    cin >> sub;

    int ans = INT_MAX;

    map<char,int> mp;

    for(int i = 0; i < s.size(); i++) mp[ s[ i ] ]++;

    for(int i = 0; i < sub.size(); i++) {

        if(mp[ sub[ i ] ] == 0){

            flag = false;
            break;
        }

        ans = min( mp[ sub[ i ] ],ans);
    }

    if(flag) cout << ans << endl;
    else cout << "NOT MATCH" << endl;

    return 0;
}
