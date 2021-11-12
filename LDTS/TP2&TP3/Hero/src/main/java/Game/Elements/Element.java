package Game.Elements;

import Game.Position;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

public class Element {

    private Position position;

    public Element(int cordX, int cordY){
       position = new Position(cordX, cordY);
    }

    public void draw(TextGraphics graphics, String color, String character){
        graphics.setForegroundColor(TextColor.Factory.fromString(color));
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), character);
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }
}
