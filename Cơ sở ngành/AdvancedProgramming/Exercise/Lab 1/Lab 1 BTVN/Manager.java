package exercise1;

class Manager extends Employee {

    public Manager() {

        department = " ";
        

    }
    public Manager(String name, String department) {
        super(name);
        Manager man2 = new Manager();
        man2.printInfor();

    }

    private String department;
    public String getDepartment() {
        return department; 
    }

    public String setDepartment(String department) {
        return this.department = department; 
    }

    public void printInfor() {


    }



}
