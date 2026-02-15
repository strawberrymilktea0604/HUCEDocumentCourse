public abstract class StaffMember
{
    private String name;
    private String address;
    private String phoneNumber;

    public StaffMember(String name, String address, String phoneNumber)
    {
        this.name = name;
        this.address = address;
        this.phoneNumber = phoneNumber;
    }

    abstract double salary();    
}