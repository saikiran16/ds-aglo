import java.util.Collections;
import java.util.Comparator;
import java.util.Stack;

public class MergingOverlaps {
     class Pair{
        int starting , ending ;
        Pair(int a ,int b){
            if(a >b){
                try {
                    throw new Exception("Invalid Start time and End time ");
                } catch (Exception e) {
                    e.printStackTrace();
                }

            }
            this.starting  = a ;
            this.ending = b;
        }
    }
    Stack<Pair> stack ;
    MergingOverlaps(){
        stack = new Stack<>();

    }
    void mergeThem(){
        Collections.sort(stack, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.starting < o2.starting){
                    return 1;
                }
                else return -1;
            }
        });
       /* for(Pair p : stack){
            System.out.println(p.starting + " --- " + p.ending);
        }*/
        Pair currentMergingPair = stack.pop();
        while(!stack.isEmpty()){
            Pair topOfStack = stack.pop();
            if(currentMergingPair.ending >= topOfStack.starting){
                currentMergingPair.ending = topOfStack.ending;
            }
            else{
                System.out.println(currentMergingPair.starting + " ---- " + currentMergingPair.ending);
                currentMergingPair = topOfStack;
            }
        }
        System.out.println(currentMergingPair.starting + " ----" + currentMergingPair.ending );
    }

    public static void main(String[] args) {
        MergingOverlaps obj = new MergingOverlaps();
        obj.stack.add(obj.new Pair(1, 2));
        obj.stack.add(obj.new Pair(17, 30));
        obj.stack.add(obj.new Pair(1, 4));
        obj.stack.add(obj.new Pair(4, 6));
        obj.mergeThem();
        for(Pair p : obj.stack){
            System.out.println(p.starting + " --- " + p.ending);
        }

    }


}
