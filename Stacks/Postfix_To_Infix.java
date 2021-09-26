package Stacks ;

import java.util.Stack;

public class Postfix_To_Infix {
    public String postfix_to_infix(String s){

        Stack<String> st = new Stack<>();
        for(int i = 0 ; i< s.length() ; i++){
            char ch = s.charAt(i);
            if(Character.isLetterOrDigit(ch)){
                st.push(ch+"");
            }
            else{
                String op1 = st.pop() ;
                String op2 = st.pop();
                st.push("(" + op2 + ch + op1 + ")");
            }
        }
        return st.pop();
    }


    //Main Method
    public static void main(String[] args) {
        Postfix_To_Infix obj = new Postfix_To_Infix();
        String postFixExpression = "ab*c+";
        String infixExpression = obj.postfix_to_infix(postFixExpression);
        System.out.println(infixExpression);
    }
}
