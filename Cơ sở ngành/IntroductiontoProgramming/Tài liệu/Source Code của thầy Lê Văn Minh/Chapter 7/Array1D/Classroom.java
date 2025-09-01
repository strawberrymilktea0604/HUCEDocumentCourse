public class Classroom {
    public static void main(String[] args) {
        Student student1 = new Student("A", 18);

        Student student2 = student1;
        student2.setAge(0);

        System.out.println(student1.getAge());
    }
}
