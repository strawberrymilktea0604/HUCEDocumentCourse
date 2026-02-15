public class Volunteer extends StaffMember {

    public Volunteer(String name, String address, String phoneNumber)
    {
        super(name, address, phoneNumber);
    }

    public double salary()
    {
        return 1000000;
    }
}
