#include <iostream>
using namespace std;

//int count=0;
void subseq(string s1,string s2,int len1,int len2,int count){
    if(len1<0 || len2<0){
        cout<<count<<endl;
        return;
    }
    if(s1[len1-1]==s2[len2-1]){
        count+=1;
        //cout<<count<<endl;
        subseq(s1,s2,len1-1,len2-1,count);
    }

    else{
        subseq(s1,s2,len1-1,len2,count);
        subseq(s1,s2,len1,len2-1,count);
    }

}

int main() {
	//code

	string s1="ABCD";
	string s2="ACBD";

	subseq(s1,s2,s1.length(),s2.length(),0);

	return 0;
}
