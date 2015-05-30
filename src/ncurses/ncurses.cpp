
#include <chrono>
#include <ncurses.h>
#include <stdio.h>



void setup() {
    noecho(); // Stop Characters being displayed to the screen
    cbreak(); // Disable buffering
    nodelay(stdscr, TRUE); // Stops getch from blocking
}

//max_timer

void event_loop() {
 
    int ch = getch();
    // Key Pressed
    if (ch != ERR) {
        switch (ch) {
            case KEY_LEFT: break; //moveLeft();
            case KEY_RIGHT: break; //moveRight();
            case KEY_UP:  break;//   = rotateLeft();
            case KEY_DOWN:  break; //= rotateRight();            
        }
    }

    
}


int main() {
    //test
    return 0;
}
