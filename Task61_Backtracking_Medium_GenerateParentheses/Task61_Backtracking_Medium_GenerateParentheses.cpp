#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> result;

    std::vector<std::string> generateParenthesis(int n) {
        std::string s = "";
        create_subsets(n, 0, 0, s);
        return result;
    }
    void create_subsets(int n, int amount, int count_open, std::string& s) {
        if (n * 2 == s.size()) {
            result.push_back(s);
            return;
        }
        if (amount < 1) {
            s.push_back('(');
            create_subsets(n, amount + 1, count_open + 1, s);
            s.pop_back();
        }
        else if (count_open == n) {
            s.push_back(')');
            create_subsets(n, amount - 1, count_open, s);
            s.pop_back();
        }
        else {
            s.push_back('(');
            create_subsets(n, amount + 1, count_open + 1, s);
            s.pop_back();
            s.push_back(')');
            create_subsets(n, amount - 1, count_open, s);
            s.pop_back();
        }
    }
};
