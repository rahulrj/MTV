#include <bits/stdc++.h>
using namespace std;

string s[50005];

bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
		cout<<s[i];
	cout<<endl;
}
