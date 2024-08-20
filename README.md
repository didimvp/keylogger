# Keylogger

Este proyecto contiene un keylogger simple escrito en C para sistemas basados en Linux. El keylogger captura y registra las teclas presionadas por el usuario y guarda esta información en un archivo de registro. El programa está diseñado para funcionar con dispositivos de entrada que utilizan eventos del sistema de entrada de Linux (`/dev/input`).

## Requisitos

- **Sistema Operativo**: Linux
- **Bibliotecas**: `linux/input.h`
- **Compilador**: GCC (GNU Compiler Collection)

## Instalación

### 1. Preparación del Entorno

Asegúrate de tener instalado GCC en tu sistema. Puedes instalarlo usando el siguiente comando:

```bash
sudo apt update
sudo apt install gcc

gcc keylogger.c -o keylogger

2. Descargar el Código
Descarga el archivo keylogger.c y colócalo en un directorio de tu elección. Si estás usando un repositorio, clónalo con:

bash
Copiar código
git clone <https://github.com/didimvp/keylogger>
cd <Keylogger>
3. Compilar el Programa
Navega al directorio que contiene el archivo keylogger.c y ejecuta el siguiente comando para compilar el programa:

bash
Copiar código
gcc keylogger.c -o keylogger
Este comando compilará el archivo keylogger.c y generará un archivo ejecutable llamado keylogger en el mismo directorio.

Uso
Para ejecutar el keylogger, utiliza el siguiente comando en la terminal:

bash
Copiar código
sudo ./keylogger
Nota: Se requieren permisos de superusuario (sudo) para acceder a los dispositivos de entrada (/dev/input).

Archivo de Registro
El keylogger guarda las teclas presionadas en el archivo /tmp/keylogger.txt. Puedes visualizar el contenido del archivo con:

bash
Copiar código
cat /tmp/keylogger.txt
Advertencias
Legalidad: El uso de keyloggers está sujeto a regulaciones legales estrictas. Asegúrate de tener permiso para usar este programa y de cumplir con las leyes y políticas de privacidad aplicables.
Privacidad: No utilices este programa para capturar información sin el consentimiento adecuado.
Contribuciones
Si deseas contribuir a este proyecto, por favor sigue las siguientes directrices:

@didicrts@gmail.com

Forkea el repositorio.
Crea una nueva rama para tus cambios.
Realiza tus modificaciones y asegúrate de probar el código.
Envía un pull request con una descripción detallada de los cambios realizados.
Licencia
Este proyecto está licenciado bajo la Licencia MIT.

Contacto
Para preguntas o soporte, por favor contacta a didicrts@gmail.com
