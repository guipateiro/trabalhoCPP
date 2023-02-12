CFLAGS = -Wall -g #-Wshadow 
CC = g++
nomePrograma = aula
files = Id.o Imagem.o  Listadepostagens.o Post.o Texto.o  Video.o Tag.o Data.o main.o Comentario.o Usuario.o Visitante.o Administrador.o Historico.o Interface.o  UsuarioAdministrador.o 
#Chat.o
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