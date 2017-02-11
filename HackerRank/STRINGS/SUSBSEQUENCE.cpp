// Print all subsequences of a string

#include <iostream>
using namespace std;

void subseq(string s,int start,string prev,int n){
    string sub=prev+s[start];
    cout<<sub<<endl;

    for(int i=start+1;i<n;i++){
        subseq(s,i,sub,n);
    }
}

int main() {
	//code
	string s="ABCDE";

	subseq(s,0,"",s.length());

	return 0;
}
