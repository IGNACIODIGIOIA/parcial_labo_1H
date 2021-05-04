/*
 * informes.c
 *
 *  Created on: 3 may. 2021
 *      Author: ignac
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compra.h"
#include "cliente.h"
//----------------------------------------------------------------------------------------------------------------

int inf_ContarPendientes(Compra* array, int limite)
{
	int respuesta = -1;
	int contador = 0;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].estado == 0)
				{
					contador++;
				}
			}
			printf("\nHay un total de %d compras pendientes", contador);
		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------

int inf_CompraConPrecioXunidadMasBajo(Compra* array, int limite)
{
	int respuesta = -1;
	int compraId = -1;
	float precio = -1;
	float precioAux;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].estado == 1)
				{
					precioAux = (float)array[i].precio / (float)array[i].cantidad;
					if(precio != -1)
					{
						if(precioAux < precio )
						{
							precio = precioAux;
							compraId = array[i].idCompra;
						}
					}
					else
					{
						precio = precioAux;
						compraId = array[i].idCompra;
					}

				}
			}
			if(compraId != -1)
			{
				printf("\n La compra con el precio por unidad mas bajo es la %d con un valor de %f por unidad", compraId, precio);
			}
			else
			{
				printf("\nNo hay compras abonadas");
			}
		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int inf_ColorMasPedido(Compra* array, int limite)
{
	int respuesta = -1;
	char colores[limite][QTY_COLOR];
	int flagEncontrado;
	int indiceColores = 1;
	char ColorMasPedido[QTY_COLOR];
	int auxCantidad = 0;
	int CantidadPedidos = 0;
	if(array != NULL && limite > 0)
			{
				respuesta = 0;
				strcpy(colores[0], array[0].color);
				for(int i=1;i<limite;i++)
				{
					if(array[i].isEmpty == 0)
					{
						flagEncontrado = 0;
						for(int j=0;i<=indiceColores;j++)
						{
							if(strcmp(colores[j],array[i].color) != 0)
							{
								flagEncontrado = 1;
							}
							break;
						}
						if(flagEncontrado == 1)
						{
							strcpy(colores[indiceColores], array[i].color);
							indiceColores++;
						}
					}
				}
				for(int i=0;i<indiceColores;i++)
				{
					if(inf_ContarPorColor(array,limite, colores[i], &auxCantidad) == 0)
					{
						if(CantidadPedidos < auxCantidad )
						{
							CantidadPedidos = auxCantidad;
							strcpy(ColorMasPedido, colores[i]);
						}
					}
				}
				printf("El color mas vendido es %s con un total de %d pedidos", ColorMasPedido,CantidadPedidos);

			}
	return respuesta;

}
//----------------------------------------------------------------------------------------------------------------
int inf_ContarPorColor(Compra* array, int limite, char* color, int* cantidad)
{
	int respuesta = -1;
	int contador = 0;
		if(array != NULL && limite > 0 && color != NULL)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && strcmp(array[i].color, color) == 0)
				{
					contador++;
				}
			}
			*cantidad = contador;
		}
	return respuesta;
}
