# cube3d

## ¿Qué es?

Motor de renderizado 3D en primera persona basado en raycasting (estilo Wolfenstein 3D). Lee un mapa desde un archivo `.cub`, dibuja las paredes con texturas y permite al jugador moverse y rotar la cámara dentro del entorno.

Usa MLX42 para la ventana gráfica y una `libft` propia para utilidades de C.

## Lo que aprendí

- Algoritmo de raycasting: lanzar rayos desde la cámara y calcular distancias a paredes.
- Trigonometría aplicada: seno, coseno y conversión ángulo ↔ dirección del rayo.
- Texturizado de paredes según la cara impactada (norte, sur, este, oeste).
- Parsing de archivos `.cub`: mapa, colores de suelo/techo y rutas de texturas.
- Validación de mapas cerrados (flood-fill) y gestión de colisiones del jugador.
- Arquitectura modular: inicialización, movimiento, raycast, liberación de memoria.

## Compilación y uso

```bash
make
./cub3d maps/ejemplo.cub
```

Controles: WASD para moverse, flechas izquierda/derecha para rotar. ESC cierra.
