CFLAGS = -Wall -g #-Wshadow 
CC = g++
nomePrograma = trabalho
files = Id.o Imagem.o IdInvalidoException.o Listadepostagens.o Post.o Texto.o  Video.o Data.o main.o Comentario.o Usuario.o Visitante.o Administrador.o Interface.o  UsuarioAdministrador.o
all: $(nomePrograma)

run: all
	./$(nomePrograma)

$(nomePrograma): $(files)   #ligacao final dos .o
	g++ -o $(nomePrograma) $(files) $(CFLAGS)

%.o : %.cpp %.hpp  #gera todos os .o
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *.gch *.txt

clear: clean
	clear


purge: clean 
	rm -f $(nomePrograma)