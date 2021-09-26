package Queue;
import java.util.*;
public class QueueUsingStack {
    Stack<Integer> stack  ;
    QueueUsingStack(){
        this.stack= new Stack<Integer>();
    }

    void enqueue(int key){
        stack.push(key);
    }
    int dequeue(){
        // Costly Operation
        Stack<Integer> temporaryStack = new Stack<>();
        if(stack.isEmpty()){
            try{
                throw new Exception("Stack is Empty you cant dequeue");
            }
            catch(Exception e){
                e.printStackTrace();
            }
            return -1 ;
        }
        while(stack.isEmpty() == false){
            temporaryStack.push(stack.pop());
        }
        
        int dequeuedElement = temporaryStack.pop();
        while(temporaryStack.isEmpty() == false){
            stack.push(temporaryStack.pop());
        }
        return dequeuedElement;
    }
}

class TesingQueueUsingStack{
    public static void main(String[] args) {
        QueueUsingStack obj = new QueueUsingStack() ;
        obj.enqueue(10);
        obj.enqueue(20);
        obj.enqueue(30);
        obj.enqueue(40);
        obj.enqueue(50);
        System.out.println(obj.stack.peek());
        System.out.println(obj.dequeue());
        System.out.println(obj.dequeue());
        System.out.println(obj.stack);
    }
}
