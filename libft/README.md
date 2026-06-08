# libft

## ¿Qué es?

Reimplementación de funciones fundamentales de la biblioteca estándar de C (`libc`). Es la base de casi todos los proyectos posteriores del cursus: se compila como `libft.a` y se enlaza con otros programas.

Incluye funciones de manipulación de cadenas, memoria, conversión de tipos y listas enlazadas.

## Lo que aprendí

- Punteros, aritmética de punteros y gestión manual de memoria en C.
- Diferencia entre funciones que modifican buffers (`memcpy`, `memmove`) y las que crean nuevos (`strdup`, `substr`).
- Implementación de listas enlazadas (`t_list`) y recorrido con punteros a función.
- Organización de un proyecto C con `Makefile`, directorios `srcs/` e `includes/`.
- Norma de 42: funciones cortas, sin variables globales y código legible.

## Compilación

```bash
make        # genera libft.a
make bonus  # incluye funciones bonus de listas
make clean  # elimina objetos
```
