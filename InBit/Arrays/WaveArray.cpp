vector<int> Solution::wave(vector<int> &A) {

    int n=A.size();
    sort(A.begin(),A.end());

    vector<int>res;

    if(n>=2){
        res.push_back(A[1]);
    }

    res.push_back(A[0]);

    for(int i=3;i<n;i=i+2){
        res.push_back(A[i]);
        res.push_back(A[i-1]);
    }

    if(n>2 && n%2!=0){
        res.push_back(A[n-1]);
    }



    return res;
}
