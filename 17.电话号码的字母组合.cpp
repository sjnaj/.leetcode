/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    string path;
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtracing(int k, int index, string &digits)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (auto c : letter[digits[index] - '0'])
        {
            path += c;
            backtracing(k, index + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        backtracing(digits.size(), 0, digits);
        return res;
    }
};
// @lc code=end
