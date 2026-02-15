import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Map testing ground.
 * 
 * @author (your name), Acuna
 * @version (version)
 */
public class Driver {
    
    /**
     * Entry point for testing.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        System.out.println("ChainMap: ");
        testStrings(new ChainMap<String, Integer>());
        
        System.out.println("TwoProbeChainMap: ");
        testStrings(new TwoProbeChainMap<String, Integer>());

        System.out.println("LinearProbingMap: ");
        testStrings(new LinearProbingMap<String, Integer>());
    }
    
    /**
     * Test string operations on symbol table implementation. No JUnit; ugly. 
     * Make assertions are enabled before using this method.
     * 
     * @param m An object implementing a symbol table.
     */
    public static void testStrings(Map<String, Integer> m) {
        
        System.out.println("*STRING TESTING*");
        System.out.println("  Testing creation and basic methods... ");
        
        //populate initial symbol table.
        Set<String> keys = new HashSet<>(Arrays.asList("DFKDJSFS", "DAFDW", "XZC", "adsfas", "a", "B", "112323", "<Object>", "AAAA", "A"));
        m.put("DFKDJSFS", 21);
        m.put("DAFDW", 52);
        m.put("XZC", 5);
        m.put("adsfas", 8);
        m.put("a", 58);
        m.put("B", 0);
        m.put("112323", 84);
        m.put("<Object>", 743564);
        m.put("AAAA", 7);
        m.put("A", 1);
        
        assert(!m.isEmpty())           : "symbol table is empty after inserting elemetns";
        assert(m.size() == 10)         : "does not contain correct number of elements";
        assert(m.contains("112323"))  : "added key -42341145 does not exist";
        assert(m.contains("a"))          : "added key 0 does not exist" ;
        assert(m.contains("DFKDJSFS"))   : "added key 38334343 does not exist";
        assert(!m.contains("b")) : "contains unknown key -62341145";
        assert(!m.contains("AA"))        : "contains unknown key -1";
        assert(!m.contains("FDFDSFSFDSFDS"))  : "contains unknown key -58334343";

        Set<String> stKeys = new HashSet<>();
        for(String i : m.keys())
            stKeys.add(i);
        assert(stKeys.equals(keys))     : "keys do not match expected";

        //note: the following code does not check if keys is maintained properly - it should.
        
        System.out.println("  Testing put()... ");
        
        //add new key
        int size = m.size();
        m.put("TEST", 42);
        assert(m.size() == size + 1)   : "size did not update.";
        assert(m.contains("TEST"))         : "does not contain new key";
        assert(m.get("TEST") == 42)        : "does not return correct value";
        
        //update existing key
        size = m.size();
        m.put("AAAA", 2);
        assert(m.size() == size)       : "size changed";
        assert(m.contains("AAAA"))     : "does not contain updated key";
        assert(m.get("AAAA") == 2)     : "does not return updated value";
            
        System.out.println("  Testing get... ");
        
        //get key not there
        size = m.size();
        Integer ret = m.get("TEST2");
        assert(ret == null)             : "returned non-null for key that doesn't exist";
        assert(m.size() == size)       : "size changed";        
        assert(!m.contains("TEST2"))   : "a key that doesn't exist appeared after get'ing it";

        //get key there ("DAFDW", 52)
        size = m.size();
        ret = m.get("DAFDW");
        assert(ret == 52)               : "returned incorrect value for key";
        assert(m.size() == size)       : "size changed";        
        assert(m.contains("DAFDW"))          : "key vanished after get'ing it";
        
        
        System.out.println("  Testing delete... ");
        
        //delete key not there
        size = m.size();
        m.remove("<Object>ZZZ");
        assert(m.get("<Object>ZZZ") == null)   : "returned non-null for key that was deleted";
        assert(m.size() == size)               : "size changed";        
        assert(!m.contains("<Object>ZZZ"))     : "a missing key is contained after it was deleted";

        //delete key there  ("<Object>", 743564)
        size = m.size();
        m.remove("<Object>");
        assert(m.get("<Object>") == null)      : "returned non-null for key that was deleted";
        assert(m.size() == size - 1)           : "size did not update";        
        assert(!m.contains("<Object>"))        : "a deleted key is still contained";
        
        System.out.println("  DONE\n");
    }
}
