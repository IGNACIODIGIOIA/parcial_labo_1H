/*
 * Compra.c
 *
 *  Created on: 29 abr. 2021
 *      Author: ignac
 */
#include"Compra.h"
#include <stdio.h>
#include <stdlib.h>

int com_inicializarArray(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(i=0;i<limite;i++)
			{
				array[i].isEmpty = 1;
			}
		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------

int com_altaForzadaArray(Compra* array,int limite, int indice, int* idCompra, int idCliente,char* descripcion, char* direccion, char* color, int* cantidad)
{
	int respuesta = -1;
	Compra bufferCompra;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCompra != NULL)
		{
			strncpy(bufferCompra.direccionDeEntrega,direccion,QTY_DIRECCIONDEENTREGA);
			strncpy(bufferCompra.color,color,QTY_COLOR);
			strncpy(bufferCompra.descripcion,descripcion,QTY_DESCRIPCION);
			bufferCompra.idCliente = idCliente;
			bufferCompra.idCompra = *idCompra;
			bufferCompra.cantidad = cantidad;
			bufferCompra.isEmpty = 0;
			bufferCompra.estado=0;
			respuesta = 0;
			array[indice] = bufferCompra;
			(*idCompra)++;


		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_imprimirArray(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("\nIdCompra - Descripcion - Entre calles - Color - Cantidad - Estado  ");
		for(i=0;i<limite;i++)
			{
				com_imprimir(&array[i]);
			}
	}
		return respuesta;
}
//----------------------------------------------------------------------------------------------------------------

int com_imprimir(Compra* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
		retorno=0;
		printf("\nID: %d - %s - %s - %s - %d - %d ",pElemento->idCompra,pElemento->descripcion,pElemento->direccionDeEntrega,pElemento->color,pElemento->cantidad,pElemento->estado);
		}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------
int com_getEmptyIndex(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
		if(array != NULL && limite > 0)
			{
				for(i=0;i<limite;i++)
				{
					if(array[i].isEmpty == 1)
					{
						respuesta = i;
						break;
					}
				}
			}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_alta(Compra* array,int limite, int indice,int* idCliente, int* idCompra , int* cantidad)
{
	int respuesta = -1;
	Compra bufferCompra;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCompra != NULL)
		{
			if( utn_getDescripcion(bufferCompra.descripcion,QTY_DESCRIPCION,"\nDescripcion? ", "\nError",2) ==0 &&
				utn_getDescripcion(bufferCompra.direccionDeEntrega,QTY_DIRECCIONDEENTREGA, "\nDireccion?","\nError",2 )==0 &&
				utn_getDescripcion(bufferCompra.color,QTY_COLOR, "\nColor?","\nError",2 )==0 &&
				utn_getNumero(&cantidad,"\nIngrese cantidad barbijos: ","\nError. Reingrese",1,10000000,2)==0)
				{
					respuesta = 0;
					bufferCompra.idCliente = idCliente;
					bufferCompra.idCompra = *idCompra;
					bufferCompra.isEmpty = 0;
					bufferCompra.estado=0;
					array[indice] = bufferCompra;
					(*idCompra)++;
				}
		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_baja(Compra* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].estado == 0)
	{
		array[indice].estado = 1;
		respuesta = 0;
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_buscarId(Compra array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idCompra == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_ImprimirClienteId(Compra* array, int limite, int clienteId)
{
	int respuesta = -1;
	Compra bufferCompra;
	if(array != NULL && limite > 0 && clienteId >= 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == clienteId && array[i].isEmpty == 0)
			{
				bufferCompra = array[i];
				com_imprimir(&bufferCompra);
				respuesta = 0;

			}
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_EliminarClienteId(Compra* array, int limite, int clienteId)
{
	int respuesta = -1;
	Compra bufferCompra;
	if(array != NULL && limite > 0 && clienteId >= 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == clienteId && array[i].isEmpty == 0)
			{
				bufferCompra = array[i];
				array[i].isEmpty = 0;
				respuesta = i;
				break;
			}
		}
	}
		return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_imprimirComImpaga(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("\nIdCompra - Descripcion - Entre calles - Color - Cantidad - Estado  ");
		for(i=0;i<limite;i++)
			{
			if(array[i].estado == 0 && array[i].isEmpty == 0)
							{
								com_imprimir(&array[i]);
							}
			}
	}
		return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_PagarCompra(Compra* array, int limite, int i)
{
	int respuesta = -1;
	int monto = 0;
	int accion = -1;
	if(array != NULL && limite > 0 && i >= 0)
	{
		if(	utn_getNumero(&monto,"\nIngrese el monto de la compra: ","\nError. Reingrese",0,10000000,2) == 0 )
		{
			if(utn_getNumero(&accion, "\nDesea guardar los cambios? 0= NO, 1=SI", "\nOpcion incorrecta. Reingrese", 0, 1, 2)== 0)
			{
				if(accion == 1)
				{
					array[i].precio = monto;
					array[i].estado = 1;
					respuesta = 0;
				}
			}
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int com_CancelarCompra(Compra* array, int limite, int i)
{
	int respuesta = -1;
	int monto = 0;
	int accion = -1;
	if(array != NULL && limite > 0 && i >= 0)
	{
		if(	utn_getNumero(&monto,"\nDesea cancelar la compra? 0= NO, 1=SI ","\nError. Reingrese",0,1,2) == 0 && array[i].estado == 0 )
		{
			if(accion == 1)
				{
					array[i].precio = monto;
					array[i].isEmpty = 1;
					respuesta = 0;
				}
		}else {
				printf("No se puede dar de baja una compra ya pagada!");
			  }
	}
	return respuesta;
}

int com_ContarClienteId(Compra* array, int limite, int clienteId, int* cantidad)
{
	int respuesta = -1;
	int contador = 0;

	if(array != NULL && limite > 0 && clienteId >= 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].idCliente == clienteId)
				{
					contador++;
				}
			}
			*cantidad = contador;
		}
	return respuesta;
}

