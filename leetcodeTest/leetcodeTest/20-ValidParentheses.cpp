/**
* 20. Valid Parentheses
*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
* 
* An input string is valid if:
* ��Ч�ַ��������㣺
* 
* 	1.Open brackets must be closed by the same type of brackets.
* 	1.�����ű�������ͬ���͵������űպϡ�
* 	2.Open brackets must be closed in the correct order.
* 	2.�����ű�������ȷ��˳��պϡ�
* 
* 
* Example 1:
* Input: s = "()"
* Output: true
* 
* Example 2:
* Input: s = "()[]{}"
* Output: true
* 
* Example 3:
* Input: s = "(]"
* Output: false
* 
* ʾ�� 4��
* ���룺s = "([)]"
* �����false
* 
* ʾ�� 5��
* ���룺s = "{[]}"
* �����true
* 
* Constraints:
* 
* 1 <= s.length <= 104
* s consists of parentheses only '()[]{}'.
**/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:

    /*
    * �˷���������⣬��ʱ�临�Ӷ�Ϊ O(n)  �ռ临�Ӷ�O(1)
    *
    * ִ�н����ͨ��
    * ִ����ʱ��0 ms, ������ C++ �ύ�л����� 100%���û�
    * �ڴ����ģ�6.3 MB, ������ C++ �ύ�л����� 11.22%���û�
    * ͨ������������91 / 91
    *
    * Success
    * Runtime:  0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
    * Memory Usage: 6.3 MB, less than 51.47% of C++ online submissions for Valid Parentheses.
    */
    bool isValid(string s) {
        // ����ǵ������϶�����
        if (s.length() % 2 != 0 )
        {
            return false;
        }

        stack<char> stackC;
        // ����ȫ���ַ�
        // c++11 ������
        for (char c : s)
        {
            // �����ǰ�����ž���ջ
            if (c=='(' || c == '[' || c == '{')
            {
                stackC.push(c);
            }
            else
            {
                // �����ʱջ�Ѿ����ˡ���
                // ��������ջ����ǰ���Ų�ƥ��
                // ˵���ַ������Ϸ�
                if (stackC.empty() || 
                    (stackC.top() == '(' && c != ')') ||
                    (stackC.top() == '[' && c != ']') ||
                    (stackC.top() == '{' && c != '}') )
                {
                    return false;
                }

                // ƥ���Ͼͳ�ջ
                stackC.pop();
            }
        }

        // ���ȫ��ƥ�䣬ջ��Ӧ���ǿյģ��������ûȫ��ƥ��
        return stackC.empty();
    }
};

int main()
{
    Solution sol;
    string s;

    s = "()";
    cout << sol.isValid(s) << endl;

    s = "()[]{}";
    cout << sol.isValid(s) << endl;

    s = "(]";
    cout << sol.isValid(s) << endl;

    s = "([)]";
    cout << sol.isValid(s) << endl;

    s = "{[]}";
    cout << sol.isValid(s) << endl;

    s = "{[]";
    cout << sol.isValid(s) << endl;

    return 0;
}