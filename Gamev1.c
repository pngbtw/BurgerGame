/* GameV1.c */
/* Made By pngbtw */
/* Todo: Make when player touches the object the game ends */

#include <ncurses.h>

int main()
{
    int key = 0, y = 15, x = 15;
    int max_y, max_x;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, max_y, max_x);

    move(25, 25);
    printw("BURGER");
    refresh();

    while (key != 'q')
    {
        move(0, 0);
        printw("Get Gambash To The Burger Or Exit by Pressing Q");

        key = getch();

        move(y, x);
        printw("       ");
        

        if (key == KEY_LEFT) {
            if (x > 0) {
                x--;
            }
        } else if (key == KEY_RIGHT) {
            if (x < max_x - 1) {
                x++;
            }
        } else if (key == KEY_UP) {
            if (y > 0) {
                y--;
            }
        } else if (key == KEY_DOWN) {
            if (y < max_y - 1) {
                y++;
            }
        }

        move(y, x);
        printw("Gambash");
        refresh();

        s
    }

    endwin();
    return 0;
}

