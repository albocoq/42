# 42 — Project Portfolio

Personal repository containing my projects from the 42 curriculum. Each folder is an independent project with its own `README.md`, `Makefile`, and source code.

## 🌟 Featured Projects

*   **[minishell](./minishell)** (C): A lightweight Bash-like command interpreter. **Focus:** Process creation (`fork`, `execve`), file descriptors, pipes, and signal handling.
*   **[cube3d](./cube3d)** (C): A 3D raycasting engine inspired by Wolfenstein 3D. **Focus:** Raycasting math, graphics rendering with MLX42, and event handling.
*   **[ft_irc](./ft_irc)** (C++98): An IRC server using non-blocking sockets. **Focus:** Object-Oriented Programming (OOP), network programming, and multiplexing (`poll`/`select`).

---

## 📂 Curriculum Structure

| Module | Project | Language | Description |
| :--- | :--- | :--- | :--- |
| — | [Born2beRoot](./Born2beRoot) | Sysadmin | Secure virtual machine configuration |
| Common | [libft](./libft) | C | Custom `libc` functions library |
| Common | [ft_printf](./ft_printf) | C | Implementation of `printf` |
| Common | [get_next_line](./get_next_line) | C | Line-by-line file reading from a file descriptor |
| 1 | [philosopher](./philosopher) | C | Dining philosophers problem (threads & mutexes) |
| 2 | [push_swap](./push_swap) | C | Stack sorting algorithm with limited operations |
| 2 | [pipex](./pipex) | C | Pipes and process management (`fork` / `exec`) |
| 2 | [so_long](./so_long) | C | 2D graphic game (MLX42) |
| 2 | [cube3d](./cube3d) | C | 3D Raycasting engine (Cub3D) |
| 3 | [minishell](./minishell) | C | Bash-like command interpreter |
| 3 | [ft_irc](./ft_irc) | C++98 | IRC server with non-blocking sockets |
| Bonus | [NetPractice](./NetPractice) | — | IP subnetting exercises |
| CPP | [CPP](./CPP) | C++98 | Object-Oriented C++ modules 00-09 |

## 🛠️ Repository Conventions

*   **README.md** in each project: explains what the project is and the core concepts learned.

## 🚀 Quick Compilation

```bash
cd <project_folder>
make
