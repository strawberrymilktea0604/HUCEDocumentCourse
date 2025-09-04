package Task1;

public class Time {
    
    private int hours;
    private int minutes;
    private boolean afternoon;
    
    public Time(String militaryTime) {
        if (militaryTime == null) {
            System.out.println("You must enter a valid military time.");
        }
        //Check to make sure there are 5 characters
        else if (militaryTime.length() != 5 /*CONDITION TO CHECK LENGTH OF STRING*/) { //18:45
            System.out.println(militaryTime + " is not a valid military time." );
        }
    else {
        //Check to make sure the colon is in
        //the correct spot
        if (militaryTime.charAt(2) != ':'/*CONDITION TO CHECK COLON POSITION*/) { //18:45
            System.out.println(militaryTime + " is not a valid military time." );
        }
        //Check to make sure all other characters are
        //digits
        else if (!Character.isDigit(militaryTime.charAt(0))/*CONDITION TO CHECK FOR DIGIT*/) { //kiem tra ki tu thu1 
            System.out.println(militaryTime + " is not a valid military time.");
        }
        else if (!Character.isDigit(militaryTime.charAt(1))/*CONDITION TO CHECK FOR DIGIT*/) {  //18:45
            System.out.println(militaryTime + " is not a valid military time.");
        }
        else if (!Character.isDigit(militaryTime.charAt(3))/*CONDITION TO CHECK FOR DIGIT*/){
            System.out.println(militaryTime + " is not a valid military time." );
        }
        else if (!Character.isDigit(militaryTime.charAt(4))/*CONDITION TO CHECK FOR DIGIT*/) {
            System.out.println(militaryTime + " is not a valid military time." );
        }
        else {
            //SEPARATE THE STRING INTO THE HOURS
            //AND THE MINUTES, CONVERTING THEM TO
            //INTEGERS AND STORING INTO THE
            //INSTANCE VARIABLES
            //validate hours and minutes are valid
            //values

            String[] tokenHours = militaryTime.split(":");  //tach chuoi thanh token
            hours = Integer.parseInt(tokenHours[0]); //chuyen string sang int
            minutes = Integer.parseInt(tokenHours[1]);


            if(hours > 23) {
                System.out.println(militaryTime + " is not a valid military" + " time." );
            }
            else if(minutes > 59) {
                System.out.println(militaryTime + " is not a valid military" + " time." );
            }
            //convert military time to conventional
            //time for afternoon times
            else if (hours > 12) {
                hours = hours - 12;
                afternoon = true;
                System.out.println(this.toString());
            }
            //account for midnight
            else if (hours == 0) {
                hours = 12;
                System.out.println(this.toString());
            }
            //account for noon
            else if (hours == 12) {
                afternoon = true;
                System.out.println(this.toString());
            }
            //morning times don’t need converting
            else {
                System.out.println(this.toString());
            }
        }
    }
    }
    /**toString method returns a conventional time
    @return a conventional time with am or pm*/
    
    public String toString() {
        String am_pm;
        String zero = "";
        if (afternoon)
            am_pm = "PM";
        else
            am_pm = "AM";
            if (minutes < 10)
                zero = "0";
        return hours + ":" + zero + minutes + " " + am_pm;
    }
}