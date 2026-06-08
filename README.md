# 42 — Portfolio de proyectos

Repositorio personal con los proyectos del cursus de [42](https://www.42.fr). Cada carpeta es un proyecto independiente con su propio `README.md`, `Makefile` y código fuente.

## Estructura por módulos

| Módulo | Proyecto | Lenguaje | Descripción |
|--------|----------|----------|-------------|
| — | [Born2beRoot](Born2beRoot/) | Sysadmin | Configuración de una máquina virtual segura |
| Common | [libft](libft/) | C | Biblioteca de funciones tipo `libc` |
| Common | [ft_printf](ft_printf/) | C | Implementación de `printf` |
| Common | [get_next_line](get_next_line/) | C | Lectura línea a línea desde un descriptor |
| 1 | [philosopher](philosopher/) | C | Problema de los filósofos con hilos y mutexes |
| 2 | [push_swap](push_swap/) | C | Ordenación de pilas con operaciones limitadas |
| 2 | [pipex](pipex/) | C | Tuberías y procesos con `fork` / `exec` |
| 2 | [so_long](so_long/) | C | Juego 2D con gráficos (MLX42) |
| 2 | [cube3d](cube3d/) | C | Motor de raycasting 3D (Cub3D) |
| 3 | [minishell](minishell/) | C | Intérprete de comandos tipo Bash |
| 3 | [ft_irc](ft_irc/) | C++98 | Servidor IRC con sockets no bloqueantes |
| Bonus | [NetPractice](NetPractice/) | — | Ejercicios de subredes IP |
| CPP | [CPP](CPP/) | C++98 | Módulos 00–09 de C++ orientado a objetos |

## Convenciones del repositorio

- **README.md** en cada proyecto: qué es el proyecto y qué se aprendió.

## Compilación rápida

```bash
cd <proyecto>
make
```