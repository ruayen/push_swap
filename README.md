# 🧠 push_swap

Ordenar una pila usando un conjunto limitado de operaciones.

## 📌 Descripción

`push_swap` es un programa encargado de ordenar una lista de enteros utilizando dos pilas (`a` y `b`) y un conjunto reducido de operaciones. El objetivo es lograr la menor cantidad de movimientos posibles respetando las restricciones impuestas.

Este proyecto desarrolla habilidades en:

- Manipulación de listas enlazadas
- Algoritmos de ordenación
- Optimización
- Análisis de complejidad
- Gestión de memoria

## 🛠️ Funcionalidades

- Validación completa de argumentos (duplicados, caracteres inválidos, rangos, etc.)
- Manejo de errores con mensajes claros
- Optimización para diferentes tamaños de input:
  - `sort_three`: para 3 elementos
  - `sort_five`: para 5 elementos
  - `chunk_sort`: para 100 y 500 números (usando chunks e índices)
- Sin fugas de memoria (`Valgrind` OK)
- Número de movimientos:
  - 🔥 Menos de **700** para 100 números
  - 🔥 Menos de **5500** para 500 números

## 📘 Lista de instrucciones

Estas son las únicas operaciones permitidas para mover elementos entre las pilas `a` y `b`:

### 🔁 Swaps

- `sa` : intercambia los dos primeros elementos de la pila `a`.
- `sb` : intercambia los dos primeros elementos de la pila `b`.
- `ss` : `sa` y `sb` al mismo tiempo.

### 📤 Pushes

- `pa` : mueve el primer elemento de `b` al inicio de `a`.
- `pb` : mueve el primer elemento de `a` al inicio de `b`.

### 🔄 Rotaciones

- `ra` : rota `a` una posición hacia arriba (el primer elemento pasa al final).
- `rb` : rota `b` una posición hacia arriba.
- `rr` : `ra` y `rb` al mismo tiempo.

### 🔃 Rotaciones inversas

- `rra` : rota `a` una posición hacia abajo (el último elemento pasa al inicio).
- `rrb` : rota `b` una posición hacia abajo.
- `rrr` : `rra` y `rrb` al mismo tiempo.

## 📂 Estructura

```bash
.
├── Makefile
├── push_swap.c
├── push_swap.h
├── operations1.c
├── operations2.c
├── operations3.c
├── sort_small.c
├── sort.c
├── utils.c
├── utils2.c
├── validation.c
└── README.md
