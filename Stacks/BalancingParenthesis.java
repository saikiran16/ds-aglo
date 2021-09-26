package Stacks ;

import java.util.Stack;

public class BalancingParenthesis {
    public boolean BalancedOrNot(String s){
        Stack<Character> stack = new Stack<>();
        for(int i = 0 ; i < s.length() ; i++){
            //System.out.println(stack);
            char ch = s.charAt(i);
          //  System.out.println(ch);
            if(ch == '(' || ch == '{' || ch == '[') { stack.push(ch); continue; }
            else if(stack.isEmpty() || (stack.peek() != '(' && ch == ')')) return false ;
            else if(stack.isEmpty() || (stack.peek() != '{' && ch == '}')) return false ;
            else if(stack.isEmpty() || (stack.peek() != '[' && ch == ']')) return false ;
            System.out.println("poped : " + stack.pop());
        }
        // If stack is empty return true . else some more parenthesis are left . not balanced .
        if(stack.isEmpty()) return true;
        return false;

    }


    // Main Method
    public static void main(String[] args) {
        BalancingParenthesis obj = new BalancingParenthesis();
        String toBeChecked = "{([])}";
        System.out.println(obj.BalancedOrNot(toBeChecked));
    }
}
