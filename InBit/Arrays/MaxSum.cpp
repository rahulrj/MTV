// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int s = A.size();
    int ans = A[0], m = 0;
    if(s==1)
        return A[0];
    for(int i = 0; i < s; i++)
    {

        m = m + A[i];
        if(m < A[i])
            m = A[i];
        if(ans < m)
            ans = m;
    }
    return ans;
}
