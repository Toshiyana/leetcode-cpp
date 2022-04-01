
        vector<int> sub;
        vector<vector<int>> subs;

        subsetsWithDup(nums, 0, sub, subs);

        return subs;
    }

private:
    void subsetsWithDup(vector<int> &nums, int begin, vector<int> &sub, vector<vector<int>> &subs)
    {
        subs.push_back(sub);

        for (int i = begin; i < nums.size(); i++)
        {
            if (i == begin || nums[i] != nums[i - 1])
            {
                sub.push_back(nums[i]);
                subsetsWithDup(nums, i + 1, sub, subs);
                sub.pop_back();
            }
        }
    }
};