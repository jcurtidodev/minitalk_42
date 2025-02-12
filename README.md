# 📡 Minitalk
## 📌 Descripción
**Minitalk** es un proyecto que implementa un sistema de comunicación entre un servidor y un cliente utilizando únicamente **señales UNIX** (`SIGUSR1` y `SIGUSR2`).

El servidor se encarga de recibir y mostrar mensajes enviados por el cliente, quien transmite una cadena de caracteres a través de señales.

## 🎯 Funcionalidades

✅ El servidor muestra su **PID** al iniciarse.

✅ El cliente envía una **cadena de texto** al servidor.

✅ El servidor muestra el mensaje recibido **rápidamente**.

✅ Se pueden recibir **mensajes consecutivos** sin necesidad de reiniciar el servidor.

✅ Implementado solo con **señales UNIX** (`SIGUSR1` y `SIGUSR2`).

✅ Manejo de errores y **prevención de leaks de memoria**.


## 📦 Requisitos
- **libft**: Este proyecto utiliza la biblioteca `libft` para funciones estándar de C.


## 🖥️ Compilación e Instalación
⚠️ **IMPORTANTE** ⚠️
Una vez clones `Minitalk`, debes clonar `libft` dentro del repositorio para que funcione.  


📂 minitalk/
```
git clone https://github.com/jcurtidodev/libft-42.git
```
Una vez hecho, continua haciendo:
```
make
```

Esto generará los ejecutables `client` y `server`.

Para limpiar archivos objeto y binarios:

```Makefile
make clean      # Elimina archivos objeto
make fclean     # Elimina archivos objeto y ejecutables
make re         # Realiza una recompilación completa
```

## 🚀 Uso

### 1️⃣ Iniciar el servidor

Ejecuta:
```C
./server
```
Esto mostrará el **PID** del servidor, necesario para que el cliente pueda enviar mensajes.

### 2️⃣ Enviar un mensaje desde el cliente
```C
./client <PID_DEL_SERVIDOR> "Mensaje a enviar"
```
Ejemplo:
```C
./client 12345 "Hola, mundo!"
```
Esto enviará la cadena _"Hola, mundo!"_ al servidor, que la mostrará en la salida estándar.  
Te animo a probar distintos inputs, como por ejemplo:
```C
./client <PID_DEL_SERVIDOR> "$(man malloc)"
```
## 🏗️ Estructura del Código
```Makefile
📂 minitalk/
├── 📜 Makefile       # Compilación del proyecto
├── 📜 server.c       # Código del servidor
├── 📜 client.c       # Código del cliente
├── 📜 minitalk.h     # Archivo de cabecera
├── 📂 libft/         # Biblioteca auxiliar
└── 📜 README.md      # Este documento
```
## 🛠️ Funciones Permitidas

El proyecto solo permite el uso de las siguientes funciones:

- `write`.

- `ft_printf` o cualquier funcion de **libft**.

- `signal`, `sigemptyset`, `sigaddset`, `sigaction`.

- `kill`, `getpid`.

- `malloc`, `free`.

- `pause`, `sleep`, `usleep`, `exit`.

## 🏆 Reglas y Restricciones

⚠️ **El programa debe cumplir:**

- No debe hacer **relink** en el `Makefile`.

- Manejo adecuado de errores y excepciones.

- **Cero leaks de memoria**.

- Solo se permite **una variable global por ejecutable**.

## 🤝 Créditos

Proyecto desarrollado por `jcurtidodev` como parte del cursus de **42 School**.
