/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (28.76%)
 * Total Accepted:    124.2K
 * Total Submissions: 423.6K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stn;
        for(auto s:tokens) {
            // stoi
            if(s.size()>1 || isdigit(s[0])) stn.push(stoi(s));
            else {
                auto x2=stn.top(); stn.pop();
                auto x1=stn.top(); stn.pop();
                switch(s[0]) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1*=x2; break;
                    //不管是正负靠近0的那个整数就是两个int类型相除的结果
                case '/': x1/=x2; break;
                }
                stn.push(x1);
            }
        }
        return stn.top();
    }

    bool isDegital(string str) {
    for (int i = 0;i < str.size();i++) {
        if (str.at(i) == '-' && str.size() > 1)  // 有可能出现负数
            continue;
        if (str.at(i) > '9' || str.at(i) < '0')
            return false;
    }
    return true;
}
    int evalRPN1(vector<string>& tokens) {
        stack<int> s;
        double c;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isDegital(tokens[i])) {
                s.push(atoi(tokens[i].c_str()));
            } else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                switch(tokens[i][0]) {
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    c = (double)b/a;
                    c = c > 0 ? floor(c) : ceil(c);
                    s.push(int(c));
                    break;
                default:
                    break;
                }
            }
        }
        return s.top();
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
