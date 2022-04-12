/**
* 14. Longest Common Prefix
* 
* 编写一个函数来查找字符串数组中的最长公共前缀。
* Write a function to find the longest common prefix string amongst an array of strings.
* 如果不存在公共前缀，返回空字符串 ""。
* If there is no common prefix, return an empty string "".
* 
* Example 1:
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
* 
* Example 2:
* Input: strs = ["dog","racecar","car"]
* Output: ""
* Explanation: There is no common prefix among the input strings.
* 
* Constraints:
* 1 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] consists of only lower-case English letters.
**/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    * 暴力双循环
    * 此方法，好理解，但时间复杂度为 O(n2)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：8 ms, 在所有 C++ 提交中击败了 12.19%的用户
    * 内存消耗：9 MB, 在所有 C++ 提交中击败了 41.6%的用户
    * 通过测试用例：123 / 123
    *
    * Success
    * Runtime: 4 ms, faster than 74.12% of C++ online submissions for Longest Common Prefix.
    * Memory Usage: 9.2 MB, less than 78.49% of C++ online submissions for Longest Common Prefix.
    */
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (!strs.size())
        {
            return "";
        }

        string sRes = "";

        // 取出第一个为基准
        string sTag = strs[0];

        for (size_t i = 0; i < sTag.length(); i++)
        {
            // 第一个是基准，不用比较
            for (size_t j = 1; j < strs.size(); j++)
            {
                // 如果字符串到了结尾 或
                // 对应位置的字母与基准位置的字母不相等，说明已经结束
                if (i > strs[j].length() || sTag[i] != strs[j][i])
                {
                    return sRes;
                }
            }

            // 全部都有此字母，说明是公共前缀
            sRes += sTag[i];
        }

        return sRes;
    }

    /*
    * 排序，再比较
    * 时间复杂度为 O(n)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    * 内存消耗：8.9 MB, 在所有 C++ 提交中击败了 77.78%的用户
    * 通过测试用例：123 / 123
    *
    * Success
    * Runtime: 3 ms, faster than 87.51% of C++ online submissions for Longest Common Prefix.
    * Memory Usage: 9.2 MB, less than 44.60% of C++ online submissions for Longest Common Prefix.
    */
    string longestCommonPrefix_2(vector<string>& strs)
    {
        if (!strs.size())
        {
            return "";
        }

        // 将全部字符串排序
        sort(strs.begin(), strs.end());

        // 只需要比较第一个和最后一个字符串即可
        string sBegin = strs.front();
        string sLast = strs.back();
        int i = 0;
        for (; i < sBegin.length(); i++)
        {
            if (sBegin[i] != sLast[i])
            {
                break;
            }
        }

        return sBegin.substr(0,i);
        
    }

};

int main()
{
    Solution sol;
    vector<string> strs;
    
    strs = { "flower", "flow", "flight" };
    cout << sol.longestCommonPrefix_2(strs) << endl;

    strs = { "dog","racecar","car" };
    cout << sol.longestCommonPrefix_2(strs) << endl;

    strs = { "12345","12345678","1234567" };
    cout << sol.longestCommonPrefix_2(strs) << endl;

    strs = { "1234544" };
    cout << sol.longestCommonPrefix_2(strs) << endl;

    return 0;
}