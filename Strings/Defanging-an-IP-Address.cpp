/*Problem: Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
*/

class Solution {
public:
    string defangIPaddr(string address) { //address="255.100.50.0"
        string newString, word;
        stringstream ss(address); // string to stringstream object
        int count=0;
        int size = address.size();
        
        // inserting string into word and checking if it the last segment of the IP address
        while(getline(ss, word,'.') && count != size-word.size()){ 
            newString += word + "[.]";
            count += word.size() + 1;
        }
        newString += word; // adding the last segment of the IP address
        return newString; // returns "255[.]100[.]50[.]0"
    }
};
