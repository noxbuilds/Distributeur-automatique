NAME = distributeur
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = main.c ft_rendre_monnaie.c
OBJECTS = $(SOURCES:.c=.o)

ifeq ($(OS),Windows_NT)
EXE = $(NAME).exe
RM = cmd /C del /Q
else
EXE = $(NAME)
RM = rm -f
endif

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

%.o: %.c distributeur.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-$(RM) $(OBJECTS)

fclean: clean
	-$(RM) $(EXE)

re: fclean all

.PHONY: all clean fclean re
