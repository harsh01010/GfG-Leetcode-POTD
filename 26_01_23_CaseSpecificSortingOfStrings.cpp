/*
Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string
with the same case of character as that
in original string is deeIRSfrsTUX
*/
// c++ solution ::

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string upper;
        string lower;
        for (char x : str)
        {
            if (x >= 'a' and x <= 'z')
                lower.push_back(x);
            else
                upper.push_back(x);
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        int Li = 0, Ui = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' and str[i] <= 'z')
                str[i] = lower[Li++];
            else
                str[i] = upper[Ui++];
        }
        return str;
    }
};