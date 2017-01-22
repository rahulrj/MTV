http://codeforces.com/problemset/problem/412/C

#include <iostream>
#include<vector>
#include <ctype.h>
using namespace std;



int main() {
	//code
	int n;
	cin>>n;
	string s;
	vector<string>v;

	for(int i=0;i<n;i++){
	    cin>>s;
	    v.push_back(s);
	}

	string res="";
	for(int i=0;i<v[0].length();i++){

	    char cc='#';
	    int countq=0;
	    int countc=0;
	    for(int j=0;j<n;j++){
	        char c=v[j][i];
	        if(isalpha(c) && c!=cc){
	           cc=c;
	           countc+=1;
	        }else{
	            countq+=1;
	        }
	    }

	    if(countq==n){
	        res+="a";
	    }
	    else if(countc>1){
	        res+="?";
	    }
	    else{
	        res+=cc;
	    }
	}

	cout<<res<<endl;



	return 0;
}
