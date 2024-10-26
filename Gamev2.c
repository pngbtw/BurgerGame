/* GameV2.c */
/* Made By pngbtw */
/* Changelog: 
 * added Colors to text
 * added random spawn to burger
 * added game ends when player touches the burger
*/

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int key = 0, y = 15, x = 15;
    int max_y, max_x;
    srand(time(0));
    int randomnumy = (rand() % (54-9+1)) + 9; // Screen Y size max is 54 so here max random num is 54 min 9
    int randomnumx = (rand() % (229-9+1)) + 9; // Screen X size max is 229 so here max random num is 229 and min 9
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW); // We set a color here
    init_pair(2, COLOR_BLACK, COLOR_RED); // Here we set a color too

    initscr();
    keypad(stdscr, TRUE); // Need this to use arrows on the keyboard
    noecho();
    curs_set(0);
    getmaxyx(stdscr, max_y, max_x); // We get the max screen size of the terminal

    move(randomnumy, randomnumx);
    attron(COLOR_PAIR(1));// Here we set the text to printed with the pair 1 that we set so it will be a yellow text (Doesnt work on all terminals only on the one that support colors)
    printw("BURGER");
    attroff(COLOR_PAIR(1)); // Remove Color
    refresh();

    while (key != 'q') // When user presses q it will stop the game
    {
        move(0, 0);
        printw("Get Gambash To The Burger Or Exit by Pressing Q");

        key = getch(); // Gets the button that is being pressed

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
        attron(COLOR_PAIR(2));
        printw("Gambash");
        attroff(COLOR_PAIR(2));
        refresh();
        if (x == randomnumx && y == randomnumy)
        {
         endwin();
         printf("Gambash Got The Burger\n");
         printf("Thanks For Playing My First Game <3\n");
         return 0;
        }
    }

    endwin();
    return 0;
}

