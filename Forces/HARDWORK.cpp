http://codeforces.com/problemset/problem/61/B

#include <iostream>
using namespace std;
string C(string s){
	string t;
	for(int i=0;i<s.length();++i){
		if(s[i]>='a' && s[i]<='z') t+=s[i];
		if(s[i]>='A' && s[i]<='Z') t+=s[i]-'A'+'a';
	}
	return t;
}
int main(){
	string x,y,z,s;
	int i,n;
	cin>>x>>y>>z;
	x=C(x);
	y=C(y);
	z=C(z);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s;
		s=C(s);
		if(s == x+y+z || s == x+z+y || s == y+x+z || s == y+z+x || s == z+x+y || s == z+y+x)
			cout<<"ACC";
		else cout<<"WA";
		cout<<endl;
	}
	return 0;
}
