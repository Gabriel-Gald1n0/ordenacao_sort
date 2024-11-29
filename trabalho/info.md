## Rodar o Programa

1. Utilize o MINGW64
2. Va até o local onde está o arquivo.
3. Digite `make` para copilar
4. Digite `make run` para executar

## 1° interação resultados - utilizando o clock()

### Com 1 repetição
Tamanho do Array: 100
Quick Sort: 0.000000 segundos
Bubble Sort: 0.000000 segundos
Shell Sort: 0.000000 segundos
Heap Sort: 0.000000 segundos

Tamanho do Array: 1000
Quick Sort: 0.000000 segundos
Bubble Sort: 0.002000 segundos
Shell Sort: 0.000000 segundos
Heap Sort: 0.000000 segundos

Tamanho do Array: 10000
Quick Sort: 0.001000 segundos
Bubble Sort: 0.131000 segundos
Shell Sort: 0.002000 segundos
Heap Sort: 0.002000 segundos

### Com 10 repetições
Quick Sort: 0.000000 segundos
Bubble Sort: 0.000000 segundos
Shell Sort: 0.000000 segundos
Heap Sort: 0.000000 segundos

Tamanho do Array: 1000
Quick Sort: 0.001400 segundos
Bubble Sort: 0.001000 segundos
Shell Sort: 0.000000 segundos
Heap Sort: 0.000100 segundos

Tamanho do Array: 10000
Quick Sort: 0.089400 segundos
Bubble Sort: 0.094900 segundos
Shell Sort: 0.000500 segundos
Heap Sort: 0.001100 segundos

### Com 100 repetições
Tamanho do Array: 100
Quick Sort: 0.000030 segundos
Bubble Sort: 0.000020 segundos
Shell Sort: 0.000000 segundos
Heap Sort: 0.000020 segundos

Tamanho do Array: 1000
Quick Sort: 0.001580 segundos
Bubble Sort: 0.000880 segundos
Shell Sort: 0.000020 segundos
Heap Sort: 0.000070 segundos

Tamanho do Array: 10000
Quick Sort: 0.098030 segundos
Bubble Sort: 0.087270 segundos
Shell Sort: 0.000310 segundos
Heap Sort: 0.001000 segundos

---

### 2° Interação resultados - utilizando o QueryPerformanceCounter() e QueryPerformanceFrequency() do windows
Utilizei o QueryPerformanceCounter() e QueryPerformanceFrequency() pois oferece uma resolução mais alta do que clock()
Obs: caso use linuxs use o `clock_gettime()` tambem serve

### Com apenas 1 repetição
Tamanho do Array: 100
Quick Sort: 0.000005 segundos
Bubble Sort: 0.000028 segundos
Shell Sort: 0.000006 segundos
Heap Sort: 0.000008 segundos

Tamanho do Array: 1000
Quick Sort: 0.000069 segundos
Bubble Sort: 0.001435 segundos
Shell Sort: 0.000103 segundos
Heap Sort: 0.000104 segundos

Tamanho do Array: 10000
Quick Sort: 0.000883 segundos
Bubble Sort: 0.138401 segundos
Shell Sort: 0.001462 segundos
Heap Sort: 0.001308 segundos
