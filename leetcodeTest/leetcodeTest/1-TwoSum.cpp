/*
* 1. Two Sum   Easy
* 
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
* You can return the answer in any order.
* 你可以按任意顺序返回答案。
* 
* 
* Example 1:
* Input: nums = [2,7,11,15], target = 9
* Output: [0,1]
* Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
* 
* 
* Example 2:
* Input: nums = [3,2,4], target = 6
* Output: [1,2]
* 
* 
* Example 3:
* Input: nums = [3,3], target = 6
* Output: [0,1]
* 
* 
* Constraints:
* 2 <= nums.length <= 104
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* Only one valid answer exists.
* 只会存在一个有效答案
* 
* Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
* 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
* */



#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    /*
    * 暴力双循环
    * 此方法，好理解，但时间复杂度为 O(n2)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：300 ms, 在所有 C++ 提交中击败了 30.18%的用户
    * 内存消耗：10 MB, 在所有 C++ 提交中击败了 63.91%的用户
    * 通过测试用例：57 / 57
    *
    * Success
    * Runtime: 606 ms, faster than 19.05% of C++ online submissions for Two Sum.
    * Memory Usage: 10.3 MB, less than 66.99% of C++ online submissions for Two Sum.
    */
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        // 循环全部数据，设为第一个数
        for (int i = 0; i < nums.size(); i++)
        {
            // 在第一个数之后，寻找第二个数字
            for (int j = i + 1; j < nums.size(); j++)
            {
                // 找到和为target的两个数字
                if ( target == nums[i] + nums[j])
                {
                    // 返回两个数的位置
                    return {i, j};
                }
            }
        }
        // 没有找到返回位置-1
        return { -1, -1 };
    }


    /*
    * 使用hash 的map
    * 时间复杂度 O(n)  空间复杂度O(n)
    * 
    * 执行结果：通过
    * 执行用时：8 ms, 在所有 C++ 提交中击败了92.14%的用户
    * 内存消耗：10.8 MB, 在所有 C++ 提交中击败了15.81%的用户
    * 通过测试用例：57 / 57
    * 
    * Success
    * Runtime: 4 ms, faster than 99.30% of C++ online submissions for Two Sum.
    * Memory Usage: 11.2 MB, less than 23.64% of C++ online submissions for Two Sum.
    */
    vector<int> twoSum_2(vector<int>& nums, int target)
    {
        // 第一个元素是当前数字，第二个元素是位置
        map<int, int> mNums;

        // 循环全部数据，
        for (int i = 0; i < nums.size(); i++)
        {
            // 查找map中是否有需要的第二个数字
            int nSecond = target - nums[i];
            if (mNums.count(nSecond) > 0)
            {
                // 返回两个数据的位置
                return {mNums[nSecond], i };
            }

            // 把当前数据和位置插入到map中
            mNums[nums[i]] = i;
        }

        // 没有找到返回位置-1
        return { -1, -1 };
    }

};


int main()
{
    Solution sol;
    vector<int> vData;
    vector<int> vRes;

    vData = {2, 7, 11, 15};
    vRes = sol.twoSum_2(vData, 9);
    cout << "[" << vRes[0] << ", " << vRes[1] << "]" << endl;

    vData = { 3,2,4 };
    vRes = sol.twoSum_2(vData, 6);
    cout << "[" << vRes[0] << ", " << vRes[1] << "]" << endl;

    vData = { 3,3 };
    vRes = sol.twoSum_2(vData, 6);
    cout << "[" << vRes[0] << ", " << vRes[1] << "]" << endl;

	return 0;
}
