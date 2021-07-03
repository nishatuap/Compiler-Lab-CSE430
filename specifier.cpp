/**
    University Of Asia Pacific

    Sabuj Kumar Tarofdar

    ID : 17101139
**/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; i++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    //file();

    map< string,bool > mp;
    map< char,bool > mp1;

    mp1[ '`' ] = true;
    mp1[ '~' ] = true;
    mp1[ '!' ] = true;
    mp1[ '@' ] = true;
    mp1[ '#' ] = true;
    mp1[ '%' ] = true;
    mp1[ '^' ] = true;
    mp1[ '&' ] = true;
    mp1[ '*' ] = true;
    mp1[ '(' ] = true;
    mp1[ ')' ] = true;
    mp1[ '-' ] = true;
    mp1[ '+' ] = true;
    mp1[ '/' ] = true;
    mp1[ '.' ] = true;
    mp1[ '<' ] = true;
    mp1[ '>' ] = true;
    mp1[ '=' ] = true;
    mp1[ '{' ] = true;
    mp1[ '}' ] = true;
    mp1[ '[' ] = true;
    mp1[ ']' ] = true;
    mp1[ '}' ] = true;
    mp1[ '\\' ] = true;
    mp1[ '|' ] = true;
    mp1[ ';' ] = true;
    mp1[ ':' ] = true;
    mp1[ '$' ] = true;
    mp[ "scanf" ] = true;
    mp[ "printf" ] = true;
    mp[ "for" ] = true;
    mp[ "while" ] = true;
    mp[ "if" ] = true;
    mp[ "else" ] = true;
    mp[ "int" ] = true;
    mp[ "float" ] = true;
    mp[ "double" ] = true;
    mp[ "string" ] = true;
    mp[ "cin" ] = true;
    mp[ "cout" ] = true;
    mp[ "bool" ] = true;
    mp[ "char" ] = true;

    string s;

    getline(cin,s);

    bool flag = true;

    if(mp[ s ]){

        flag = false;
    }
    else{

        if(s.size() > 31 or s[ 0 ] >= '0' and s[ 0 ] <= '9') flag = false;
        else{

            for(int i = 0; i < s.size(); i++){

                if(s[ i ] == ' ' or mp1[ s[ i ] ] ){

                    flag = false;
                    break;
                }
            }
        }
    }

    if(flag)  cout << "Valid\n";
    else cout << "Not Valid\n";

    return 0;
}
