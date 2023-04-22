/*
You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].
*/
// c++ solution(nlogn) using map:

vector<long long> smallerSum(int n, vector<int> &arr)
{
    // Code here
    map<int, long long> mp;
    vector<long long> res(n, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    long long int prv = 0;
    for (auto &it : mp)
    {
        int f = it.second;
        it.second = prv;
        prv = it.second + f * it.first;
    }

    for (int i = 0; i < n; i++)
    {
        res[i] = mp[arr[i]];
    }
    return res;
}