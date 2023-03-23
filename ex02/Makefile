NAME = PmergeMe

CPP	= c++

CPP_FLAGS = -std=c++98

FILES = main.cpp \
		PmergeMe.cpp\

all     : $(NAME)

$(NAME) : $(FILES)
	$(CPP) $(CPP_FLAGS) $(FILES) -o $(NAME)

RM = rm -rf

clean	:
	$(RM) $(NAME)

re		: clean all