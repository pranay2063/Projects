import Cache.*;
import org.junit.Before;
import org.junit.Test;

public class CacheTest {

    private Cache<String, String> cache;

    @Before
    public void init() throws Exception {
        cache = new Cache<String, String>(CachePolicyType.LRU, 3);
    }

    @Test
    public void testCacheNotFullCases(){
        cache.put("Pranay", "Bangalore");
        assert "Bangalore".equals(cache.get("Pranay"));
        cache.put("Ranjan", "Kolkata");
        cache.put("Pranay", "Bhopal");
        assert "Bhopal".equals(cache.get("Pranay"));
        assert cache.get("random") == null;
    }

    @Test
    public void testCacheFullCases(){
        cache.put("Pranay", "Bangalore");
        cache.put("Ranjan", "Kolkata");
        cache.put("Matt", "London");
        cache.put("Damon", "NY");
        assert "NY".equals(cache.get("Damon"));
        assert cache.get("Pranay") == null;
        cache.put("Ranjan", "Mumbai");
        cache.put("Pranay", "Bangalore");
        assert cache.get("Matt") == null;
        assert "Bangalore".equals(cache.get("Pranay"));
        assert "Mumbai".equals(cache.get("Ranjan"));
    }

}
