http://codeforces.com/problemset/problem/144/C

#include<cstdio>
char s[100005],p[100005];
int T[1<<8],c[1<<8],i,j,L,A;
main(){
	scanf("%s%s",s,p);
	for(i=0;p[i];i++)
		T[p[i]]++;
	L=i;
	for(i=0;i<L-1;i++)
		c[s[i]]++;
	for(;s[i];i++){
		c[s[i]]++;
		if(i>=L)
			c[s[i-L]]--;
		for(j='a';j<='z';j++)
            if(c[j]>T[j]){
				A--;
				break;
			}
		A++;
	}
	printf("%d",A);
}
