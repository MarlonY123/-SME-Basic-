/** 
Marlon Yahir Martínez Chacon 
A01424875
**/


#include "Pyme.h"
#include <string>
#include <iostream>

using namespace std;

Pyme::Pyme(){
  //inicializa todos los productos de la tienda
  string productos[LENGTH] = {"Cafe","Pan de caja", "Leche","Salsa","Galletas","Mantequilla","Frijoles","Pasta","Aceite","Sopa"};
  double precios[LENGTH] = {22.32,10.5,5.32,10.40,15.34,23.32,25.90,18.39,29.34,19.99};
  int cantidadDisponible[LENGTH] = {10,15,22,43,21,9,24,11,36,5};
  for(int i = 0;i<LENGTH;i++){
    setPrecios(precios[i], i);
    setCantidadDisponible(cantidadDisponible[i], i);
    setProductos(productos[i],i);
    

  }
  
}


void Pyme::setPrecios(double precios, int i){
  this -> precios[i] = precios;
}
void Pyme::setCantidadDisponible(int cantidad, int i){
  this -> cantidadDisponible[i] = cantidad;
}

void Pyme::setProductos(string productos, int i){
  this -> productos[i] = productos;
}

void Pyme::generandoTicket(double total){
  //genera el ticket de compra de todos los datos
  cout << "Cliente " << cliente1.getNombreCompleto() << "\nDireccion " << cliente1.getDireccion() << endl;
  cout << "Producto\tCantidad\tCosto" << endl;
  for(int i = 0;i<contadorCompras;i++){
    if(cantidadComprada[i] != 0 && subtotalProducto[i] !=0){
      cout << productosComprados[i] << "\t\t" << cantidadComprada[i] << "\t\t" << subtotalProducto[i] << endl;
    }
    
  }
  cout << "TOTAL\t" << total << endl;
}

void Pyme::procesandoPago(double total){
  
  int numeroTarjeta;
  string respuesta;
  introducirNumero:
  cout << "\nIntroduzca el numero de tarjeta para poder realizar su pago: ";
  cin >> numeroTarjeta;
  //te confirma si es que la tarjeta esta a tu nombre
  if(numeroTarjeta==banco1.getNumeroTarjeta()){
    string respuesta;
    cin.ignore();
    cout << "Su tarjeta esta a nombre de " << banco1.getNombre() << "?: ";
    getline(cin,respuesta);
    if(respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
      pago:
      cout << "\nProcediendo a realizar el pago...." << endl;
      //banco1.procesarPago(total);      
      if(banco1.procesarPago(total)){
        cout << "Pago realizado con exito\n";
        cout << "Su pedido sera enviado a la siguiente direccion: "<< cliente1.getDireccion() << endl;
        cout << "\nTICKET\n";
        generandoTicket(total);
        //cout << ""
        cout << "\nGracias por su compra" << endl;
      }
      else{
        cout << "Fondos insuficientes para poder completar el pago" << endl;
        goto introducirOtraTarjeta;
      }

    }
    else{
      //hace que puedas introducir otra tarjeta cuando no corresponde el nombre o cuando no tienes saldo
      introducirOtraTarjeta:
      string respuesta;
      cout << "\nDesea introducir otra tarjeta? ";
      getline(cin,respuesta);
      if(respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
      cout << "Introduzca una tarjeta con su nombre\n";
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
      
      banco1.setNombre(nombre);
      banco1.setNumeroTarjeta(numeroTarjeta);
      banco1.setCuenta(cuenta);
      cin.ignore();
      goto pago;
      }
      else{
        return;
      }

      //cout << "Contacte con su banco para solucionar este problema " << endl;
    }
  }

  else{
    cout << "Numero de tarjeta incorrecto" << endl;
    goto introducirNumero;
  }
}

void Pyme::mostrarProductos(){
  //string f
  iniciarCompra:
  int centinela = -1;
  bool seguirComprando = true;
  contadorCompras = 0;
  string elegir;
  int eleccion;
  int cantidad=0;
  double total = 0;
  cout << "\n/**BIENVENIDO A NUESTRA TIENDA EN LINEA**/\nPara salir de la compra, introduzca 'terminar'): \n\n";
  for(int i = 0;i< LENGTH;i++){
    cout << i+1 << ". " << productos[i] << "\t $" << precios[i] << "\t Cantidad: "<< cantidadDisponible[i] << endl;
  }
  do{
    cout << endl;
  do{
  cout << "Que numero de producto desea escoger?: ";
  cin >> elegir;
  if(elegir == "terminar"){
    if(productosComprados[0] == ""){
      return;
    }
    eleccion = centinela;
  }

  else{
    eleccion = stoi(elegir);
  }
  }while(eleccion< -1 || eleccion > LENGTH || eleccion == 0);
  
  if(eleccion!=centinela)
  {
    cout << "Cantidad disponible de " << productos[eleccion-1] << ": " << cantidadDisponible[eleccion-1] << endl;

    if(cantidadDisponible[eleccion-1] == 0){
      cin.ignore();
      string respuesta;
      cout << "Desea que cuando tengamos el producto le notifiquemos?  ";
      getline(cin,respuesta);
      if(respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
        cout << "Gracias por su preferencia\nLe notificaremos a la brevedad\n";
      }
      else{
        cout << "Gracias por su tiempo\n";
      }
      cout << "Desea seguir comprando: ";
      cin >> respuesta;
      if (respuesta == "No" || respuesta == "NO" || respuesta == "no"){
        eleccion = centinela;
      }
      else{
        cout << "Que disfrute de nuestra tienda\n";
      }
    
    cantidad=0;
    
    }
    else{
    do{ 
    cout << "Indique la cantidad: " ;
    cin >> cantidad;
    }while(cantidad <= 0);
    }
    //Te permite comprar lo que hay en existencia cuando le das un valor  mayor a la cantidad disponible
    if(cantidadDisponible[eleccion-1] < cantidad){
      string respuesta;
      cin.ignore();
      cout << "Solo contamos con " << cantidadDisponible[eleccion-1] << " productos. Desea solo comprar esta cantidad?: ";
      getline(cin,respuesta);
      if(respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
        //se realiza la compra todos los productos disponible
        double subtotal = 0;
        cantidad = cantidadDisponible[eleccion-1];//se asigna toda la cantidad disponible del producto a otra variable para manipularla
        subtotal = cantidad*precios[eleccion-1];//se multiplica la cantidad que se compro por el precio
        productosComprados[contadorCompras] = productos[eleccion-1];//se asigna el producto comprado a otro arreglo para registrarlo
        subtotalProducto[contadorCompras] = subtotal;//se asigna el precio por toda la cantidad que se compro
        cantidadComprada[contadorCompras] = cantidad;
        contadorCompras++;//se aumenta en uno la cantidad de productos comprados
        total = total + (subtotal);
      }
      else if(respuesta == "No" || respuesta == "NO" || respuesta == "no"){
      noHayProducto:
      cout << "Desea que cuando tengamos el producto le notifiquemos?  ";
      getline(cin,respuesta);
      if(respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
        cout << "Gracias por su preferencia\nLe notificaremos a la brevedad\n";
      }
      else{
        cout << "Gracias por su tiempo\n";
      }
      cout << "Desea seguir comprando: ";
      cin >> respuesta;
      if (respuesta == "No" || respuesta == "NO" || respuesta == "no"){
        eleccion = centinela;
      }
      else{
        cout << "\nContinue con su compra\n";
      }
      }
      
    }
    else if(cantidadDisponible[eleccion-1] >= cantidad){
      //se realiza cuando se da un valor menor a la cantidad disponible y se agregan a otro arreglo para registrar el producto que se compro

      double subtotal = 0;
      subtotal = cantidad*precios[eleccion-1];
      productosComprados[contadorCompras] = productos[eleccion-1];//se agrega el producto comprado a otro arreglo
      subtotalProducto[contadorCompras] = subtotal;//se agrega la multiplicacion del precio del producto por la cantidad
      cantidadComprada[contadorCompras] = cantidad;
      contadorCompras++;
      total = total + (subtotal);
    }
    cantidadDisponible[eleccion-1] -= cantidad;
  }
  }while(eleccion!=centinela);
  cin.ignore();
  if(productosComprados[0] == ""){
    return;
  }
  //cin.ignore();
  //Elimina productos de la lista
  string respuesta2;
  cout << "\nDesea eliminar un producto de la lista? ";
  getline(cin,respuesta2);
  cout << "\n";
  if(respuesta2 == "Si" || respuesta2 == "si" || respuesta2 == "SI"){
    for(int i = 0;i<contadorCompras;i++){
        cout << i+1<< ".\t"<< productosComprados[i] << "\t\t" << cantidadComprada[i] << "\t\t" << subtotalProducto[i] << endl;
    }
    int numeroRemover,cantidadRemover;
    do{
    cout << "\nCual producto(indique el numero)?: ";
    cin >> numeroRemover;
    }while(numeroRemover>contadorCompras || numeroRemover <=0);
    
    numeroRemover--;
    do{
    cout << "Cantidad a eliminar?: ";
    cin >> cantidadRemover;
    }while(cantidadRemover <= 0 || cantidadRemover > cantidadComprada[numeroRemover]);
    if(cantidadRemover == cantidadComprada[numeroRemover]){
    total -= subtotalProducto[numeroRemover];
    //les asigna a los valores que estan un lugar adelante una posicion anterior para poder eliminar un producto
    for (int i = numeroRemover;i<contadorCompras;i++){
      productosComprados[i] = productosComprados[i+1];
      cantidadComprada[i] = cantidadComprada[i+1];
      subtotalProducto[i] = subtotalProducto[i+1];
    } 
    //le asigna el valor de 0 y "" al ultimo item del arreglo porque se recorrio a un lugar antes
    productosComprados[contadorCompras-1] = "";
    cantidadComprada[contadorCompras-1] = 0;
    subtotalProducto[contadorCompras-1] = 0;
    cout << "\nProducto eliminado" << endl;
    for(int i = 0;i<(contadorCompras-1);i++){
        cout << i+1<< ".\t"<< productosComprados[i] << "\t\t Cantidad: " << cantidadComprada[i] << "\t\t $" << subtotalProducto[i] << endl;
    }
    }
    //es para cuando se da un cantidad menor para remover a la maxima que tiene el producto
    else if(cantidadRemover < cantidadComprada[numeroRemover]){
      total -= cantidadRemover*(subtotalProducto[numeroRemover] / cantidadComprada[numeroRemover]); 
      subtotalProducto[numeroRemover] -= cantidadRemover*(subtotalProducto[numeroRemover] / cantidadComprada[numeroRemover]);  
      cantidadComprada[numeroRemover] -= cantidadRemover;
      for(int i = 0;i<contadorCompras;i++){
        cout << i+1<< ".\t"<< productosComprados[i] << "\t\t Cantidad: " << cantidadComprada[i] << "\t\t $" << subtotalProducto[i] << endl;
    }
    
    }
    cin.ignore();
  }
  //Hace que al momento de tener 0 articulos te regrese a volver a comprar si asi lo deseas
  if(productosComprados[0] == "" && cantidadComprada[0] == 0){
    string realizarCompra;
    cout << "\nDesea realizar otra compra? ";
    getline(cin,realizarCompra);
    if(realizarCompra == "Si" || realizarCompra == "si" || realizarCompra == "SI")
    {
      for(int i =0;i<LENGTH;i++){
      productosComprados[i] = "";
      subtotalProducto[i] = 0;
      cantidadComprada[i] = 0;
      }
      goto iniciarCompra;
  }
  else{
    return;
  }
  }
  //te pide los datos dell cliente para poder realizar el envio
  cout << "\nDATOS DE ENVIO"<<endl;
  cout << "Ingrese sus datos para seguir con el pago" << endl;
  cliente1.obtenerDatos();


  cout << "\nSu total es de "  << total << endl;
  cout << "Su cargo se realizara a su cuenta" << endl;

  procesandoPago(total);
  
  string realizarCompra;
  cout << "\nDesea realizar otra compra? ";
  getline(cin,realizarCompra);
  if(realizarCompra == "Si" || realizarCompra == "si" || realizarCompra == "SI")
  {
      for(int i =0;i<LENGTH;i++){
      productosComprados[i] = "";
      subtotalProducto[i] = 0;
      cantidadComprada[i] = 0;
      }
      goto iniciarCompra;
  }
  else{
    return;
  }


}
