/**
* 9. Palindrome Number
* 
* Given an integer x, return true if x is palindrome integer.
* 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
* An integer is a palindrome when it reads the same backward as forward.
* 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
* 
* For example, 121 is a palindrome while 123 is not.
* 例如，121 是回文，而 123 不是。
* * 
* * 
* * Example 1:
* Input: x = 121
* Output: true
* Explanation: 121 reads as 121 from left to right and from right to left.
* 
* Example 2:
* Input: x = -121
* Output: false
* Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
* 
* Example 3:
* Input: x = 10
* Output: false
* Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*  
* Constraints: -231 <= x <= 231 - 1
* 
* Follow up: Could you solve it without converting the integer to a string?
* 进阶：你能不将整数转为字符串来解决这个问题吗？
**/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
    * 翻转一半
    * 此方法，时间复杂度为 O(n)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：8 ms, 在所有 C++ 提交中击败了 77.43%的用户
    * 内存消耗：5.6 MB, 在所有 C++ 提交中击败了 99.27%的用户
    * 通过测试用例：11510 / 11510
    *
    * Success
    * Runtime: 19 ms, faster than 55.85% of C++ online submissions for Palindrome Number.
    * Memory Usage: 5.7 MB, less than 91.63% of C++ online submissions for Palindrome Number.
    */

    bool isPalindrome(int x) 
    {

        // 负数以及0结尾的数字，肯定不是回文（0除外）
        if(x < 0 || (x % 10 == 0 && x !=0 ) )
        {
            return false;
        }

        // 将数字倒置
        // 因为是回文，翻转一半数字就可以了。
        // 注意：如果整体进行翻转，验证时会溢出，而且还要多计算n/2次
        int nNewNum = 0;
        while (x > nNewNum)
        {
            // 新数字*10是往前挪一位。
            // 加上老数字末尾的数字
            nNewNum = nNewNum * 10 + x % 10;
            x /= 10;
        }

        // 如果位数是偶数，前后部分应该是相等的
        // 如果位数是奇数，翻转后的会多出1位，去掉即可
        // (奇数位最中间的数字，对对称没有影响)
        if (x == nNewNum || x == nNewNum / 10)
        {
            return true;
        }

        return false;
        
    }


    /*
    * 翻转全部
    * 此方法，时间复杂度为 O(n) 比上面方法实际多运算 n/2 次
    * 空间复杂度O(1)  数据类型是long 还要多申请1个
    *
    * 执行结果：通过
    * 执行用时：12 ms, 在所有 C++ 提交中击败了52.28%的用户
    * 内存消耗：5.6 MB, 在所有 C++ 提交中击败了 99.27%的用户
    * 通过测试用例：11510 / 11510
    *
    * Success
    * Runtime: 8 ms, faster than 90.75% of C++ online submissions for Palindrome Number.
    * Memory Usage: 5.9 MB, less than 33.65% of C++ online submissions for Palindrome Number.
    * （不明白为什么这个在英文版提交反倒更快）
    */
    bool isPalindrome_2(int x) 
    {
        // 负数以及0结尾的数字，肯定不是回文（0除外）
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        // 将数字倒置
        long nNewNum = 0;
        long nOldNum = x;
        while (x)
        {
            // 新数字*10是往前挪一位。
            // 加上老数字末尾的数字
            nNewNum = (nNewNum * 10) + x % 10;
            x /= 10;
        }

        // 颠倒之后不相等
        if (nNewNum != nOldNum)
        {
            return false;
        }

        return true;
    }

    /*
    * 翻转字符串
    * 此方法，时间复杂度为 O(1) 空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：4 ms, 在所有 C++ 提交中击败了94.88%的用户
    * 内存消耗：5.7 MB, 在所有 C++ 提交中击败了 94.66%的用户
    * 通过测试用例：11510 / 11510
    *
    * Success
    * Runtime: 20 ms, faster than 49.78% of C++ online submissions for Palindrome Number.
    * Memory Usage: 6.1 MB, less than 13.13% of C++ online submissions for Palindrome Number.
    */
    bool isPalindrome_3(int x) 
    {
        // 将数字转换为字符串
        string sOld = to_string(x);

        // 翻转字符串
        string sNew = to_string(x);
        reverse(sNew.begin(), sNew.end());

        // 返回是否相等的结果
        return (sOld == sNew);
    }

    static bool isPalindrome_4(int x)
    {
        // 负数 和 被10整除（0除外）的数都不是回文
        if( x < 0 || (x % 10 == 0 && x!= 0) )
        {
            return false;
        }

        int nReserve = 0;   // 翻转的数字
        // 只需要验证一半即可，当x小于或等于返转之后的数字时，正好一半了
        // （翻转一半既可以提高销量，又可以防止int溢出）
        while (x > nReserve)
        {
            // 将当前最后一位数字，放入到翻转数字的末尾
            int nLastNumber = x % 10;
            nReserve =  nReserve * 10 + nLastNumber;

            // 上方翻转之后，去掉源数字的末尾
            x /= 10;
        }

        // 如果是数字是偶数位，返转之后，两边正好相当。
        // 如果是奇数位，翻转的数字或多一位，所以要去掉最后一位（也就是源数字最中间的一位）
        if (x == nReserve || x == nReserve / 10)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    cout << Solution::isPalindrome_4(121) << endl;
    cout << Solution::isPalindrome_4(-121) << endl;
    cout << Solution::isPalindrome_4(10) << endl;
    return 0;
}