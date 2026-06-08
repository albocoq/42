# ft_printf

## ¿Qué es?

Recreación de la función `printf` de la biblioteca estándar de C, usando funciones variádicas (`stdarg.h`). Soporta los especificadores de conversión básicos (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`).

## Lo que aprendí

- Funciones variádicas: `va_start`, `va_arg`, `va_end` y cómo recorrer argumentos de tipos variables.
- Conversión de enteros a distintas bases (decimal, hexadecimal) y manejo de números negativos.
- Impresión de punteros en formato hexadecimal con el prefijo `0x`.
- Diseño modular: una función por especificador, orquestadas desde `ft_printf`.
- Reutilización de `libft` para funciones auxiliares (`write`, `strlen`, etc.).

## Compilación

```bash
make        # genera libftprintf.a
make clean
```
