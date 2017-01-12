http://codeforces.com/problemset/problem/50/B

#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[1000],x=0;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[int(s[i])]++;
	for(int i=0;i<1000;i++)
		x+=a[i]*a[i];
	cout<<x;
}
