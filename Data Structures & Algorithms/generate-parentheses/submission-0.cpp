class Solution {
    void solve(int idx, string& s, int open, int close, int n, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        // we can always push open bracket !!!
        if (open > 0) {
            s += '(';
            solve(idx + 1, s, open - 1, close, n, ans);
            s.pop_back();
        }
        // pushing close is allowed only when close count is more than open!!!
        if (close > open) {
            s += ')';
            solve(idx + 1, s, open, close - 1, n, ans);
            s.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(0, s, n, n, n, ans);
        return ans;
    }
};
