package exercise1;

interface EmployeeInterface {
    public int basis_salary = 138000;
    public double getSalary();
}

public abstract class Employee implements EmployeeInterface {
    private String name;
    private double salary_rate;
    public double getSalary() {
        return basis_salary * salary_rate; 
    }


    //khong doi so
    public Employee() {
        name = " ";


    }

    //co doi so
    public Employee(String n) {
        this.name = n;
    }

    public String getName() {
        return name;
    }

    public void setName(String n) {
        this.name = n; 
    }

    public void printInfor() {
        System.out.println(getName()); 
    }

    //abstract public void printInfor();
    //Employee e = Employee();





}


