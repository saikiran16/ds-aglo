package Queue ;
import java.util.* ;

class DLLNode{
    int key ;
    int value ;
    DLLNode next , prev ;
    DLLNode(int key ,int  value){
        this.key = key ;
        this.value = value ;
        this.next = this.prev = null ;
    }
}
class LRUCache {
    HashMap<Integer , DLLNode> hm  ;
    int size  , capacity ;
    DLLNode head = null   ,tail = null;
    public LRUCache(int capacity) {
        this.size = 0 ;
        this.capacity = capacity ;
        this.hm = new HashMap<>() ;

    }
    DLLNode addFirst(DLLNode newNode){
        
        if(head == null) {
            head = newNode ;
            tail = newNode ;
            return head;
        }
        head.prev = newNode ;
        newNode.next = head ;
        head = newNode ;
        return head ;
    }
    void  removeLast(){
        tail = tail.prev ;
        return  ;
    }
    void removeNode(DLLNode nodeToBeRemoved){
        if(nodeToBeRemoved == tail){
            removeLast();
        }
        else{
            if(nodeToBeRemoved.prev != null )
                nodeToBeRemoved.prev.next = nodeToBeRemoved.next ;
            if(nodeToBeRemoved.next != null)
                nodeToBeRemoved.next.prev = nodeToBeRemoved.prev ;
            nodeToBeRemoved.prev = null ;
            nodeToBeRemoved.next = null ;
        }
    }
    public int get(int key) {
        // Need to remove the Node and add it at the First .
        
        if(hm.containsKey(key)){
            System.out.println("present  " + key);
            DLLNode curr = hm.get(key);
            if(curr != head)
                removeNode(curr);
            addFirst(curr);
            return curr.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        
        if(hm.containsKey(key)){
            //If Already present then we need to remove and insert at first with new update value ;
            DLLNode curr = hm.get(key);
            if(curr == head){
                curr.value = value;
            }
            else{
                removeNode(curr);
                curr.value = value;
                addFirst(curr);
            }
            return ;
        }
        else{
            System.out.println("Fresh Node : " +key + " " + value);
            DLLNode newNode = new DLLNode(key , value);
            hm.put(key, addFirst(newNode));
            size++;
        }
        if(size > capacity){
            hm.remove(tail.key);
            removeLast();
            size--;
        }
        System.out.println(hm);
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 * ["LRUCache","get","put","get","put","put","get","get"]
[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
 */
class TestingLRUCache{
    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(1);
        lRUCache.put(2, 1); // cache is {1=1}
        //lRUCache.put(2, 2); // cache is {1=1, 2=2}
        System.out.println(lRUCache.get(2));    // return 1
        lRUCache.put(3, 2); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        System.out.println(lRUCache.get(2));    // returns -1 (not found)
        //lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        //System.out.println(lRUCache.get(1));    // return -1 (not found)
        System.out.println(lRUCache.get(3));    // return 3
       // System.out.println(lRUCache.get(4));    // return 4
    }
}