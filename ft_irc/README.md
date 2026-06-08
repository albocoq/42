# ft_irc

## ¿Qué es?

Servidor de chat IRC implementado en C++98. Los clientes se conectan por TCP, se autentican con contraseña y pueden unirse a canales, enviar mensajes privados y gestionar salas de chat siguiendo el protocolo IRC.

La arquitectura separa la capa de red (sockets no bloqueantes con `poll`), el parseador de mensajes IRC y el enrutador de comandos.

## Lo que aprendí

- Programación de red en C++: sockets, `bind`, `listen`, `accept`, `recv`, `send`.
- I/O multiplexado con `poll()` y descriptores no bloqueantes (`fcntl`, `O_NONBLOCK`).
- Parseo del protocolo IRC: prefijo, comando, parámetros y trailing (`:`).
- Patrón dispatcher con `std::map` de punteros a funciones miembro para enrutar comandos.
- Gestión de estado de clientes: buffers de lectura/escritura, handshake (`PASS`, `NICK`, `USER`).
- Modelado orientado a objetos en C++98: clases `Server`, `Client`, `Channel`, `Message`.
- Códigos numéricos de respuesta IRC (`001`, `433`, `461`, etc.) y mensajes de error estándar.

## Compilación y uso

```bash
make
./ircserv <puerto> <contraseña>
```

Conéctate con un cliente IRC (irssi, WeeChat, etc.) al puerto configurado. Comandos básicos: `PASS`, `NICK`, `USER`, `JOIN`, `PRIVMSG`, `PART`, `QUIT`.
