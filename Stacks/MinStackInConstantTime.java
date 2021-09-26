package Stacks ;

import java.util.Stack;

public class MinStackInConstantTime {
    int min ;
    public void push(int a,Stack<Integer> s)
    {
        //add code here.
        if(s.isEmpty()) {
            min = a ;
            s.push(a);
        }
        else if(min > a) {
            s.push(min - a);
            min = a ;
        }
        else s.push(a);


    }
    public int pop(Stack<Integer> s)
    {
        //add code here.
        if(s.peek() >= min) return s.pop() ;
        else{
            min = s.peek() + min ;
            return s.pop() ;
        }
    }
    public int min(Stack<Integer> s)
    {
        //add code here.
        return min ;
    }
    public boolean isFull(Stack<Integer>s, int n)
    {
        //add code here.
        if(s.size() >= n) return true;
        return false ;
    }
    public boolean isEmpty(Stack<Integer>s)
    {
        //add code here.r
        return s.isEmpty();
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>() ;
        MinStackInConstantTime obj = new MinStackInConstantTime();
        obj.push(8 ,stack);
        obj.push(10 ,stack);
        obj.push(6 ,stack);
        obj.push(3 ,stack);
        obj.push(7 ,stack);
        obj.pop(stack);
        System.out.println(obj.min(stack));
        obj.pop(stack);
        System.out.println(obj.min(stack));


    }
}
