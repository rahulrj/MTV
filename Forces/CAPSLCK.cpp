http://codeforces.com/problemset/problem/131/A

#include <cstdio>
char a[105];
main()
{
    int i=1,f=1;
    gets(a);
    for(;a[i];)f&=(a[i++]<'a');
    for(i=0;a[i];)
    putchar(a[i++]^f*32);
}
