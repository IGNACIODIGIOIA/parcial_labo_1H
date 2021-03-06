/*
 * Cliente.c
 *
 *  Created on: 29 abr. 2021
 *      Author: ignac
 */
#include"cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

int cli_inicializarArray(Cliente* array,int limite)
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
int cli_alta(Cliente* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre? \n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido? \n","\nERROR\n",2) == 0 &&
			utn_getNumero(bufferCliente.Cuit,"\n Cuit? \n","\nERROR\n",10000000000, 99999999999, 2)==0)
		{
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\n %d - %s - %s - %n ",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->Cuit);
		}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("IdCliente - Nombre - Apellido - Cuit");
			for(i=0;i<limite;i++)
			{
				cli_imprimir(&array[i]);
			}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_getEmptyIndex(Cliente* array,int limite)
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
int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido,char* cuit)
{
	int respuesta = -1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferCliente.nombre,nombre,NOMBRE_LEN);
			strncpy(bufferCliente.apellido,apellido,APELLIDO_LEN);
			strncpy (bufferCliente.Cuit,cuit,11);
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
		{
			if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
			utn_getNumero(bufferCliente.Cuit,"\n Cuit? \n","\nERROR\n",10000000000, 99999999999,2)== 0)

			{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			}
		}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_baja(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int cli_imprimirPorId(Cliente* array,int limite, int indice)
{

	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].id == indice)
			{
				printf("\nId - Nombre - Apellido - Cuit");
				printf("\n %d - %s - %s - %n ",array[i].id,array[i].nombre,array[i].apellido,array[i].Cuit);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------

int cli_ImprimirConCompras(Cliente* pElemento, int compra)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\n %d - %s - %s - %n - %d ",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->Cuit, compra);
		}
	return retorno;
}
