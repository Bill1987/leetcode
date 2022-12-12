/**
* 9. Palindrome Number
* 
* Given an integer x, return true if x is palindrome integer.
* ����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��
* An integer is a palindrome when it reads the same backward as forward.
* ��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
* 
* For example, 121 is a palindrome while 123 is not.
* ���磬121 �ǻ��ģ��� 123 ���ǡ�
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
* ���ף����ܲ�������תΪ�ַ�����������������
**/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
    * ��תһ��
    * �˷�����ʱ�临�Ӷ�Ϊ O(n)  �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��8 ms, ������ C++ �ύ�л����� 77.43%���û�
    * �ڴ����ģ�5.6 MB, ������ C++ �ύ�л����� 99.27%���û�
    * ͨ������������11510 / 11510
    *
    * Success
    * Runtime: 19 ms, faster than 55.85% of C++ online submissions for Palindrome Number.
    * Memory Usage: 5.7 MB, less than 91.63% of C++ online submissions for Palindrome Number.
    */

    bool isPalindrome(int x) 
    {

        // �����Լ�0��β�����֣��϶����ǻ��ģ�0���⣩
        if(x < 0 || (x % 10 == 0 && x !=0 ) )
        {
            return false;
        }

        // �����ֵ���
        // ��Ϊ�ǻ��ģ���תһ�����־Ϳ����ˡ�
        // ע�⣺���������з�ת����֤ʱ����������һ�Ҫ�����n/2��
        int nNewNum = 0;
        while (x > nNewNum)
        {
            // ������*10����ǰŲһλ��
            // ����������ĩβ������
            nNewNum = nNewNum * 10 + x % 10;
            x /= 10;
        }

        // ���λ����ż����ǰ�󲿷�Ӧ������ȵ�
        // ���λ������������ת��Ļ���1λ��ȥ������
        // (����λ���м�����֣��ԶԳ�û��Ӱ��)
        if (x == nNewNum || x == nNewNum / 10)
        {
            return true;
        }

        return false;
        
    }


    /*
    * ��תȫ��
    * �˷�����ʱ�临�Ӷ�Ϊ O(n) �����淽��ʵ�ʶ����� n/2 ��
    * �ռ临�Ӷ�O(1)  ����������long ��Ҫ������1��
    *
    * ִ�н����ͨ��
    * ִ����ʱ��12 ms, ������ C++ �ύ�л�����52.28%���û�
    * �ڴ����ģ�5.6 MB, ������ C++ �ύ�л����� 99.27%���û�
    * ͨ������������11510 / 11510
    *
    * Success
    * Runtime: 8 ms, faster than 90.75% of C++ online submissions for Palindrome Number.
    * Memory Usage: 5.9 MB, less than 33.65% of C++ online submissions for Palindrome Number.
    * ��������Ϊʲô�����Ӣ�İ��ύ�������죩
    */
    bool isPalindrome_2(int x) 
    {
        // �����Լ�0��β�����֣��϶����ǻ��ģ�0���⣩
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        // �����ֵ���
        long nNewNum = 0;
        long nOldNum = x;
        while (x)
        {
            // ������*10����ǰŲһλ��
            // ����������ĩβ������
            nNewNum = (nNewNum * 10) + x % 10;
            x /= 10;
        }

        // �ߵ�֮�����
        if (nNewNum != nOldNum)
        {
            return false;
        }

        return true;
    }

    /*
    * ��ת�ַ���
    * �˷�����ʱ�临�Ӷ�Ϊ O(1) �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��4 ms, ������ C++ �ύ�л�����94.88%���û�
    * �ڴ����ģ�5.7 MB, ������ C++ �ύ�л����� 94.66%���û�
    * ͨ������������11510 / 11510
    *
    * Success
    * Runtime: 20 ms, faster than 49.78% of C++ online submissions for Palindrome Number.
    * Memory Usage: 6.1 MB, less than 13.13% of C++ online submissions for Palindrome Number.
    */
    bool isPalindrome_3(int x) 
    {
        // ������ת��Ϊ�ַ���
        string sOld = to_string(x);

        // ��ת�ַ���
        string sNew = to_string(x);
        reverse(sNew.begin(), sNew.end());

        // �����Ƿ���ȵĽ��
        return (sOld == sNew);
    }

    static bool isPalindrome_4(int x)
    {
        // ���� �� ��10������0���⣩���������ǻ���
        if( x < 0 || (x % 10 == 0 && x!= 0) )
        {
            return false;
        }

        int nReserve = 0;   // ��ת������
        // ֻ��Ҫ��֤һ�뼴�ɣ���xС�ڻ���ڷ�ת֮�������ʱ������һ����
        // ����תһ��ȿ�������������ֿ��Է�ֹint�����
        while (x > nReserve)
        {
            // ����ǰ���һλ���֣����뵽��ת���ֵ�ĩβ
            int nLastNumber = x % 10;
            nReserve =  nReserve * 10 + nLastNumber;

            // �Ϸ���ת֮��ȥ��Դ���ֵ�ĩβ
            x /= 10;
        }

        // �����������ż��λ����ת֮�����������൱��
        // ���������λ����ת�����ֻ��һλ������Ҫȥ�����һλ��Ҳ����Դ�������м��һλ��
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