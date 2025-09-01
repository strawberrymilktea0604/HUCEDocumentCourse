/**
This class simulates rolling a pair of dice 10,000 times and
counts the number of times doubles of are rolled for each different pair of doubles.
*/
import java.util.Random; //to use the random number
//generator
public class DiceSimulation
{
public static void main(String[] args)
{
final int NUMBER = 10000; //the number of times to
//roll the dice
//a random number generator used in simulating
//rolling a dice
Random generator = new Random();
int die1Value; // number of spots on the first
// die
int die2Value; // number of spots on the second
// die
int count = 0; // number of times the dice were
// rolled
int snakeEyes = 0; // number of times snake eyes is
// rolled
int twos = 0; // number of times double
// two is rolled
int threes = 0; // number of times double three
// is rolled
int fours = 0; // number of times double four
// is rolled
int fives = 0; // number of times double five
// is rolled
int sixes = 0; // number of times double six is
// rolled
//ENTER YOUR CODE FOR THE ALGORITHM HERE

/**

* Following while loop will run until count < Number.

*/



for (; count < NUMBER; count++)
{

/**
 * To generate random number in range 1 to 6,
* I have declared two integer variables named min and max
* and initialized to 1 and 6 respectively.
*/
    
    int min=1,max=6;
    
/**
* An object of Random class named rand is created so that we can generate
* random number
*/
    
    Random rand=new Random();
    
     
    
/**
* Using following formula we get random number in range 1 to 6.
* Both variables i.e die1Value and die2Value are initialized
* with the formula given in each iteration.
*/
    die1Value = rand.nextInt((max - min) + 1) + min;
    die2Value = rand.nextInt((max - min) + 1) + min;
    
     
/**
* Now we are interested in cases where there is double i.e
* Both random generated numbers in die1Value and die2Value are same.
*/
    
    if(die1Value==die2Value){
    
/**
* Now there are 6 possibilities. They are shown in Nested IF-ELSE-IF statements.
* As both values are same, I have taken die1Value to check if it is 1,2,3,4,5 or 6.
*/
    
    
    
/**
* If die1Value is 1 then we increment snakeEyes by 1.
* Similarly for others too we do the same.
*/
    
    if(die1Value==1)
    {
    snakeEyes++;
    }
    
    else if(die1Value==2)
    {
    twos++;
    }
    
    else if(die1Value==3)
    {
    threes++;
    }
    
    else if(die1Value==4)
    {
    fours++;
    }
    
    else if(die1Value==5)
    {
    fives++;
    }
    else if(die1Value==6)
    {
    sixes++;
    }
    
    }
    
    /**
    * In each iteration we increment count by 1.
    */
    
    count++;

  

    
    }while(count<NUMBER);
    //While loop ends here.



System.out.println ("You rolled snake eyes " +
snakeEyes + " out of " + count + " rolls.");
System.out.println ("You rolled double twos " + twos +
" out of " + count + " rolls.");
System.out.println ("You rolled double threes " +
threes + " out of " + count + " rolls.");
System.out.println ("You rolled double fours " + fours
+ " out of " + count + " rolls.");
System.out.println ("You rolled double fives " + fives
+ " out of " + count + " rolls.");
System.out.println ("You rolled double sixes " + sixes
+ " out of " + count + " rolls.");
}
}