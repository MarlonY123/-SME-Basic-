/** 
Marlon Yahir Martínez Chacon 
A01424875
**/


#include <string>
using namespace std;
class Banco
{
private:
  double cuenta;
  string nombre;
  long int numeroTarjeta;
  
public:
  Banco();
  //void obtenerDatos();
  double getCuenta();
  void setCuenta(double);
  string getNombre();
  void setNombre(string);
  long int getNumeroTarjeta();
  void setNumeroTarjeta(long int);
  bool procesarPago(double);
};