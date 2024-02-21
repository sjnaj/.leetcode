#include <bits/stdc++.h>

int removeElement(std::vector<int> &nums, int val)
{
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++)
    {
        if (nums[fast] !=val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}