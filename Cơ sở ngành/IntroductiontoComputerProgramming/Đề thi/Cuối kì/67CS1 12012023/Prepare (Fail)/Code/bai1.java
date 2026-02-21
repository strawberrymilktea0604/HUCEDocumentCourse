import java.util.Scanner;

public class bai1 {
    public static void main(String args[]) {
        

// tạo class
        class Employee{
        
            
            private String name;
            private String address;
            private int age;
            private int days;
            private double basicSalary;
            private double hours;
            private double salary;
            
            
            public Employee(String name, int age, int hours, String address) {
                 basicSalary = 120.000;
            }

            
            public void setName(String n)
            {
                 name = n;
            }
            
            public String getName() {
                return name;
            }

            public void setAge(int a) {
                age = a;
            }

            public int getAge() {
                return age;
            }

            public void setHours(double h) {
                hours = h;
            }

            public double getHours () {
                return hours;
            }

            public void setAddress(String b) {
                address = b;
            }

            public String getAdress() {
                return address;
            }

            public double getSalary() {
                return salary = days * 8 * basicSalary;
            }
                
            }
        }

// tạo mảng 


    }

