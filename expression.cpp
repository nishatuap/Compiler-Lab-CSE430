#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class postfix
{
    char post[30],inf[30];
    int top,y,op;
    float oper[30],stac[30],so;
    public:
        postfix()
        {
            top=-1;y=0,op=0;
        }
        void convert()
        {
            char temp[30];
            int z;
            for(int i=0;inf[i]!=0;i++)
            {
                if(inf[i]>=48&&inf[i]<=57)
                {
                    post[y++]=inf[i];
                    for(z=i;inf[z]<=57&&inf[z]>=48||inf[z]=='.';z++)
                          temp[z-i]=inf[z];
                    temp[z-i]='\0';
                    oper[op++]=atof(temp);
                    i=z-1;
                }
                else
                {
                    switch(inf[i])
                    {
                    case '+':
                    case '-':
                        while(top>=0&&stac[top]!='(')
                            post[y++]=stac[top--];
                        stac[++top]=inf[i];
                        break;
                    case '*':
                    case '/':
                        while(stac[top]!='+'&&stac[top]!='-'&&top>=0&&stac[top]!='(')
                            post[y++]=stac[top--];
                        stac[++top]=inf[i];
                        break;
                    case '^':
                        stac[++top]=inf[i];
                        break;
                    case '(':
                        stac[++top]=inf[i];
                        break;
                    case ')':
                        while(stac[top]!='(')
                                post[y++]=stac[top--];
                        top--;
                        break;
                    }
                }
            }
            while(top>=0)
                post[y++]=stac[top--];
        }
        float solve()
        {
            op=0;
            for(int i=0;i<y;i++)
            {
                if(post[i]>=48&&post[i]<=57)
                    stac[++top]=oper[op++];
                else
                {
                    switch(post[i])
                    {
                    case '+':
                        so=stac[top]+stac[top-1];
                        stac[--top]=so;
                        break;
                    case '-':
                        so=stac[top-1]-stac[top];
                        stac[--top]=so;
                        break;
                    case '*':
                        so=stac[top-1]*stac[top];
                        stac[--top]=so;
                        break;
                    case '/':
                        so=stac[top-1]/stac[top];
                        stac[--top]=so;
                        break;
                    case '^':
                        so=powf(stac[top-1],stac[top]);
                        stac[--top]=so;
                        break;
                    }
                }
            }
            return stac[0];
        }
        void getdata()
        {
            cout<<"Enter expression : ";
            cin.getline(inf,30);
        }
};
int main()
{
    postfix con;
    con.getdata();
    con.convert();
    cout<<con.solve();
    return 0;
}
