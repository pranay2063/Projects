package Cache;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.HashMap;

public class LRU<t1, t2> implements CachePolicy<t1, t2> {

    private final Logger logger = LoggerFactory.getLogger(LRU.class);
    HashMap<t1, t2> valueMap;
    HashMap<t1, Node<t1>> nodeMap;
    Node<t1> head;
    Node<t1> last;
    int capacity;
    int size;

    LRU(int capacity){
        valueMap = new HashMap<>();
        nodeMap = new HashMap<>();
        head = null;
        last = null;
        this.capacity = capacity;
        size = 0;
    }

    /**
     * If key is present, shuffle the position of the key in the LRU cache and return its value
     * @param key
     * @return value
     */
    @Override
    public t2 get(t1 key) {
        if(valueMap.containsKey(key)){
            shuffleNode(nodeMap.get(key));
            return valueMap.get(key);
        }
        return null;
    }

    /**
     * If the key is present, shuffle the position of the key in the LRU cache and update the value
     * Else remove the least used entry if cache is full and then insert the pair in the cache
     * @param key
     * @param value
     */
    @Override
    public void put(t1 key, t2 value) {
        if(valueMap.containsKey(key)){
            shuffleNode(nodeMap.get(key));
            valueMap.put(key, value);
        }
        else {
            if(size == capacity){
                nodeMap.remove(head.val);
                valueMap.remove(head.val);
                valueMap.put(key, value);
                if(head == last){
                    head.val = key;
                    nodeMap.put(key, head);
                }
                else {
                    Node<t1> temp = head;
                    head = head.next;
                    temp.val = key;
                    temp.next = null;
                    last.next = temp;
                    nodeMap.put(key, temp);
                    last = last.next;
                }
            }
            else {
                if (head == null){
                    head = new Node<>(key, null);
                    last = head;
                }
                else {
                    last.next = new Node<>(key, null);
                    last = last.next;
                }
                valueMap.put(key, value);
                nodeMap.put(key, last);
                ++size;
            }
        }
    }

    public void shuffleNode(Node<t1> node){
        if(node != last){
            if(node.next == last){
                t1 tempKey = node.val;
                node.val = last.val;
                last.val = tempKey;
                nodeMap.put(last.val, last);
                nodeMap.put(node.val, node);
            }
            else {
                t1 tempKey = node.val;
                Node<t1> tempNode = node.next;
                nodeMap.put(tempKey, tempNode);
                node.val = node.next.val;
                nodeMap.put(node.val, node);
                node.next = node.next.next;
                tempNode.val = tempKey;
                tempNode.next = null;
                last.next = tempNode;
                last = last.next;
            }
        }
    }

    public void printCache(){
        Node<t1> temp = head;
        while (temp != null){
            System.out.print(temp.val+"="+valueMap.get(temp.val)+", ");
            temp = temp.next;
        }
        System.out.println();
    }

}
