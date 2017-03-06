string addd(string prev,string res){
    string resnew=res;
    string ans="";

    int len1=prev.length();
    int reslen=resnew.length();
    int minlen=len1<reslen?len1:reslen;

    int carry=0;

    //cout<<"Addhere"<<prev<<" "<<resnew<<endl;

    for(int i=0;i<minlen;i++){
        int sum=carry+(prev[i]-'0')+(resnew[i]-'0');
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);
    }

    //cout<<ans<<endl;

    for(int i=minlen;i<len1;i++){
        int sum=carry+(prev[i]-'0');
        //cout<<"S1"<<sum<<endl;
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);

    }

    for(int i=minlen;i<reslen;i++){
        int sum=carry+(resnew[i]-'0');
        //cout<<"S2"<<sum<<endl;
        int rem=sum%10;
        carry=sum/10;
        ans+=std::to_string(rem);
        //cout<<"S"<<ans<<endl;
    }
    if(carry>0){
    	ans+=std::to_string(carry);
    }

    std::reverse(res.begin(),res.end());
    return ans;

    //cout<<ans<<endl;

}
