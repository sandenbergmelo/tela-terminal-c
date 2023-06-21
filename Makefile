################################
########### Makefile ##########
################################

# Make file baseada no que é ensinado neste tutorial:
# https://embarcados.com.br/introducao-ao-makefile/

# Nome do projeto
PROJ_NAME=crud-janela

# Arquivos .c
C_SOURCE=$(wildcard ./src/*.c) main.c

# Arquivos .h
H_SOURCE=$(wildcard ./src/*.h)

# Arquivos objeto
OBJ=$(patsubst ./src/%.c,./build/%.o,$(C_SOURCE))

# Compilador e linker
# Verifica se o clang está instalado, se não, use o gcc
ifeq ($(shell which clang),)
		CC=gcc
else
		CC=clang
endif

# Flags para o compilador
CC_FLAGS=-c         \
         -W         \
         -Wall      \

# Comando usado para o target clean
RM = rm -rf

#
# Compilação e linking
#
all: folders $(PROJ_NAME)

# Cria o binário
$(PROJ_NAME): $(OBJ)
	@ echo 'Construindo o binário com o linker $(CC): $@'
	$(CC) $^ -o ./bin/$@
	@ echo 'Binário construído: $@'
	@ echo ' '

# Cria os arquivos objeto
./build/%.o: ./src/%.c ./src/%.h
	@ echo 'Construindo o target com o compilador $(CC): $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

# Cria as pastas build e bin
folders:
	@ if [ ! -d "./build" ]; then mkdir build; fi
	@ if [ ! -d "./bin" ]; then mkdir bin; fi

# Limpa os arquivos objeto
clean:
	@ $(RM) ./build/*.o $(PROJ_NAME) *~
	@ rmdir build

# Limpa os arquivos objeto e o binário
reset:
	@ $(RM) ./build/*.o $(PROJ_NAME) *~
	@ $(RM) build
	@ $(RM) bin

run:
	@ ./bin/$(PROJ_NAME)

.PHONY: all clean
