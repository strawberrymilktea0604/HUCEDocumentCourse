package bai5;

public class Payroll
{
    private int employeeId, hours;
    private double payRate;
    private String name;

    public Payroll() {}

    public Payroll(String name, int employeeId, double payRate)
    {
        try
        {
            if(name == "")
            {
                throw new InvalidName();
            }

            setName(name);

            if(employeeId <= 0)
            {
                throw new InvalidID();
            }

            setEmployeeId(employeeId);

            if(payRate < 0 || payRate > 25)
            {
                throw new InValidHourlyRate();
            }

            setPayRate(payRate);
        }
        catch(InvalidName e)
        {
            System.out.println("Error: the employee's name cannot be blank");
            System.exit(1);
        }
        catch(InvalidID e)
        {
            System.out.println("Error: the employee's id must be above 0");
            System.exit(1);
        }
        catch(InValidHourlyRate e)
        {
            System.out.println("Error: the payrate must not be negative nor exceed 25");
            System.exit(1);
        }

        setEmployeeId(employeeId);
        setPayRate(payRate);
    }

    public double getGrossPay()
    {
        return payRate * hours;
    }

    public int getEmployeeId()
    {
        return employeeId;
    }

    public int getHours()
    {
        return hours;
    }

    public double getPayRate()
    {
        return payRate;
    }

    public String getName()
    {
        return name;
    }

    public void setEmployeeId(int employeeId)
    {
        try
        {
            if(employeeId <= 0)
            {
                throw new InvalidID();
            }

            this.employeeId = employeeId;
        }
        catch(InvalidID e)
        {
            System.out.println("Error: the employee's id must be above 0");
            System.exit(1);
        }
    }

    public void setHours(int hours)
    {
        try
        {
            if(hours < 0 || hours > 84)
            {
                throw new InValidHoursWorked();
            }

            this.hours = hours;
        }
        catch(InValidHoursWorked e)
        {
            System.out.println("Error: hours worked cannot be negative nor exceed 84");
            System.exit(1);
        }
    }

    public void setPayRate(double payRate)
    {
        try
        {
            if(payRate < 0 || payRate > 25)
            {
                throw new InValidHourlyRate();
            }

            this.payRate = payRate;
        }
        catch(InValidHourlyRate e)
        {
            System.err.println("Error: the payrate must not be negative nor exceed 25");
            System.exit(1);
        }
    }

    public void setName(String name)
    {
        try
        {
            if(name.isEmpty())
            {
                throw new InvalidName();
            }

            this.name = name;
        }
        catch(InvalidName e)
        {
            System.out.println("Error: the employee's name cannot be blank");
            System.exit(1);
        }
    }
}