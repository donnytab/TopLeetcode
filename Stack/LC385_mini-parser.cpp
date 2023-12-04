// O(n)
// O(n)

/*
 *输入：s = "[123,[456,[789]]]",
 输出：[123,[456,[789]]]
 解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
 1. 一个 integer 包含值 123
 2. 一个包含两个元素的嵌套列表：
     i.  一个 integer 包含值 456
         ii. 一个包含一个元素的嵌套列表
                  a. 一个 integer 包含值 789
                   
 *
 * */

// Use stack to simulate
class Solution {
    public:
        NestedInteger deserialize(string s) {
            if (s[0] != '[') {
                return NestedInteger(stoi(s));
            }
            stack<NestedInteger> st;
            int num = 0;
            bool negative = false;
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '-') {
                    negative = true;
                } else if (isdigit(c)) {
                    num = num * 10 + c - '0';
                } else if (c == '[') {
                    st.emplace(NestedInteger());
                } else if (c == ',' || c == ']') {
                    if (isdigit(s[i - 1])) {
                        if (negative) {
                            num *= -1;
                        }
                        st.top().add(NestedInteger(num));  // Nestedinteger offers add()
                    }
                    num = 0;
                    negative = false;
                    if (c == ']' && st.size() > 1) {
                        NestedInteger ni = st.top();
                        st.pop();
                        st.top().add(ni);
                    }
                }
            }
            return st.top();
        }
};
