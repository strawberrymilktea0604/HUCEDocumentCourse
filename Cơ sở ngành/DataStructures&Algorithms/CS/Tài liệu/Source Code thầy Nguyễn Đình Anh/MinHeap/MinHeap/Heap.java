public class Heap<T extends Comparable<T>> extends LinkedBinaryTree<T> implements HeapADT<T> 
{

    protected HeapNode<T> lastNode;

    public Heap()
    {
        super();
    }

    @Override
    public void addElement(T element) {
        HeapNode<T> node = new HeapNode<T>(element);
        if (root == null)
        {
            root = node;
        }
        else
        {
            HeapNode<T> nextParent = getNextParentAdd();


            if (nextParent.left == null)
                nextParent.left = node;
            else 
                nextParent.right = node;
            
            node.parent = nextParent;
        }
        lastNode = node;
        count++;
        if (count > 1)
            heapifyAdd();
    }

    private void heapifyAdd()
    {
        T temp;
        HeapNode<T> next = lastNode;

        while(next!=root && next.parent.element.compareTo(next.element)>0)
        {
            temp = next.element;
            next.element = next.parent.element;
            next.parent.element = temp;
            next = next.parent;
        }
    }

    private HeapNode<T> getNextParentAdd()
    {
        HeapNode<T> result = lastNode;
        while(result != root && result.parent.left != result)
            result = result.parent;

        if (result != root)
        {
            if (result.parent.right == null)
            {
                result = result.parent;
            }
            else
            {
                result = (HeapNode<T>)result.parent.right;
                while (result.left != null)
                    result = (HeapNode<T>)result.left;
            }
        } else {
            while(result.left != null)
                result = (HeapNode<T>)result.left;
        }
        
        return result;
    }

    @Override
    public T removeMin() {
        if (isEmpty())
            throw new EmptyCollectionException("MinHeap");
        
        T minElement = root.element;
        if (count == 1)
        {
            root = null;
            lastNode = null;
        }
        else
        {
            HeapNode<T> nextLast = getNewLastNode();
            if (lastNode.parent.left == lastNode)
                lastNode.parent.left = null;
            else
                lastNode.parent.right = null;

            root.element = lastNode.element;
            lastNode = nextLast;
            heapifyRemove();
        }

        count--;

        return minElement;
    }

    public void heapifyRemove()
    {
        T temp;
        HeapNode<T> node = (HeapNode<T>) root;
        HeapNode<T> left = (HeapNode<T>) node.left;
        HeapNode<T> right = (HeapNode<T>) node.right;
        HeapNode<T> next;

        if (left == null && right == null)
            next = null;
        else if (left == null)
            next = right;
        else if (right == null)
            next = left;
        else if (left.element.compareTo(right.element)<0)
            next = left;
        else
            next = right;

        while (next != null && node.element.compareTo(next.element) > 0)
        {
            temp = node.element;
            node.element = next.element;
            next.element = temp;
            node = next;
            
            left = (HeapNode<T>) node.left;
            right = (HeapNode<T>) node.right;
            
            if (left == null && right == null)
                next = null;
            else if (left == null)
                next = right;
            else if (right == null)
                next = left;
            else if (left.element.compareTo(right.element)<0)
                next = left;
            else
                next = right;
        }
    }

    private HeapNode<T> getNewLastNode()
    {
        HeapNode<T> result = lastNode;

        while (result != root && result.parent.left == result)
            result = result.parent;

        if (result != root)
            result = (HeapNode<T>)result.parent.left;

        while (result.right != null)
            result = (HeapNode<T>) result.right;

        return result;
    }

    @Override
    public T findMin() {
        if (isEmpty())
            throw new EmptyCollectionException("Min Heap");
        return root.element;
    }
}
