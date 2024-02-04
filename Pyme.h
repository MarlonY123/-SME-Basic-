/** 
Marlon Yahir Martínez Chacon 
A01424875
**/


#include "Banco.h"
#include "Cliente.h"
const int LENGTH = 10;
class Pyme
{
private:
  Banco banco1;
  Cliente cliente1;
  string productos[LENGTH];
  double precios[LENGTH],sueldo;
  int cantidadDisponible[LENGTH],contadorCompras;
  string productosComprados[LENGTH*2];
  int cantidadComprada[LENGTH*2];
  double subtotalProducto[LENGTH*2];
public:
  Pyme();
  void mostrarProductos();
  double getPrecios();
  int getCantidadDisponble();
  void setPrecios(double, int);
  void setCantidadDisponible(int, int);
  void setProductos(string,int);
  void recibirPago();
  void procesandoPago(double);
  void mostrarCuenta();
  void generandoTicket(double);

};