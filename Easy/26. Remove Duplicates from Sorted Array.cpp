#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return static_cast<int>(nums.size());
        int i = 0;
        for (auto it = nums.begin() + 1; it != nums.end();)
        {
            if (*it == *(it - 1))
            {
                it++;
                i++;
                continue;
            }
            if (*it != *(it - 1))
            {
                if (!i)
                {
                    it++;
                    continue;
                }
                else
                {
                    it = nums.erase(it - i, it);
                    i = 0;
                }
            }
        }
        if (i > 0)
            nums.erase(nums.end() - i, nums.end());
        return int(nums.size());
    }
};

int main(int agrc, const char *argv[])
{
    vector<int> test = {1, 1};
    Solution sol;
    int len = sol.removeDuplicates(test);
    cout << len << endl;
    for (int i = 0; i < test.size(); i++)
        cout << test.at(i) << ' ';
    cout << endl;
    return 0;
}