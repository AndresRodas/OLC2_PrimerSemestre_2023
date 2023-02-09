# Clase 3

### [Grabación](https://drive.google.com/file/d/174ojX-mX_UMfcTG4gCzT0Wmay2W2flVl/view?usp=sharing)
-------------
## Ejemplo del laboratorio (*Windows*)

### 1) Instalación de QT
* Descargar el archivo de instalación de **QT Community** en el siguiene [enlace de descarga](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4).
* Ejecutar el instalador, para proceder con la instalación es necesario crear una cuenta.

![](https://i.imgur.com/G9rEQSY.png)

* Leer los terminos y condiciones de uso 😉 marcar ambas casillas y hacer click en siguiente.
* En la opción de *Carpeta de Instalación* marcamos la casilla de *Opción personalizada* y damos click en siguiente.
* Cuando lleguemos a la parte de *Seleccionar Componentes* vamos a seleccionar los siguientes componentes:
    * QT Design Studio
    ![](https://i.imgur.com/sx5pbeK.png)
    * QT versión 6.4.2
    ![](https://i.imgur.com/qQOJi9w.png)
    * MinGW última versión
    ![](https://i.imgur.com/5unKgF5.png)
    * QT Installer Framework y paquete OpenSSL
    ![](https://i.imgur.com/PjlUt7I.png)

* Luego haremos click en siguiente hasta que inicie la instalación.  La duración dependerá de su velocidad de internet.

### 2) Crear nuevo proyecto en QT

* Buscamos en nuestro equipo la aplicacion QT Creator y la ejecutamos.

![](https://i.imgur.com/A0JVCve.png)

* Seleccionamos la opción *Create Project...*
* Marcamos la opción *Qt Widgets Application* y hacemos click en siguiente. 

![](https://i.imgur.com/TqMPr2o.png)

* Ingresamos un nombre para nuestro proyecto y seleccionamos una ubicación.
* Seleccionamos el Build system de nuestra elección (se recomienda qmake).

![](https://i.imgur.com/Pat7tMJ.png)

* Ingresamos un nombre para nuestras clases, las cabeceras y el cuerpo de nuestro proyecto.

![](https://i.imgur.com/WLZU9W4.png)

* **Importante** en la opción de lenguajes se recomienda dejar *"none"* debido a que seleccionar un lenguaje suele dar problemas en el compilado.

![](https://i.imgur.com/Lb5ctBC.png)

* Seleccionamos la version de Qt que acabamos de instalar.

![](https://i.imgur.com/vOLA68B.png)

* Seleccionamos la opción de Git si deseamos utilizarlo y finalizamos la creación del proyecto.

![](https://i.imgur.com/BbaMEoq.png)

### 3) Cargar ejemplo realizado en clase

* Buscamos en nuestro equipo la aplicacion QT Creator y la ejecutamos.
* Seleccionamos la opción *Open Project...*

![](https://i.imgur.com/KaUI0v7.png)

* Buscamos la carpeta donde se encuentra el proyecto que deseamos abrir, para este caso abriremos el proyecto ubicado en este [repositorio](https://github.com/AndresRodas/OLC2_PrimerSemestre_2023) en la carpeta "*Clase3\Ejemplo_Clase3*".
* Dentro de la carpeta buscamos el archivo con extensión "*.pro*" y lo seleccionamos.
* Listo, cargamos nuestro proyecto de ejemplo.

![](https://i.imgur.com/pKzsSWv.png)

> Si aun existen dudas con el funcionamiento básico de Qt pueden ver [el siguiente tutorial](https://youtube.com/playlist?list=PL54fdmMKYUJuGSIbgd7y5oPvTG6jKbcPf) para comprender mejor el tema.

-------------
| Carne     | Nombre                     |
| --------- | -------------------------- |
| 201504220 | José Andres Rodas Arrecis  |
