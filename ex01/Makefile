SRC_DIR := srcs
OBJ_DIR := srcs

LIB := libft.a

SOURCES := ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC := $(SOURCES:%=$(SRC_DIR)/%)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iincludes
CFLAGS   := -Wall -Wextra -Werror
LDFLAGS  :=
LDLIBS   :=

.PHONY: all clean fclean re

all: $(LIB)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(LIB)

re: fclean all

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) -p $@
