# Sistema de **gestión de tickets**
---
### Descripción
Este programa fue creado para gestionar de forma correcta distintos tickets que se le vayan otorgando. Cada **ticket** posee datos que hacen que se pueda **identificar un cliente** con un **problema clave** a resolver. 

El programa busca poder hacer que el **sistema de gestión** sea lo más **directo** y **simple** posible en situaciones de **soporte o apoyo técnico**, otorgando herramientas de registro y búsqueda de tickets, un sistema de prioridades, mostrar los tickets pendientes a ser procesados y atender el ticket con mayor prioridad (y más antiguo).

### Requerimientos
- Tener instalado **Visual Studio Code**, junto con la extensión C/C++ de Microsoft.
- Tener un compilador de C (como **gcc**) instalado. Para **Windows**, es recomendable utilizar **MinGW**.

### Compilación y ejecución

Para compilarlo, dentro del sistema operativo **Windows**, es necesario:
1. Descargar este **repositorio** como archivo `zip` (haciendo **click** en la sección `code`, y apretando el botón de `Descargar ZIP`).
2. Abrir el **explorador de archivos** y navegar hasta el archivo `zip` para descomprimirlo. Una vez descomprimido, abrir el directorio con los archivos del programa.
3. Abrir el archivo `main.c` del `zip` en **Visual Studio Code**.
4. Dentro de **Visual Studio Code**, abrir el **terminal** para poder compilar el programa.
5. Ejecutar el siguiente comando: `gcc TDAs/*.c *.c -o programa.exe`.
6. Abrir el archivo `programa.exe`, o escribir la línea `./programa.exe` en **Visual Studio Code** para ejecutarlo.

Una forma alternativa de compilación, dentro de **Windows**, sería:
1. Descargar el **repositorio** como archivo `zip`.
2. Abrir el **explorador de archivos** y navegar hasta encontrar el archivo `zip` para descomprimirlo.
3. En **Windows 11**, una vez descomprimido, hacer **click derecho** en el directorio para abrir el menú de opciones y seleccionar para **abrir en Terminal**. Alternativamente, abrir **PowerShell** o **Línea de Comandos**, copiar la dirección del repositorio (la ruta `C:\Users\...`) y ejecutar el comando `cd "C:\Users\..."`.
4. Ejecutar el comando: `gcc TDAs/*.c *.c -o programa.exe`.
5. Abrir el archivo `programa.exe` o escribir en la misma **terminal** el comando `./programa.exe` para ejecutarlo (si lo permite).

### Funciones del programa
El programa incluye **5 funciones principales** con las cuáles opera. 
1. `Registrar ticket`: Se encarga de poder agregar un ticket a la lista de sistema de gestión de tickets. Los tickets poseen la **ID del usuario**, un **mensaje con el problema a resolver**, la **hora a la que se hizo el registro** (y su orden de llegada), y la **prioridad del ticket** (**ALTO**, **MEDIO** o **BAJO**, asignado con valores numéricos).
2. `Asignar prioridad`: Permite poder cambiar la prioridad de un ticket a disposición. Se le otorga una ID, y si el ticket que se desea cambiar está dentro, da la opción de cambiar la prioridad actual a **ALTO**, **MEDIO**, o **BAJO** escribiendo **'2'**, **'1'** o **'0'** para cada uno respectivamente.
3. `Mostrar lista de tickets`: **Muestra la lista** de los tickets pendientes a ser atendidos. Está **ordenado por orden de prioridad** (de más alta prioridad a más baja), y por la **hora más antigua** (el **orden de llegada**).
4. `Procesar tickets`: Toma el ticket con mayor prioridad, y con la hora más antigua, y lo procesa mostrando los datos del ticket, eliminándolo posteriormente de la lista.
5. `Buscar ticket`: Busca un ticket a disposición dentro de la lista. Se da la opción de ingresar la ID del ticket que se desea buscar, y se muestran los datos correspondientes al ticket (su prioridad, ID, hora de entrada, y problema).

#### Posibles fallas
Hay **acciones específicas** que no funcionan tan correctamente como se debería:
- Al momento de usar la función `Registrar ticket`, si es que en el **ID** se ingresa un dato que **no es numérico**, puede ocasionar problemas al asignar la ID del ticket, junto con no declarar un mensaje al problema.
- Si se quiere **ingresar un problema** que supera la cantidad máxima de carácteres que se puede (**1000 máximo**), sólo se ingresarán los carácteres hasta el valor máximo.
- Si se ingresa una opción en el menú que **no es sólamente un carácter numérico**, el programa interpreta el primer carácter cómo su operación y, lo que resta, lo asigna dependiendo de la función.
---
### Ejemplos de ejecución

1. **Funciones ``Registrar ticket`` y ``Mostrar lista de tickets``:**
![Función Registrar y Mostrar](/Ejemplos/Registro_Mostrar.gif)

2. **Función ``Asignar prioridad``:**
![Función Asignar](/Ejemplos/AsignarPrioridad.gif)

3. **Función ``Buscar ticket``:**
![Función Buscar Ticket](/Ejemplos/BuscarTicket.gif)

4. **Función ``Procesar ticket``:**
![Función Procesar Ticket](/Ejemplos/ProcesarTicket.gif)
- Ejemplo al **procesar múltiples tickets**:
![Múltiples Procesar Ticket](/Ejemplos/Multiples_Procesar.gif)