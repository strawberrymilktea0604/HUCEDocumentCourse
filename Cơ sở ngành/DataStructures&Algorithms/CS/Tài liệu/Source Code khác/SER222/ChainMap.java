import java.util.LinkedList;
import java.util.Queue;

/**
 * A map (like) ADT implemented using a hashtable with chaining.
 * @author Acuna, Sedgewick and Wayne
 */
public class ChainMap<Key, Value> implements Map<Key, Value> {
    
    private class Entry {
        public Key key;
        public Value value;
        public Entry (Key k, Value v) {
            key = k;
            value = v;
        }
    }
    
    private int N; // number of key-value pairs
    private int M; // hash table size
    
    private LinkedList<Entry>[] entries;
    
    public ChainMap() {
        this(997);
    }
    
    public ChainMap(int M) {
        this.N = 0;
        this.M = M;
        entries = new LinkedList[M];
        for (int i = 0; i < M; i++)
            entries[i] = new LinkedList<ChainMap<Key, Value>.Entry>();
    }
    
    private int hash(Key key) {
        return (key.hashCode() & 0x7fffffff) % M;
    }
    
    @Override
    public Value get(Key key) {
        
        for(Entry entry : entries[hash(key)])
            if(key.hashCode() == entry.key.hashCode())
                return entry.value;
                
        return null;
    }
    
    @Override
    public void put(Key key, Value val) {
        boolean added = false;
        
        for(Entry entry : entries[hash(key)])
            if(key.hashCode() == entry.key.hashCode()) {
                entry.value = val;
                added = true;
            }
        
        if(!added) {
             entries[hash(key)].add(new Entry(key, val));
             N++;
        }
    }
    
    @Override
    public int size() {
        return N;
    }
    
    @Override
    public boolean isEmpty() {
        return N == 0;
    }
    
    @Override
    public boolean contains(Key k) {
        return get(k) != null;
    }
    
    @Override
    public void remove(Key key) {
        if(contains(key)) {
            Entry target = null;
            for(Entry e : entries[hash(key)])
                if(e.key == key)
                    target = e;
            
            entries[hash(key)].remove(target);
            N--;
        }
    }
    
    @Override
    public Iterable<Key> keys() {        
        Queue<Key> queue = new LinkedList<Key>();
        
        for (int i = 0; i < M; i++)
            for(Entry e : entries[i])
                    queue.add(e.key);
        
        return queue;
    }
}
