/**
* 20. Valid Parentheses
*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
* 
* An input string is valid if:
* 有效字符串需满足：
* 
* 	1.Open brackets must be closed by the same type of brackets.
* 	1.左括号必须用相同类型的右括号闭合。
* 	2.Open brackets must be closed in the correct order.
* 	2.左括号必须以正确的顺序闭合。
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
* 示例 4：
* 输入：s = "([)]"
* 输出：false
* 
* 示例 5：
* 输入：s = "{[]}"
* 输出：true
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
    * 此方法，好理解，但时间复杂度为 O(n)  空间复杂度O(1)
    *
    * 执行结果：通过
    * 执行用时：0 ms, 在所有 C++ 提交中击败了 100%的用户
    * 内存消耗：6.3 MB, 在所有 C++ 提交中击败了 11.22%的用户
    * 通过测试用例：91 / 91
    *
    * Success
    * Runtime:  0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
    * Memory Usage: 6.3 MB, less than 51.47% of C++ online submissions for Valid Parentheses.
    */
    bool isValid(string s) {
        // 如果是单数，肯定错了
        if (s.length() % 2 != 0 )
        {
            return false;
        }

        stack<char> stackC;
        // 遍历全部字符
        // c++11 新特性
        for (char c : s)
        {
            // 如果是前半括号就入栈
            if (c=='(' || c == '[' || c == '{')
            {
                stackC.push(c);
            }
            else
            {
                // 如果此时栈已经空了。或
                // 后括号与栈顶的前括号不匹配
                // 说明字符串不合法
                if (stackC.empty() || 
                    (stackC.top() == '(' && c != ')') ||
                    (stackC.top() == '[' && c != ']') ||
                    (stackC.top() == '{' && c != '}') )
                {
                    return false;
                }

                // 匹配上就出栈
                stackC.pop();
            }
        }

        // 如果全部匹配，栈中应该是空的，否则就是没全部匹配
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