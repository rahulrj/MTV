http://codeforces.com/problemset/problem/8/A

#include <iostream>
#include <string.h>
#include<bits/stdc++.h>

using namespace std;

int main() {
	//code

	string s,a,b;
	cin>>s;
	cin>>a;
	cin>>b;

	int x=0;

	 string::size_type loc1 = s.find(a,0);
	 string::size_type loc2 = s.find(b,loc1+a.length());

	 reverse(s.begin(),s.end());


	 string::size_type loc3 = s.find(a);
	 string::size_type loc4 = s.find(b,loc3+a.length());


	 if(loc1!=string::npos && loc2!= string::npos){
	     if(loc2>loc1)
	        x=1;
	 }

	 if(loc3!=string::npos && loc4!= string::npos){
	      if(loc4>loc3)
	        x=x+2;
	 }

	//cout<<x<<endl;

	 if(x==1)
	    cout<<"forward"<<endl;
	 if(x==2)
	    cout<<"backward"<<endl;
	 if(x==3)
	    cout<<"both"<<endl;
	 if(x==0)
	    cout<<"fantasy"<<endl;


	return 0;
}
