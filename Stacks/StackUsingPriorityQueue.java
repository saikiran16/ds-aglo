
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

class Pair{
    int data ,  priority ;
    public Pair(int data , int priority){
        this.data = data;
        this.priority = priority ;
    }
}

/*  Java PriorityQueue Time Complexity :
        For enqueing and dequeing methods, the time complexity is O(log(n))
        For the remove(Object) and contains(Object) methods, the time complexity is linear
        For the retrieval methods, it has constant time complexity
*/
public class StackUsingPriorityQueue {
     Queue<Pair> pq = null ;
    StackUsingPriorityQueue(){
        pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.priority > o2.priority)
                    return 1 ;
                return -1;
            }
        });
    }
    void push(int key){
        pq.offer(new Pair(key , pq.size()));
    }
    int pop(){
        return pq.poll().data;
    }

    public static void main(String[] args) {
        StackUsingPriorityQueue obj = new StackUsingPriorityQueue();
        obj.push(10);
        obj.push(20);
        obj.push(30);
        obj.push(40);
        obj.push(50);
        obj.push(60);
        obj.push(70);
        obj.pop();
        obj.push(90);
        obj.pop();
        for(Pair p : obj.pq){
            System.out.println(p.data  + " "  + p.priority);
        }


    }
}
