class StackNode{
    int data ;
    StackNode next ;
}
public class ReverseStackWithoutExtraSpace {
    StackNode top ;
    ReverseStackWithoutExtraSpace(){
        top = new StackNode();
    }
    void push(int key){
        StackNode newEntry = new StackNode();
        newEntry.data = key ;
        if(top == null) {
            top = newEntry;
            return;
        }
        newEntry.next = top ;
        top = newEntry ;
    }
    int pop(){
        if(top == null){
            throwEmptyStackException();
        }
        StackNode poped = top ;
        top = top.next ;
        return poped.data ;
    }
    boolean isEmpty(){
        if(top == null) return true ;
        return false ;
    }
    void reverseStack(){
        StackNode nextNode , currentNode ;
        currentNode = top ;
        nextNode = top.next;
        currentNode.next = null ;
        while(nextNode != null){
            currentNode = nextNode ;
            nextNode = nextNode.next;
            currentNode.next = top ;
            top = currentNode ;
        }

    }
    void printStack(){
        StackNode iter = top ;
        while(iter != null){
            System.out.println(iter.data);
            iter = iter.next;
        }
    }
    void throwEmptyStackException(){
        try{
            throw new Exception("Empty Stack ");
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    //Main method for testing
    public static void main(String[] args) {
        ReverseStackWithoutExtraSpace stack = new ReverseStackWithoutExtraSpace() ;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        System.out.println("Stack before reversing");
        stack.printStack();
        stack.reverseStack();
        System.out.println("stack afer reversing");
        stack.printStack();
    }
}
