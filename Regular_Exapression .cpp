#include<bits/stdc++.h>

using namespace std;

string s;
char c;

bool check_char(char c){

    if(c >= '0' and c <='9')return false;

    if(c >= 'a' and c <= 'z' or c >= 'A' or c <= 'Z') return true;
}

int convert(int i,int n){

    int a = 0;


    for(int j = i; j < n; j++){

        if(s[ j ] >= '0' and s[ j ] <= '9'){

            a = a * 10;

            a += (s[ j ] - 48);
        }
        else break;
    }

    return a;
}

void print_char(char a,char b){

    int n = b;

    for(int i = a; i <= n; i++){

        char c = i;

        cout << c;
    }

    cout << endl;
}

void print_number(int a,int b){

    for(int i = a; i <= b; i++) cout << i;

    cout << endl;
}

string convert_string(int a,int b){

    string ss = "";
    int i;

    for(i = a; i < b; i++){

        if(s[ i ] != ')') {

            if(s[ i ] == '+' or s[ i ] == '*') continue;

            ss += s[ i ];
        }
        else break;
    }

    c = s[ i + 1 ];

    return ss;
}

void print_normal(){

    for(int i = 0; i < 5 ; i++){

        for(int j = 0; j < s.size(); j++){

            if(s[ j + 1 ] == '*'){

                if(s[ j ] != '(' and s[ j ] != ')')
                for(int k = 0; k < i; k++)cout << s[ j ];
            }
            else if(s[ j + 1 ] == '+'){

                if(s[ j ] != '(' and s[ j ] != ')')
                for(int k = 0; k <= i; k++) cout << s[ j ];
            }
            else if(s[ j ] != '*' and
                    s[ j ] != '+' and
                    s[ j ] != '(' and
                    s[ j ] != ')')
                    cout << s[ j ];
            else if(s[ j ] == '('){

                string ch = convert_string(j+1,s.size());

                if(c == '*')for(int k = 0; k < i; k++) cout << ch;
                else if(c == '+')for(int k = 0; k <= i; k++) cout << ch;

                j = j + ch.size() + 1;
            }
        }
        cout << endl;
    }
}
int main(){

    while(getline(cin,s)){

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] == '[' ){

                if(s[ i + 1 ] == ' ') continue;

                if(check_char(s[ i + 1 ])){

                    char a = s[ i + 1 ];
                    char b;

                    for(int j = i + 2; j < s.size(); j++){

                        if(s[ j ] >= 'a' and s[ j ] <= 'z'){

                            b = s[ j ];
                            break;
                        }
                        else if(s[ j ] >= 'A' and s[ j ] <= 'Z'){

                            b = s[ j ];
                            break;
                        }
                    }
                    print_char(a,b);
                    break;
                }
                else {

                    int a = convert(i+1,s.size());
                    int b;

                    for(int j = i + 2; j < s.size(); j++){

                        if(s[ j ] >= '0' and s[ j ] <= '9'){

                            b = convert(j,s.size());
                            break;
                        }
                    }
                    print_number(a,b);
                    break;
                }
            }
            else{

                print_normal();
                break;
            }
        }

        puts("");

    }

    return 0;
}
