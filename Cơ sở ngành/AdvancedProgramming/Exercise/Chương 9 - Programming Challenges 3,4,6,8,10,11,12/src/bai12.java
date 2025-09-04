import java.util.*;


public class bai12 {

    static long getWordCount(String word) {
        return Arrays.stream(word.split(" ")).count();
    }
    static String ArraytoString(char[] chars) {
        return String.valueOf(chars);

    }

    static char mostFrequent(String word) {
        String mostFreq = "";
        int count = 0;

        String[] array = word.split("");

        for (int i = 0; i < array.length; i++) {
            int temp = 0;

            for (int j = 0; j < array.length; j++) {
                if (array[i].equalsIgnoreCase(array[j])){
                    temp++;
                }
                if(temp > count) {
                    count = temp;
                    mostFreq = array[i];
                }
            }
        }
        return mostFreq.charAt(0);
    }

    public static String getReplaceSubstring(String str1, String str2, String str3) {
        return str1.replace(str2, str3);
    }

    public static void main(String[] args) {

        String string4 = "One hundred years ago.";
        System.out.println(getWordCount(string4));

        char[] chars = {'h', 'e', 'l', 'l', 'o'};
        System.out.println(ArraytoString(chars));

        String string5 = "Heeeeeeeyyyyyy";
        System.out.println(mostFrequent(string5));




        String string1 = "the dog jumped over the fence";
        String string2 = "the";
        String string3 = "that";

        System.out.println(getReplaceSubstring(string1, string2, string3));

    }
}
