CC = epiclang
CFLAGS = -c -Wno-implicit-function-declaration -Wint-to-void-pointer-cast
NAME = libmy.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(NAME)
fclean: clean
	$(RM) $(NAME)

re: fclean all

build:
	$(CC) $(CFLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)
	$(RM) $(OBJS)