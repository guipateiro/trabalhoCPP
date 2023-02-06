CFLAGS = -Wall #-Wshadow
CC = g++
nomePrograma = aula
files = main.o Administrador.o Chat.o Comentario.o Historico.o Id.o Imagem.o Interface.o Listadepostagens.o Post.o Texto.o Usuario.o UsuarioAdministrador.o Video.o Visitante.o

all: $(nomePrograma)

run: all
	./$(nomePrograma)

$(nomePrograma): $(files)   #ligacao final dos .o
	g++ -o $(nomePrograma) $(files) $(CFLAGS)

%.o : %.cpp %.hpp  #gera todos os .o
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *.gch *.txt

purge: clean 
	rm -f $(nomePrograma)	