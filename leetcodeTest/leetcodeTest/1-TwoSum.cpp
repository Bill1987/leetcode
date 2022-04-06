/*
* 1. Two Sum   Easy
* 
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* ����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
* You can return the answer in any order.
* ����԰�����˳�򷵻ش𰸡�
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
* ֻ�����һ����Ч��
* 
* Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
* ���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
* */



#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    /*
    * ����˫ѭ��
    * �˷���������⣬��ʱ�临�Ӷ�Ϊ O(n2)  �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��300 ms, ������ C++ �ύ�л����� 30.18%���û�
    * �ڴ����ģ�10 MB, ������ C++ �ύ�л����� 63.91%���û�
    * ͨ������������57 / 57
    *
    * Success
    * Runtime: 606 ms, faster than 19.05% of C++ online submissions for Two Sum.
    * Memory Usage: 10.3 MB, less than 66.99% of C++ online submissions for Two Sum.
    */
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        // ѭ��ȫ�����ݣ���Ϊ��һ����
        for (int i = 0; i < nums.size(); i++)
        {
            // �ڵ�һ����֮��Ѱ�ҵڶ�������
            for (int j = i + 1; j < nums.size(); j++)
            {
                // �ҵ���Ϊtarget����������
                if ( target == nums[i] + nums[j])
                {
                    // ������������λ��
                    return {i, j};
                }
            }
        }
        // û���ҵ�����λ��-1
        return { -1, -1 };
    }


    /*
    * ʹ��hash ��map
    * ʱ�临�Ӷ� O(n)  �ռ临�Ӷ�O(n)
    * 
    * ִ�н����ͨ��
    * ִ����ʱ��8 ms, ������ C++ �ύ�л�����92.14%���û�
    * �ڴ����ģ�10.8 MB, ������ C++ �ύ�л�����15.81%���û�
    * ͨ������������57 / 57
    * 
    * Success
    * Runtime: 4 ms, faster than 99.30% of C++ online submissions for Two Sum.
    * Memory Usage: 11.2 MB, less than 23.64% of C++ online submissions for Two Sum.
    */
    vector<int> twoSum_2(vector<int>& nums, int target)
    {
        // ��һ��Ԫ���ǵ�ǰ���֣��ڶ���Ԫ����λ��
        map<int, int> mNums;

        // ѭ��ȫ�����ݣ�
        for (int i = 0; i < nums.size(); i++)
        {
            // ����map���Ƿ�����Ҫ�ĵڶ�������
            int nSecond = target - nums[i];
            if (mNums.count(nSecond) > 0)
            {
                // �����������ݵ�λ��
                return {mNums[nSecond], i };
            }

            // �ѵ�ǰ���ݺ�λ�ò��뵽map��
            mNums[nums[i]] = i;
        }

        // û���ҵ�����λ��-1
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
