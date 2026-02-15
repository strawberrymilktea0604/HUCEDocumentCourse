public class SalaryCalculation {
    public static void main(String[] args)
    {
        StaffMember staff;
        staff = new Employee("Quang", "Hanoi", "21321321", "12321312", 100000);
        System.out.println(staff.salary());
        staff = new Volunteer("Linh", "Vinh", "213213213");
        System.out.println(staff.salary());
    }
}
