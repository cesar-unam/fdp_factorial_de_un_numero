/*
*************************************
+ $calcular factorial de un numero  +
+
+  FUNDAMENTOS DE PROGRAMACION      +
+                                   +
*************************************
+                                   +
+
*/


#include <stdio.h>
#include <stdlib.h>
// estructura funcion obtener_factorial
unsigned long obtener_factorial(int x);
void borrar_scanf(); // borramos el scanf en caso de que el valor ingresado no sea numero
int main()
{
    int n = 0;  //declaramos n, es el valor que el usuario ingresara
    int valor;   // respuesta boleana de scanf
    char res;   // respuesta para repetir el programa


 while(n < 1) // mientras n sea menor que 1 , no calculamos factorial
 {
     // pedimos al usuario ingresar numero
     printf("Hola! Por favor, ingresa el numero del que quieras obtener su factorial\n");
     valor = scanf("%d", &n); // asignamos scanf en una variable
    while (valor == 0)       // mientras el boleano de scanf sea 0, no se introdujo un valor valido
    {
      system("cls");
      printf("Lo sentimos, solo puedes introducir un valor entero\n");
      printf("Hola! Por favor, ingresa el numero del que quieras obtener su factorial\n");
      borrar_scanf(); // limpiamos buffer

      valor = scanf("%d", &n); // volvemos a leer a n


    }

    if(n > 0)  // Si el valor de n es mayor que 0, calculamos nuestro factorial
     {
     if(n > 12) //Si n es mayor de 12, el valor resultante excedera a unsinged long
     {
           n = 0; // reasignamos n, para reinicializar el programa
           borrar_scanf();   // limpiamos buffer
           system("cls"); // limpiamos pantalla

         printf("El numero maximo que puedo calcular es 12, intenta con otro numero\n"); // mensaje de error
          continue; // continuamos el bucle
     }

      printf("El factorial del numero %d es: %lu", n, obtener_factorial(n)); // invocamos a la funcion para obtener factorial
      printf("\n");
      borrar_scanf(); // limpiamos buffer
      printf("Deseas repetir el programa Y/N?\n");  // ¿El usuario quiere calcular otro numero?

      scanf("%c", &res); //asignamos su respuesta a una variable
      if(res == 'y' || res == 'Y')  // si quiere calcular otro numero reiniciamos programa
      {
          n = 0;
          borrar_scanf();
          system("cls");
          continue;
      } else {
        //No quizo calcular otro numero, salimos
        printf("ADIOS! \n");  //mensaje despedida

      return 0; // terminamos programa
      }
 }

 }

    return 0;  // fin programa
}

unsigned long obtener_factorial(int x){ // el valor de retorno de la funcion sera unsigned long
    unsigned long factorial = 1; // declaramos variable para almacenar el factorial
    int i;
    //inicializamos bucle para obtener factorial
    for(i=1; i < x; i++)
    {
        factorial *= (i + 1); // multiplicamos el consecutivo de numeros
    }
    return factorial; // retornamos el valor de factorial

}
void borrar_scanf(){ // limpiamos buffer de scanf


    int ch;
    while((ch = getc(stdin)) != EOF && ch != '\n');

}
