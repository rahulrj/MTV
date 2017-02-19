https://www.hackerrank.com/challenges/string-function-calculation

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include<cassert>
using namespace std;

struct suffix
{
	int index; // To store original index
	int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
		(a.rank[0] < b.rank[0] ?1: 0);
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
vector<int> buildSuffixArray(string txt, int n)
{
	// A structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	// The structure is needed to sort the suffixes alphabatically
	// and maintain their old indexes while sorting
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
	}

	// Sort the suffixes using the comparison function
	// defined above.
	sort(suffixes, suffixes+n, cmp);

	// At his point, all suffixes are sorted according to first
	// 2 characters. Let us sort suffixes according to first 4
	// characters, then first 8 and so on
	int ind[n]; // This array is needed to get the index in suffixes[]
	// from original index. This mapping is needed to get
	// next suffix.
	for (int k = 4; k < 2*n; k = k*2)
	{
		// Assigning rank and index values to first suffix
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		// Assigning rank to suffixes
		for (int i = 1; i < n; i++)
		{
			// If first rank and next ranks are same as that of previous
			// suffix in array, assign the same new rank to this suffix
			if (suffixes[i].rank[0] == prev_rank &&
					suffixes[i].rank[1] == suffixes[i-1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else // Otherwise increment rank and assign
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		// Assign next rank to every suffix
		for (int i = 0; i < n; i++)
		{
			int nextindex = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (nextindex < n)?
								suffixes[ind[nextindex]].rank[0]: -1;
		}

		// Sort the suffixes according to first k characters
		sort(suffixes, suffixes+n, cmp);
	}

	// Store indexes of all sorted suffixes in the suffix array
	vector<int>suffixArr;
	for (int i = 0; i < n; i++)
		suffixArr.push_back(suffixes[i].index);

	// Return the suffix array
	return suffixArr;
}

vector<int> kasai(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();
	vector<int>lcp(n,0);

    vector<int>invSuff(n,0);

    for(int i=0;i<n;i++){
        invSuff[suffixArr[i]]=i;
    }

    int k=0;
    for(int i=0;i<n;i++){

        if(invSuff[i]==n-1){
            k=0;
            continue;
        }

        int j = suffixArr[invSuff[i]+1];

        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
			k++;

		lcp[invSuff[i]] = k; // lcp for the present suffix.

		// Deleting the starting character from the string.
		if (k>0)
			k--;
    }



	return lcp;
}

int getMaxArea(vector<int>hist, int n)
{
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	stack<int> s;

	int max_area = 0; // Initalize max area
	int tp; // To store top of stack
	int area_with_top; // To store area with top bar as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, then calculate area of rectangle
		// with stack top as the smallest (or minimum height) bar. 'i' is
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top());

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top());

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int main()
{
    string str;
    cin>>str;

    int len=str.length();
    vector<int>suffixArr = buildSuffixArray(str, len);



    vector<int>lcp = kasai(str, suffixArr);




    int temp = getMaxArea(lcp,len);
    if(temp > str.length() )
        cout<<temp<<endl;
    else
        cout<<str.length()<<endl;
    return 0;
}
