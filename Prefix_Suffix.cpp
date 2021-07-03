#include<bits/stdc++.h>

using namespace std;

vector < int > Kmp_array(string p){

    int n = p.size();

    vector< int > v( n+5 );

    int i = 0,index = -1;

    v[ i ] = index;

    while(i < n){

        while(index >= 0 && p[ i ] != p[ index ]) index = v[ index ];

        i++,index++;

        v[ i ] = index;
    }

    return v;
}

int KMP(string s,string p){

    int s_size = s.size(),p_size = p.size();

    int mx = -1,i = 0,index = 0;

    vector< int > v = Kmp_array( p );

    while(i < s_size){

        while(index >= 0 && s[ i ] != p[ index ]) index = v[ index ];

        i++,index++;
    }

    return index;
}

int main(){

    int n;

    cin >> n;

    string ans,s,temp;

    cin >> ans;
    n--;

    cout << ans << endl;

    while(n--){

        cin >> s;

        cout << s << endl;

        int index = KMP(ans,s);

        ans += s.substr(index,s.size());
    }

    cout << ans << endl;

    return 0;
}
