import java.util.ArrayList;

/**
 * DemoArrayListStudent
 */
public class DemoArrayListStudent {

    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();

        Student student1 = new Student("A", 18);
        students.add(student1);

        int findIndex = -1;
        for (int i = 0; i < students.size(); i++) {
            if (students.get(i).getName().equals("A")) {
                findIndex = i;
                break;
            }
        }

        if (findIndex != -1) {
            students.remove(findIndex);
        }
    }
}