/*
 * Cli-Com.c
 *
 *  Created on: 2 may. 2021
 *      Author: ignac
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compra.h"
#include "Cli-Com.h"
#include "utn.h"


int Rel_baja(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra)
{
	int respuesta = -1;
	int accion = -1;
	if(arrayCliente != NULL && limiteCliente > 0 && indiceCliente < limiteCliente && indiceCliente >= 0 && arrayCliente[indiceCliente].isEmpty == 0
			&&arrayCompra != NULL)
	{
		if(com_ImprimirClienteId(arrayCompra,limiteCompra,indiceCliente) == 0)
		{
			if(utn_getNumero(&accion, "\nEsta seguro de eliminar el cliente ? 0= NO, 1=SI", "\nReintente", 0, 1, 2)== 0)
			{
				if(accion == 1)
				{
					if(com_EliminarClienteId(arrayCompra,limiteCliente,indiceCliente)== 0 && com_EliminarClienteId(arrayCliente,limiteCliente, indiceCliente) == 0)
					{
						respuesta = 0;
					}
				}
			}
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int Rel_Pagar(Compra* Array, int limiteCompra,int indiceCompras, Cliente* clienteArray, int limiteCliente)
{
	int respuesta = -1;
	int compraId = -1;
	int posicion;
	if(com_imprimirComImpaga(Array,limiteCompra)== 0)
	{
		if(	utn_getNumero(&compraId,"\nIngrese el id de la compra: ","\nError. Reingrese",0,indiceCompras-1,2) == 0 )
			{
			posicion = com_buscarId(Array, limiteCompra, compraId);
				if(posicion != -1)
				{
					if(cli_imprimirPorId(clienteArray,limiteCliente, Array[posicion].idCliente)== 0 && com_PagarCompra(Array, limiteCompra, posicion) == 0)
					{
						printf("\nCambios guardados correctamente");
					}
				}
				respuesta = 0;
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int Rel_Cancelar(Compra* Array, int limiteCompra,int indiceCompras, Cliente* clienteArray, int limiteCliente)
{
	int respuesta = -1;
	int compraId = -1;
	int posicion;
	if(com_imprimirComImpaga(Array,limiteCompra)== 0)
	{
		if(	utn_getNumero(&compraId,"\nIngrese el id de la compra: ","\nError. Reingrese",0,indiceCompras-1,2) == 0 )
			{
			posicion = com_buscarId(Array, limiteCompra, compraId);
				if(posicion != -1)
				{
					if(cli_imprimirPorId(clienteArray,limiteCliente, Array[posicion].idCliente)== 0 && com_CancelarCompra(Array, limiteCompra, posicion) == 0)
					{
						printf("\nCompra cancelada correctamente");
					}
				}
				respuesta = 0;
		}
	}
	return respuesta;
}
//----------------------------------------------------------------------------------------------------------------
int Rel_ImprimirClientesyCompras(Compra* compraArray, Cliente* clienteArray, int limiteCompras,int indiceCompras, int limiteCliente)
{
	int respuesta = -1;
	int cantidadCompras;
	if(clienteArray != NULL && limiteCliente > 0 && compraArray != NULL && limiteCompras > 0)
		{
			printf("IdCliente - Nombre - Apellido - Cuit - Compras");

			for(int i=0;i<limiteCliente;i++)
			{
				if(clienteArray[i].isEmpty == 0 && com_ContarClienteId(compraArray,limiteCompras, clienteArray[i].id, &cantidadCompras) == 0)
				{
					cli_ImprimirConCompras(&clienteArray[i], cantidadCompras);
				}
			}
			respuesta = 0;
		}
	return respuesta;
}

