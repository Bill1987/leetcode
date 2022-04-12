/**
* 13. Roman to Integer
* 
* 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

* Symbol       Value
* I             1
* V             5
* X             10
* L             50
* C             100
* D             500
* M             1000
* 例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
* For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, 
* which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
* 
* 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
* 所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
* Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
* Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
* The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
* 
* I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
* I can be placed before V (5) and X (10) to make 4 and 9.
* X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
* X can be placed before L (50) and C (100) to make 40 and 90.
* C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
* C can be placed before D (500) and M (1000) to make 400 and 900.
* 
* 给定一个罗马数字，将其转换成整数。
* Given a roman numeral, convert it to an integer.
* 
* Example 1:
* Input: s = "III"
* Output: 3
* Explanation: III = 3.
* 
* Example 2:
* Input: s = "LVIII"
* Output: 58
* Explanation: L = 50, V= 5, III = 3.
* 
* Example 3:
* Input: s = "MCMXCIV"
* Output: 1994
* Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
* 
* 提示：
* 1 <= s.length <= 15
* s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
* s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
* 题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
* It is guaranteed that s is a valid roman numeral in the range [1, 3999].
* 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
* IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
* 关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。
**/

#include <string>
#include <iostream>
#include <map>

using namespace std;

#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1


class Solution {
public:
    /*
    * 自己尝试解决
    * 直接处理字符串，判断是否为组合
    * 此方法，好理解，时间复杂度为 O(n)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：4 ms, 在所有 C++ 提交中击败了 94.48%的用户
    * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 86.45%的用户
    * 通过测试用例：3999 / 3999
    *
    * Success
    * Runtime: 7 ms, faster than 86.85% of C++ online submissions for Roman to Integer.
    * Memory Usage: 6 MB, less than 66.40% of C++ online submissions for Roman to Integer.
    */

    int romanToInt(string s) 
    {
        int nNum = 0;
        const size_t nCount = s.size();

        for (size_t i = 0; i < nCount; i++)
        {
            switch (s[i])
            {
            // MDKV 没有组合情况，直接加上就可以了
            case 'M':
                nNum += M;
                break;
            case 'D':
                nNum += D;
                break;
            case 'L':
                nNum += L;
                break;
            case 'V':
                nNum += V;
                break;

            // CXI 都有组合需要判断
            case 'C':
                // 最后一位，直接加结果即可
                // 只有不是最后一位的才能+1，否则溢出
                // 判断是否为组合
                if (nCount != i + 1 && (s[i+1] == 'D' || s[i+1] == 'M'))
                {
                    // 是组合的话，减去本身值
                    nNum -= C;
                }
                else
                {
                    nNum += C;
                }
                break;


            case 'X':
                // 最后一位，直接加结果即可
                // 只有不是最后一位的才能+1，否则溢出
                // 判断是否为组合
                if (nCount != i + 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
                    // 是组合的话，减去本身值
                    nNum -= X;
                }
                else
                {
                    nNum += X;
                }
                break;

            case 'I':
                // 最后一位，直接加结果即可
                // 只有不是最后一位的才能+1，否则溢出
                // 判断是否为组合
                if (nCount != i + 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
                    // 是组合的话，减去本身值
                    nNum -= I;
                }
                else
                {
                    nNum += I;
                }
                break;
            default:
                break;
            }

        }
        
        return nNum;
    }


    /*
    * 处理成数字，比较大小判断是否为组合
    * 参考改进，代码更短
    * 时间复杂度为 O(n)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：4 ms, 在所有 C++ 提交中击败了 94.48%的用户
    * 内存消耗：8 MB, 在所有 C++ 提交中击败了 24.72%的用户
    * 通过测试用例：3999 / 3999
    *
    * Success
    * Runtime: 17 ms, faster than 47.52% of C++ online submissions for Roman to Integer.
    * Memory Usage: 6 MB, less than 87.40% of C++ online submissions for Roman to Integer.
    */
    map<char, int> mRoman = { 
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

    int romanToInt_2(string s)
    {
        int nNum = 0;
        const size_t nCount = s.size();

        for (size_t i = 0; i < nCount; i++)
        {
            // 罗马数字对应的数字
            int nVal = mRoman[s[i]];
            
            // 如果不是最后一位，并且 比身后的数字小，则说明是组合，减去本身
            // 必须要判断是不是最后一位，否则溢出
            if (nCount != i +1 && nVal < mRoman[s[i+1]])
            {
                nNum -= nVal;
            }
            //如果是最后一位 或 比后边的数字大，直接增加本身
            else
            {
                nNum += nVal;
            }

        }

        return nNum;
    }


};

int main()
{
    Solution sol;
    cout << sol.romanToInt_2("III") << endl;
    cout << sol.romanToInt_2("LVIII") << endl;
    cout << sol.romanToInt_2("MCMXCIV") << endl;
	return 0;
}