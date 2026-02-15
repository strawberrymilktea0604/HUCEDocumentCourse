public class Employee extends StaffMember {
    private String socialSecurityNumber;
    private double payRate;

    public Employee(String name, String address, String phoneNumber, String socialSecurityNumber, double payRate)
    {
        super(name,address,phoneNumber);
        this.socialSecurityNumber = socialSecurityNumber;
        this.payRate = payRate;
    }

    public double salary()
    {
        return 25*payRate;
    }
}
