package Stacks ;
import java.util.* ;
class ReverseAStackUsingRecursion{
    Stack<Integer> stack ;
    ReverseAStackUsingRecursion(){
        stack = new Stack<>();
    }
    void pushAllElements(int[] arr){
        for(int item : arr){
            stack.push(item);
        }
    }
    void reverse(){
        if(stack.isEmpty()) return ;
        int currentEle = stack.pop() ;
        reverse();
        stack.push(currentEle);
    }
    void printStack(){
        while(!stack.isEmpty()){
            System.out.println(stack.pop());
        }
    }

    // Main Method  for testing 
    public static void main(String[] args) {
        ReverseAStackUsingRecursion obj = new ReverseAStackUsingRecursion();
        int arr[] = {1,2,3,4,5,6};
        obj.pushAllElements(arr);
        obj.reverse();
        obj.printStack();
    }
}