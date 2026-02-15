public class FoodItem
{
    final private int CALORIES_PER_GRAM = 9;
    private int fatGram;
    protected int servings;

    public FoodItem(int fatGram, int servings)
    {
        this.fatGram = fatGram;
        this.servings = servings;
    }

    private int calories()
    {
        return fatGram*CALORIES_PER_GRAM;
    }

    public int caloriesPerServing()
    {
        return calories()/servings;
    }
}