public class Sorting {
    public static<T extends Comparable<T>> void selectionSort(T[] data)
    {
        int min;
        for(int index=0; index<data.length-1;index++)
        {
            min = index;
            for(int scan=index+1; scan<data.length; scan++)
                if(data[scan].compareTo(data[min])<0)
                    min=scan;
            swap(data, index, min);
        }
    }

    public static<T extends Comparable<T>> void insertionSort(T[] data)
    {
        for(int index=1; index<data.length; index++)
        {
            T key = data[index];
            int position = index;
            while(position>0 && data[position-1].compareTo(key)>0)
            {
                data[position] = data[position-1];
                position--;
            }
            data[position] = key;
        }
    }

    public static <T extends Comparable<T>> void bubbleSort(T[] data)
    {
        for(int position = data.length-1; position>0;position--)
            for(int scan = 0; scan<position; scan++)
                if(data[scan].compareTo(data[scan+1])>0)
                    swap(data, scan, scan+1);
    }

    public static<T extends Comparable<T>> void quickSort(T[] data, int min, int max)
    {
        if (min<max)
        {
            int partitionIndex = partition(data, min, max);
            quickSort(data, min, partitionIndex-1);
            quickSort(data, partitionIndex+1, max);
        }
    }

    private static<T extends Comparable<T>> int partition(T[] data, int min, int max)
    {
        int mid = (min+max)/2;
        T partitionElement = data[mid];
        int left, right;
        left = min;
        right = max;
        swap(data,min, mid);
        while(left<right)
        {
            while(left<right && data[left].compareTo(partitionElement)<=0)
                left++;
            while(data[right].compareTo(partitionElement)>0)
                right--;
            if (left<right)
                swap(data, left, right);
        }
        swap(data, min, right);
        return right;
    }

    public static<T extends Comparable<T>> void mergeSort(T[] data, int min, int max)
    {
        if (min<max)
        {
            int mid = (min+max)/2;
            mergeSort(data, min, mid);
            mergeSort(data, mid+1, max);
            merge(data,min,mid,max);
        }
    }

    @SuppressWarnings("unchecked")
    private static<T extends Comparable<T>> void merge(T[] data, int first, int mid, int last)
    {
        T[] temp = (T[])(new Comparable[data.length]);
        int first1 = first, last1 = mid;
        int first2 = mid + 1, last2 = last;
        int index = first;
        while(first1<=last1 && first2<=last2)
        {
            if(data[first1].compareTo(data[first2])<0)
            {
                temp[index] = data[first1];
                first1++;
            }
            else
            {
                temp[index] = data[first2];
                first2++;
            }
            index++;
        }

        while(first1<=last1)
        {
            temp[index] = data[first1];
            first1++;
            index++;
        }
        while(first2<=last2)
        {
            temp[index] = data[first2];
            first2++;
            index++;
        }

        for(int i=first;i<=last;i++)
        {
            data[i]=temp[i];
        }
    }   

    private static<T extends Comparable<T>> void swap(T[] data, int index1, int index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }
}
