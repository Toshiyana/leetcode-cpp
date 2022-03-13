#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n*n!) The time complexity is the same as the above approach, i.e. there are n! permutations and it requires O(n) time to print a permutation.
// Auxiliary Space: O(|s|)

void permute(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << " ";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        // cout << "left: " << left_substr << endl;
        // cout << "right: " << right_substr << endl;

        string rest = left_substr + right_substr;
        // cout << "rest: " << rest << endl;
        // cout << "anser + ch: " << answer + ch << endl;

        permute(rest, answer + ch);
    }
}

int main()
{
    string s;
    string answer = "";

    cout << "Enter the string: ";
    cin >> s;

    cout << "\nAll possible strings are: ";
    permute(s, answer);
}