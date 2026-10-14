import java.util.*;

class node {
    int data;
    node next;
    node(int data){
        this.data = data;
        this.next = null;
    }
}

class ReverseNodes {

    public node reverseIterativeWithoutStack(node head, int k){
        node current = head;
        node start = null;
        node last = null;
        while (current != null){
            int cnt = 0;
            node prev = null;
            node next = null;
            node visited = null;
            while(current != null && cnt < k){
                if(visited == null) visited = current;
                next = current.next;
                current.next = prev;
                prev = current;
                current = next;
                ++cnt;
            }
            if(last == null) last = visited;
            else{
                last.next = prev;
                last = visited;
            }
            if(start == null) start = prev;
        }
        return start; 
    }

    public node reverseIterativeStack(node head, int k){
        node temp = head;
        node prev  = null;
        node start = null;
        Stack<node> st = new Stack<node>();
        while(temp != null){
            int cnt = 0;
            while (temp != null && cnt < k){
                st.push(temp);
                temp = temp.next;
                ++cnt;
            }
            while (!st.empty()){
                node current = st.peek();
                if(prev == null){
                    prev = current;
                    start = current;
                }
                else{
                    prev.next = current;
                    prev = current;
                }
                st.pop();
            }
        }
        prev.next = null;
        return start;
    }

    public node reverseRecursive (node head, int k){
        //System.out.println(head.data);
        node current = head;
        node next, prev = null;
        int cnt = 0;
        while (current != null && cnt < k){
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            ++cnt;
        }
        if(current != null)
            head.next = reverseRecursive(current, k);
        return prev;
    }
    public void display(node head){
        if(head == null) return;
        node current = head;
        while (current != null){
            if(current.next == null)
                System.out.print(current.data);
            else System.out.print(current.data+"->");
            current = current.next;
        }
    }
}

class ReverseKNodes {
    public static void main(String[] args){
        node head = new node(1);
        head.next = new node(2);
        head.next.next = new node(3);
        head.next.next.next = new node(4);
        head.next.next.next.next = new node(5);
        head.next.next.next.next.next = new node(6);
        head.next.next.next.next.next.next = new node(7);
        head.next.next.next.next.next.next.next = new node(8);
        ReverseNodes obj = new ReverseNodes();
        obj.display(obj.reverseIterativeWithoutStack(head, 8));
    }
}
