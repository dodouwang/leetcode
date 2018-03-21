/*
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.03%)
 * Total Accepted:    220.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '""'
 *
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up
 * front.
 * 
 * 
 * 
 * Requirements for atoi:
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the
 * correct value is out of the range of representable values, INT_MAX
 * (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 */
class Solution {
public:
    // 常规模式，先处理可能存在的空白与头部符号，然后就必须是数字了
    int myAtoi1(string str) {
        int i = 0;
        int sign = 1;
        long long r = 0;
        while (i < str.length() && str[i] == ' ') {
            i++;
        }

        if (i < str.length()) {
            if (str[i] == '+') {
                sign = 1;
                i++;
            } else if (str[i] == '-') {
                sign = -1;
                i++;
            }
        }
        for (;i < str.length(); i++) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            } 
            r = r*10 + (str[i] - '0');
            if (sign == 1 && r*sign > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && r*sign < INT_MIN) {
                return INT_MIN;
            }
        }
        return r*sign;
    }
    
    // 状态机模式
    int myAtoi(string s) {
        long long ret = 0;
        int sign = 1;
        int len = s.length();
        int cur = 0;
        const int WAIT = 0;
        const int ONLY_SPACE = 1;
        const int FOUND_SIGN = 2;
        const int FOUND_INT = 3;
        const int FOUND_OTHER = 4;
        int cur_stats = WAIT;

        if (s == "") {
            return 0;
        }

        for (;cur < len; cur++) {
            switch (cur_stats) {
            case WAIT:
            case ONLY_SPACE:
                if (s[cur] == ' ') {
                    cur_stats = ONLY_SPACE;
                } else if (s[cur] == '+' || s[cur] == '-'){
                    cur_stats = FOUND_SIGN;
                    if (s[cur] == '-') {
                        sign = -1;
                    }
                } else if (s[cur] >= '0' && s[cur] <= '9') {
                    cur_stats = FOUND_INT;
                    ret = ret * 10 + (s[cur]-'0');
                    if (ret*sign > INT_MAX) return INT_MAX;
                    if (ret*sign < INT_MIN) return INT_MIN;
                } else {
                    return 0;
                }
                break;
            case FOUND_SIGN:
                if (s[cur] >= '0' && s[cur] <= '9') {
                    cur_stats = FOUND_INT;
                    ret = ret * 10 + (s[cur]-'0');
                    if (ret*sign > INT_MAX) return INT_MAX;
                    if (ret*sign < INT_MIN) return INT_MIN;
                } else {
                    return 0;
                }
                break;
            case FOUND_INT:
                if (s[cur] >= '0' && s[cur] <= '9') {
                    cur_stats = FOUND_INT;
                    ret = ret * 10 + (s[cur]-'0');
                    if (ret*sign > INT_MAX) return INT_MAX;
                    if (ret*sign < INT_MIN) return INT_MIN;
                } else {
                    ret = ret * sign;
                    if (ret > INT_MAX) return INT_MAX;
                    if (ret < INT_MIN) return INT_MIN;
                    return ret;
                }
                break;
            }
        }

        ret = ret * sign;
        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }
};
