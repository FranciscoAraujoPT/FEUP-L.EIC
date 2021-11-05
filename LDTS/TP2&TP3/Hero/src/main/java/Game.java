import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;

import java.io.IOException;

public class Game {

    Screen screen;
    Arena arena;
    public Game(){
        try {
            TerminalSize terminalSize = new TerminalSize(40, 20);
            DefaultTerminalFactory terminalFactory = new DefaultTerminalFactory()
                    .setInitialTerminalSize(terminalSize);
            Terminal terminal = terminalFactory.createTerminal();
            screen = new TerminalScreen(terminal);

            screen.setCursorPosition(null);   // we don't need a cursor
            screen.startScreen();             // screens must be started
            screen.doResizeIfNecessary();     // resize screen if necessary

            arena = new Arena(40, 20);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void draw(){
        try {
            screen.clear();
            arena.draw(screen.newTextGraphics());
            screen.refresh();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run(){
        KeyStroke key;
        while(true){
            try {
                key = screen.readInput();
                if(!arena.processKey(key)){
                    System.out.println("YOU DIED!");
                    screen.stopScreen();
                    break;
                }
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
            draw();
        }
    }
}
