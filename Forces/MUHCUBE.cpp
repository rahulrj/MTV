http://codeforces.com/problemset/problem/471/D

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int res=0;

void computeLPSArray(int *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(int *pat, int  *txt,int M,int N)
{
    // int M = strlen(pat);
    // int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            res=res+1;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(int *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
	//code
	int n,w;
	cin>>n>>w;
	int *b=new int[n];
	int *e=new int[w];

	for(int i=0;i<n;i++){
	    cin>>b[i];
	}

	for(int i=0;i<w;i++){
	    cin>>e[i];
	}

	int j=0,i=0,count=0,save=0;
	//int count=0;
	//int save=0;

	if(n<w){
	    cout<<0<<endl;
	}
	else if(w==1){
	    cout<<n<<endl;
	}
	else{

     string s1="",s2="";
     int *d1=new int[n];
     int *d2=new int[w];

	for(int i=0;i+1<n;i++){
	    d1[i]=b[i+1]-b[i];
	    //s1+=std::to_string(x);
	    if(i+1<w){
	         d2[i]=e[i+1]-e[i];
	        //s2+=std::to_string(y);
	    }
	}

	//cout<<s1<<endl;
	//cout<<s2<<endl;

	KMPSearch(d2, d1,w-1,n-1);
	cout<<res<<endl;




// 	while(i<n){
// 	    int diffe=e[j+1]-e[j];
// 	    int diffb=b[i+1]-b[i];

// 	    //cout<<diffe<<" "<<diffb<<" "<<i<<" "<<j<<endl;
// 	    if(diffe!=diffb){
// 	        j=0;
// 	        i=save+1;
// 	        save=i;
// 	        continue;
// 	    }

// 	    j=j+1;
// 	    if(j==w-1){
// 	       count+=1;
// 	       //cout<<count<<" "<<j<<endl;

// 	       j=0;
// 	       i=save+1;
// 	       save=i;
// 	    }
// 	    else{
// 	        i=i+1;
// 	    }


// 	}

}

	return 0;
}
