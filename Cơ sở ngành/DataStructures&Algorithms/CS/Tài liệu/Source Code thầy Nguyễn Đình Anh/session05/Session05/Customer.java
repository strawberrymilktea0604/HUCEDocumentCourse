public class Customer implements Comparable<Customer>
{
    private String name;
    private int age;

    public Customer(String name, int age) 
    {
        this.name = name;
        this.age = age;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getAge()
    {
        return age;
    }

    public void setAge(int age)
    {
        this.age = age;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || obj.getClass() != this.getClass())
            return false;
        
        Customer anotherCustomer = (Customer) obj;
        return (this.name.equals(anotherCustomer.name) && this.age == anotherCustomer.age);
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }

    @Override
    public int compareTo(Customer o) {
        int nameComparision = this.name.compareTo(o.name);
        if (nameComparision == 0)
        {
            return Integer.compare(this.age, o.age);
        }
        return nameComparision;
    }

    @Override
    public String toString() {
        String result = "";
        result += this.name + " " + this.age;
        return result;
    }
}