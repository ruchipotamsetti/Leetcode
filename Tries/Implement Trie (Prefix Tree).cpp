//Time Complexity: O(n) where n is the length of the word to be inserted/searched/checked for prefix. 
// In the insert and search operations, we traverse the trie down to the depth of the word, which takes O(n) time.
// In the startsWith operation, we also traverse down to the depth of the prefix, which also takes O(n) time.
//Space Complexity: O(t) where t is the total number of nodes in the trie. 
// In the worst case, if we insert m words of length n, and all words are unique, 
// we could end up with O(m*n) nodes in the trie. 
// However, if there are common prefixes among the words, 
// the number of nodes will be less than m*n. 
// The space complexity is therefore O(t), 
// where t is the total number of nodes in the trie, which can be up to O(m*n) in the worst case.   

class Node{

public:
    bool endOfWord;
    Node* children[26];

    Node(){
        endOfWord = false;
        for(int i=0;i<26; i++){
            children[i]=nullptr;
        }
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        int n = word.size();
        for(int i = 0; i<n; i++){
            
            if(curr->children[word[i]-'a'] == nullptr){
                curr->children[word[i]-'a'] = new Node();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(curr->children[word[i]-'a'] == nullptr){
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            if(curr->children[prefix[i]-'a'] == nullptr){
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */