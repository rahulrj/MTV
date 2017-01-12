http://codeforces.com/problemset/problem/219/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	string s;
	cin>>s;
	int a[26]={};
	for(int i=0;i<s.size();i++)
	{
		a[s[i]-'a']++;
	}
	string ans;
	for(int i=0;i<26;i++)
	{
		if(a[i]%k!=0)
		{
			ans="-1";
			k=1;
			break;
		}
		ans+=string(a[i]/k,'a'+i);
	}
	for(int i=0;i<k;i++)
		cout<<ans;

	return 0;
}
