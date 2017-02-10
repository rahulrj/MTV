#include <iostream>
using namespace std;

int *lpps(string pat,int M){
    int *lps=new int[M];
    lps[0]=0;
    int i=1,len=0;

    while(i<M){
        if(pat[i]==pat[len]){
            len+=1;
            lps[i]=len;
            i+=1;

        }
        else{
            if(len==0){
                lps[i]=0;
                i+=1;
            }
            else{
                len=lps[len-1];
            }
        }
    }




    return lps;
}

int main() {
	//code
	string s="AAACAAAAAC";
	int *lps=lpps(s,s.length());
	for(int i=0;i<s.length();i++){
	    cout<<lps[i]<<" ";
	}
	return 0;
}
