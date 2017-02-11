#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


using namespace std;

    int dp[5005][5005];

int LCS(string s1,string s2){


    int m=s1.length();
    int n=s2.length();




    //dp[0][0]=1;
    for(int i=0;i<n;i++){
        if(s1[0]==s2[i]){
            if(i==0){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=dp[0][i-1]+1;
            }
        }
        else{
            if(i==0){
              dp[0][i]=0;
            }
            else{
                dp[0][i]=dp[0][i-1];
            }
        }
    }

    for(int i=0;i<m;i++){
        if(s1[i]==s2[0]){
            if(i==0){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=dp[i-1][0]+1;
            }
        }
        else{
            if(i==0){
              dp[i][0]=0;
            }
            else{
                dp[i][0]=dp[i-1][0];
            }
        }
    }




    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
	//code

	string s1;
	string s2;

    cin>>s1;
    cin>>s2;

	cout<<LCS(s1,s2)<<endl;


	return 0;
}
