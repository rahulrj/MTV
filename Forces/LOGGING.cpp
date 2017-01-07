http://codeforces.com/problemset/problem/16/D

#include <iostream>
#include <string.h>


using namespace std;

int main() {
	//code
	int n,ans=1;
	int count10=0;
	string ss;
	cin>>n;
	string s[100][3];

	for(int i=0;i<n;i++){
        std::getline(cin, ss);
	    cout<<ss<<endl;
	    s[i][0]=ss.substr(1,2);
	    s[i][1]=ss.substr(4,2);
	    s[i][2]=ss.substr(7,1);

	   // if(i==0)
	   //     continue;

	   // if(s[i][0]==s[i-1][0] && s[i][1]==s[i-1][1] && s[i][2]==s[i-1][2]){
	   //     count10+=1;
	   //     if(count10!=10){
	   //         continue;
	   //     }
	   //     count10=0;
	   //     ans+=1;
	   // }

	   // if(s[i][2]=="a" && s[i-1][2]=="p"){
	   //     continue;
	   // }

	   // if(s[i][2]==s[i-1][2]){
	   //     if(stoi(s[i][0]) > stoi(s[i-1][0])){
	   //         continue;
	   //     }else{
	   //         ans+=1;
	   //         continue;
	   //     }

	   //     if(stoi(s[i][0]) == stoi(s[i-1][0])){
	   //         if(stoi(s[i][1]) > stoi(s[i-1][1])){
	   //             continue;
	   //         }
	   //         ans+=1;
	   //         continue;
	   //     }
	   //     ans+=1;
	   //     continue;
	   // }

	   // ans+=1;



	}



	return 0;
}
