package Stacks ;

import java.util.Stack;

public class Postfix_To_Prefix {
    public String postfixToPrefix(String s){
        Stack<String> st = new Stack<>();
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s.charAt(i);
            if(Character.isLetterOrDigit(ch)){
                st.push(String.valueOf(ch));
            }
            else{
                String op1 = st.pop() ;
                String op2 = st.pop() ;
                st.push(ch+op2+op1+"");
            }
        }
        return st.pop() ;
    }

    // Main Method
    public static void main(String[] args) {
        Postfix_To_Prefix obj = new Postfix_To_Prefix() ;
        String postfixExpression = "ABC/-AK/L-*" ;
        String prefixExpression = obj.postfixToPrefix(postfixExpression);
        System.out.println(prefixExpression);
    }
}
