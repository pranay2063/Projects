package Cache;

public interface CachePolicy <t1, t2> {
    t2 get(t1 key);
    void put(t1 key, t2 value);
}
