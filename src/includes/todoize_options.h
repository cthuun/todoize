#ifndef TODOIZE_OPTIONS_H_
#define TODOIZE_OPTIONS_H_

typedef struct s_todoize_options {
  char display_help;
} t_todoize_options;

int todoize_getopt(int argc, char** argv, t_todoize_options* todoize_options);

#endif /* !TODOIZE_OPTIONS_H_ */
