http://codeforces.com/problemset/problem/58/A

#include <cstdio>
char A[10]="hello",a;
int i;
int main(){
    while(scanf("%c",&a) && a!='\n')if(a == A[i])i++;printf(i==5 ? "YES" : "NO");
}
