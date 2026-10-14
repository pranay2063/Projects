package Cache;

public class Main {

    public static void main(String[] args) throws Exception {
        Cache<String, String> cache = new Cache<String, String>(CachePolicyType.LRU, 3);
        cache.put("Pranay", "Bangalore");
        System.out.println(cache.get("Pranay"));
    }

}
