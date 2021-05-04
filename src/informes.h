/*
 * informes.h
 *
 *  Created on: 3 may. 2021
 *      Author: ignac
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int inf_ContarPendientes(Compra* array, int limite);
int inf_CompraConPrecioXunidadMasBajo(Compra* array, int limite);
int inf_ColorMasPedido(Compra* array, int limite);
int inf_ContarPorColor(Compra* array, int limite, char* color, int* cantidad);

#endif /* INFORMES_H_ */
