/*
Question : Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.
 */
/*
Algorithm :
  Create a stack
 for every character in String i.e either a '( ' or ')':
    if character is '(' push index of character
    else if character is ')' and stack is not empty then pop the stack and calcuate the length and update the result .

 */

import java.util.Stack;

public class LongestValidParenthesis {
    Stack<Integer> stack ;
    String s ;
    LongestValidParenthesis(String s){
        stack = new Stack<>();
        this.s = s ;
    }
    int getLongestValidSubString(){
        int longest_length = 0 ;
        stack.push(-1);
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s.charAt(i);
            if(ch == '(') stack.push(i);
            else{
                if(!stack.isEmpty()) stack.pop();
                if(!stack.isEmpty()) longest_length = Math.max(longest_length , i - stack.peek());
                else stack.push(i);

            }
        }
        return longest_length;
    }


}
