#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>	// readline, 
# include <readline/history.h>	// rl_on_new_line, rl_replace_line, rl_redisplay, add_history, 
# include <stdio.h>		// printf, 
# include <stdlib.h>		// malloc, free, exit, getenv, 
# include <unistd.h>		// write, close, fork, getcwd, unlink, execve, dup, dup2, pipe, chdir, isatty, ttyname, ttyslot, 
# include <fcntl.h>		// open, 
# include <sys/wait.h>		// wait, waitpid, wait3, wait4, 
# include <signal.h>		// signal, kill, 
# include <dirent.h>		// opendir, readdir, closedir, 
# include <sys/types.h>		// 
# include <sys/stat.h>		// stat, lstat, fstat, 
# include <string.h>		// strerror, 
# include <errno.h>		// errno, 
# include <sys/ioctl.h>		// ioctl, 
# include <termios.h>		// tcsetattr, tcgetattr, 
# include <term.h>		// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

#endif
