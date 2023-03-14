# Clases 4-7

### [Grabación clase 4 (Ejemplo de declaración y operaciones)](https://drive.google.com/file/d/1cfg76APiNGo2No8_XSDI4Z4jCLb70o3v/view?usp=sharing)
### [Grabación clase 5 (Ejemplo de If, Elseif, Else)](https://drive.google.com/file/d/1pM12N5TbpYSwRj0e3SFoYaH57Ug1paW8/view?usp=sharing)
### [Grabación clase 6 (Ejemplo de structs)](https://drive.google.com/file/d/1GI9-ShYqxXmFWPdQZr_SvUy1KHCr9ESm/view?usp=sharing)
### [Grabación clase 7 (Ejemplo de funciones y matrices)](https://drive.google.com/file/d/1CZWvLKwdYBSX82n0aukZIHc9STQvlC2-/view?usp=sharing)
-------------
## Ejemplo del laboratorio (Proyecto 1)
En esta carpeta se encuentra todo lo elaborado en el laboratorio referente al proyecto 1.  En este ejemplo se agregaron las definiciones de expresiones, instrucciones, operaciones, declaracion y acceso de variables, impresión, manejo de entornos, definición y llamado de funciones, structs, arreglos y matrices.

### Entradas de prueba:
```cpp
void main()
{
  int num1 = 25;
  printf(num1*4);
  if(2<3)
  {
    printf("es menor");
  } 
  else if(6>5) 
  { 
    printf("es mayor"); 
  } 
  else 
  {
    printf("es igual"); 
  }
}
```
```cpp
void main(){
  //declaración
  struct persona { 
    int edad; 
    string nombre; 
  }

  //creación
  struct persona andres = { 27, "andres" }

  //acceso
  printf("Mi nombre es: ");
  printf(andres.nombre);
  printf("Mi edad es: ");
  printf(andres.edad);
}
```
```cpp
int suma(int num1, int num2)
{
    printf("******suma******");
    return num1 + num2;
}

void main()
{
    printf("******MAIN******");
    printf(suma(6,40));
}
```
```cpp
void main()
{
    array arreglo = {{1,2,3},{4,5,6},{"hola","mundo"},{7,8,9}};
    printf(arreglo);
}
```
```cpp
void imprimirArray(array arr, int index)
{
    printf(arr[index]);
}

void main()
{
    array arreglo = {"esto ","es ","un ","arreglo ", "<3"};
    imprimirArray(arreglo, 0);
    imprimirArray(arreglo, 1);
    imprimirArray(arreglo, 2);
    imprimirArray(arreglo, 3);
    imprimirArray(arreglo, 4);
}
```
```cpp
void imprimirArray(array arr, int index)
{
    printf(arr[index]);
}

void main()
{
    array arreglo = {{1,2,3},{4,5,6},{7,8,9}};
    imprimirArray(arreglo, 0);
    imprimirArray(arreglo, 1);
    imprimirArray(arreglo, 2);
}
```
-------------
| Carne     | Nombre                     |
| --------- | -------------------------- |
| 201504220 | José Andres Rodas Arrecis  |
