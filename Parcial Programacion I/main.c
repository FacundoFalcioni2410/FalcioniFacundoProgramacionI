#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3


typedef struct
{
    int id;
    char procesador[5];
    char marca[20];
    float precio;


}eNotebook;


float aplicarDescuento(float precio);
int contarCaracteres(char string[], char caracter);
void ordernarNotebooks(eNotebook x[], int tam);

int main()
{

    float precio;
    float precioFinal;

    char cadena[20];
    char caracter;
    int cantidad;

    eNotebook lista[3] = { {1000,"i5","Intel",20000}, {1001, "Ryzen 5","AMD",15000}, {1002, "i3","Intel",10000} };

    printf("Ingrese una cadena de caracteres:");
    gets(cadena);

    printf("Ingrese un caracter: ");
    scanf("%c",&caracter);


    cantidad = contarCaracteres(cadena,caracter);
    printf("%d", cantidad);

    printf("Ingrese el precio al cual le desea sacar un porcentaje: ");
    fflush(stdin);
    scanf("%f",&precio);

    precioFinal = aplicarDescuento(precio);

    printf("\nEl precio con el descuento aplicado es de: $%.2f\n\n",precioFinal);

    mostrarNotebooks(lista,TAM);

    ordernarNotebooks(lista, TAM);

    mostrarNotebooks(lista, TAM);

}

float aplicarDescuento(float precio)
{
    float precioConDescuentoAplicado;

    precioConDescuentoAplicado = precio - precio * 5/100;

    return precioConDescuentoAplicado;
}

int contarCaracteres(char string[], char caracter)
{
    int contador = 0;

    for(int i = 0; string[i]!='\0'; i++)
    {
        if(string[i] == caracter)
        {
            contador++;
        }
    }

    return contador;
}

void ordernarNotebooks(eNotebook x[], int tam)
{
    eNotebook auxiliar;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(x[i].marca, x[j].marca) > 0)
            {
                auxiliar = x[i];
                x[i] = x[j];
                x[j] = auxiliar;
            }
            else if(strcmp(x[i].marca, x[j].marca) == 0 && x[i].precio < x[j].precio)
            {
                auxiliar = x[i];
                x[i] = x[j];
                x[j] = auxiliar;
            }
        }
    }
}


void mostrarNotebook(eNotebook x)
{
    printf("\n");
    printf("%4d    %s     %s     %.2f\n", x.id, x.marca, x.procesador, x.precio);
}

void mostrarNotebooks(eNotebook x[], int tam)
{
    printf("\n\n");

    printf("ID    MARCA   PROCESADOR   PRECIO");

    for(int i = 0; i < tam; i++)
    {
        mostrarNotebook(x[i]);
    }
}

