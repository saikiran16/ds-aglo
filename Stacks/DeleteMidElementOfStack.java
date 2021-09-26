import java.util.Stack;
// Delete Mid element of Stack . If Even number of elements are there in stack we will two middle Elements then remove the first element.
public class DeleteMidElementOfStack {
    Stack<Integer> stack = null;
    DeleteMidElementOfStack(){
        stack = new Stack<>();
    }
    private  void pushAll(int[] arr){
        for(int item : arr){
            stack.push(item);
        }
    }
    private  void deleteMidElement(int currentIndex , int sizeofStack){
        if(stack.isEmpty()) return ;
        if(currentIndex == sizeofStack/2){
            stack.pop();
            return;
        }
        else{
            int element = stack.pop();
            deleteMidElement(currentIndex+1 , sizeofStack);
            stack.push(element);
        }

    }

    public static void main(String[] args) {
        DeleteMidElementOfStack obj = new DeleteMidElementOfStack();
        obj.pushAll(new int[]{1,2,3,4,5,6});
        obj.deleteMidElement(0 , obj.stack.size());
        obj.printStack();
    }

    private void printStack() {
        while(!stack.isEmpty()){
            System.out.println(stack.pop());
        }
    }
}
