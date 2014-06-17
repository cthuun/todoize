#include <ncurses.h>
#include <todoize_error.h>

static void todoize_display_help(void)
{
  clear();
  printw("Hello Help !!!");  /* Print Hello World      */
  refresh();      /* Print it on to the real screen */
  getch();
}

/**
 *
 * This is the main function of the program.
 *
 */
int todoize_display_main(void)
{
  int key_pressed;
  initscr();      /* Start curses mode      */
  noecho(); /* Do not print on screen when getch() */
  printw("Hello World !!!");  /* Print Hello World      */
  refresh();      /* Print it on to the real screen */
  while (((key_pressed = getch()) != 'q'))      /* Wait for user input */
  {
    switch (key_pressed) {
      case 'h':
      case '?':
        todoize_display_help();
        clear();
        printw("Hello World !!!");  /* Print Hello World      */
        refresh();      /* Print it on to the real screen */
        break;
      default:
        break;
    }
  }
  endwin();     /* End curses mode      */
  return TODOIZE_ERROR_NONE;
}
