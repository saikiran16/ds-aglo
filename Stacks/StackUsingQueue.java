package Stacks ;

import java.util.LinkedList;
import java.util.Queue;

public class StackUsingQueue {
    Queue<Integer> q  = null ;
    StackUsingQueue(){
        q = new LinkedList<>() ;
    }
    void push(int data){
        q.add(data) ;
    }
    int pop()  {
        if(q.size() == 0) try {
            throw new Exception("Empty Queue ");
        } catch (Exception e) {
            e.printStackTrace();

        }
        Queue<Integer> dummyQueue = new LinkedList<>();
        while(q.size() > 1){
            dummyQueue.add(q.poll());
        }
        int res = q.poll();
        while(dummyQueue.size() > 0){
            q.add(dummyQueue.poll());
        }
        return res ;

    }
    public static void main(String[] args) {
        StackUsingQueue obj = new StackUsingQueue();
        obj.push(10);
        obj.push(20);
        obj.push(30);
        obj.push(40);
        obj.push(50);
        obj.push(60);
        System.out.println(obj.pop());
        System.out.println(obj.q);
        System.out.println(obj.pop());
        System.out.println(obj.q);


    }

}
