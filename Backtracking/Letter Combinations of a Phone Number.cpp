//Time Complexity: O(n*4^n) where n is the length of the input string. 
// the recursion forms a tree where each level branches by about 3–4 choices.
//The total number of combinations is therefore:
////worst case: 4^n
////more generally: product of branching factors per digit
//For every complete combination, you also:
////build/store a string of length n
//In the worst case, each digit can map to 4 letters (like '7' and '9'), and we are generating all possible combinations, which can be 4^n in the worst case.
//The extra n: Copying/pushing a string of length n into result costs O(n)
//Space Complexity: O(n⋅4^n) for the result vector, which can contain up to 4^n combinations, and each combination is a string of length n.

class Solution {
public:
    vector<string>result;
    vector<string> letterCombinations(string digits) {
        //note: we could use a vector instead of an unordered map
        // vector<string>keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        unordered_map<char, string>keypad = {{'2',"abc"},{'3',"def"},{'4',"ghi"}, {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        string curr = "";
        createCombinations(0, digits, keypad, curr);

        return result;
    }

    void createCombinations(int i, string& digits, unordered_map<char, string>& keypad, string& curr){

        if(i>digits.size()){
            return;
        }

        if(curr.size() == digits.size()){
            result.push_back(curr);
            return;
        }

        int n = keypad[digits[i]].size();
        // cout<<"Size: "<<n<<", "<<keypad[digits[i]]<<", Curr: "<<curr<<endl;
        for(int j=0; j<keypad[digits[i]].size(); j++){
            curr+=keypad[digits[i]][j];
            createCombinations(i+1, digits, keypad, curr);
            curr.pop_back();
        }

    }
};