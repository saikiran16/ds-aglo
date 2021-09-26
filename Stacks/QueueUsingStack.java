package Stacks;

import java.util.Stack;

public class QueueUsingStack {
    Stack<Integer> stack  , dummyStack ;
    public QueueUsingStack(){
        stack = new Stack<Integer>() ;
    }
    public  void pushIntQueue(int data){
        stack.push(data) ;
    }
    public int popFromQueue(){
        dummyStack = new Stack<Integer>() ;
        while(!stack.isEmpty()){
            dummyStack.push(stack.pop());
        }
        int res = dummyStack.pop();
        while(!dummyStack.isEmpty()){
            stack.push(dummyStack.pop());
        }
        return res;
    }
    public static void main(String[] args) {
        QueueUsingStack object = new QueueUsingStack() ;
        object.pushIntQueue(10);
        object.pushIntQueue(20);
        object.pushIntQueue(30);
        object.pushIntQueue(40);
        object.pushIntQueue(50);
        object.pushIntQueue(60);
        System.out.println(object.popFromQueue());
        System.out.println(object.stack);
        
    }

}
