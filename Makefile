CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L/usr/X11/lib -lmlx -lXext -lX11
INCLUDES = -I/usr/X11/include

SRCS = main.c
OBJS = $(SRCS:.c=.o)

TARGET = heart

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
