public class Die
{
    private int faceValue;
    private final int MAX=6;

    //Constructor
    public Die()
    {
        faceValue = 1;
    }

    //Accessor
    public int getFaceValue()
    {
        return faceValue;
    }

    //Mutator
    public void setFaceValue(int faceValue)
    {
        if(faceValue>0 && faceValue<=6)
            this.faceValue = faceValue;
    }

    //Method
    public int roll()
    {
        faceValue = (int)(Math.random()*MAX) + 1;
        return faceValue;
    }
}