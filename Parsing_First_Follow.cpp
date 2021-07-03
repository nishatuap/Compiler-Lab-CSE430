#include<bits/stdc++.h>

using namespace std;

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);
int cnt,n = 0,m = 0;
char first_cal[ 1000 ][ 1000 ];
char follow_cal[ 1000 ][ 1000 ];
char grammer[ 1000 ][ 1000 ];
char f[ 10000 ],first[ 10000 ];

void follow(char c)
{
    if(grammer[ 0 ][ 0 ] == c)
        f[ m++ ] = '$';

    for(int i = 0; i < cnt; i++){

        for(int j = 2; grammer[ i ][ j ] != '\0' ; j++){

            if(grammer[ i ][ j ] == c){

                if(grammer[ i ][ j + 1 ] != '\0')
                    followfirst(grammer[ i ][ j + 1 ], i,(j + 2));

                if(grammer[ i ][ j + 1 ] == '\0' and c != grammer[ i ][ 0 ])
                    follow(grammer[ i ][ 0 ]);
            }
        }
    }
}

void followfirst(char c, int c1, int c2)
{
    if(!(isupper(c)))
        f[ m++ ] = c;
    else
    {
        int i = 0, j = 1;

        for(;i < cnt; i++)
            if(first_cal[ i ][ 0 ] == c)
                break;

        while(first_cal[ i ][ j ] != '!')
        {
            if(first_cal[ i ][ j ] != '#')
            {
                f[ m++ ] = first_cal[ i ][ j ];
            }
            else
            {
                if(grammer[ c1 ][ c2 ] == '\0')
                {
                    follow(grammer[ c1 ][ 0 ]);
                }
                else
                {
                    followfirst(grammer[ c1 ][ c2 ],c1,c2+1);
                }
            }
            j++;
        }
    }
}

void findfirst(char c, int q1, int q2)
{
    if(!(isupper(c))) first[ n++ ] = c;

    for(int i = 0; i < cnt; i++)
    {
        if(grammer[ i ][ 0 ] == c)
        {
            if(grammer[ i ][ 2 ] == '#')
            {
                if(grammer[ q1 ][ q2 ] == '\0')
                    first[ n++ ] = '#';

                else if(grammer[ q1 ][ q2 ] != '\0' and (q1 != 0 || q2 != 0))
                    findfirst(grammer[ q1 ][ q2 ],q1,q2 + 1);

                else first[ n++ ] = '#';
            }
            else if(!isupper(grammer[ i ][ 2 ])) first[ n++ ] = grammer[ i ][ 2 ];

            else findfirst(grammer[ i ][ 2 ],i,3);
        }
    }
}

int main(int argc, char **argv)
{
    freopen("in.txt","r",stdin);

    int in = 0;
    int im = 0;
    char c;
    cnt = 0;

    string s;

    while(true){

        if(!getline(cin,s)) break;
        int j = 2;

        grammer[ cnt ][ 0 ] = s[ 0 ];
        grammer[ cnt ][ 1 ] = '=';

        for(int i = 5; i < s.size(); i++){

            if(s[ i ] == ' ') continue;

            if(s[ i ] == '/') {

                cnt++,j = 2;
                grammer[ cnt ][ 0 ] = s[ 0 ];
                grammer[ cnt ][ 1 ] = '=';
                continue;
            }
            grammer[ cnt ][ j++ ] = s[ i ];
        }
        cnt++;
    }

    for(int i = 0; i < cnt; i++){

        cout << grammer[ i ][ 0 ] << " : ";

        for(int j = 2; j < grammer[ i ][ j ] != '\0'; j++) cout << grammer[ i ][ j ];

        cout << endl;
    }

    cout << endl;

    char done[ cnt ];
    int ptr = -1;

    for(int i = 0; i < cnt; i++)
        for(int kay = 0; kay < 1000; kay++)
            first_cal[ i ][ kay ] = '!';

    int p;

    for(int i = 0; i < cnt; i++)
    {
        c = grammer[ i ][ 0 ];
        p = 0;

        bool flag = false;

        for(int kay = 0; kay <= ptr; kay++)
            if(c == done[ kay ])
                flag = true;

        if(flag) continue;

        findfirst(c,0,0);
        ptr++;

        done[ ptr ] = c;
        printf("\n First(%c) = { ", c);
        first_cal[ i ][ p++ ] = c;

        bool foo = false;

        for(int j = 0 + in; j < n; j++) {

            bool chk = true;

            for( int k = 0; k < p; k++) {

                if (first[ j ] == first_cal[ i ][ k ]){

                    chk = false;

                    break;
                }
            }
            if(chk){

                if(foo) printf(", ");
                foo = true;

                printf("%c ", first[ j ]);

                first_cal[ i ][ p++ ] = first[ j ];
            }
        }
        printf("}\n");
        in = n;
    }

    printf("\n");
    printf("-----------------------------------------------\n\n");

    char donee[ cnt ];
    ptr = -1;

    for(int i = 0; i < cnt; i++) {
        for(int kay = 0; kay < 100; kay++) {
            follow_cal[ i ][ kay ] = '!';
        }
    }

    for(int k = 0; k < cnt; k++)
    {
        c = grammer[ k ][ 0 ];
        int p = 0;

        bool flag = false;

        for(int kay = 0; kay <= ptr; kay++)
            if(c == donee[ kay ])
                flag = true;

        if(flag) continue;

        follow( c );
        ptr += 1;

        donee[ ptr ] = c;

        printf(" Follow(%c) = { ", c);
        follow_cal[ k ][ p++ ] = c;

        bool foo = false;

        for(int i = 0 + im; i < m; i++) {

            bool flag = true;

            for(int j = 0; j < p; j++)
            {
                if (f[ i ] == follow_cal[ k ][ j ])
                {
                    flag = false;

                    break;
                }
            }
            if(flag)
            {
                if(foo) printf(", ");
                foo = true;

                printf("%c", f[ i ]);
                follow_cal[ k ][ p++ ] = f[ i ];
            }
        }
        printf(" }\n\n");
        im = m;
    }

    return 0;
}
