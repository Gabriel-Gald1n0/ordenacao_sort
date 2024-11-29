# Utilizar no MinGW64
# Compilador e flags
CC := gcc
CFLAGS := -Wall -std=c99 -pedantic -O3
OUT_DIR := build
SRC_DIR := src
INC_DIR := include

# Alvo padrão
all: $(OUT_DIR)\Main.exe 

# Compilar Main.exe
$(OUT_DIR)\Main.exe: $(SRC_DIR)\Main.c $(OUT_DIR)\Biblioteca.o | $(OUT_DIR)
	$(CC) -o $@ $(SRC_DIR)\Main.c $(OUT_DIR)\Biblioteca.o $(CFLAGS) -I$(INC_DIR)

# Compilar Biblioteca.o
$(OUT_DIR)\Biblioteca.o: $(SRC_DIR)\Biblioteca.c | $(OUT_DIR)
	$(CC) -c $(SRC_DIR)\Biblioteca.c -o $@ -I$(INC_DIR)

# Criar diretório de saída
$(OUT_DIR):
	@if not exist $(OUT_DIR) mkdir $(OUT_DIR)

# Executar Main
run: $(OUT_DIR)\Main.exe
	$(OUT_DIR)\Main.exe

# Limpar arquivos gerados
clean:
	@if exist $(OUT_DIR) del /Q $(OUT_DIR)\*.o $(OUT_DIR)\*.exe
