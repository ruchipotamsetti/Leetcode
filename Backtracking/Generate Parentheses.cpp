// Time complexity: O(4^n / sqrt(n)) where n is the number of pairs of parentheses.
// Number of recursive calls:
// At each level:2 choices
// Depth of recursion: 2n (here depth means we will stop until we have 2n characters in the string)
// So total possible strings explored: 2^(2n) = 4^n
// But since we are pruning combinations, we get O(4^n / sqrt(n)).
// This is because the number of valid combinations of parentheses is given by the nth Catalan number, which is approximately 4^n / (n^(3/2) * sqrt(pi)).
// Space complexity: O(n) for the recursive call stack and the current string being built.  

class Solution {
public:
    vector<string>result;
    vector<string> generateParenthesis(int n) {
        string p="";
        string parentheses="()";
        unordered_map<char, int>m;
        generate(n, p, m, parentheses);

        return result;

    }

    void generate(int n, string& p, unordered_map<char, int>& m, string& parentheses){

        if(m[')']>m['('])
            return;
        if(p.length() == n*2){
            if(m['('] == m[')']){
                result.push_back(p);
            }
            return;
        }

        for(int i=0; i<parentheses.length(); i++){
            p += parentheses[i];
            m[parentheses[i]]++;

            generate(n, p, m, parentheses);
            p.pop_back();
            m[parentheses[i]]--;
        }
    }

};