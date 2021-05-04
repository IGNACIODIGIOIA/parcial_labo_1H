/*
 * Compra.h
 *
 *  Created on: 29 abr. 2021
 *      Author: ignac
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#define QTY_DIRECCIONDEENTREGA 64
#define QTY_COLOR 32
#define QTY_DESCRIPCION 128

typedef struct{
	int idCliente;
	char direccionDeEntrega[QTY_DIRECCIONDEENTREGA];
	char color [QTY_COLOR];
	int idCompra;
	int isEmpty;
	char descripcion[QTY_DESCRIPCION];
	int estado;
	int precio;
	int cantidad;

}Compra;

int com_inicializarArray(Compra* array,int limite);
int com_altaForzadaArray(Compra* array,int limite, int indice, int* idCompra, int idCliente,char* descripcion, char* direccion, char* color, int cantidad);
int com_imprimirArray(Compra* array,int limite);
int com_imprimir(Compra* pElemento);
int com_alta(Compra* array,int limite, int indice,int idCliente, int* idCompra , int* precio);
int com_getEmptyIndex(Compra* array,int limite);
int com_baja(Compra* array,int limite, int indice);
int com_buscarId(Compra array[], int limite, int valorBuscado);
int com_imprimirCompraActivas(int idCliente, Compra* array, int limite);
int com_ImprimirClienteId(Compra* array, int limite, int clienteId);
int com_EliminarClienteId(Compra* array, int limite, int clienteId);
int com_imprimirComImpaga(Compra* array,int limite);
int com_PagarCompra(Compra* array, int limite, int i);
int com_CancelarCompra(Compra* array, int limite, int i);
int com_ContarClienteId(Compra* array, int limite, int clienteId, int* cantidad);

#endif /* COMPRA_H_ */
