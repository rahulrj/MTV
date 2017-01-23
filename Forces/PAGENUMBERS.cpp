http://codeforces.com/problemset/problem/34/C

#include <bits/stdc++.h>

using namespace std;
int arr[1001];
int main()
{
	int n;
	bool flag=true;
	while(scanf("%d,",&n)!=EOF) arr[n]=1;
	for(int i=1,j=1; i<1001; i=++j)
		if(arr[i])
		{
			for(j=i; arr[j]; j++);
			--j;
			if(flag) flag=false;
			else printf(",");
			if(i==j) printf("%d",i);
			else printf("%d-%d",i,j);
		}
	return printf("\n"), 0;
}
