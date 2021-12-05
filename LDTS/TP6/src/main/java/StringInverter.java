public class StringInverter implements StringTransformer{

    private final StringBuilder builder;

    public StringInverter(){
        builder = new StringBuilder();
    }

    public void execute(StringDrink drink) {
         drink.setText(builder.append(drink.getText()).reverse().toString());
    }
}
