/** 
Marlon Yahir Martínez Chacon 
A01424875
**/



#include <string>
using namespace std;

class Cliente{
  private:
    string nombreCompleto,telefono,correo,direccion;
  public:
  Cliente();

  string getNombreCompleto();
  string getTelefono();
  string getCorreo();
  string getDireccion();

  void setNombreCompleto(string);
  void setTelefono(string);
  void setCorreo(string);
  void setDireccion(string);

  void ordenarProducto();
  void obtenerDatos();


  
};