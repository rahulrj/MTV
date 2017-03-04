#include <iostream>
using namespace std;

int main() {
	//code

	string txt="AABAACAADAABAAABAA";
	string pat="AABA";

	int M=pat.length();

	int FA[M+1][256];

	for(int state=0;state<=M;state++){
	    for(int j=0;j<256;j++){

	        if(pat[state]==j+65){
	            FA[state][j]=state+1;
	        }
	        else{

	        int flag=0;
	        int ans=0;
	        for(int k=state;k>0;k--){
	            if(pat[k-1]==j+65){
	                int len=k-1;
	                int kk=0;// from start
	                int jj=state-k+1;
	                int ctr=0;

	               // if(state==3 && j==1){
	               //     cout<<jj<<" "<<len<<endl;
	               // }

	                while(ctr<=len){
	                    if(pat[jj]!=pat[kk]){
	                        break;
	                    }
	                    ctr+=1;
	                    jj+=1;
	                    kk+=1;
	                    if(ctr==len){
	                        flag=1;
	                        ans=k;
	                        break;
	                    }
	                }
	                if(flag==1){
	                    break;
	                }
	            }


	        }

	       // if(state==2 && j==0){
	       //     cout<<ans<<"DD"<<endl;
	       // }

	        if(flag==1){
	            FA[state][j]=ans;
	        }
	        else{
	            FA[state][j]=0;
	        }
	   }

	    }
	}

	for(int i=0;i<=M;i++){
	    for(int j=0;j<256;j++){
	        cout<<FA[i][j]<<" ";
	    }
	    cout<<endl;
	}


	int stat=0;
	int N=txt.length();
	for(int i=0;i<N;i++){
	    //int x=txt[i]-65;
	    //cout<<x<<endl;
	    stat=FA[stat][txt[i]-65];
	    //cout<<stat<<endl;
	    if(stat==M){
	        cout<<"Found"<<" "<<i-M+1<<endl;
	    }
	}











	return 0;
}
