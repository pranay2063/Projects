import java.util.*;

class Trie {
    //One of the best data structures for string search
    //Time complexity is quite efficient
    //Major concern is space complexity as it takes quite additional space
    static final int alphabets = 26;
    static TrieNode root;
    static class TrieNode {
        boolean EndOfWord;
        TrieNode[] child = new TrieNode[alphabets];
        TrieNode(){
            this.EndOfWord = false;
            for(int i = 0; i < alphabets; ++i)
                child[i] = null;
        }
    }
    public void insert(String s){
        //Traverse trie and insert node when required and not found
        //Time Complexity - O(M) where M is length of string
        TrieNode temp = root;
        for(int i = 0; i < s.length(); ++i){
            int idx = s.charAt(i)-'a';
            if(temp.child[idx] == null)
                temp.child[idx] = new TrieNode();
            temp = temp.child[idx];
        }
        temp.EndOfWord = true;
    }
    public boolean search(String s){
        //search a string in trie
        //traverse from root to its children using string
        //Time Complexity - O(M) where M is length of string
        TrieNode temp = root;
        for(int i = 0; i < s.length(); ++i){
            int idx = s.charAt(i)-'a';
            if(temp.child[idx] == null)
                return false;
            temp = temp.child[idx];
        }
        //System.out.println("CHECK EXECUTION");
        return (temp != null && temp.EndOfWord);
    }
}

class TrieImplementation {
    public static void main(String[] args){
        Trie.root = new Trie.TrieNode();
        Trie obj = new Trie();
        obj.insert("abhinay");
        System.out.println(obj.search("abhinaya"));
        obj.insert("pranay");
        obj.insert("alexa");
        System.out.println(obj.search("alex"));
        System.out.println(obj.search("pranay"));
        obj.insert("alex");
        System.out.println(obj.search("alex"));
    }
}
