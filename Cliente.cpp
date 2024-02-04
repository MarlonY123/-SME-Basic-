/** 
Marlon Yahir Martínez Chacon 
A01424875
**/



#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

Cliente::Cliente(){
 
  
}

string Cliente::getNombreCompleto(){
  return nombreCompleto;
}

string Cliente::getTelefono(){
  return telefono;
}
string Cliente::getCorreo(){
  return correo;
}
string Cliente::getDireccion(){
  return direccion;
}

void Cliente::setNombreCompleto(string nombreCompleto){
  this -> nombreCompleto = nombreCompleto;
}
void Cliente::setTelefono(string telefono){
  this -> telefono = telefono;
}
void Cliente::setCorreo(string correo){
  this -> correo = correo;
}
void Cliente::setDireccion(string direccion){
  this -> direccion = direccion;
}

void Cliente::obtenerDatos(){
  //recolecta los datos necesario del cliente para el envio del producto
  string nombreCompleto,telefono,correo,direccion;
  cout << "Datos para envio" <<  endl;
  cout << "Nombre completo: ";
  getline(cin,nombreCompleto);
  cout << "Telefono: ";
  getline(cin,telefono);
  cout << "Correo: ";
  getline(cin,correo);
  cout << "Direccion: ";
  getline(cin,direccion);
  setNombreCompleto(nombreCompleto);
  setTelefono(telefono);
  setCorreo(correo);
  setDireccion(direccion);

}