public class Searching {
    public static<T> boolean linearSearch(T[] data, int min, int max, T targetElement)
    {
        int index = min;
        boolean found = false;
        while(!found && index<=max)
        {
            found = data[index].equals(targetElement);
            index++;
        }
        return found;
    }
    
    public static<T extends Comparable<T>> boolean binarySearch(T[] data, int min, int max, T targetElement)
    {
        boolean found = false;
        int mid = (min+max)/2;
        if (data[mid].compareTo(targetElement) == 0)
            found = true;
        else
        if (data[mid].compareTo(targetElement)>0)
        {
            if(min<mid-1)
                found = binarySearch(data, min, mid-1, targetElement);
        }
        else if (mid+1<max)
        {
            found = binarySearch(data, mid+1, max, targetElement);
        }
        return found;
    }
}
