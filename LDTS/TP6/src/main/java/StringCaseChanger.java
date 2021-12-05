import java.sql.Array;
import java.util.Arrays;

public class StringCaseChanger implements StringTransformer{

    private char strCaseChange[];

    public void execute(StringDrink drink) {
        strCaseChange = new char[drink.getText().length()];
        int i = 0;
        for(char c : drink.getText().toCharArray()) {
            if(Character.isLowerCase(c)){
                strCaseChange[i] = Character.toUpperCase(c);
            } else {
                strCaseChange[i] = Character.toLowerCase(c);
            }
            i++;
        }
        drink.setText(new String(strCaseChange));
    }
}
