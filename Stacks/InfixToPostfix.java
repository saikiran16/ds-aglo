package Stacks ;
import java.util.Stack;

public class InfixToPostfix {
    public static int precedence(char operator) {
        if (operator == '^') return 3;
        if (operator == '*') return 2;
        if (operator == '/') return 2;
        if (operator == '+') return 1;
        if (operator == '-') return 1;
        return -1;
    }

    public static String infixToPostfix(String exp) {
        // Your code here
        Stack<Character> st = new Stack<Character>();
        String result = "";
        for (int i = 0; i < exp.length(); i++)
        {
           // System.out.println(st);
            char ch = exp.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                result += ch;
            }
            else if (ch == '(') {st.push(ch) ;continue;}
            else if (ch == ')')
            {
                while (!st.isEmpty() && st.peek() != '(') {
                    result += st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.isEmpty() && precedence(ch) <= precedence(st.peek()))
                    result += st.pop();
                st.push(ch);
            }
        }

        while (!st.isEmpty()) {
            result += st.pop();
        }
        return result;
    }
    public static void main(String[]args){
        
        String s = "(a+b+c)/d";
        String r = infixToPostfix(s);
        System.out.println(r);

    }

}
