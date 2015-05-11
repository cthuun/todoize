#ifndef TODOIZE_DISPLAY_H_
# define TODOIZE_DISPLAY_H_

# include <ncurses.h>
# include <unistd.h>
# include <todoize_error.h>

void todoize_display_init(void);
int todoize_display_pre_main(void);
int todoize_display_main(void);

#endif /* !TODOIZE_DISPLAY_H_ */
