NAME	:= fdf
CC 		:= cc
CFLAGS	:= -g3 -ofast
LIBMLX	:= ./MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= ./libft/libft.a
SRCS	:= main.c \
			create_a_line.c \
			parsing_map.c \
			draw.c \
			line_utils.c \
			utils.c \
			change_angle.c
			
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

 %.o: %.c
	 @$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft


re: clean all

.PHONY: all, clean, fclean, re, libmlx