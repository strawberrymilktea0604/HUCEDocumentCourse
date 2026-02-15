import java.util.Iterator;

public class MainProgram {
    public static void main(String[] args)
    {
        // LinkedBinaryTree<String> D = new LinkedBinaryTree<String>("D", null, null);
        // LinkedBinaryTree<String> E = new LinkedBinaryTree<String>("E", null, null);
        // LinkedBinaryTree<String> B = new LinkedBinaryTree<String>("B", D, E);
        // LinkedBinaryTree<String> C = new LinkedBinaryTree<String>("C", null, null);
        // LinkedBinaryTree<String> A = new LinkedBinaryTree<String>("A", B, C);

        // Iterator<String> it = A.iteratorInOrder();

        // while(it.hasNext())
        // {
        //     String result = it.next();
        //     System.out.println(result+" ");
        // }

        Heap<Integer> test = new Heap<Integer>();

        test.addElement(Integer.valueOf(8));
        test.addElement(Integer.valueOf(3));
        test.addElement(Integer.valueOf(6));
        test.addElement(Integer.valueOf(5));
        test.addElement(Integer.valueOf(4));
        test.addElement(Integer.valueOf(9));

        while (!test.isEmpty())
        {
            Integer element = test.removeMin();
            System.out.println(element);
        }
    }
}
