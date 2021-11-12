package Game.Elements;

import Game.Position;
import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.graphics.TextGraphics;

public class Hero extends Element {

    private int numberOfCoins = 0;

    public Hero(int cordX, int cordY) {
        super(cordX, cordY);
    }

    @Override
    public void draw(TextGraphics graphics, String color, String character){
        super.draw(graphics, color, character);
        graphics.enableModifiers(SGR.BOLD);
    }

    public Position moveUp(Position position){
        return new Position(position.getX(), position.getY() - 1);
    }

    public Position moveDown(Position position){
        return new Position(position.getX(), position.getY() + 1);
    }

    public Position moveLeft(Position position){
        return new Position(position.getX() - 1, position.getY());
    }

    public Position moveRight(Position position){
        return new Position(position.getX() + 1, position.getY());
    }

    public int getNumberOfCoins() {
        return numberOfCoins;
    }

    public void setNumberOfCoins(int numberOfCoins) {
        this.numberOfCoins = numberOfCoins;
    }
}
