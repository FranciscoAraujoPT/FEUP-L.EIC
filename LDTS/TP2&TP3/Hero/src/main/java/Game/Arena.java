package Game;

import Game.Elements.*;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class Arena extends Thread{

    public static final int MAX_COINS = 5;
    public static final int MAX_MONSTERS = 10;
    int width;
    int height;

    Hero hero = new Hero(10, 10);
    private final List<Wall> walls = new ArrayList<>();
    private final List<Coin> coins = new ArrayList<>();
    private final List<Monster> monsters = new ArrayList<>();

    public Arena(int width, int height) {
        this.width = width;
        this.height = height;
        createWalls();
        createCoins();
        createMonster();
    }

    private void createMonster() {
        Random random = new Random();
        Monster aux;

        for (int i = 0; i < MAX_MONSTERS; i++) {
            aux = new Monster(random.nextInt(width - 2) + 1, random.nextInt(height - 2) + 1);
            if(aux.getPosition().equals(hero.getPosition()) || ElementsAreInSamePlace(aux)){
                i--;
                continue;
            }
            monsters.add(aux);
        }
    }

    private void createCoins() {
        Random random = new Random();
        Coin aux;

        for (int i = 0; i < MAX_COINS; i++) {
            aux = new Coin(random.nextInt(width - 2) + 1, random.nextInt(height - 2) + 1);
            if(aux.getPosition().equals(hero.getPosition()) || ElementsAreInSamePlace(aux)){
                i--;
                continue;
            }
            coins.add(aux);
        }
    }

    private boolean ElementsAreInSamePlace(Element auxElement) {
        for(Coin coin : coins){
            if(coin.getPosition().equals(auxElement.getPosition())) {
                return true;
            }
        }

        for(Monster monster: monsters) {
            if (monster.getPosition().equals(auxElement.getPosition())) {
                return true;
            }
        }

        return false;
    }

    private boolean verifyCoins(Position position) {
        for (Coin coin : coins) {
            if(coin.getPosition().equals(position)){
                coins.remove(coin);
                hero.setNumberOfCoins(hero.getNumberOfCoins()+1);
                if(hero.getNumberOfCoins() == MAX_COINS){
                    return true;
                }
                break;
            }
        }
        return false;
    }

    private boolean verifyWall(Position position) {
        for (Wall wall : walls) {
            if(wall.getPosition().equals(position)){
                return false;
            }
        }
        return true;
    }

    private boolean verifyMonster(Position position) {
        for (Monster monster: monsters) {
            if(monster.getPosition().equals(position)){
                return false;
            }
        }
        return true;
    }

    private void createWalls() {
        for (int c = 0; c < width; c++) {
            walls.add(new Wall(c, 0));
            walls.add(new Wall(c, height - 1));
        }

        for (int r = 1; r < height - 1; r++) {
            walls.add(new Wall(0, r));
            walls.add(new Wall(width - 1, r));
        }
    }

    public void moveMonsters() {
        Position aux;
        for (Monster monster: monsters) {
            aux = monster.move(monster.getPosition());
            if (canElementMove(aux) && verifyMonster(aux)) {
                monster.setPosition(aux);
            }
        }
    }

    private boolean moveHero(Position position) {
        if (canElementMove(position)) {
            hero.setPosition(position);
            if(verifyCoins(position)){
                return false;
            } else {
                return verifyMonster(position);
            }
        }

        return true;
    }

    private boolean canElementMove(Position position) {
        return (position.getX() < width && position.getY() < height && position.getX() >= 0 && position.getY() >= 0)
                && verifyWall(position);
    }

    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(width, height), ' ');
        for (Wall wall : walls) {
            wall.draw(graphics, "#FFFFFF", "X");
        }
        for (Coin coin : coins) {
            coin.draw(graphics, "#FFFF33", "O");
        }
        for (Monster monster : monsters) {
            monster.draw(graphics, "#F30000", "&");
        }
        hero.draw(graphics, "#000000", "??");
    }

    public boolean processKey(KeyStroke key) {
        switch (key.getKeyType()){
            case ArrowUp:
                return moveHero(hero.moveUp(hero.getPosition()));
            case ArrowDown:
                return moveHero(hero.moveDown(hero.getPosition()));
            case ArrowLeft:
                return moveHero(hero.moveLeft(hero.getPosition()));
            case ArrowRight:
                return moveHero(hero.moveRight(hero.getPosition()));
            case Character:
                if(key.getCharacter() == 'q'){
                    return false;
                }
                break;
            case EOF:
                return false;
        }

        return true;
    }
}
