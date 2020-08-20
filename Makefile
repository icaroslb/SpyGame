LIBS = -lSDL2 -lGL -lGLEW
FLAGS = -O3
VERSION = --std=c++11
MAIN = main
OBJ = obj/

FISICA = $(wildcard fisica/*.h)
OBJETOS = $(wildcard objetos/*.h)
PERSONAGENS = $(wildcard personagens/*.h)
MAPAS = $(wildcard mapas/*.h)

all: $(OBJ) $(MAIN)

$(OBJ):
	if test ! -d $(OBJ); then mkdir $(OBJ); fi

$(OBJ)Engine_OpenGl.o: engines/Engine_OpenGl.cpp engines/Engine_OpenGl.h
	g++ -g -c $< -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

$(OBJ)Engine_SDL.o: engines/Engine_SDL.cpp engines/Engine_SDL.h
	g++ -g -c $< -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

$(OBJ)Shader.o: shaders/Shader.cpp shaders/Shader.h
	g++ -g -c $< -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

$(OBJ)Teclado.o: io/Teclado.cpp io/Teclado.h
	g++ -g -c $< -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

$(OBJ)Leitor_imagem.o: leitor_imagem/Leitor_imagem.cpp leitor_imagem/Leitor_imagem.h
	g++ -g -c $< -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

$(MAIN): $(OBJ)Engine_OpenGl.o $(OBJ)Engine_SDL.o $(OBJ)Shader.o $(OBJ)Teclado.o $(OBJ)Leitor_imagem.o camera/Canvas.h $(OBJETOS) $(PERSONAGENS) $(MAPAS) $(FISICA) $(MAIN).cpp
	g++ $^ -o $@ $(INCLUDES) $(FLAGS) $(VERSION) $(LIBS)

clean:
	rm -r $(MAIN) $(OBJ)*.o

