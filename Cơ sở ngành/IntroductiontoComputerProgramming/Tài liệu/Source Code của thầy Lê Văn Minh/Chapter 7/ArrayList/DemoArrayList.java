import java.util.ArrayList;

/**
 * DemoArrayList
 */
public class DemoArrayList {

    public static void main(String[] args) {
        ArrayList<String> nameList = new ArrayList<String>();
        nameList.add("A");
        nameList.add("B");
        nameList.add("A");

        nameList.remove(nameList.indexOf("A"));
        nameList.remove(nameList.lastIndexOf("A"));

        for (String string : nameList) {
            System.out.println(string);
        }

        for (int i = 0; i < nameList.size(); i++) {
            System.out.println(nameList.get(i)); //khác so với mảng []
        }
    }
}