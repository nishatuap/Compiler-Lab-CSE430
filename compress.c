#include<stdio.h>

char* StrCompress(char myStr[])
{
    char *s = myStr;
    char *r, *p;
    int count, i;

    while (*s)
    {
        /*initially only 1 character of a kind is present*/
        count = 1;

        /*we check whether current character matches the next one*/
        while (*s && *s == *(s+1))
        {
            /*if yes,then increase the count due to the match
            and increment the string pointer to next */
            count++;
            s++;
        }

        if (count > 1) /*if more than one character of a kind is present*/
        {
            /*assign the value of count to second occurence of a particular character*/
            *(s - count + 2) = count + '0';

            /*delete all other occurences except the first one and second one using array shift*/
            for (i = 0; i < count - 2; i++)
            {
                p = s + 1;
                r = s;

                while (*r)
                    *r++ = *p++;

                s--;
            }
        }
        s++;
    }

    return myStr;
}

int main()
{    printf("Enter string: ");
    char myStr[1000];
    scanf ("%[^\n]", &myStr);
    printf("Compressed String: %s\n", StrCompress(myStr));

    return 0;
}
