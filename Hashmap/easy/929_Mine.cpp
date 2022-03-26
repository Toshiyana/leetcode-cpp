#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> res;

        for (int i = 0; i < emails.size(); i++)
        {
            string email = emails[i];
            int border = email.find("@");
            string local, domain;

            local = email.substr(0, border);
            domain = email.substr(border + 1);

            string newLocal;
            for (int j = 0; j < local.size(); j++)
            {
                if (local[j] == '+')
                    break;
                if (local[j] != '.')
                    newLocal += local[j];
            }

            res.insert(newLocal + "@" + domain);
        }
        return res.size();
    }
};

int main()
{
    Solution sol;
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    sol.numUniqueEmails(emails);
}