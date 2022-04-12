/**
* 14. Longest Common Prefix
* 
* ��дһ�������������ַ��������е������ǰ׺��
* Write a function to find the longest common prefix string amongst an array of strings.
* ��������ڹ���ǰ׺�����ؿ��ַ��� ""��
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
    * ����˫ѭ��
    * �˷���������⣬��ʱ�临�Ӷ�Ϊ O(n2)  �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��8 ms, ������ C++ �ύ�л����� 12.19%���û�
    * �ڴ����ģ�9 MB, ������ C++ �ύ�л����� 41.6%���û�
    * ͨ������������123 / 123
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

        // ȡ����һ��Ϊ��׼
        string sTag = strs[0];

        for (size_t i = 0; i < sTag.length(); i++)
        {
            // ��һ���ǻ�׼�����ñȽ�
            for (size_t j = 1; j < strs.size(); j++)
            {
                // ����ַ������˽�β ��
                // ��Ӧλ�õ���ĸ���׼λ�õ���ĸ����ȣ�˵���Ѿ�����
                if (i > strs[j].length() || sTag[i] != strs[j][i])
                {
                    return sRes;
                }
            }

            // ȫ�����д���ĸ��˵���ǹ���ǰ׺
            sRes += sTag[i];
        }

        return sRes;
    }

    /*
    * �����ٱȽ�
    * ʱ�临�Ӷ�Ϊ O(n)  �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
    * �ڴ����ģ�8.9 MB, ������ C++ �ύ�л����� 77.78%���û�
    * ͨ������������123 / 123
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

        // ��ȫ���ַ�������
        sort(strs.begin(), strs.end());

        // ֻ��Ҫ�Ƚϵ�һ�������һ���ַ�������
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