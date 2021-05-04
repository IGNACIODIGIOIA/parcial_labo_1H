/*
 * Cli-Com.h
 *
 *  Created on: 2 may. 2021
 *      Author: ignac
 */

#ifndef CLI_COM_H_
#define CLI_COM_H_

int Rel_baja(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra);
int Rel_Pagar(Compra* Array, int limiteCompra,int indiceCompras, Cliente* clienteArray, int limiteCliente);
int Rel_Cancelar(Compra* Array, int limiteCompra,int indiceCompras, Cliente* clienteArray, int limiteCliente);
int Rel_ImprimirClientesyCompras(Compra* compraArray, Cliente* clienteArray, int limiteCompras,int indiceCompras, int limiteCliente);

#endif /* CLI_COM_H_ */
