import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

public class Wall {

    private final int x;
    private final int y;

    public Wall(int cordsX, int cordsY) {
        this.x = cordsX;
        this.y = cordsY;
    }

    public void draw(TextGraphics graphics) {
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFFFFF"));
        graphics.putString(new TerminalPosition(x, y), "X");
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
