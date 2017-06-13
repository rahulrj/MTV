//https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {

       int max=B,min=1;
    vector <int> res;
    for(int i=0;i<B-1;i++)
    {
        if(A[i]=='I')
        {
            res.push_back(min);
            min++;
        }
        else
        {
            res.push_back(max);
            max--;
        }
    }
    res.push_back(min);
    return res;
}
