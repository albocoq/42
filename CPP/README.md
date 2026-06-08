# CPP Modules (00–09)

## ¿Qué es?

Conjunto de ejercicios de C++ orientado a objetos del cursus de 42. Cada módulo (`CPP_0` a `CPP_9`) introduce conceptos progresivos de C++98, con ejercicios independientes que se compilan por separado.

| Módulo | Tema principal |
|--------|----------------|
| CPP_0 | Namespaces, clases, funciones miembro, streams I/O |
| CPP_1 | Memoria, punteros, referencias, punteros a miembros |
| CPP_2 | Punto fijo (`Fixed`), sobrecarga de operadores |
| CPP_3 | Herencia, polimorfismo, interfaces abstractas (`ScavTrap`, `FragTrap`) |
| CPP_4 | Clases abstractas, interfaces (`Animal`, `Brain`, `AAnimal`) |
| CPP_5 | Excepciones, formularios (`Bureaucrat`, `Form`) |
| CPP_6 | Casting (`static_cast`, `dynamic_cast`, `reinterpret_cast`) |
| CPP_7 | Plantillas (`Array`, `iter`) |
| CPP_8 | Contenedores STL (`vector`, `list`, `deque`, `stack`, `map`) |
| CPP_9 | Algoritmos (`BitcoinExchange`, `RPN`, `PmergeMe`) |

## Lo que aprendí

- Fundamentos de C++98: clases, constructores, destructores, regla de los tres.
- Herencia simple y múltiple, clases virtuales y polimorfismo con `virtual`.
- Gestión de memoria en C++: `new`/`delete`, copia profunda, punteros inteligentes manuales.
- Excepciones (`try`/`catch`/`throw`) y diseño robusto ante errores.
- Plantillas de funciones y clases para código genérico reutilizable.
- Contenedores y algoritmos de la STL: cuándo usar cada estructura.
- Respeto de la norma C++98 (sin C++11/14/17) y compilación con `-Wall -Wextra -Werror -std=c++98`.

## Compilación

Cada ejercicio tiene su propio `Makefile` dentro de su carpeta:

```bash
cd CPP_4/ex00
make
./programa
```
