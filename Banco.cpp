/** 
Marlon Yahir Martínez Chacon 
A01424875
**/

#include "Banco.h"
#include <iostream>
using namespace std;

Banco::Banco(){
  cout << "\nDATOS CUENTA BANCARIA" <<endl;
  string nombre;
  long int numeroTarjeta;
  double cuenta;
  cout << "Introduzca su nombre completo: ";
  getline(cin, nombre);
  cout << "Introduzca su numero de tarjeta: ";
  cin >> numeroTarjeta;
  cout << "Su saldo: ";
  cin >> cuenta;

  setNombre(nombre);
  setNumeroTarjeta(numeroTarjeta);
  setCuenta(cuenta);
}



double Banco::getCuenta(){
  return cuenta;
}

void Banco::setCuenta(double cuenta){
  this->cuenta = cuenta;
}

string Banco::getNombre(){
  return nombre;
}
void Banco::setNombre(string nombre){
  this -> nombre = nombre;
}
long int Banco::getNumeroTarjeta(){
  return numeroTarjeta;
}
void Banco::setNumeroTarjeta(long int numeroTarjeta){
  this -> numeroTarjeta = numeroTarjeta;
}


bool Banco::procesarPago(double pago){
  bool pagoRealizado = true;
  if (pago > cuenta){
    //Fondos insuficentes no se puede realizar el pago";
    pagoRealizado = false;
  }
  else if(pago <= cuenta){
    //Pago realizado con exito
    
    pagoRealizado = true;
  }

  return pagoRealizado;
}

