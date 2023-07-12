PP = g++
src = src/main.cpp	\
	  src/Algorithm/Map.cpp	\
	  src/Render/Window.cpp	\
	  src/Render/Grid.cpp	\
	  src/Render/Cell.cpp	\

NAME = map_generator
OBJ = ${src:.cpp=.o}

${NAME}:
	${PP} -I include -o ${NAME} ${src} -std=c++20 -Wall -g3 -fPIC -lSDL2 -lSDL2_ttf
	@echo '> Files compiled'

all : ${NAME}

clean :
	rm -rf ${OBJ}
	@echo '> Temporary files deleted'

fclean : clean
	rm -rf ${NAME}
	rm -rf unit_tests
	@echo '> Executable deleted'

re : fclean all

tests_run:
	@${PP} ${src} \
	tests/*.cpp -W -I include -o unit_tests \
	--coverage -lcriterion
	@./unit_tests

test:
	@clear
	@${PP} -o unit_tests ${src} -I include tests/*.cpp -W --coverage -lcriterion
	@./unit_tests
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branche

.PHONY: re fclean clean all test tests_run