/**
 * Map interface.
 * 
 * @author Acuna
 * @param <Key> search key
 * @param <Value> return type
 */
public interface Map<Key, Value> {
    
    /**
     * Puts a key-value pair into the map.
     * 
     * @param key Key to use.
     * @param val Value to associate.
     */
    void put(Key key, Value val);
    
    /**
     * Gets the value paired with a key. If the key doesn't exist in map,
     * returns null.
     * 
     * @param key Key to use.
     * @return Value associated with key.
     */
    Value get(Key key);
    
    /**
     * Removes a key (and its associated value) from the map.
     * 
     * @param key Key to use.
     */
    void remove(Key key);
    
    /**
     * Checks if the map contains a particular key.
     * 
     * @param key True if map contains key, false otherwise.
     * @return Result of check.
     */
    boolean contains(Key key);
    
    /**
     * Returns true if there are no key-vale pairs stored in the map, and false
     * otherwise.
     * 
     * @return True if map is empty, false otherwise.
     */
    boolean isEmpty();
    
    /**
     * Returns the number of key-value pairs in the map.
     * 
     * @return Number of key-value pairs.
     */
    int size();
    
    /**
     * Returns an Iterable object containing all keys in the table. Keys not
     * guaranteed to be in any particular order.
     * 
     * @return Iterable object containing all keys.
     */
    Iterable<Key> keys();
}