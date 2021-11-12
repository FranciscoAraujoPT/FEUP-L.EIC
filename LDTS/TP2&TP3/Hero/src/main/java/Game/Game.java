package Game;

import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.gui2.*;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;

import java.io.IOException;

public class Game {

    Screen screen;
    Arena arena;
    WindowBasedTextGUI textGUI;
    Window window;
    Panel contentPanel;

    public Game() {
        try {
            TerminalSize terminalSize = new TerminalSize(40, 20);
            DefaultTerminalFactory terminalFactory = new DefaultTerminalFactory()
                    .setInitialTerminalSize(terminalSize);
            Terminal terminal = terminalFactory.createTerminal();
            screen = new TerminalScreen(terminal);

            screen.startScreen();             // screens must be started
            screen.doResizeIfNecessary();     // resize screen if necessary
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void drawRestart() {
        contentPanel = new Panel(new GridLayout(3));
        GridLayout gridLayout = (GridLayout)contentPanel.getLayoutManager();
        gridLayout.setHorizontalSpacing(3);

        Label title = new Label("Restart");
        title.setLayoutData(GridLayout.createLayoutData(GridLayout.Alignment.CENTER,
                GridLayout.Alignment.CENTER, true, true,
                3, 1));
        contentPanel.addComponent(title);

        contentPanel.addComponent(new Button("Yes", this::run));
        contentPanel.addComponent(
                new EmptySpace()
                        .setLayoutData(GridLayout.createHorizontallyFilledLayoutData(1)));
        contentPanel.addComponent(new Button("No", this::close));
    }

    public void drawMenu() {
        textGUI = new MultiWindowTextGUI(screen);
        window = new BasicWindow("Home");

        contentPanel = new Panel(new GridLayout(6));
        GridLayout gridLayout = (GridLayout)contentPanel.getLayoutManager();
        gridLayout.setHorizontalSpacing(3);

        Label title = new Label("The Game.Game");
        title.setLayoutData(GridLayout.createLayoutData(GridLayout.Alignment.CENTER,
                GridLayout.Alignment.CENTER, true, true,
                3, 1));
        contentPanel.addComponent(title);

        contentPanel.addComponent(
                new EmptySpace()
                        .setLayoutData(GridLayout.createHorizontallyFilledLayoutData(1)));

        contentPanel.addComponent(new Button("Start", this::run));

        contentPanel.addComponent(
                new EmptySpace()
                        .setLayoutData(GridLayout.createHorizontallyFilledLayoutData(1)));

        window.setComponent(contentPanel);
        textGUI.addWindowAndWait(window);
    }

    private void close() {
        try {
            screen.stopScreen();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void endWin() {
        textGUI = new MultiWindowTextGUI(screen);
        window = new BasicWindow("YOU WON!");

        drawRestart();

        window.setComponent(contentPanel);
        textGUI.addWindowAndWait(window);
    }

    private void endLost() {
        textGUI = new MultiWindowTextGUI(screen);
        window = new BasicWindow("YOU DIED!");

        drawRestart();

        window.setComponent(contentPanel);
        textGUI.addWindowAndWait(window);
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
        screen.setCursorPosition(null);   // we don't need a cursor
        arena = new Arena(40, 20);

        while(true){
            draw();
            try {
                key = screen.readInput();
                if(!arena.processKey(key)){
                    if(arena.hero.getNumberOfCoins() == 5){
                        endWin();
                    } else {
                        endLost();
                    }
                    break;
                }
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
    }
}
