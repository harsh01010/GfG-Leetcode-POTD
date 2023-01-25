/*
Input:
N = 3
Arr[] = {10, 40, 20}
Output: 0 2 1
Explanation: 10 is the least element so it
is replaced by 0. 40 is the largest
element so it is replaced by 3-1 = 2. And
20 is the 2nd smallest element so it is
replaced by 1.
*/

// solution
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    vector<int>vec(arr,arr+n);
	    sort(vec.begin(),vec.end());
	    unordered_map<int,int>ump;
	    for(int i=0;i<vec.size();i++)
	        ump[vec[i]] = i;
	    for(int i=0;i<n;i++)
	        arr[i] = ump[arr[i]];
	}

};