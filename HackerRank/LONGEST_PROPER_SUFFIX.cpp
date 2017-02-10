#include <iostream>
using namespace std;

int *lpps(string s,int len){
    int *lps=new int[len];
    lps[0]=0;

    for(int i=1;i<len;i++){
        int max=0;
        for(int j=1;j<i+1;j++){
            string sub1=s.substr(0,j);
            string sub2=s.substr(i+1-j,j);
            // if(i==2){
            //  cout<<sub1<<" "<<sub2<<endl;
            // }
            
            if(sub1==sub2){
                max=j;
            }
        }
        lps[i]=max;
    }

    return lps;
}

int main() {
	//code
	string s="AAAA";
	int *lps=lpps(s,s.length());
	for(int i=0;i<s.length();i++){
	    cout<<lps[i]<<" ";
	}
	return 0;
}
