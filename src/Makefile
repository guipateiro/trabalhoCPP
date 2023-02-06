CFLAGS = -Wall #-Wshadow
CC = g++
nomePrograma = aula
files =   Comentario.o  Id.o Imagem.o  Listadepostagens.o Post.o Texto.o  Video.o Tag.o Usuario.o Visitante.o Data.o main.o
# Administrador.o Historico.o Interface.o  Usuarioadministrador.o Chat.o
all: $(nomePrograma)

run: all
	./$(nomePrograma)

$(nomePrograma): $(files)   #ligacao final dos .o
	g++ -o $(nomePrograma) $(files) $(CFLAGS)

Permissao.o: Permissao.hpp
	g++ -c $< -o $@

%.o : %.cpp %.hpp  #gera todos os .o
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *.gch *.txt

clear: clean
	clear


purge: clean 
	rm -f $(nomePrograma)