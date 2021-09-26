package Stacks ;

import java.util.Stack;
import java.util.Vector;

public class StockSpanProblem {
    Vector<Integer> calculateSpan(int price[], int n)
    {
        // Your code here
        Vector<Integer> finalAns = new Vector<>();
        Stack<Integer> st = new Stack<>();
        st.push(0);
        finalAns.add(1) ;
        for(int i = 1 ; i < n ; i++){
            
            while(!st.empty() && price[st.peek()] <= price[i]){
                st.pop();
            }
            if(st.empty() == true) finalAns.add(i+1);
            else
                finalAns.add(i - st.peek());
            st.push(i);
        }
        return finalAns;
    }

    // Main
    public static void main(String[] args) {
        StockSpanProblem obj = new StockSpanProblem();
        int stocks[] = {100, 80, 60, 70, 60, 75, 85} ;
        System.out.println(obj.calculateSpan(stocks , stocks.length));
    }
}
