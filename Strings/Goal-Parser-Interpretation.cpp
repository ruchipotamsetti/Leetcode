/*
You own a Goal Parser that can interpret a string command. 
The command consists of an alphabet of "G", "()" and/or "(al)" in some order. 
The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". 
The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.
*/

class Solution {
public:
    string interpret(string command) { //command = "G()()()()(al)"
        string  parsedCommand;
        int i = 0;
        
        //check each character in the string and add its parsed value to the new string parsedCommand
        while(i < command.size()){
            if(command[i] == 'G'){
                parsedCommand += "G";
                i++;
            }
            else if(command[i] == '(' && command[i+1] == ')'){
                parsedCommand += "o";
                i += 2;
            }
            else{
                parsedCommand += "al";
                i += 4;
            }
        }
        return parsedCommand;  //returns "alGalooG"           
    }
};
