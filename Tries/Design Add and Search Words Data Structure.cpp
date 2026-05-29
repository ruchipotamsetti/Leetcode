//Usin vector of strings:
// Time Complexity: O(n) for addWord, O(m*n) for search
// Space Complexity: O(n) for addWord, O(m*n) for search    
// TIME LIMIT EXCEEDED for search when there are many words in the stock and the search word has many '.' characters.

class WordDictionary {
public:
    vector<string>stock;
    WordDictionary() {
        stock = {};
    }
    
    void addWord(string word) {
        stock.push_back(word);
    }
    
    bool search(string word) {
        for(string s:stock){
            if(s.size() != word.size())
                continue;
            int i=0;
            while(i<word.size()){
                if(word[i]=='.' || word[i]==s[i]){
                    i++;
                }
                else{
                    break;
                }
            }
            if(i==word.size())
                return true;
        }
        return false;
    }
};

// Using Tries:
// Time Complexity: O(n) for addWord, O(n) for search
// Space Complexity: O(n+t)
// Where n is the length of the string and t is the total number of TrieNodes created in the Trie.

class Node{
public:
    bool endOfWord;
    Node* children[26];
    Node(){
        endOfWord = false;
        for(int i=0; i<26; i++){
            children[i]=nullptr;
        }
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr =  root;
        for(auto c:word){
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new Node();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(0, word, root);
        
    }

    bool dfs(int j, string word, Node* root){
        Node* curr = root;

        for(int i=j; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(Node* child:curr->children){
                    if(child != nullptr && dfs(i+1, word, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->children[c-'a']==nullptr){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->endOfWord;
    }
};
