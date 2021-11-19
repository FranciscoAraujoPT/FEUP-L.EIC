package Game.Elements;

import Game.Position;

import java.util.Random;

public class Monster extends Element {
    public Monster(int cordsX, int cordsY) {
        super(cordsX, cordsY);
    }

    public Position move(Position position) {
        Random random = new Random();
        switch (random.nextInt(4)) {
            case 0 -> {
                return new Position(position.getX() + 1, position.getY());
            }
            case 1 -> {
                return new Position(position.getX() - 1, position.getY());
            }
            case 2 -> {
                return new Position(position.getX(), position.getY() + 1);
            }
            case 3 -> {
                return new Position(position.getX(), position.getY() - 1);
            }
        }

        return null;
    }
}
