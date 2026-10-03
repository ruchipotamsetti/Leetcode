class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        cur.reserve(2 * n);
        backtrack(result, cur, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            result.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(result, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(result, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
};