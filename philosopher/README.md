# philosopher

## ¿Qué es?

Simulación del problema clásico de los filósofos comensales. Varios filósofos se sientan alrededor de una mesa con tenedores limitados: cada uno debe comer, dormir y pensar sin morir de hambre ni provocar un deadlock.

El programa crea un hilo (`pthread`) por filósofo y usa mutexes para proteger los tenedores y el acceso a datos compartidos.

## Lo que aprendí

- Programación concurrente con POSIX threads (`pthread_create`, `pthread_join`).
- Mutexes para evitar condiciones de carrera al acceder a recursos compartidos.
- Detección de muerte por inanición con un hilo monitor que vigila los tiempos.
- Sincronización temporal con `gettimeofday` y gestión de microsegundos.
- Diseño de estructuras de datos para modelar filósofos, tenedores y configuración global.

## Compilación y uso

```bash
make
./philo 5 800 200 200
```

Parámetros: `número_de_filósofos`, `tiempo_para_morir`, `tiempo_para_comer`, `tiempo_para_dormir`, `[veces_que_deben_comer]` (opcional).
