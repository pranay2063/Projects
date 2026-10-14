package Cache;

public class Node<t1> {

    public t1 val;
    public Node<t1> next;

    Node(t1 val, Node<t1> next){
        this.val = val;
        this.next = next;
    }

}
