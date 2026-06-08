# get_next_line

## ¿Qué es?

Función que lee una línea completa desde un descriptor de archivo (`fd`), devolviendo el texto hasta el salto de línea (`\n`) incluido. Diseñada para funcionar en bucle con archivos de cualquier tamaño, leyendo en trozos con un buffer estático.

## Lo que aprendí

- Lectura por trozos con `read()` y gestión de un buffer estático entre llamadas.
- Concatenación eficiente de cadenas sin fugas de memoria.
- Manejo de casos límite: fin de archivo, líneas sin `\n`, múltiples llamadas consecutivas.
- Uso de `BUFFER_SIZE` como macro de compilación para ajustar el rendimiento.
- Separación en módulos: lógica principal (`get_next_line.c`) y utilidades (`get_next_line_utils.c`).

## Compilación

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c
```
