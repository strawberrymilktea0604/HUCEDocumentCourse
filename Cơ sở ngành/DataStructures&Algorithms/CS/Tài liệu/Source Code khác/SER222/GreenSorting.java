/**
 * Implements various sorting algorithms.
 * 
 * @author (your name), Acuna, Sedgewick
 * @verison (version)
 */

public class GreenSorting {
     
    /**
     * Entry point for sample output.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        //Q1
        String[] a = {"S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E"};
        quicksortmid(a);
        assert isSorted(a); //requires assertions enabled.
        show(a);
        
        //Q2
        String[] b = {"S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E"};
        mergesort(b);
        assert isSorted(b);
        show(b);
    }
    
    public static <T extends Comparable<T>> void quicksortmid(T[] a) 
    {
        quicksortmid(a, 0, a.length-1);
    }
    
    public static <T extends Comparable<T>> void quicksortmid(T[] a, int min, int max)
    {
    	if (min < max)
		{
			// create partitions
			int indexofpartition = partition(a, min, max);
			
			// sort the left partition (lower values)
			quicksortmid(a, min, indexofpartition - 1);
			
			// sort the right partition (higher values)
			quicksortmid(a, indexofpartition + 1, max);
		}
    }
    
    public static <T extends Comparable<T>> int partition(T[] a, int min, int max)
    {
    	T partitionelement;
		int left, right;
		int middle = (min + max) / 2;
		
		if(a[middle].compareTo(a[min]) < 0)
			swap(a, min, middle);
		if(a[max].compareTo(a[min]) < 0)
			swap(a, min, max);
		if(a[max].compareTo(a[middle]) < 0)
			swap(a, middle, max);
		
		partitionelement = a[middle];
		
		swap(a, middle, min);
		
		left = min;
		right = max;
		
		while (left < right)
		{
			// search for an element that is > the partition element
			while (left < right && a[left].compareTo(partitionelement) <= 0)
				left++;
			
			// search for an element that is < the partition element
			while (a[right].compareTo(partitionelement) > 0)
				right--;
			
			// swap the elements
			if (left < right)
				swap(a, left, right);
		}
		
		// move the partition element into place
		swap(a, min, right);
		
		return right;
    }
    
    private static <T extends Comparable<T>> void swap(T[] data, int index1, int index2)
    {
    	T temp = data[index1];
    	data[index1] = data[index2];
    	data[index2] = temp;
    }
    
    @SuppressWarnings("rawtypes")
	public static void mergesort(Comparable[] a) 
    {
        Comparable[] answer = mergesortReturn(a);
        
        for(int i = 0; i < answer.length -1; i++)
        	a[i] = answer[i];
        
    }
    
    @SuppressWarnings("rawtypes")
	public static Comparable[] mergesortReturn(Comparable[] a)
    {	
    	if(a.length == 1)
    		return a;
    	
    	int mid = a.length / 2;
    	Comparable[] b = split(a, 0, mid);
    	Comparable[] c = split(a, mid, a.length);
    	
    	b = mergesortReturn(b);
    	c = mergesortReturn(c);
    	
    	return merge(b,c);
    }
    
    @SuppressWarnings("rawtypes")
	public static Comparable[] split(Comparable[] a, int min, int max)
    {
    	int size = max - min;
	int k = 0;
    	Comparable[] d = new Comparable[size];
    	for(int i = min; i < max; i++)
	{    
    		d[k] = a[i];
		k++;
	}
    	return d;
    }
    
    @SuppressWarnings({ "unchecked", "rawtypes" })
	public static Comparable[] merge(Comparable[] a, Comparable[] b)
    {
    	Comparable[] e = new Comparable[a.length + b.length];
    	int i = 0, j = 0, k = 0;
    	
    	while(i < a.length && j < b.length)
    	{
    		if(a[i].compareTo(b[j]) < 0)
    		{
    			e[k] = a[i];
    			i++;
    		}
    		else
    		{
    			e[k] = b[j];
    			j++;
    		}
    		k++;
    	}
    	
    	while(i < a.length)
    	{
    		e[k] = a[i];
    		i++;
    		k++;
    	}
    	while(j < b.length)
    	{
    		e[k] = b[j];
    		j++;
    		k++;
    	}
    	
    	return e;
    }
    
    /**
     * Displays contents of array, space separated.
     * @author Sedgewick
     * @param a Array to display.
     */
    private static void show(Comparable[] a) 
    {
        for (Comparable a1 : a)
            System.out.print(a1 + " ");

        System.out.println();
    }
    
    /**
     * Checks if array is in sorted order.
     * @author Sedgewick
     * @param a Array to be checked.
     * @return Returns true if array is sorted.
     */
    public static boolean isSorted(Comparable[] a) 
    {
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i-1]))
                return false;
        
        return true;
    }
    
    //See previous method.
    private static boolean less(Comparable v, Comparable w) 
    {
        return v.compareTo(w) < 0;
    }
}
