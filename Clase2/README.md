# Clase 2

### [Grabación](https://drive.google.com/file/d/1yP3_YifC2FqBswCCLy4IJMzmpfHlG-HJ/view?usp=sharing)
-------------
## Ejemplo del laboratorio (*Windows*)

### 1) Instalar compilador de C
* Descargar el archivo "mingw-get-setup.exe" de la siguiente [carpeta de UEDI](https://uedi.ingenieria.usac.edu.gt/campus/mod/folder/view.php?id=461838).
* Ejecutar el instalador, hacer click en siguiente hasta finalizar.
* Dirigirse a la carpeta donde se instaló el compilador de C y copiar la ruta de la carpeta "\bin".
* Dirigirse a la edición de variables de entorno del sistema.

![](https://i.imgur.com/klKtlga.png)

* Seleccionar la variable "Path" y hacemos click en editar.
* Seleccionamos la opción "Nuevo" y pegamos la ruta de la carpeta "\bin" que acabamos de copiar y hacemos click en aceptar.

![](https://i.imgur.com/xyV6xIY.png)

* Abrimos una consola y con el siguiente comando procedemos a validar que el compilador de C se ha instalado de manera correcta.
```
gcc --version
```

### 2) Instalar paquete de herramientas (Flex y Bison)
* Vamos a instalar las herramientas con ayuda de un gestor de descargas llamado **Chocolatey** por lo que procedemos a abrir una consola de *Powershell.exe* como administrador.
* Pegamos el siguiente comando en la consola y presionamos enter.
```
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
* Una vez instalado el gestor procedemos a instalar las herramientas, para ello pegamos el siguiente comando en consola y presionamos enter.
```
choco install winflexbison3
```
* Nos dirigimos a la ruta de instalación de *Chocolatey*, por lo general es la siguiente: "C:\ProgramData\chocolatey" y copiamos la ruta de la carpeta "\bin", En ocaciones la carpeta *ProgramData* se encuentra oculta. 

* Como en el paso anterior agregamos la ruta en la variable de entorno "Path".

![](https://i.imgur.com/WovcxiN.png)

* Abrimos una consola y con los siguientes comandos procedemos a validar que las herramientas se instalaron de manera correcta.
```
win_flex --version
```
```
win_bison --version
```
### 3) Compilar archivos de análisis

* Abrimos una consola y nos dirigimos a la carpeta donde tenemos los archivos de flex (*calc.l*) y bison (*calc.y*).
* Ejecutamos el siguiente comando para compilar el archivo de bison.
```
win_bison -dy .\calc.y
```
* Ejecutamos el siguiente comando para compilar el archivo de flex. 
```
win_flex .\calc.l
```
* Por último ejecutamos el siguiente comando para generar el ejecutable de C, este tomará el nombre de *a.exe*.

```
gcc lex.yy.c y.tab.c
```

### 4) Entradas de ejemplo
* Para iniciar el programa que acabamos de crear abrimos una consola y nos dirigimos a la ubicación del archivo "*a.exe*".
* Iniciamos la aplicación ingresando "*.\a.exe*" y presionando enter.
* Ya podemos ingresar algunas entradas en nuestra calculadora, siempre teniendo en cuenta la grámatica.

```
evaluar(2+2*4-1+10);
evaluar(5*5/5);
evaluar(9-5/2*6*2+20-32);
evaluar(0+0-0*0/1);
```

![](https://i.imgur.com/7uhZMWP.png)

-------------
| Carne     | Nombre                     |
| --------- | -------------------------- |
| 201504220 | José Andres Rodas Arrecis  |