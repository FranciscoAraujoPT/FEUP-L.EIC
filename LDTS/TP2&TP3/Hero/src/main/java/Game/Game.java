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

    boolean flag = false;
    Screen screen;
    Arena arena;
    WindowBasedTextGUI textGUI;
    Window window;
    Panel contentPanel;
    Thread monstersThread, timeThread;

    Thread heroThread = new Thread(() -> {
        KeyStroke key;
        while(true){
            try {
                key = screen.readInput();
                System.out.println(key);
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
    });

    public Game() {
        try {
            TerminalSize terminalSize = new TerminalSize(40, 20);
            DefaultTerminalFactory terminalFactory = new DefaultTerminalFactory()
                    .setInitialTerminalSize(terminalSize);
            Terminal terminal = terminalFactory.createTerminal();
            screen = new TerminalScreen(terminal);

            screen.startScreen();
            screen.doResizeIfNecessary();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void stopAllThreads(){
        flag = false;
        if(monstersThread != null) {
            while (monstersThread.isAlive() || timeThread.isAlive());
        }
    }

    private void startAllThreads() {
        flag = true;
        monstersThread.start();
        timeThread.start();
    }

    private void drawRestart() {
        textGUI = new MultiWindowTextGUI(screen);

        contentPanel = new Panel(new GridLayout(3));
        GridLayout gridLayout = (GridLayout)contentPanel.getLayoutManager();
        gridLayout.setHorizontalSpacing(3);

        Label title = new Label("Restart");
        title.setLayoutData(GridLayout.createLayoutData(GridLayout.Alignment.CENTER,
                GridLayout.Alignment.CENTER, true, true,
                3, 1));
        contentPanel.addComponent(title);

        contentPanel.addComponent(new Button("Yes", this::runGame));
        contentPanel.addComponent(
                new EmptySpace()
                        .setLayoutData(GridLayout.createHorizontallyFilledLayoutData(1)));
        contentPanel.addComponent(new Button("No", this::close));
        window.setComponent(contentPanel);
        textGUI.addWindowAndWait(window);
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

        contentPanel.addComponent(new Button("Start", this::startGame));

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
        stopAllThreads();
        window = new BasicWindow("YOU WON!");
        drawRestart();
    }

    private void endLost() {
        stopAllThreads();
        window = new BasicWindow("YOU DIED!");
        drawRestart();
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

    private void startGame() {
        heroThread.start();
        runGame();
    }

    private void runGame(){
        arena = new Arena(40, 20);
        stopAllThreads();

        monstersThread = new Thread(() -> {
            while(flag){
                arena.moveMonsters();
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        timeThread = new Thread(() -> {
            while(flag) {
                screen.setCursorPosition(null);
                draw();
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        startAllThreads();
    }
}
