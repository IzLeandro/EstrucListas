#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cmath>
using namespace std;
//Para leer el archivo 
string readFile(string filepath){
    ifstream archivo(filepath.c_str());
    string buffer;
    string texto;
    cout<<buffer;
    while (getline(archivo, buffer)) {
        buffer=buffer+";";
        texto += buffer;
    }
    archivo.close();
    return texto;
}
//Nodos, clases y funciones principales de cada clase
//Nodo, clase y funciones principales de las habitaciones 
class nodoHabitaciones {
   public:
    nodoHabitaciones(string codHabitacion, string tipoCuarto, string numCamas, string precioHab, string estadoHab )
    {
       codigoHab= codHabitacion;
       cuarto=tipoCuarto;
       camas=numCamas;
       precio=precioHab;
       estado=estadoHab;
       siguiente = NULL;
       anterior =NULL;
       hab=NULL;
    }
nodoHabitaciones(string codHabitacion, string tipoCuarto, string numCamas, string precioHab, string estadoHab, nodoHabitaciones * signodoHabitaciones)
    {
       codigoHab= codHabitacion;
       cuarto=tipoCuarto;
       camas=numCamas;
       precio=precioHab;
       estado=estadoHab;
       siguiente = signodoHabitaciones;
    }
    string codigoHab;
    string cuarto;
    string camas;
    string precio;
    string estado;
    nodoHabitaciones *siguiente;
    nodoHabitaciones *anterior;
    nodoHabitaciones *hab;
   friend class listaHabitaciones;
};
typedef nodoHabitaciones *pnodoHabitaciones;
class listaHabitaciones {
   public:
    listaHabitaciones() { primero = NULL; }
    ~listaHabitaciones();
    bool ListaVaciaHabitaciones() { return primero == NULL; } 
    void crearListaHabitaciones();
    void InsertarFinalHabitaciones(string codHabitacion, string tipoCuarto, string numCamas, string precioHab, string estadoHab);
    void MostrarHabitaciones();
    void insertarHabitacion();
    int largoListaHabitaciones();
    void BorrarFinalHabitaciones();
    void BorrarInicioHabitaciones();
    void BorrarPosicionHabitaciones(int pos);
    int posHabitacion(string cod);
    void eliminarHabitacion();
    void modTipoCuarto();
    void modNumCamas();
    void modPrecioHa();
    void modEstadoHa();
    void modHab();
    void MostrarUltHab();
   private:
    pnodoHabitaciones primero;
};
listaHabitaciones::~listaHabitaciones()
{
   pnodoHabitaciones aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      delete aux;
   }
}
void listaHabitaciones::InsertarFinalHabitaciones(string codHabitacion, string tipoCuarto, string numCamas, string precioHab, string estadoHab)
{//Inserta al final de la lista una habitacion
   if (ListaVaciaHabitaciones())
   {
     primero = new nodoHabitaciones(codHabitacion,tipoCuarto,numCamas,precioHab,estadoHab);
     primero->anterior=NULL;     
   }
   else
     { pnodoHabitaciones aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoHabitaciones(codHabitacion,tipoCuarto,numCamas,precioHab,estadoHab);
        aux->siguiente->anterior=aux;       
      }    
}
int listaHabitaciones::largoListaHabitaciones(){//Retorna el largo de la lista de habitaciones
    int cont=0;
    pnodoHabitaciones aux;
    aux = primero;
    if(ListaVaciaHabitaciones()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
}
void listaHabitaciones::BorrarFinalHabitaciones()
{//Borra al final de la lista de habitaciones
    if (ListaVaciaHabitaciones()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL)
		 {
        	pnodoHabitaciones temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{
                pnodoHabitaciones aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
              pnodoHabitaciones temp = aux->siguiente;
              aux->siguiente= NULL;    
                delete temp;
            }
        }
}
void listaHabitaciones::BorrarInicioHabitaciones()
{//Borra al inicio de la lista de habitaciones
    if (ListaVaciaHabitaciones()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL) {
            pnodoHabitaciones temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{
                pnodoHabitaciones aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}
void listaHabitaciones:: BorrarPosicionHabitaciones(int pos)
{//Borra una posicion exacta en la lista de habitaciones
     if(ListaVaciaHabitaciones())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoListaHabitaciones())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicioHabitaciones();
        else
        {
          if (pos == largoListaHabitaciones())   
             BorrarFinalHabitaciones();
          else
          {   
            int cont=2;
            pnodoHabitaciones aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoHabitaciones temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
//Nodo, clase y funciones principales de los pisos
class nodoPisos {
   public:
    nodoPisos(string numPiso,string nomPiso, string cantHabitaciones)
    {
       numeroPiso = numPiso;
       nombrePiso= nomPiso;
       habitaciones=cantHabitaciones;
       siguiente = NULL;
       anterior =NULL;
       pisos=NULL;
       hab=NULL;
    }
nodoPisos(string numPiso,string nomPiso, string cantHabitaciones, nodoPisos * signodoPisos)
    {
       numeroPiso = numPiso;
       nombrePiso= nomPiso;
       habitaciones=cantHabitaciones;
       siguiente = signodoPisos;
    }
    string numeroPiso;
    string nombrePiso;
    string habitaciones;
    nodoPisos *siguiente;
    nodoPisos *anterior;
    nodoHabitaciones *hab;
    nodoPisos *pisos;
   friend class listaPisos;
};
typedef nodoPisos *pnodoPisos;
class listaPisos {
   public:
    listaPisos() { primero = NULL; }
    ~listaPisos();
     void InsertarFinalPisos(string numPiso,string nomPiso, string cantHabitaciones);
     bool ListaVaciaPisos() { return primero == NULL; } 
     void crearListaPisos();
     void MostrarListaPisos();
     void MostrarHabPisos();
     void insertarPiso();
     void BorrarPosicionPisos(int pos);
     void BorrarFinalPisos();
     void BorrarInicioPisos();
     int largoListaPisos();
     int posPiso(string num);
     void eliminarPiso();
     void modificarCantHab();
     void modificarNomPiso();
     void modHabNom();
     void MostrarCantHab();
     void MostrarUltPiso();
    pnodoPisos primero;
};
listaPisos::~listaPisos()
{
   pnodoPisos aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      delete aux;
   }
}
void listaPisos::InsertarFinalPisos(string numPiso,string nomPiso, string cantHabitaciones)
{//Inserta al final de la lista de pisos
   if (ListaVaciaPisos())
     {
     primero = new nodoPisos(numPiso,nomPiso,cantHabitaciones);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoPisos nuevo = new nodoPisos(numPiso,nomPiso,cantHabitaciones);;
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}
int listaPisos::largoListaPisos()
{//Retorna el largo de la lista de los pisos
    int cont=0;
    pnodoPisos aux = primero;
    if(ListaVaciaPisos())
    {
        return cont;
    }
    else
    {
        while(aux->siguiente!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    cont++;
    return cont;
    }
}
void listaPisos::BorrarFinalPisos()
{//Borra al final de la lista de pisos
    if (ListaVaciaPisos())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoPisos temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoPisos aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoPisos temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}
void listaPisos::BorrarInicioPisos()
{//Borra al inicio de la lista de pisos
    if (ListaVaciaPisos())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoPisos temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoPisos aux = primero->anterior;
        pnodoPisos temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}
void listaPisos:: BorrarPosicionPisos(int pos)
{//Borra una posicion exacta en la lista de pisos
  if(ListaVaciaPisos())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoListaPisos())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicioPisos();
      else
      {
       int cont=2;
       pnodoPisos aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoPisos temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior=aux;// FALTABA ESTA LINEA
       delete temp;
     }
    }
  }
}
//Nodo, clase y funciones principales de Hotel
class nodoHotel {
   public:
    nodoHotel(string codHotel,string nomHotel,string cantEstrellas)
    {
       codigo = codHotel;
       nombre = nomHotel;
       estrellas= cantEstrellas;
       siguiente = NULL;
       anterior =NULL;
       pisos=NULL;
    }
nodoHotel(string codHotel,string nomHotel,string cantEstrellas, nodoHotel * signodoD)
    {
       codigo = codHotel;
       nombre = nomHotel;
       estrellas= cantEstrellas;
       siguiente = signodoD;
    }
    string codigo;
    string nombre;
    string estrellas;
    nodoHotel *siguiente;
    nodoHotel *anterior;
    nodoPisos *pisos;     
   friend class listaHotel;
};
typedef nodoHotel *pnodoHotel;
class listaHotel {
   public:
    listaHotel() { primero =  NULL; }
    ~listaHotel();
    void InsertarFinalHotel(string codHotel,string nomHotel,string cantEstrellas);
    bool ListaVaciaHotel() { return primero == NULL; } 
    void crearListaHotel ();
    void MostrarHotel();
    void crearListaPisos ();
    void MostrarPisosHotel();
    void insertarHotel();
    int largoListaHotel();
    void BorrarFinalHotel();
    void BorrarInicioHotel();
    void BorrarPosicionHotel(int pos);
    int posHotel(string cod);
    void eliminarHotel();
    void modificarNombreHotel();
    void modificarEstrellasHotel();
    void modNomEstrellas();
    void MostrarCantEstrellas();
    void MostrarUltHotel();
    pnodoHotel primero;
};
listaHotel::~listaHotel()
{
   pnodoHotel aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaHotel::InsertarFinalHotel(string codHotel,string nomHotel,string cantEstrellas)
{//Inserta al final de la lista de hoteles
	if (ListaVaciaHotel())
	{
     primero = new nodoHotel(codHotel,nomHotel,cantEstrellas);
     primero->anterior=NULL;
 	}
	else
	{
	    pnodoHotel aux=primero;
	    while (aux->siguiente!=NULL)
	       aux= aux->siguiente;
	    aux->siguiente=new nodoHotel(codHotel,nomHotel,cantEstrellas);   
	    aux->siguiente->anterior=aux;
	}
}
int listaHotel::largoListaHotel(){//Retorna el largo de la lista de hoteles
    int cont=0;
    pnodoHotel aux;
    aux = primero;
    if(ListaVaciaHotel()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
}
void listaHotel::BorrarFinalHotel()
{//Borra al final de la lista de hoteles
    if (ListaVaciaHotel()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL)
		 {
        	pnodoHotel temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{
                pnodoHotel aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
              pnodoHotel temp = aux->siguiente;
              aux->siguiente= NULL;     
                delete temp;
            }
        }
}
void listaHotel::BorrarInicioHotel()
{//Borra al inicio de la lista de hoteles
    if (ListaVaciaHotel()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL) {
            pnodoHotel temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{
                pnodoHotel aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}
void listaHotel:: BorrarPosicionHotel(int pos)
{//Borra en una posicion exacta de la lista de hoteles
     if(ListaVaciaHotel())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoListaHotel())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicioHotel();
        else
        {
          if (pos == largoListaHotel())   
             BorrarFinalHotel();
          else
          {   
            int cont=2;
            pnodoHotel aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoHotel temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
//Nodo, clase y funciones de carro
class nodoCarro {
   public:
    nodoCarro(string placa,string modelo, string numAsientos,string anho,string precioC, string estadoCarro)
    {
       numeroPlaca = placa;
       modeloCar = modelo;
       numeroDeAsientos=numAsientos;
       anno=anho;
       precio = precioC;
       estadoDelCarro = estadoCarro;
       siguiente = NULL;
       anterior =NULL;
       car=NULL;
    }
nodoCarro(string placa,string modelo, string numAsientos,string anho,string precioC, string estadoCarro, nodoCarro * signodoCarro)
    {
       numeroPlaca = placa;
       modeloCar = modelo;
       numeroDeAsientos=numAsientos;
       anno=anho;
       precio = precioC;
       estadoDelCarro = estadoCarro;
       siguiente = signodoCarro;
    }
    string numeroPlaca;
    string modeloCar;
    string numeroDeAsientos;
    string anno;
    string precio;
    string estadoDelCarro;
    nodoCarro *siguiente;
    nodoCarro *anterior;
    nodoCarro *car;
   friend class listaCarros;
};
typedef nodoCarro *pnodoCarro;
class listaCarros {
   public:
    listaCarros() { primero =  NULL; }
    ~listaCarros();
    void crearListaCarros();
    void InsertarFinalCarros(string placa,string modelo, string numAsientos,string anho,string precioC, string estadoCarro);
    bool ListaVaciaCarros() { return primero == NULL; } 
    void BorrarPosicionCarros(int pos);
    int largoListaCarros();
    void BorrarFinalCarros();
    void BorrarInicioCarros();
    int posCarro(string placa);
    void eliminarCarro();
    void insertarCarro();
    void modNumAsien();
    void modPrecioCarro();
    void modEstCarro();
    void modCarro();
    void mostrarAsientosCarro();
    void mostrarModeloCarro();
    void mostrarAgnoCarro();
    void mostrarPrecioCarro();
    void mostrarEstCarro();
    void mostrarCarro();
    void mostrarUltCarro();
   private:
    pnodoCarro primero;
};
listaCarros::~listaCarros()
{
   pnodoCarro aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaCarros::InsertarFinalCarros(string placa,string modelo, string numAsientos,string anho,string precio, string estadoCarro)
{//Inserta al final de la lista de carros
   if (ListaVaciaCarros())
     {
     primero = new nodoCarro(placa,modelo,numAsientos,anho,precio,estadoCarro);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoCarro nuevo = new nodoCarro(placa,modelo,numAsientos,anho,precio,estadoCarro);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}
int listaCarros::largoListaCarros()
{//Retorna el largo de la lista de carros
    int cont=0;
    pnodoCarro aux = primero;
    if(ListaVaciaCarros())
    {
        return cont;
    }
    else
    {
        while(aux->siguiente!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    cont++;
    return cont;
    }
}
void listaCarros::BorrarFinalCarros()
{//Borra al final de la lista de carros
    if (ListaVaciaCarros())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoCarro temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoCarro aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoCarro temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}
void listaCarros::BorrarInicioCarros()
{//Borra al inicio de la lista de carros
    if (ListaVaciaCarros())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoCarro temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoCarro aux = primero->anterior;
        pnodoCarro temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}
void listaCarros:: BorrarPosicionCarros(int pos)
{//Borra en una posicion especifica de la lista de carros
  if(ListaVaciaCarros())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoListaCarros())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicioCarros();
      else
      {
       int cont=2;
       pnodoCarro aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoCarro temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior=aux;// FALTABA ESTA LINEA
       delete temp;
     }
    }
  }
}
//Nodo, clase lista y funciones principales de tipo flotilla
class nodoTF {
   public:
    nodoTF(string codTipo,string nombreTF,string cantCarrosTipo)
    {
       codigoTipo = codTipo;
       nombre = nombreTF;
       CantidadCarrosTipo=cantCarrosTipo;
       siguiente = NULL;
       anterior =NULL;
       tflotilla=NULL;
       car=NULL;
    }
nodoTF(string codTipo,string nombreTF,string cantCarrosTipo, nodoTF * signodoTF)
    {
       codigoTipo = codTipo;
       nombre = nombreTF;
       CantidadCarrosTipo=cantCarrosTipo;
       siguiente = signodoTF;
    }
    string  codigoTipo;
    string  nombre;
    string CantidadCarrosTipo;
    nodoTF *siguiente;
    nodoTF *anterior;
    nodoTF *tflotilla;
    nodoCarro *car;
   friend class listaTF;
};
typedef nodoTF *pnodoTF;
class listaTF {
   public:
    listaTF() { primero =  NULL; }
    ~listaTF();
    void crearListaTF();
    void InsertarFinalTF(string codTipo,string nombre,string cantCarrosTipo);
    bool ListaVaciaTF() { return primero == NULL; } 
    void MostrarCarrosTF();
    void BorrarPosicionTF(int pos);
    int largoListaTF();
    void BorrarFinalTF();
    void BorrarInicioTF();
    int posTF(string cod);
    void eliminarTF();
    void insertarTF();
    void modNombreTF();
    void modCantCarrosTF();
    void modNombreYCarrosTF();
    void mostrarUltTF();
    pnodoTF primero;
};
listaTF::~listaTF()
{
   pnodoTF aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaTF::InsertarFinalTF(string codTipo,string nombre,string cantCarrosTipo)
{//Inserta al final de la lista de tipos de flotilla
	if (ListaVaciaTF())
	{
     primero = new nodoTF(codTipo,nombre,cantCarrosTipo);
     primero->anterior=NULL;
 	}
	else
	{
	    pnodoTF aux=primero;
	    while (aux->siguiente!=NULL)
	       aux= aux->siguiente;
	    aux->siguiente=new nodoTF(codTipo,nombre,cantCarrosTipo);  
	    aux->siguiente->anterior=aux;
	}
}
int listaTF::largoListaTF(){//Retorna el largo de la lista de tipos de flotilla
    int cont=0;
    pnodoTF aux;
    aux = primero;
    if(ListaVaciaTF()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
}
void listaTF::BorrarFinalTF()
{//Borra al final de la lista de tipos de flotilla
    if (ListaVaciaTF()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL)
		 {
        	pnodoTF temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{
                pnodoTF aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
              pnodoTF temp = aux->siguiente;
              aux->siguiente= NULL;   
                delete temp;
            }
        }
}
void listaTF::BorrarInicioTF()
{//Borra al inicio de la lista de tipos de flotilla
    if (ListaVaciaTF()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == NULL) {
            pnodoTF temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{
                pnodoTF aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}
void listaTF:: BorrarPosicionTF(int pos)
{//Borra una posicion exacta de la lista de tipos de flotilla
     if(ListaVaciaTF())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoListaTF())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicioTF();
        else
        {
          if (pos == largoListaTF())   
             BorrarFinalTF();
          else
          {   
            int cont=2;
            pnodoTF aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoTF temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
// Nodo, clase lista y funciones de AgenciasCarros 
class nodoAgencia {
   public:
    nodoAgencia(string idAgencia, string nombreAgencia, string cantVehiculos)
    {
       id = idAgencia;
       nombre= nombreAgencia;
       vehiculos=cantVehiculos;
       siguiente = NULL;
       tflotilla=NULL;
    }
nodoAgencia(string idAgencia, string nombreAgencia,string cantVehiculos, nodoAgencia * signodo)
    {
       id = idAgencia;
       nombre= nombreAgencia;
       vehiculos=cantVehiculos;
       siguiente = signodo;
    }
    string id;
    string nombre;
    string vehiculos;
    nodoAgencia *siguiente;
    nodoTF *tflotilla;
   friend class listaAgencia;
};
typedef nodoAgencia *pnodoAgencia;
class listaAgencia {
   public:
    listaAgencia() { primero =  NULL; }
    ~listaAgencia();
    bool ListaVaciaAgencia() { return primero == NULL; } 
    void crearListaAgencia();
    void InsertarFinalAgencias(string idAgencia, string nombreAgencia, string cantVehiculos);
    void MostrarListaAgencia();
    void MostrarTFAgen();
    void borrarPosicionAgencia(int pos);
    int largoListaAgencia();
    void BorrarFinalAgencia();
    void BorrarInicioAgencia();
    int posAgencia(string id);
    void eliminarAgencia();
    void insertarAgencia();
    void modNombreAgen();
    void modCantCarrosAgen();
    void modNombreYCarrosAgen();
    void mostrarCantVehAgen();
    void mostrarUltAgen();
    pnodoAgencia primero;
};
listaAgencia::~listaAgencia()
{
   pnodoAgencia aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaAgencia::InsertarFinalAgencias(string idAgencia, string nombreAgencia, string cantVehiculos)
{//Inserta al final de la lista de agencias
	if (ListaVaciaAgencia())
	{
     pnodoAgencia nuevo= new nodoAgencia(idAgencia,nombreAgencia,cantVehiculos);
     primero = nuevo;
     nuevo->siguiente=primero;
 	}
	else
	{
		pnodoAgencia nuevo= new nodoAgencia(idAgencia,nombreAgencia,cantVehiculos);
	    pnodoAgencia aux=primero;
	    while (aux->siguiente!=primero)
	       aux= aux->siguiente;
	    nuevo->siguiente=primero;   
	    aux->siguiente=nuevo; 	
	}
}
int listaAgencia::largoListaAgencia(){//Retorna el largo de la lista de agencias
    int cont=0;
    pnodoAgencia aux= primero;
    if(ListaVaciaAgencia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;        
       aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
     }
}
void listaAgencia::BorrarFinalAgencia()
{//Borra al final de la lista de agencias
    if (ListaVaciaAgencia()){
     cout << "No hay elementos en la lista:" << endl;
   }else{
        if (primero->siguiente == primero)
		{
        	    pnodoAgencia temp=primero;
                primero= NULL;
                delete temp;
        }
		else {
                pnodoAgencia aux = primero;
                while (aux->siguiente->siguiente != primero) {
                    aux = aux->siguiente;
                }
              pnodoAgencia temp = aux->siguiente;
              aux->siguiente= primero;
                delete temp; 
            }
        }
}
void listaAgencia::BorrarInicioAgencia()
{//Borra al inicio de la lista de agencias
	if (ListaVaciaAgencia()){
     cout << "No hay elementos en la lista:" << endl;
   }else
   {
        if (primero->siguiente == primero)
		{
        	    pnodoAgencia temp=primero;
                primero= NULL;
                delete temp;
        }
		else
		{
                pnodoAgencia aux = primero;
                pnodoAgencia aux2 = primero;
                while (aux2->siguiente!=primero)
                	aux2=aux2->siguiente;
                primero=primero->siguiente;
				aux2->siguiente=primero;                
                delete aux;
        }
   }
}
void listaAgencia:: borrarPosicionAgencia(int pos)
{//Borra en una posicion especifica de la lista de agencias
	if(ListaVaciaAgencia()){
	        cout << "Lista vacia" <<endl;
	    }else{
	         if((pos>largoListaAgencia())||(pos<0)){
	        cout << "Error en posicion" << endl;
	        }else{
	        if(pos==1)
			{
	         BorrarInicioAgencia();
	        }
			else
			{
	          int cont=2;
	            pnodoAgencia aux=  primero;
	            while(cont<pos){
	             aux=aux->siguiente;
	             cont++;
	            }
	            pnodoAgencia temp=aux->siguiente;
	            aux->siguiente=aux->siguiente->siguiente;
	            delete temp;
	            }
	        }
	     }
}
//Nodo, clase lista y funciones de usuarios
class nodoUsuarios {
   public:
    nodoUsuarios(string pasaporte,string nombreU)
    {
       nPasaporte = pasaporte;
       nombre = nombreU;
       siguiente = NULL;
       anterior =NULL;
    }
nodoUsuarios(string pasaporte,string nombreU, nodoUsuarios * signodoUsuarios)
    {
       nPasaporte = pasaporte;
       nombre = nombreU;
       siguiente = signodoUsuarios;
    }
   private:
    string nPasaporte;
    string nombre;
    nodoUsuarios *siguiente;
    nodoUsuarios *anterior;
   friend class listaUsuarios;
};
typedef nodoUsuarios *pnodoUsuarios;
class listaUsuarios {
   public:
    listaUsuarios() { primero =  NULL; }
    ~listaUsuarios();
    bool ListaVaciaUsuarios() { return primero == NULL; } 
    void InsertarFinalUsuario(string pasaporte,string nombreU);
    void crearListaUsuarios();
    void MostrarListaUsuarios();
    bool validarCodigoU(string cod);
   private:
    pnodoUsuarios primero;
};
listaUsuarios::~listaUsuarios()
{
   pnodoUsuarios aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaUsuarios::InsertarFinalUsuario(string pasaporte,string nombreU)
{//Inserta al final en la lista de usuarios
   if (ListaVaciaUsuarios())
     {
     primero = new nodoUsuarios(pasaporte,nombreU);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoUsuarios nuevo = new nodoUsuarios(pasaporte,nombreU);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}
//Nodo, clase lista y funciones de Administradores de hotel
class nodoAdminH {
   public:
    nodoAdminH(string codAdminH,string nombreH)
    {
       CodigoAdministradorH = codAdminH;
       nombre = nombreH;
       siguiente = NULL;
       anterior =NULL;
    }
nodoAdminH(string codAdminH,string nombreH, nodoAdminH * signodoAdminH)
    {
       CodigoAdministradorH = codAdminH;
       nombre = nombreH;
       siguiente = signodoAdminH;
    }
   private:
    string CodigoAdministradorH;
    string nombre;
    nodoAdminH *siguiente;
    nodoAdminH *anterior;
   friend class listaAdminH;
};
typedef nodoAdminH *pnodoAdminH;
class listaAdminH {
   public:
    listaAdminH() { primero =  NULL; }
    ~listaAdminH();
    bool ListaVaciaAdminH() { return primero == NULL; } 
    void crearListaAdminH();
    void InsertarFinalAdminH(string codAdminH,string nombreH);
    void MostrarListaAdminH();
    bool validarCodigoH(string cod);
   private:
    pnodoAdminH primero;
};
listaAdminH::~listaAdminH()
{
   pnodoAdminH aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaAdminH::InsertarFinalAdminH(string codAdminH,string nombreH)
{//Inserta al final de la lista de administradores de hotel
   if (ListaVaciaAdminH())
     {
     primero = new nodoAdminH(codAdminH,nombreH);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoAdminH nuevo = new nodoAdminH(codAdminH,nombreH);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}
//Nodo, clase lista y funciones de administrador de agencias
class nodoAdminA {
   public:
    nodoAdminA(string codAdminA,string nombreA)
    {
       CodigoAdministradorA = codAdminA;
       nombre = nombreA;
       siguiente = NULL;
       anterior =NULL;
    }
nodoAdminA(int codAdminA,string nombreA, nodoAdminA * signodoAdminA)
    {
       CodigoAdministradorA = codAdminA;
       nombre = nombreA;
       siguiente = signodoAdminA;
    }
   private:
    string CodigoAdministradorA;
    string nombre;
    nodoAdminA *siguiente;
    nodoAdminA *anterior;
   friend class listaAdminA;
};
typedef nodoAdminA *pnodoAdminA;
class listaAdminA {
   public:
    listaAdminA() { primero =  NULL; }
    ~listaAdminA();
    void crearListaAdminA();
    bool ListaVaciaAdminA() { return primero == NULL; } 
    void InsertarFinalAdminA(string codAdminA,string nombreA);
    void MostrarListaAdminA();
    bool validarCodigoA(string cod);
   private:
    pnodoAdminA primero; 
};
listaAdminA::~listaAdminA()
{
   pnodoAdminA aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
}
void listaAdminA::InsertarFinalAdminA(string codAdminA,string nombreA)
{//Inserta al final de la lista de administradores de agencias
   if (ListaVaciaAdminA())
     {
     primero = new nodoAdminA(codAdminA,nombreA);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoAdminA nuevo = new nodoAdminA(codAdminA,nombreA);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}
//Creacion de listas y lectura de archivos
listaHotel hoteles;//Declaracion de la lista de hoteles
void listaHotel::crearListaHotel () {//Llena la lista de hoteles con lo que contiene el archivo
    string texto = readFile("Hoteles.txt");//Aqui lee el archivo
    string nombre="";
    string codigo="";
    string estrellas="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que tiene el archivo
        if (texto[i] == ';' && cont==0){
            codigo=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            nombre=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            estrellas=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        if (codigo!="" && nombre!="" && estrellas!=""){
        	int flag=0;
	        if (hoteles.ListaVaciaHotel()){
	        	hoteles.InsertarFinalHotel(codigo,nombre,estrellas);
			}
			else{
	        pnodoHotel aux=hoteles.primero;
	        while (aux!=NULL){
	        	if (aux->codigo==codigo)
	        		flag=1;
	        	aux=aux->siguiente;
				}	
			if (flag==0){
				hoteles.InsertarFinalHotel(codigo,nombre,estrellas);
		}
			codigo="";
			nombre="";
			estrellas="";
		}
		}
     }}
listaPisos pisos;//Declaracion de la lista de pisos
void listaPisos::crearListaPisos () {//Llena la lista de pisos con lo que contiene el archivo
    string texto = readFile("PisosHotel.txt");//Lee el archivo
    string codigoH="";
    string numPiso="";
    string nomPiso="";
    string numHab="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que tiene el archivo
        if (texto[i] == ';' && cont==0){
            codigoH=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            numPiso=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            nomPiso=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==3){
        	numHab=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
		}
        txt = txt + texto[i];
        int flag=0;
        if (codigoH!="" && numPiso!="" && nomPiso!="" && numHab!=""){
        	pnodoHotel aux=hoteles.primero;
        	while (aux!=NULL){
        		if (aux->codigo==codigoH){
        			if(aux->pisos==NULL){
        			pisos.InsertarFinalPisos(numPiso,nomPiso,numHab);
        			pnodoPisos aux2=pisos.primero;
        			while (aux2->siguiente!=pisos.primero){
        				aux2=aux2->siguiente;
					}
						aux->pisos=aux2;
					}
        			else{
        				pnodoPisos aux4=aux->pisos;
        				while (aux4!=NULL){
        				if (aux4->numeroPiso==numPiso){
        					flag=1;
						}
						aux4=aux4->pisos;
        			}
        				if (flag==0){
        				pisos.InsertarFinalPisos(numPiso,nomPiso,numHab);
        				pnodoPisos aux2=pisos.primero;
        				while (aux2->siguiente!=pisos.primero){
        				aux2=aux2->siguiente;
					}
						pnodoPisos aux5=aux->pisos;
						while (aux5->pisos!=NULL){
							aux5=aux5->pisos;
						}
						aux5->pisos=aux2;	
					}
					}	
				}
				aux=aux->siguiente;	
			}
				codigoH="";
        		numPiso="";
        		nomPiso="";
        		numHab="";
    }
		}
     }
listaHabitaciones habitaciones;//Declaracion de la lista de habitaciones
void listaHabitaciones::crearListaHabitaciones () {//Llena la lista de habitaciones con lo que contiene el archivo
    string texto = readFile("Habitaciones.txt");//Lee el archivo
    string codigoHo="";
    string numPiso="";
    string codigoHa="";
    string tipoCuarto="";
    string numCamas="";
    string precio="";
    string estado="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que contiene el archivo
        if (texto[i] == ';' && cont==0){
            codigoHo=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            numPiso=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            codigoHa=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==3){
        	tipoCuarto=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==4){
        	numCamas=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==5){
        	precio=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==6){
        	estado=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        int flag =0;
        if (codigoHo!="" && numPiso!="" && codigoHa!="" && tipoCuarto!="" && numCamas!="" && precio!="" && estado!=""){
        	pnodoHotel aux=hoteles.primero; 
        	while (aux!=NULL){
        		if (aux->codigo==codigoHo){
        			pnodoPisos aux2=pisos.primero;
        			while (aux2->siguiente!=pisos.primero){
        				if (aux2->numeroPiso==numPiso){
        					if(aux2->hab==NULL){
        						habitaciones.InsertarFinalHabitaciones(codigoHa, tipoCuarto, numCamas, precio, estado);
        						pnodoHabitaciones aux3=habitaciones.primero;
        						while (aux3->siguiente!=NULL){
        							aux3=aux3->siguiente;
								}
        						aux2->hab=aux3;
							}
							else{
								pnodoHabitaciones aux4=aux2->hab;
								while (aux4!=NULL){
									if (aux4->codigoHab==codigoHa){
										flag=1;	
									}
									aux4=aux4->hab;
									}
								if (flag==0){
									pnodoHabitaciones aux6=aux2->hab;
									while (aux6->hab!=NULL){
							
									aux6=aux6->hab;
									}
									
								habitaciones.InsertarFinalHabitaciones(codigoHa, tipoCuarto, numCamas, precio, estado);
        						pnodoHabitaciones aux5=habitaciones.primero;
        						while (aux5->siguiente!=NULL){
        							aux5=aux5->siguiente;
								}
        						aux6->hab=aux5;
							}
						
							}
        					
						}	
						aux2=aux2->siguiente;
					}
							if (aux2->numeroPiso==numPiso){
        					if(aux2->hab==NULL){
        						habitaciones.InsertarFinalHabitaciones(codigoHa, tipoCuarto, numCamas, precio, estado);
        						pnodoHabitaciones aux3=habitaciones.primero;
        						while (aux3->siguiente!=NULL){
        							aux3=aux3->siguiente;
								}
        						aux2->hab=aux3;
							}
							else{
								pnodoHabitaciones aux4=aux2->hab;
								while (aux4!=NULL){
									if (aux4->codigoHab==codigoHa){
										flag=1;	
									}
									aux4=aux4->hab;
									}
								if (flag==0){
									pnodoHabitaciones aux6=aux2->hab;
									while (aux6->hab!=NULL){
							
									aux6=aux6->hab;
									}
									
								habitaciones.InsertarFinalHabitaciones(codigoHa, tipoCuarto, numCamas, precio, estado);
        						pnodoHabitaciones aux5=habitaciones.primero;
        						while (aux5->siguiente!=NULL){
        							aux5=aux5->siguiente;
								}
        						aux6->hab=aux5;
							}
						
							}
        					
						}
				}
				aux=aux->siguiente;
			}
			codigoHo="";
			numPiso="";
			codigoHa="";
			tipoCuarto="";
			numCamas="";
			precio="";
			estado="";
	   }
}
}
listaAgencia agencias;//Declara la lista de agencias
void listaAgencia::crearListaAgencia () {//Llena la lista de agencias con lo que contiene el archivo
    string texto = readFile("Agencias.txt");//Lee el archivo
    string id="";
    string nombre="";
    string vehiculos="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que contiene el archivo
        if (texto[i] == ';' && cont==0){
            id=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            nombre=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            vehiculos=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        
        txt = txt + texto[i];
        if (id!="" && nombre!="" && vehiculos!=""){
        	int flag=0;
	        if (agencias.ListaVaciaAgencia()){
	        	agencias.InsertarFinalAgencias(id,nombre,vehiculos);
			}
			else{
	        pnodoAgencia aux=agencias.primero;
	        while (aux->siguiente!=agencias.primero){
	        	if (aux->id==id)
	        		flag=1;
	        	aux=aux->siguiente;
				}
			if (aux->id==id)
	        		flag=1;	
			if (flag==0){
				agencias.InsertarFinalAgencias(id,nombre,vehiculos);
				}
	}
			id="";
			nombre="";
			vehiculos="";
		}
     }}
listaTF tiposFlotillas;//Declara la lista de tipos de flotilla
void listaTF::crearListaTF () {//Llena la lista de tipos de flotilla con lo que contiene el archivo
    string texto = readFile("TipoFlotilla.txt");//Lee el archivo
    string id="";
    string codigo="";
    string nombre="";
    string carros="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que contiene el archivo
        if (texto[i] == ';' && cont==0){
            id=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            codigo=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            nombre=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==3){
        	carros=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
		}
        txt = txt + texto[i];
        int flag=0;
        if (id!="" && codigo!="" && nombre!="" && carros!=""){
        	pnodoAgencia aux1=agencias.primero;
        	while (aux1->siguiente!=agencias.primero){
        		if (aux1->id==id){
        			if(aux1->tflotilla==NULL){
        			tiposFlotillas.InsertarFinalTF(codigo,nombre,carros);
        			pnodoTF aux2=tiposFlotillas.primero;
        			while (aux2->siguiente!=NULL){
        				aux2=aux2->siguiente;
					}
						aux1->tflotilla=aux2;
					}
        			else{
        				pnodoTF aux4=aux1->tflotilla;
        				while (aux4!=NULL){
        				if (aux4->codigoTipo==codigo){
        					flag=1;
						}
						aux4=aux4->tflotilla;
        			}
        				if (flag==0){
        				tiposFlotillas.InsertarFinalTF(codigo,nombre,carros);
        				pnodoTF aux2=tiposFlotillas.primero;
        				while (aux2->siguiente!=NULL){
        				aux2=aux2->siguiente;
					}
						pnodoTF aux5=aux1->tflotilla;
						while (aux5->tflotilla!=NULL){
							aux5=aux5->tflotilla;
						}
						aux5->tflotilla=aux2;
					}
					}	
				}
				aux1=aux1->siguiente;	
			}
			if (aux1->id==id){
        			if(aux1->tflotilla==NULL){
        			tiposFlotillas.InsertarFinalTF(codigo,nombre,carros);
        			pnodoTF aux2=tiposFlotillas.primero;
        			while (aux2->siguiente!=NULL){
        				aux2=aux2->siguiente;
					}
						aux1->tflotilla=aux2;
					}
        			else{
        				pnodoTF aux4=aux1->tflotilla;
        				while (aux4!=NULL){
        				if (aux4->codigoTipo==codigo){
        					flag=1;
						}
						aux4=aux4->tflotilla;
        			}
        				if (flag==0){
        				tiposFlotillas.InsertarFinalTF(codigo,nombre,carros);
        				pnodoTF aux2=tiposFlotillas.primero;
        				while (aux2->siguiente!=NULL){
        				aux2=aux2->siguiente;
					}
						pnodoTF aux5=aux1->tflotilla;
						while (aux5->tflotilla!=NULL){
							aux5=aux5->tflotilla;
						}
						aux5->tflotilla=aux2;	
					}
					}	
				}
				id="";
        		codigo="";
        		nombre="";
        		carros="";
    }
		}
     }   
listaCarros carros;//Declara la lista de carros
void listaCarros::crearListaCarros() {//Llena la lista de carros con lo que contiene el archivo
    string texto = readFile("Carros.txt");//Lee el archivo
    string id="";
    string codTF="";
    string placa="";
    string modelo="";
    string asientos="";
    string agno="";
    string precio="";
    string estado="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que contiene el archivo
        if (texto[i] == ';' && cont==0){
            id=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            codTF=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==2){
            placa=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==3){
        	modelo=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==4){
        	asientos=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==5){
        	agno=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==6){
        	precio=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else if (texto[i] == ';' && cont==7){
        	estado=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        int flag =0;
        int flag2=0;
        if (id!="" && codTF!="" && placa!="" && modelo!="" && asientos!="" && agno!="" && precio!="" && estado!=""){
        	pnodoAgencia aux=agencias.primero; 
        	while (aux->siguiente!=agencias.primero){
        		if (aux->id==id){
        			pnodoTF aux2=tiposFlotillas.primero;
        			while (aux2!=NULL){
        				if (aux2->codigoTipo==codTF){
        					if(aux2->car==NULL){
        						if (carros.ListaVaciaCarros()){
        							carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							aux2->car=aux3;
								}
								else{
									pnodoCarro aux4=carros.primero;
									while(aux4->siguiente!=carros.primero){
										if (aux4->numeroPlaca==placa){
											flag2=1;
										}
										aux4=aux4->siguiente;
								}
									if (aux4->numeroPlaca==placa){
											flag2=1;
										}
									if (flag2==0){
									carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							while(aux4->siguiente!=carros.primero){
        								aux4=aux4->siguiente;
        								}
										aux2->car=aux4;
									}
								}
							}
							else{
								pnodoCarro aux4=carros.primero;
								while(aux4->siguiente!=carros.primero){
									if (aux4->numeroPlaca==placa){
											flag=1;
										}
										aux4=aux4->siguiente;
									}
									if (aux4->numeroPlaca==placa){
											flag=1;
										}
								if (flag==0){
									carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							while(aux4->siguiente!=carros.primero){
        								aux4=aux4->siguiente;
        								}
										aux2->car=aux4;
									}
							}	
					}
						aux2=aux2->siguiente;
			}
		}
				aux=aux->siguiente;
			}
			if (aux->id==id){
        			pnodoTF aux2=tiposFlotillas.primero;
        			while (aux2!=NULL){
        				if (aux2->codigoTipo==codTF){
        					if(aux2->car==NULL){
        						if (carros.ListaVaciaCarros()){
        							carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							aux2->car=aux3;
								}
								else{
									pnodoCarro aux4=carros.primero;
									while(aux4->siguiente!=carros.primero){
										if (aux4->numeroPlaca==placa){
											flag2=1;
										}
										aux4=aux4->siguiente;
								}
									if (aux4->numeroPlaca==placa){
											flag2=1;
										}
									if (flag2==0){
									carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							while(aux4->siguiente!=carros.primero){
        								aux4=aux4->siguiente;
        								}
										aux2->car=aux4;	
									}
								}
							}
							else{
								pnodoCarro aux4=carros.primero;
								while(aux4->siguiente!=carros.primero){
									if (aux4->numeroPlaca==placa){
											flag=1;
										}
										aux4=aux4->siguiente;
									}
									if (aux4->numeroPlaca==placa){
											flag=1;
										}
								if (flag==0){
									carros.InsertarFinalCarros(placa, modelo, asientos, agno,precio, estado);
        							pnodoCarro aux3=carros.primero;
        							while(aux4->siguiente!=carros.primero){
        								aux4=aux4->siguiente;
        								}
										aux2->car=aux4;
									}
							}	
					}
						aux2=aux2->siguiente;
			}
		}
			id="";
			codTF="";
			placa="";
			modelo="";
			asientos="";
			agno="";
			precio="";
			estado="";
		}
}
}
listaUsuarios usuarios;//Declara la lista de usuarios
void listaUsuarios::crearListaUsuarios(){//Llena la lista de usuarios con lo que contiene el archivo
	string texto = readFile("Usuarios.txt");//Lee el archivo
    string pasaporte="";
    string nombre="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre lo que contiene el archivo
        if (texto[i] == ';' && cont==0){
            pasaporte=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            nombre=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        if (pasaporte!="" && nombre!=""){
        	int flag=0;
        	if (usuarios.ListaVaciaUsuarios()){
        		usuarios.InsertarFinalUsuario(pasaporte,nombre);
			}
			else{
				pnodoUsuarios aux=usuarios.primero;
				while (aux->siguiente!=usuarios.primero){
					if (aux->nPasaporte==pasaporte){
						flag=1;
					}
					aux=aux->siguiente;
				}
				if (aux->nPasaporte==pasaporte){
						flag=1;
					}
				if (flag==0){
					usuarios.InsertarFinalUsuario(pasaporte,nombre);
				}
			}
        pasaporte="";
        nombre="";  	
		}   
}
}
listaAdminH adminH;//Declara la lista de administradores de hotel
void listaAdminH::crearListaAdminH(){//Llena la lista de administradores de hotel con lo que contiene el archivo
	string texto = readFile("AdministradorH.txt");//Lee el archivo
    string cod="";
    string nombre="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre el archivo
        if (texto[i] == ';' && cont==0){
            cod=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            nombre=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        if (cod!="" && nombre!=""){
        	int flag=0;
        	if (adminH.ListaVaciaAdminH()){
        		adminH.InsertarFinalAdminH(cod,nombre);
			}
			else{
				pnodoAdminH aux=adminH.primero;
				while (aux->siguiente!=adminH.primero){
					if (aux->CodigoAdministradorH==cod){
						flag=1;
					}
					aux=aux->siguiente;
				}
				if (aux->CodigoAdministradorH==cod){
						flag=1;
					}
				if (flag==0){
					adminH.InsertarFinalAdminH(cod,nombre);
				}
			}
        cod="";
        nombre="";  	
		}   
}
}
listaAdminA adminA;//Declara la variable de administrador de agencia
void listaAdminA::crearListaAdminA(){//Llena la lista de administrador de agencias con lo que contiene el archivo
	string texto = readFile("AdministradorA.txt");//Lee el archivo
    string cod="";
    string nombre="";
    int contador=0;
    int cont=0;
    string txt;
    for (int i = 0; i <= texto.length(); i++){//Recorre el archivo
        if (texto[i] == ';' && cont==0){
            cod=txt;
            txt.clear();
            contador++;
            cont++;
            continue; // Asi evitamos agregar el ; al texto
        }
        else  if (texto[i] == ';' && cont==1){
            nombre=txt;
            txt.clear();
            contador++;
            cont=0;
            continue; // Asi evitamos agregar el ; al texto
        }
        txt = txt + texto[i];
        if (cod!="" && nombre!=""){
        	int flag=0;
        	if (adminA.ListaVaciaAdminA()){
        		adminA.InsertarFinalAdminA(cod,nombre);
			}
			else{
				pnodoAdminA aux=adminA.primero;
				while (aux->siguiente!=adminA.primero){
					if (aux->CodigoAdministradorA==cod){
						flag=1;
					}
					aux=aux->siguiente;
				}
				if (aux->CodigoAdministradorA==cod){
						flag=1;
					}
				if (flag==0){
					adminA.InsertarFinalAdminA(cod,nombre);
				}
			}
        cod="";
        nombre="";  	
		}   
}
}
//Modificaciones 
void listaHotel::modificarNombreHotel(){
	//Modifica el nombre del hotel escogido 
	string codH;
	string nomH;
	int flag;
	pnodoHotel aux=hoteles.primero;
	cout<<"Digite el codigo del hotel a modificar: ";
	cin>>codH;
	while (aux){
		if (aux->codigo==codH){
			flag=1;
			cout<<"Digite el nuevo nombre del hotel: ";
			cin>>nomH;
			aux->nombre=nomH;
			cout<<"Nombre de hotel modificado"<<endl;	
		}
		aux=aux->siguiente;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaHotel::modificarEstrellasHotel(){
	//Modifica la cantidad de estrellas del hotel escogido  
	string codH;
	string estrellas;
	int flag=0;
	pnodoHotel aux=hoteles.primero;
	cout<<"Digite el codigo del hotel a modificar: ";
	cin>>codH;
	while (aux){
		if (aux->codigo==codH){
			flag=1;
			cout<<"Digite la nueva cantidad de estrellas del hotel: ";
			cin>>estrellas;
			aux->estrellas=estrellas;
			cout<<"Cantidad de estrellas modificada"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaHotel::modNomEstrellas(){
	//Menu para modificar un hotel
	string op;
	cout<<"1. Modificar el nombre de un hotel"<<endl;
	cout<<"2. Modificar la cantidad de estrellas de un hotel "<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		hoteles.modificarNombreHotel();
	}
	else if(op=="2"){
		hoteles.modificarEstrellasHotel();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
void listaPisos::modificarCantHab(){//Modifica la cantidad de habitaciones de un piso escogido  
	string codH;
	string numP;
	string cantH;
	int flag=0;
	int flag2=0;
	pnodoHotel aux=hoteles.primero;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	while(aux){
		if(aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero del piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite la nueva cantidad de habitaciones: ";
					cin>>cantH;
					aux2->habitaciones=cantH;
					cout<<"Cantidad de habitaciones modificada"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2=0)
			cout<<"El piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"El hotel no existe"<<endl;
}
void listaPisos::modificarNomPiso(){//Modifica el nombre de un piso escogido  
	string codH;
	string numP;
	string nomP;
	int flag=0;
	int flag2=0;
	pnodoHotel aux=hoteles.primero;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	while(aux){
		if(aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero del piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el nuevo nombre del piso: ";
					cin>>nomP;
					aux2->nombrePiso=nomP;
					cout<<"Nombre del piso modificado"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2=0)
			cout<<"El piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"El hotel no existe"<<endl;
}
void listaPisos::modHabNom(){//Menu para modificar un piso
	string op;
	cout<<"1. Modificar el nombre de un piso"<<endl;
	cout<<"2. Modificar la cantidad de habitaciones de un piso "<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		pisos.modificarNomPiso();
	}
	else if(op=="2"){
		pisos.modificarCantHab();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}	
void listaHabitaciones::modTipoCuarto(){//Modifica el tipo de cuarto de una habitacion escogida
	string codHo;
	string numP;
	string codHa;
	string tcuarto;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codHo;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codHo){
			flag=1;
			cout<<"Digite el numero de piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el codigo de la habitacion a modificar: ";
					cin>>codHa;
					pnodoHabitaciones aux3=aux2->hab;
					while(aux3){
						if(aux3->codigoHab==codHa){
							flag3=1;
							cout<<"Digite el nuevo tipo de cuarto: ";
							cin>>tcuarto;
							aux3->cuarto=tcuarto;
							cout<<"Habitacion modificada"<<endl;
						}
						aux3=aux3->hab;
					}
					if (flag3==0)
					cout<<"Habitacion no existe"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"Piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"Hotel no existe"<<endl;	
}
void listaHabitaciones::modNumCamas(){//Modifica el numero de camas de una habitacion escogida
	string codHo;
	string numP;
	string codHa;
	string numC;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codHo;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codHo){
			flag=1;
			cout<<"Digite el numero de piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el codigo de la habitacion a modificar: ";
					cin>>codHa;
					pnodoHabitaciones aux3=aux2->hab;
					while(aux3){
						if(aux3->codigoHab==codHa){
							flag3=1;
							cout<<"Digite el nuevo numero de camas: ";
							cin>>numC;
							aux3->camas=numC;
							cout<<"Habitacion modificada"<<endl;
						}
						aux3=aux3->hab;
					}
					if (flag3==0)
					cout<<"Habitacion no existe"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"Piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"Hotel no existe"<<endl;	
}
void listaHabitaciones::modPrecioHa(){//Modifica el precio de una habitacion escogida
	string codHo;
	string numP;
	string codHa;
	string precio;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codHo;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codHo){
			flag=1;
			cout<<"Digite el numero de piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el codigo de la habitacion a modificar: ";
					cin>>codHa;
					pnodoHabitaciones aux3=aux2->hab;
					while(aux3){
						if(aux3->codigoHab==codHa){
							flag3=1;
							cout<<"Digite el nuevo precio: ";
							cin>>precio;
							aux3->precio=precio;
							cout<<"Habitacion modificada"<<endl;
						}
						aux3=aux3->hab;
					}
					if (flag3==0)
					cout<<"Habitacion no existe"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"Piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"Hotel no existe"<<endl;	
}
void listaHabitaciones::modEstadoHa(){//Modifica el estado de una habitacion escogida
	string codHo;
	string numP;
	string codHa;
	string estado;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codHo;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codHo){
			flag=1;
			cout<<"Digite el numero de piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el codigo de la habitacion a modificar: ";
					cin>>codHa;
					pnodoHabitaciones aux3=aux2->hab;
					while(aux3){
						if(aux3->codigoHab==codHa){
							flag3=1;
							cout<<"Digite el nuevo estado: ";
							cin>>estado;
							aux3->estado=estado;
							cout<<"Habitacion modificada"<<endl;
						}
						aux3=aux3->hab;
					}
					if (flag3==0)
					cout<<"Habitacion no existe"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"Piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"Hotel no existe"<<endl;	
}
void listaHabitaciones::modHab(){//Menu oara modificar una habitacion
	string op;
	cout<<"1. Modificar el tipo de cuarto"<<endl;
	cout<<"2. Modificar el numero de camas del cuarto"<<endl;
	cout<<"3. Modificar el precio del cuarto"<<endl;
	cout<<"4. Modificar el estado del cuarto"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		habitaciones.modTipoCuarto();
	}
	else if(op=="2"){
		habitaciones.modNumCamas();
	}
	else if(op=="3"){
		habitaciones.modPrecioHa();
	}
	else if(op=="4"){
		habitaciones.modEstadoHa();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
void listaAgencia::modNombreAgen(){//Modifica el nombre de una agencia escogida
	string id;
	int flag=0;
	string nom;
	cout<<"Digite la identificacion de la agencia a modificar: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el nuevo nombre de la agencia: ";
			cin>>nom;
			aux->nombre=nom;
			cout<<"Agencia modificada"<<endl;
		}
		aux=aux->siguiente;
	}
	if (aux->id==id){
			flag=1;
			cout<<"Digite el nuevo nombre de la agencia: ";
			cin>>nom;
			aux->nombre=nom;
			cout<<"Agencia modificada"<<endl;
		}
	if (flag==0)
	cout<<"La agencia no existe"<<endl;
}
void listaAgencia::modCantCarrosAgen(){//Modifica la cantidad de carros de una agencia escogida
	string id;
	int flag=0;
	string cantC;
	cout<<"Digite la identificacion de la agencia a modificar: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite la nueva cantidad de carros de la agencia: ";
			cin>>cantC;
			aux->vehiculos=cantC;
			cout<<"Agencia modificada"<<endl;
		}
		aux=aux->siguiente;
	}
	if (aux->id==id){
			flag=1;
			cout<<"Digite la nueva cantidad de carros de la agencia: ";
			cin>>cantC;
			aux->vehiculos=cantC;
			cout<<"Agencia modificada"<<endl;
		}
	if (flag==0)
	cout<<"La agencia no existe"<<endl;
}
void listaAgencia::modNombreYCarrosAgen(){//Menu para modificar una agencia
	string op;
	cout<<"1. Modificar el nombre de una agencia"<<endl;
	cout<<"2. Modificar el numero de carros de una agencia"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		agencias.modNombreAgen();
	}
	else if(op=="2"){
		agencias.modCantCarrosAgen();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
void listaTF::modNombreTF(){//Modifica el nombre de un tipo de flotilla escogida
	string id;
	string codTF;
	int flag=0;
	int flag2=0;
	string nom;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite el nuevo nombre del tipo de flotilla: ";
					cin>>nom;
					aux2->nombre=nom;
					cout<<"Tipo de flotilla modificada"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if(flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
}
aux=aux->siguiente;
}	
if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite el nuevo nombre del tipo de flotilla: ";
					cin>>nom;
					aux2->nombre=nom;
					cout<<"Tipo de flotilla modificada"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if(flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
}
if (flag==0)
cout<<"La agencia no existe"<<endl;
}
void listaTF::modCantCarrosTF(){//Modifica la cantidad de carros de un tipo de flotilla escogida
	string id;
	string codTF;
	int flag=0;
	int flag2=0;
	string cantC;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la nueva cantidad de carros del tipo de flotilla: ";
					cin>>cantC;
					aux2->CantidadCarrosTipo=cantC;
					cout<<"Tipo de flotilla modificada"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if(flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
}
aux=aux->siguiente;
}	
if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la nueva cantidad de carros del tipo de flotilla: ";
					cin>>cantC;
					aux2->CantidadCarrosTipo=cantC;
					cout<<"Tipo de flotilla modificada"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if(flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
}
if (flag==0)
cout<<"La agencia no existe"<<endl;
}		   
void listaTF::modNombreYCarrosTF(){//Menu para modificar un tipo de flotilla
	string op;
	cout<<"1. Modificar el nombre de un tipo de flotilla"<<endl;
	cout<<"2. Modificar el numero de carros de un tipo de flotilla"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		tiposFlotillas.modNombreTF();
	}
	else if(op=="2"){
		tiposFlotillas.modCantCarrosTF();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
void listaCarros::modNumAsien(){//Modifica el numero de asientos de un carro escogido
	string id;
	string codTF;
	int flag=0;
	int flag2=0;
	int flag3=0;
	string placa;
	string numA;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;	
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo numero de asientos: ";
							cin>>numA;
							aux3->numeroDeAsientos=numA;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	aux=aux->siguiente;
}
if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo numero de asientos: ";
							cin>>numA;
							aux3->numeroDeAsientos=numA;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	if (flag==0)
	cout<<"La agencia no existe"<<endl;
}
void listaCarros::modPrecioCarro(){//Modifica el precio de un carro escogido
	string id;
	string codTF;
	int flag=0;
	int flag2=0;
	int flag3=0;
	string placa;
	string precio;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;	
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo precio del carro: ";
							cin>>precio;
							aux3->precio=precio;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	aux=aux->siguiente;
}
if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo precio del carro: ";
							cin>>precio;
							aux3->precio=precio;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	if (flag==0)
	cout<<"La agencia no existe"<<endl;
}
void listaCarros::modEstCarro(){//Modifica el estado de un carro escogido
	string id;
	string codTF;
	int flag=0;
	int flag2=0;
	int flag3=0;
	string placa;
	string estado;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;	
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo estado del carro: ";
							cin>>estado;
							aux3->estadoDelCarro=estado;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	aux=aux->siguiente;
}
if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a modificar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Digite el nuevo estado del carro: ";
							cin>>estado;
							aux3->estadoDelCarro=estado;
							cout<<"Carro modificado"<<endl;
						}
					aux3=aux3->car;	
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
			}
			aux2=aux2->tflotilla;
		}
		if(flag2==0)
		cout<<"El tipo de flotilla no existe"<<endl;
	}
	if (flag==0)
	cout<<"La agencia no existe"<<endl;
}
void listaCarros::modCarro(){//Menu para modificar un carro
	string op;
	cout<<"1. Modificar el numero de asientos de un carro"<<endl;
	cout<<"2. Modificar el precio de un carro"<<endl;
	cout<<"3. Modificar el estado de un carro"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		carros.modNumAsien();
	}
	else if(op=="2"){
		carros.modPrecioCarro();
	}
	else if(op=="3"){
		carros.modEstCarro();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
//Reportes
void listaHotel::MostrarHotel()
//Muestra todos los hoteles registrados
{	cout<<endl;
	cout<<"Hoteles"<<endl;
	cout<<endl;
   pnodoHotel aux=hoteles.primero;
   while(aux) {
      cout << "Codigo: "+aux->codigo<<endl;
	  cout << "Nombre: "+aux->nombre<<endl;  
	  cout << "Estrellas: "+aux->estrellas<<endl;  
	  cout<<endl;
      aux = aux->siguiente;
   }
   cout << endl;
}
void listaHotel::MostrarPisosHotel(){
//Muestra todos los pisos de un hotel
	string cod;
	int flag=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>cod;
	cout<<endl;
	pnodoHotel aux=hoteles.primero;
	while(aux!=NULL){
		if (aux->codigo==cod){
			flag=1;
			cout<<"Pisos"<<endl;
			cout<<endl;
			pnodoPisos aux2=aux->pisos;
			while (aux2!=NULL){
			cout<<"Numero de piso: "+aux2->numeroPiso<<endl;
			cout<<"Nombre: "+aux2->nombrePiso<<endl;
			cout<<"Cantidad de habitaciones: "+aux2->habitaciones<<endl;
			cout<<endl;
			aux2=aux2->pisos;
			}
		}
		aux=aux->siguiente;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
	cout<<endl;
}
void listaPisos::MostrarHabPisos(){
	//Muestra todas las habitaciones de un piso de un hotel
	int flag=0;
	int flag2=0;
	string codH;
	string codP;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux=hoteles.primero;
	while(aux!=NULL){
		if (aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero de piso: ";
			cin>>codP;
			pnodoPisos aux2=aux->pisos;
			while(aux2!=NULL){
				if(aux2->numeroPiso==codP){
					flag2=1;
					cout<<endl;
					cout<<"Habitaciones"<<endl;
					cout<<endl;
					pnodoHabitaciones aux3=aux2->hab;
					while (aux3!=NULL){
						  cout << "Codigo: "+aux3->codigoHab<<endl;
						  cout << "Tipo: "+aux3->cuarto<<endl;  
						  cout << "Camas: "+aux3->camas<<endl; 
						  cout << "Precio: "+aux3->precio<<endl;  
						  cout << "Estado: "+aux3->estado<<endl;  
						  cout<<endl;
      					  aux3 = aux3->hab;
					}
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"El piso no existe"<<endl;		
}
aux=aux->siguiente;	
}   
if (flag==0)
cout<<"El hotel no existe"<<endl;
}
void listaHotel::MostrarCantEstrellas(){//Muestra la cantidad de estrellas de un hotel
	string codH;
	int flag=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codH){
			flag=1;
			cout<<"El hotel tiene "+aux->estrellas+" estrellas"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaPisos::MostrarCantHab(){//Muestra la cantidad de habitaciones de un piso de un hotel
	string codH;
	string numP;
	int flag=0;
	int flag2=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if(aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero del piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while (aux2){
				if (aux2->numeroPiso==numP){
					flag2=1;
					cout<<"El piso "+aux2->numeroPiso+" tiene "+aux2->habitaciones+" habitaciones"<<endl;
				}
				aux2=aux2->pisos;
			}
			if (flag2==0)
			cout<<"El piso no existe"<<endl;
		}
		aux=aux->siguiente;
	}
	if (flag==0)
	cout<<"El hotel no existe"<<endl;
}
void listaHotel::MostrarUltHotel(){//Muestra el ultimo hotel registrado
	pnodoHotel aux=hoteles.primero;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	cout<<endl;
	cout << "Codigo: "+aux->codigo<<endl;
	cout << "Nombre: "+aux->nombre<<endl;  
	cout << "Estrellas: "+aux->estrellas<<endl;  
	cout<<endl;
}
void listaPisos::MostrarUltPiso(){//Muestra el ultimo piso registrado
	pnodoPisos aux=pisos.primero;
	while(aux->siguiente!=pisos.primero){
		aux=aux->siguiente;
	}
	cout<<endl;
	cout<<"Numero de piso: "+aux->numeroPiso<<endl;
	cout<<"Nombre: "+aux->nombrePiso<<endl;
	cout<<"Cantidad de habitaciones: "+aux->habitaciones<<endl;
	cout<<endl;
}
void listaHabitaciones::MostrarUltHab(){//Muestra la ultima habitacion registrada
	pnodoHabitaciones aux=habitaciones.primero;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	  cout<<endl;
	  cout << "Codigo: "+aux->codigoHab<<endl;
	  cout << "Tipo: "+aux->cuarto<<endl;  
	  cout << "Camas: "+aux->camas<<endl; 
	  cout << "Precio: "+aux->precio<<endl;  
	  cout << "Estado: "+aux->estado<<endl;  
	  cout<<endl;
}	
void listaAgencia::MostrarListaAgencia(){//Muestra todas las agencias registradas
   pnodoAgencia aux=agencias.primero;
   while(aux->siguiente!=primero)
     {                     
      	cout <<"ID: "+aux->id<<endl;
	  	cout<<"Nombre: "+aux->nombre<<endl;
	  	cout<<"Cantidad de vehiculos: "+aux->vehiculos<<endl;
		cout<<endl;
      	aux = aux->siguiente;
     }
    	cout <<"ID: "+aux->id<<endl;
	  	cout<<"Nombre: "+aux->nombre<<endl;
	  	cout<<"Cantidad de vehiculos: "+aux->vehiculos<<endl;
		cout<<endl;
}
void listaAgencia::MostrarTFAgen(){//Muestra los tipos de flotilla de una agencia
	string id;
	int flag=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	cout<<endl;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			while (aux2!=NULL){
			cout << "Codigo: "+aux2->codigoTipo<<endl;
	  		cout << "Nombre: "+aux2->nombre<<endl;  
	  		cout << "Cantidad de carros: "+aux2->CantidadCarrosTipo<<endl;  
	  		cout<<endl;
			aux2=aux2->tflotilla;	
			}
		}
		aux=aux->siguiente;
	}
		if (aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			while (aux2!=NULL){
			cout << "Codigo: "+aux2->codigoTipo<<endl;
	  		cout << "Nombre: "+aux2->nombre<<endl;  
	  		cout << "Cantidad de carros: "+aux2->CantidadCarrosTipo<<endl;  
	  		cout<<endl;
			aux2=aux2->tflotilla;	
			}
}
if (flag==0)
cout<<"La agencia no existe"<<endl;	
}
void listaAgencia::mostrarCantVehAgen(){//Muestra la cantidad de vehiculos de una agencia
	string id;
	int flag=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	cout<<endl;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"La cantidad de vehiculos de la agencia "+aux->id+" es: "+aux->vehiculos;
		}
		aux=aux->siguiente;
	}
	if (aux->id==id){
			flag=1;
			cout<<"La cantidad de vehiculos de la agencia "+aux->id+" es: "+aux->vehiculos;
		}
}
void listaCarros::mostrarAsientosCarro(){//Muestra la cantidad de asientos de un carro
	string id;
	string codTF;
	string placa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El numero de asientos del carro placa "+aux3->numeroPlaca+" es "+aux3->numeroDeAsientos<<endl;
							
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El numero de asientos del carro placa "+aux3->numeroPlaca+" es "+aux3->numeroDeAsientos<<endl;	
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}
void listaCarros::mostrarModeloCarro(){//Muestra el modelo de un carro
	string id;
	string codTF;
	string placa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El modelo del carro placa "+aux3->numeroPlaca+" es "+aux3->modeloCar<<endl;
							
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El modelo del carro placa "+aux3->numeroPlaca+" es "+aux3->modeloCar<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}	
void listaCarros::mostrarAgnoCarro(){//Muestra el año de un carro
	string id;
	string codTF;
	string placa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El agno del carro placa "+aux3->numeroPlaca+" es "+aux3->anno<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El agno del carro placa "+aux3->numeroPlaca+" es "+aux3->anno<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}
void listaCarros::mostrarPrecioCarro(){//Muestra el precio de un carro
	string id;
	string codTF;
	string placa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El precio del carro placa "+aux3->numeroPlaca+" es "+aux3->precio<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El precio del carro placa "+aux3->numeroPlaca+" es "+aux3->precio<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}	
void listaCarros::mostrarEstCarro(){//Muestra el estado de un carro
	string id;
	string codTF;
	string placa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El estado del carro placa "+aux3->numeroPlaca+" es "+aux3->estadoDelCarro<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"El estado del carro placa "+aux3->numeroPlaca+" es "+aux3->estadoDelCarro<<endl;
						}
						aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}
void listaCarros::mostrarCarro(){//Menu de consultas de carros
	string op;
	cout<<"1. Consultar el modelo de un carro"<<endl;
	cout<<"2. Consultar el agno de un carro"<<endl;
	cout<<"3. Consultar el numero de asientos de un carro"<<endl;
	cout<<"4. Consultar el precio de un carro"<<endl;
	cout<<"5. Consultar el estado de un carro"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	cin>>op;
	if (op=="1"){
		carros.mostrarModeloCarro();
	}
	else if(op=="2"){
		carros.mostrarAgnoCarro();
	}
	else if(op=="3"){
		carros.mostrarAsientosCarro();
	}
	else if(op=="4"){
		carros.mostrarPrecioCarro();
	}
	else if(op=="5"){
		carros.mostrarEstCarro();
	}
	else{
		cout<<"Opcion no valida"<<endl;
	}	
	}
void listaAgencia::mostrarUltAgen(){//Muestra la ultima agencia registrada
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		aux=aux->siguiente;
	}
	cout <<"ID: "+aux->id<<endl;
	cout<<"Nombre: "+aux->nombre<<endl;
	cout<<"Cantidad de vehiculos: "+aux->vehiculos<<endl;
	cout<<endl;	
}		
void listaTF::mostrarUltTF(){//Muestra el ultimo tipo de flotilla registrado
	pnodoTF aux=tiposFlotillas.primero;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	cout << "Codigo: "+aux->codigoTipo<<endl;
	cout << "Nombre: "+aux->nombre<<endl;  
	cout << "Cantidad de carros: "+aux->CantidadCarrosTipo<<endl;
	cout<<endl;	
}
void listaCarros::mostrarUltCarro(){//Muestra el ultimo carro registrado
	pnodoCarro aux=carros.primero;
	while(aux->siguiente!=carros.primero){
		aux=aux->siguiente;
	}
	cout << "Placa: "+aux->numeroPlaca<<endl;
	cout << "Modelo: "+aux->modeloCar<<endl;
	cout << "Numero de asientos: "+aux->numeroDeAsientos<<endl;
	cout << "Agno: "+aux->anno<<endl;
	cout << "Precio: "+aux->precio<<endl;
	cout << "Estado: "+aux->estadoDelCarro<<endl;
	cout<<endl;	
}																
void listaTF::MostrarCarrosTF(){//Muestra los carros de un tipo de flotilla
	string id;
	string tf;
	int flag=0;
	int flag2=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>tf;
			pnodoTF aux2=aux->tflotilla;
			while (aux2!=NULL){
				if (aux2->codigoTipo==tf){
					flag2=1;
					pnodoCarro aux3=aux2->car;
					while (aux3!=NULL){
						cout<<endl;
						cout << "Placa: "+aux3->numeroPlaca<<endl;
						cout << "Modelo: "+aux3->modeloCar<<endl;
						cout << "Numero de asientos: "+aux3->numeroDeAsientos<<endl;
						cout << "Agno: "+aux3->anno<<endl;
						cout << "Precio: "+aux3->precio<<endl;
						cout << "Estado: "+aux3->estadoDelCarro<<endl;
						cout<<endl;	
						aux3=aux3->car;
					}
				}
			aux2=aux2->tflotilla;	
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		aux=aux->siguiente;
	}
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>id;
			pnodoTF aux2=aux->tflotilla;
			while (aux2!=NULL){
				if (aux2->codigoTipo==tf){
					flag2=1;
					pnodoCarro aux3=aux2->car;
					while (aux3!=NULL){
						cout << "Placa: "+aux3->numeroPlaca<<endl;
						cout << "Modelo: "+aux3->modeloCar<<endl;
						cout << "Numero de asientos: "+aux3->numeroDeAsientos<<endl;
						cout << "Agno: "+aux3->anno<<endl;
						cout << "Precio: "+aux3->precio<<endl;
						cout << "Estado: "+aux3->estadoDelCarro<<endl;
						cout<<endl;	
						aux3=aux3->car;
					}
				}
			aux2=aux2->tflotilla;	
			}
			if (flag2==0)
			cout<<"El tipo de flotilla no existe"<<endl;
		}
		if (flag==0)
		cout<<"La agencia no existe"<<endl;
}	
//Inserciones
void listaHotel::insertarHotel(){//Inserta un hotel nuevo
	string cod;
	string nom;
	string estr;
	int flag=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>cod;
	cout<<"Digite el nombre del hotel: ";
	cin>>nom;
	cout<<"Digite las estrellas del hotel: ";
	cin>>estr;
	pnodoHotel aux= hoteles.primero;
	while(aux!=NULL){
		if (aux->codigo==cod){
			flag=1;
		}
		aux=aux->siguiente;
	}
	if(flag==0){
		hoteles.InsertarFinalHotel(cod,nom,estr);
		cout<<"Hotel insertado"<<endl;
	}
	else{
		cout<<"Codigo de hotel repetido"<<endl;
	}
}
void listaPisos::insertarPiso(){//Inserta un piso nuevo
	string codH;
	string numP;
	string nombre;
	string cantH;
	int flag=0;
	int flag2=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux= hoteles.primero;
	while (aux!=NULL){
		if (aux->codigo==codH){
			flag2=1;
			cout<<"Digite el numero de piso: ";
			cin>>numP;
			cout<<"Digite el nombre del piso: ";
			cin>>nombre;
			cout<<"Digite la cantidad de habitaciones: ";
			cin>>cantH;
			if (aux->pisos==NULL){
				pisos.InsertarFinalPisos(numP,nombre,cantH);
				pnodoPisos aux3=pisos.primero;
				while(aux3->siguiente!=pisos.primero){
					aux3=aux3->siguiente;
				}
				aux->pisos=aux3;
				cout<<"Piso insertado"<<endl;
			}
			else{
				pnodoPisos aux2=aux->pisos;
				while(aux2!=NULL){
					if (aux2->numeroPiso==numP){
						flag=1;
					}
					aux2=aux2->pisos;
				}
				if (flag==0){
					pisos.InsertarFinalPisos(numP,nombre,cantH);
					pnodoPisos aux3=pisos.primero;
					while(aux3->siguiente!=pisos.primero){
						aux3=aux3->siguiente;
					}
					pnodoPisos aux4=aux->pisos;
					while(aux4->pisos!=NULL){
						aux4=aux4->pisos;
				}
					aux4->pisos=aux3;
					cout<<"Piso insertado"<<endl;
			}
			else
			cout<<"Numero de piso repetido"<<endl;
		}
	}
	aux=aux->siguiente;
}
if (flag2==0){
	cout<<"El hotel no existe"<<endl;
}
}
void listaHabitaciones::insertarHabitacion(){//Inserta una habitacion nueva
	string codHo;
	string numP;
	string codHa;
	string tcuarto;
	string numCam;
	string precioH;
	string estado;
	int flagHo=0;
	int flagP=0;
	int flagHa=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codHo;
	pnodoHotel aux = hoteles.primero;
	while (aux){
		if (aux->codigo==codHo){
			flagHo=1;
		cout<<"Digite el numero del piso: ";
		cin>>numP;
		pnodoPisos aux2=aux->pisos;
		while(aux2){
			if (aux2->numeroPiso==numP){
				flagP=1;
				cout<<"Digite el codigo de la habitacion: ";
				cin>>codHa;
				cout<<"Digite el tipo de cuarto: ";
				cin>>tcuarto;
				cout<<"Digite el numero de camas: ";
				cin>>numCam;
				cout<<"Digite el precio de la habitacion: ";
				cin>>precioH;
				cout<<"Digite el estado de la habitacion: ";
				cin>>estado;
				pnodoHabitaciones aux3=aux2->hab;
				while(aux3){
					if (aux3->codigoHab==codHa){
						flagHa=1;
						cout<<"Codigo de habitacion repetido"<<endl;
					}
					aux3=aux3->hab;
				}
				if (flagHa==0){
					habitaciones.InsertarFinalHabitaciones(codHa,tcuarto,numCam,precioH,estado);
					pnodoHabitaciones habi=habitaciones.primero;
					while(habi->siguiente!=NULL){
						habi=habi->siguiente;
					}
					pnodoHabitaciones habP=aux2->hab;
					if(aux2->hab==NULL){
						aux2->hab=habi;
					}
					else{
						while(habP->hab!=NULL){
							habP=habP->hab;
						}
						habP->hab=habi;
					}
					cout<<"Habitacion ingresada"<<endl;	
				}	
			}
			aux2=aux2->pisos;
		}
		if (flagP==0){
			cout<<"El piso no existe"<<endl;	
		}	
		}
		aux=aux->siguiente;
	}
	if (flagHo==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaAgencia::insertarAgencia(){//Inserta una agencia nueva
	string id;
	string nom;
	string cantV;
	int flag=0;
	cout<<"Digite la identificacion de la agencia a insertar: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if(aux->id==id){
			flag=1;
			cout<<"Codigo de agencia repetido"<<endl;
		}
		aux=aux->siguiente;
	}
	if(aux->id==id){
			flag=1;
			cout<<"Codigo de agencia repetido"<<endl;
		}
	if (flag==0){
		cout<<"Digite el nombre de la agencia a insertar: ";
		cin>>nom;
		cout<<"Digite la cantidad de vehiculos de la agencia a insertar: ";
		cin>>cantV;
		agencias.InsertarFinalAgencias(id,nom,cantV);
		cout<<"Agencia insertada"<<endl;
	}
}
void listaTF::insertarTF(){//Inserta un tipo de flotilla nuevo
	string id;
	string codTF;
	string nombre;
	string cantC;
	int flag=0;
	int flag2=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla a insertar: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Codigo de tipo de flotilla repetido "<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0){
				cout<<"Digite el nombre del tipo de flotilla a insertar: ";
				cin>>nombre;
				cout<<"Digite la cantidad de carros del tipo de flotilla a insertar: ";
				cin>>cantC;
				tiposFlotillas.InsertarFinalTF(codTF,nombre,cantC);
				pnodoTF aux3=tiposFlotillas.primero;
				while (aux3->siguiente!=NULL){
					aux3=aux3->siguiente;
				}
				if (aux->tflotilla==NULL){
					aux->tflotilla=aux3;
				}
				else{
					pnodoTF aux4=aux->tflotilla;
					while(aux4->tflotilla!=NULL){
						aux4=aux4->tflotilla;
					}
					aux4->tflotilla=aux3;
				}
				cout<<"Tipo de flotilla insertado"<<endl;
			}
		}
		aux=aux->siguiente;
	}
	if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla a insertar: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if (aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Codigo de tipo de flotilla repetido "<<endl;
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0){
				cout<<"Digite el nombre del tipo de flotilla a insertar: ";
				cin>>nombre;
				cout<<"Digite la cantidad de carros del tipo de flotilla a insertar: ";
				cin>>cantC;
				tiposFlotillas.InsertarFinalTF(codTF,nombre,cantC);
				pnodoTF aux3=tiposFlotillas.primero;
				while (aux3->siguiente!=NULL){
					aux3=aux3->siguiente;
				}
				if (aux->tflotilla==NULL){
					aux->tflotilla=aux3;
				}
				else{
					pnodoTF aux4=aux->tflotilla;
					while(aux4->tflotilla!=NULL){
						aux4=aux4->tflotilla;
					}
					aux4->tflotilla=aux3;
				}
				cout<<"Tipo de flotilla insertado"<<endl;
			}
		}
		if (flag==0){
			cout<<"Agencia no existe"<<endl;
		}
}
void listaCarros::insertarCarro(){//Inserta un carro nuevo
	string id;
	string codTF;
	string placa;
	string modelo;
	string numA;
	string agno;
	string precio;
	string estado;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if(aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a insertar: ";
					cin>>placa;
					pnodoCarro aux3=carros.primero;
					while(aux3->siguiente!=carros.primero){
						if (aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Placa repetida"<<endl;
						}
						aux3=aux3->siguiente;
					}
					if (aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Placa repetida"<<endl;
						}
					if (flag3==0){
						cout<<"Digite el modelo del carro a insertar: ";
						cin>>modelo;
						cout<<"Digite el numero de asientos del carro a insertar: ";
						cin>>numA;
						cout<<"Digite el agno del carro a insertar: ";
						cin>>agno;
						cout<<"Digite el precio del carro a insertar: ";
						cin>>precio;
						cout<<"Digite el estado del carro a insertar: ";
						cin>>estado;
						carros.InsertarFinalCarros(placa,modelo,numA,agno,precio,estado);
						pnodoCarro aux4=carros.primero;
						while(aux4->siguiente!=carros.primero){
							aux4=aux4->siguiente;
						}
						 if (aux2->car==NULL){
						 	aux2->car=aux4;
						 	cout<<"Carro insertado"<<endl;
						 }
						 else{
						 	pnodoCarro aux5=aux2->car;
						 	while(aux5->car!=NULL){
						 		aux5=aux5->car;
							 }
							 aux5->car=aux4;
							 cout<<"Carro insertado"<<endl;
						 }
					}
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
				cout<<"Tipo de flotilla no existe"<<endl;	
		}
		aux=aux->siguiente;
	}
	if(aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a insertar: ";
					cin>>placa;
					pnodoCarro aux3=carros.primero;
					while(aux3->siguiente!=carros.primero){
						if (aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Placa repetida"<<endl;
						}
						aux3=aux3->siguiente;
					}
					if (aux3->numeroPlaca==placa){
							flag3=1;
							cout<<"Placa repetida"<<endl;
						}
					if (flag3==0){
						cout<<"Digite el modelo del carro a insertar: ";
						cin>>modelo;
						cout<<"Digite el numero de asientos del carro a insertar: ";
						cin>>numA;
						cout<<"Digite el agno del carro a insertar: ";
						cin>>agno;
						cout<<"Digite el precio del carro a insertar: ";
						cin>>precio;
						cout<<"Digite el estado del carro a insertar: ";
						cin>>estado;
						carros.InsertarFinalCarros(placa,modelo,numA,agno,precio,estado);
						pnodoCarro aux4=carros.primero;
						while(aux4->siguiente!=carros.primero){
							aux4=aux4->siguiente;
						}
						if (aux2->car==NULL){
						 	aux2->car=aux4;
						 	cout<<"Carro insertado"<<endl;
						 }
						 else{
						 	pnodoCarro aux5=aux2->car;
						 	while(aux5->car!=NULL){
						 		aux5=aux5->car;
							 }
							 aux5->car=aux4;
							 cout<<"Carro insertado"<<endl;
						 }
					}
				}
				aux2=aux2->tflotilla;
			}
			if (flag2==0)
				cout<<"Tipo de flotilla no existe"<<endl;	
		}
		if (flag==0)
		cout<<"Agencia no existe"<<endl;
}
//Retorno de posiciones
int listaPisos::posPiso(string num){//Retorna la posicion de un piso especifico
	pnodoPisos aux=pisos.primero;
	int cont=0;
	int cont2=0;
	int flag=0;
	while (aux->siguiente!=pisos.primero){
		if (aux->numeroPiso==num){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}
	cont++;
	return cont;		
}
int listaHabitaciones::posHabitacion(string cod){//Retorna la posicion de una habitacion especifica
	pnodoHabitaciones aux=habitaciones.primero;
	int cont=0;
	while (aux){
		if (aux->codigoHab==cod){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}	
}
int listaHotel::posHotel(string cod){//Retorna la posicion de un hotel especifico
	pnodoHotel aux=hoteles.primero;
	int cont=0;
	while (aux){
		if (aux->codigo==cod){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}	
}
int listaCarros::posCarro(string placa){//Retorna la posicion de un carro especifico
	pnodoCarro aux=carros.primero;
	int cont=0;
	int flag=0;
	while (aux->siguiente!=carros.primero){
		if (aux->numeroPlaca==placa){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}
	cont++;
	return cont;		
}
int listaTF::posTF(string cod){//Retorna la posicion de un tipo de flotilla especifico
	pnodoTF aux=tiposFlotillas.primero;
	int cont=0;
	while (aux){
		if (aux->codigoTipo==cod){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}	
}
int listaAgencia::posAgencia(string id){//Retorna la posicion de una agencia especifica
	pnodoAgencia aux=agencias.primero;
	int cont=0;
	int flag=0;
	while (aux->siguiente!=agencias.primero){
		if (aux->id==id){
			cont++;
			return cont;
		}
		else{
			cont++;
		}
		aux=aux->siguiente;
	}
	cont++;
	return cont;		
}
//Eliminaciones
void listaHotel::eliminarHotel(){//Elimina un hotel
	string cod;
	string cod2;
	string codHa;
	string numP;
	cout<<"Digite el codigo del hotel a eliminar: ";
	cin>>cod;
	int flag=0;
	int flag2=0;
	pnodoHotel aux=hoteles.primero;
	while (aux){
		if(aux->codigo==cod){
			flag=1;
			pnodoPisos aux2=aux->pisos;
			while(aux2!=NULL){
				while(aux2->hab!=NULL){
					pnodoHabitaciones aux3=aux2->hab;
					aux3->codigoHab="eliminar";
					codHa=aux3->codigoHab;
					aux2->hab=aux3->hab;
					habitaciones.BorrarPosicionHabitaciones(habitaciones.posHabitacion(codHa));
				}
				aux2->numeroPiso="eliminar";
				numP=aux2->numeroPiso;
				aux->pisos=aux2->pisos;
				pisos.BorrarPosicionPisos(pisos.posPiso(numP));
				aux2=aux->pisos;	
			}
			if (aux->pisos==NULL){
				flag2=1;
				cod2=aux->codigo;
				aux=aux->siguiente;
				hoteles.BorrarPosicionHotel(hoteles.posHotel(cod2));	
				cout<<"Hotel eliminado"<<endl;
			}
		}
		if (flag2==0)
		aux=aux->siguiente;
		flag2=0;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaPisos::eliminarPiso(){//Elimina un piso
	string codH;
	string numP;
	string codHa;
	int flag=0;
	int flag2=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if (aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero del piso a eliminar: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if(aux2->numeroPiso==numP){
					flag2=1;
					while(aux2->hab!=NULL){
					pnodoHabitaciones aux3=aux2->hab;
					aux3->codigoHab="eliminar";
					codHa=aux3->codigoHab;
					aux2->hab=aux3->hab;
					habitaciones.BorrarPosicionHabitaciones(habitaciones.posHabitacion(codHa));
				}
				aux2->numeroPiso="eliminar";
				numP=aux2->numeroPiso;
				aux->pisos=aux2->pisos;
				pisos.BorrarPosicionPisos(pisos.posPiso(numP));
				aux2=aux->pisos;
				cout<<"Piso eliminado"<<endl;	
				}
				else
				aux2=aux2->pisos;	
			}
			if (flag2==0){
				cout<<"El piso no existe"<<endl;
			}	
		}
		aux=aux->siguiente;
	}
	if (flag==0){
		cout<<"El hotel no existe"<<endl;
	}
}
void listaHabitaciones::eliminarHabitacion(){//Elimina una habitacion
	string codH;
	string numP;
	string codHa;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite el codigo del hotel: ";
	cin>>codH;
	pnodoHotel aux=hoteles.primero;
	while(aux){
		if (aux->codigo==codH){
			flag=1;
			cout<<"Digite el numero del piso: ";
			cin>>numP;
			pnodoPisos aux2=aux->pisos;
			while(aux2){
				if(aux2->numeroPiso==numP){
					flag2=1;
					cout<<"Digite el codigo de la habitacion a eliminar: ";
					cin>>codHa;
					pnodoHabitaciones aux3=aux2->hab;
					while(aux3){
						if(aux3->codigoHab==codHa){
						flag3=1;
						if (aux3==aux2->hab){
							aux3->codigoHab="eliminar";
							codHa=aux3->codigoHab;
							aux2->hab=aux3->hab;
							habitaciones.BorrarPosicionHabitaciones(habitaciones.posHabitacion(codHa));	
							cout<<"Habitacion eliminada"<<endl;
						}
						else{
							pnodoHabitaciones aux4=aux2->hab;
							while(aux4->hab!=aux3){
								aux4=aux4->hab;
							}
							aux3->codigoHab="eliminar";
							codHa=aux3->codigoHab;
							aux4->hab=aux3->hab;
							habitaciones.BorrarPosicionHabitaciones(habitaciones.posHabitacion(codHa));
							cout<<"Habitacion eliminada"<<endl;	
						}
					}
					aux3=aux3->hab;
					}
					if (flag3==0)
					cout<<"La habitacion no existe"<<endl;
				}
				aux2=aux2->pisos;
				}
				if (flag2==0){
				cout<<"El piso no existe"<<endl;
			}
			}
			aux=aux->siguiente;
		}
		if (flag==0){
				cout<<"El hotel no existe"<<endl;
			}
	}
void listaAgencia::eliminarAgencia(){//Elimina una agencia
	string id;
	string cod2;
	string placa;
	string codT;
	cout<<"Digite la identificacion de la agencia a eliminar: ";
	cin>>id;
	int flag=0;
	int flag2=0;
	pnodoAgencia aux=agencias.primero;
	while (aux->siguiente!=agencias.primero){
		if(aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			while(aux2!=NULL){
				while(aux2->car!=NULL){
					pnodoCarro aux3=aux2->car;
					placa=aux3->numeroPlaca;
					aux2->car=aux3->car;
					carros.BorrarPosicionCarros(carros.posCarro(placa));
				}
				aux2->codigoTipo="eliminar";
				codT=aux2->codigoTipo;
				aux->tflotilla=aux2->tflotilla;
				tiposFlotillas.BorrarPosicionTF(tiposFlotillas.posTF(codT));
				aux2=aux->tflotilla;
			}
			if (aux->tflotilla==NULL){
				flag2=1;
				cod2=aux->id;
				aux=aux->siguiente;
				agencias.borrarPosicionAgencia(agencias.posAgencia(cod2));	
				cout<<"Agencia eliminada"<<endl;
			}
		}
		if (flag2==0)
		aux=aux->siguiente;
		flag2=0;
	}
	if(aux->id==id){
			flag=1;
			pnodoTF aux2=aux->tflotilla;
			while(aux2!=NULL){
				while(aux2->car!=NULL){
					pnodoCarro aux3=aux2->car;
					placa=aux3->numeroPlaca;
					aux2->car=aux3->car;
					carros.BorrarPosicionCarros(carros.posCarro(placa));
				}
				aux2->codigoTipo="eliminar";
				codT=aux2->codigoTipo;
				aux->tflotilla=aux2->tflotilla;
				tiposFlotillas.BorrarPosicionTF(tiposFlotillas.posTF(codT));
				aux2=aux->tflotilla;
			}
			if (aux->tflotilla==NULL){
				flag2=1;
				cod2=aux->id;
				agencias.borrarPosicionAgencia(agencias.posAgencia(cod2));	
				cout<<"Agencia eliminada"<<endl;
			}
		}	
	if (flag==0){
		cout<<"La agencia no existe"<<endl;
	}
}
void listaTF::eliminarTF(){//Elimina un tipo de flotilla
	string id;
	string codTF;
	string placa;
	string codTF2;
	int flag=0;
	int flag2=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla a eliminar: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					while(aux2->car!=NULL){
					pnodoCarro aux3=aux2->car;
					placa=aux3->numeroPlaca;
					aux2->car=aux3->car;
					carros.BorrarPosicionCarros(carros.posCarro(placa));
				}
				aux2->codigoTipo="eliminar";
				codTF2=aux2->codigoTipo;
				aux->tflotilla=aux2->tflotilla;
				tiposFlotillas.BorrarPosicionTF(tiposFlotillas.posTF(codTF2));
				aux2=aux->tflotilla;
				cout<<"Tipo de flotilla eliminado"<<endl;	
				}
				else
				aux2=aux2->tflotilla;
			}
			if (flag2==0){
				cout<<"El tipo de flotilla no existe"<<endl;
			}
		}
		aux=aux->siguiente;
	}
	if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla a eliminar: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					while(aux2->car!=NULL){
					pnodoCarro aux3=aux2->car;
					placa=aux3->numeroPlaca;
					aux2->car=aux3->car;
					carros.BorrarPosicionCarros(carros.posCarro(placa));
				}
				aux2->codigoTipo="eliminar";
				codTF2=aux2->codigoTipo;
				aux->tflotilla=aux2->tflotilla;
				tiposFlotillas.BorrarPosicionTF(tiposFlotillas.posTF(codTF2));
				aux2=aux->tflotilla;
				cout<<"Tipo de flotilla eliminado"<<endl;	
				}
				else
				aux2=aux2->tflotilla;
			}
			if (flag2==0){
				cout<<"El tipo de flotilla no existe"<<endl;
			}
}
if (flag==0){
		cout<<"La agencia no existe"<<endl;
	}
}
void listaCarros::eliminarCarro(){//Elimina un carro
	string id;
	string codTF;
	string placa;
	string placa2;
	int flag=0;
	int flag2=0;
	int flag3=0;
	cout<<"Digite la identificacion de la agencia: ";
	cin>>id;
	pnodoAgencia aux=agencias.primero;
	while(aux->siguiente!=agencias.primero){
		if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a eliminar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
						flag3=1;
						if (aux3==aux2->car){
							placa2=aux3->numeroPlaca;
							aux2->car=aux3->car;
							carros.BorrarPosicionCarros(carros.posCarro(placa2));	
						}
						else{
							pnodoCarro aux4=aux2->car;
							while(aux4->car!=aux3){
								aux4=aux4->car;
							}
							placa2=aux3->numeroPlaca;
							aux4->car=aux3->car;
							carros.BorrarPosicionCarros(carros.posCarro(placa2));	
						}
					}
					aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
				}
				if (flag2==0){
				cout<<"El tipo de flotilla no existe"<<endl;
			}
			}
			aux=aux->siguiente;
		}
			if (aux->id==id){
			flag=1;
			cout<<"Digite el codigo del tipo de flotilla: ";
			cin>>codTF;
			pnodoTF aux2=aux->tflotilla;
			while(aux2){
				if(aux2->codigoTipo==codTF){
					flag2=1;
					cout<<"Digite la placa del carro a eliminar: ";
					cin>>placa;
					pnodoCarro aux3=aux2->car;
					while(aux3){
						if(aux3->numeroPlaca==placa){
						flag3=1;
						if (aux3==aux2->car){
							placa2=aux3->numeroPlaca;
							aux2->car=aux3->car;
							carros.BorrarPosicionCarros(carros.posCarro(placa2));
							cout<<"Carro eliminado"<<endl;
						}
						else{
							pnodoCarro aux4=aux2->car;
							while(aux4->car!=aux3){
								aux4=aux4->car;
							}
							placa2=aux3->numeroPlaca;
							aux4->car=aux3->car;
							carros.BorrarPosicionCarros(carros.posCarro(placa2));
							cout<<"Carro eliminado"<<endl;	
						}
					}
					aux3=aux3->car;
					}
					if (flag3==0)
					cout<<"El carro no existe"<<endl;
				}
				aux2=aux2->tflotilla;
				}
				if (flag2==0){
				cout<<"El tipo de flotilla no existe"<<endl;
			}
			}
		if (flag==0){
				cout<<"El hotel no existe"<<endl;
			}
	}
//Validar usuarios y administradores
bool listaAdminH::validarCodigoH(string cod){//Valida el codigo de un administrador de hotel dado
	pnodoAdminH aux=adminH.primero;
	while(aux->siguiente!=adminH.primero){
		if (aux->CodigoAdministradorH==cod){
			return true;
		}
		aux=aux->siguiente;
	}
		if (aux->CodigoAdministradorH==cod){
			return true;
		}
		else{
			return false;
		}
}
bool listaAdminA::validarCodigoA(string cod){//Valida el codigo de un administrador de agencia dado
	pnodoAdminA aux=adminA.primero;
	while(aux->siguiente!=adminA.primero){
		if (aux->CodigoAdministradorA==cod){
			return true;
		}
		aux=aux->siguiente;
	}
		if (aux->CodigoAdministradorA==cod){
			return true;
		}
		else{
			return false;
		}
}
bool listaUsuarios::validarCodigoU(string cod){//Valida el codigo de un usuario dado
	pnodoUsuarios aux=usuarios.primero;
	while(aux->siguiente!=usuarios.primero){
		if (aux->nPasaporte==cod){
			return true;
		}
		aux=aux->siguiente;
	}
		if (aux->nPasaporte==cod){
			return true;
		}
		else{
			return false;
		}
}
//MENU DE Reportes ADMIN Hoteles
void reportesAdminHoteles(){
	system("title Reportes para administrador de Hoteles");
	int opcion=999;
    while (opcion!=0){
    system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tBienvenido Administrador al menu de reportes de Hoteles" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Reportes de Hoteles*" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t1. Consultar Hoteles" << endl;
        cout << "\t2. Consultar Piso" << endl;
        cout << "\t3. Consultar Habitaciones" << endl;
        cout << "\t4. Consultar Cantidad de estrellas de un hotel" << endl;
        cout << "\t5. Cantidad de Habitaciones de un piso" << endl ;
        cout << "\t6. Ultimo Hotel insertado" << endl ;
        cout << "\t7. Ultimo Piso Insertado" << endl ;
        cout << "\t8. Ultima Habitacion insertada" << endl;
        cout << "\t0. Volver" << endl ;
		cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas
   			cin.ignore(100, '\n'); //Vacia el buffer
			opcion=999;	
		}
        system("cls");
        switch (opcion) {
             case 1:                 
				hoteles.MostrarHotel();  
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";            
                system("pause>nul"); // Pausa
                break;
            case 2:
            	;
            	hoteles.MostrarPisosHotel();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";   
                system("pause>nul"); // Pausa
                break;
            case 3:
            	pisos.MostrarHabPisos();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;
			case 4:                 
				hoteles.MostrarCantEstrellas();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";               
                system("pause>nul"); // Pausa
                break;
            case 5:
            	;
            	pisos.MostrarCantHab();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 6:
            	hoteles.MostrarUltHotel();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;	
          	case 7:                 
				pisos.MostrarUltPiso();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";               
                system("pause>nul"); // Pausa
                break;
            case 8:
            	;
            	habitaciones.MostrarUltHab();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
    	}
	}
}
//MENU DE Reportes ADMIN AGENCIAS
void reportesAdminAgencias(){
	system("title Reportes para administrador de Agencias");
	int opcion=999;
    while (opcion!=0){
    system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tBienvenido Administrador al menu de reportes de Agencias" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Reportes de Agencias *" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t1. Consultar Agencias" << endl;
        cout << "\t2. Consultar Tipos de flotilla" << endl;
        cout << "\t3. Consultar cantidad de vehiculos de una Agencia" << endl;
        cout << "\t4. Consultar cantidad de asientos de un carro" << endl;
        cout << "\t5. Consultar el modelo o el año o el numero de asientos o el precio o bien el estado de un carro" << endl ;
        cout << "\t6. Ultima Agencia insertada" << endl ;
        cout << "\t7. Ultimo Tipo flotilla insertado" << endl ;
        cout << "\t8. Ultima Carro Insertado" << endl;
        cout << "\t0. Volver" << endl ;
		cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas 
   			cin.ignore(100, '\n'); //Vacia el buffer
			opcion=999;	
		}
        system("cls");
        switch (opcion) {
             case 1:                 
				agencias.MostrarListaAgencia();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";               
                system("pause>nul"); // Pausa
                break;
            case 2:
            	;
            	agencias.MostrarTFAgen();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 3:
            	agencias.mostrarCantVehAgen();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;
			case 4:                 
				carros.mostrarAsientosCarro();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";          
                system("pause>nul"); // Pausa
                break;
            case 5:
            	;
            	carros.mostrarCarro();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 6:
            	agencias.mostrarUltAgen();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;	
          	case 7:                 
				tiposFlotillas.mostrarUltTF();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";               
                system("pause>nul"); // Pausa
                break;
            case 8:
            	;
            	carros.mostrarUltCarro();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
    	}
	}
}
//MENU DE ADMINISTRADOR HOTEL
void adminHoteles(){
	system("title Administrador de hotel");
	int opcion=999;
    while (opcion!=0){
    system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tBienvenido Administrador de hotel" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Inserciones *" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t1. Insertar Hotel" << endl;
        cout << "\t2. Insertar Piso" << endl;
        cout << "\t3. Insertar Habitacion" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Eliminaciones *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t4. Eliminar Hotel" << endl;
        cout << "\t5. Eliminar Piso" << endl;
        cout << "\t6. Eliminar Habitacion" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t* Modificaciones *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t7. Modificar Hotel" << endl ;
        cout << "\t8. Modificar Piso" << endl;
        cout << "\t9. Modificar Habitacion" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t* Reportes *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t10. Menu de reportes" << endl ;   
        cout << "\t0. Volver" << endl ;
		cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas
   			cin.ignore(100, '\n'); //Vacia el buffer	
   			opcion=999;
		}
        system("cls");
        switch (opcion) {
            case 1:                 
				hoteles.insertarHotel();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";              
                system("pause>nul"); // Pausa
                break;
            case 2:
            	;
            	pisos.insertarPiso();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 3:
            	habitaciones.insertarHabitacion();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;
			case 4:                 
				hoteles.eliminarHotel();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";           
                system("pause>nul"); // Pausa
                break;
            case 5:
            	;
            	pisos.eliminarPiso();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 6:
            	habitaciones.eliminarHabitacion();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa            
                break;	
          	case 7:                 
				hoteles.modNomEstrellas();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";           
                system("pause>nul"); // Pausa
                break;
            case 8:
            	;
            	pisos.modHabNom();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 9:
				habitaciones.modHab();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";     
				system("pause>nul"); // Pausa
                break;
            case 10:
            	reportesAdminHoteles();
            	break;
    	}
	}
}
//MENU DE ADMINISTRADOR AGENCIAS
void adminAgencias(){
	system("title Administrador de Agencias");
	int opcion=999;
    while (opcion!=0){
    system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tBienvenido Administrador de agencias" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Inserciones *" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t1. Insertar Agencia" << endl;
        cout << "\t2. Insertar TipoFlotilla" << endl;
        cout << "\t3. Insertar Carro" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Eliminaciones *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t4. Eliminar Agencia" << endl;
        cout << "\t5. Eliminar TipoFlotilla" << endl;
        cout << "\t6. Eliminar Carro" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t* Modificaciones *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t7. Modificar Agencia" << endl ;
        cout << "\t8. Modificar TipoFlotilla" << endl ;
        cout << "\t9. Modificar Carro" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t* Reportes *" << endl ;
        cout << "\t----------------" << endl ;
        cout << "\t10. Menu de reportes" << endl ;        
        cout << "\t0. Volver" << endl ;
		cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas
   			cin.ignore(100, '\n'); //Vacia el buffer
			opcion=999;	
		}
        system("cls");
        switch (opcion) {
             case 1:                 
				agencias.insertarAgencia();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";                 
                system("pause>nul"); // Pausa
                break;
            case 2:
            	;
            	tiposFlotillas.insertarTF();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";   
                system("pause>nul"); // Pausa
                break;
            case 3:
            	carros.insertarCarro();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";   
                system("pause>nul"); // Pausa            
                break;
			case 4:                 
				agencias.eliminarAgencia(); 
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";              
                system("pause>nul"); // Pausa
                break;
            case 5:
            	;
            	tiposFlotillas.eliminarTF();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";   
                system("pause>nul"); // Pausa
                break;
            case 6:
            	carros.eliminarCarro();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";   
                system("pause>nul"); // Pausa            
                break;	
          	case 7:                 
				agencias.modNombreYCarrosAgen();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar...";              
                system("pause>nul"); // Pausa
                break;
            case 8:
            	;
            	tiposFlotillas.modNombreYCarrosTF();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
        	case 9:
        		carros.modCarro();
        		cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
				system("pause>nul"); // Pausa
                break;
        	case 10:
        		reportesAdminAgencias();
        		break;
    	}
	}
}
// MENU DE USUARIO
void userMenu(){
	system("title Opciones de usuario");
	int opcion=999;
    while (opcion!=0){
    system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tBienvenido Usuario." << endl;
        cout << "\t----------------" << endl ;
        cout << "\t* Consultas *" << endl;
        cout << "\t----------------" << endl ;
        cout << "\t1. Consultar Hoteles" << endl;
        cout << "\t2. Consultar Pisos de un hotel" << endl;
        cout << "\t3. Consultar Habitaciones de un piso en un hotel" << endl;
        cout << "\t4. Consultar Agencias" << endl;
        cout << "\t5. Consultar Flotilla de una agencia" << endl;
        cout << "\t6. Consultar carros de una flotilla en una agencia" << endl ;
        cout << "\t0. Volver" << endl ;
		cout << "\n\tIngrese una opcion ===> ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas 
   			cin.ignore(100, '\n'); //Vacia el buffer
   		   	opcion=999;
		}
		int codigoBusqueda;
		int codigoBusquedaAux;
        system("cls");
        switch (opcion) {
            case 1:                 
				hoteles.MostrarHotel();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 2:
            	hoteles.MostrarPisosHotel();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 3:
            	pisos.MostrarHabPisos();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
			case 4:                 
				agencias.MostrarListaAgencia();
				cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 5:
            	agencias.MostrarTFAgen();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
            case 6:
            	tiposFlotillas.MostrarCarrosTF();
            	cout<<endl;
				cout<<"Presione cualquier tecla para continuar..."; 
                system("pause>nul"); // Pausa
                break;
    	}
	}
}
//MENU PRINCIPAL
void mainMenu(){
	int opcion=999;
    while (opcion!=0){
    system("title Sistema de reservaciones");
        system("cls");        // Para limpiar la pantalla
        system("color 0e");
        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\t\tSistema de reservaciones" << endl;
        cout << "\t\t\t\t----------------" << endl << endl;
        cout << "\t1. Administrador de Hotel" << endl;
        cout << "\t2. Administrador de Agencia" << endl;
        cout << "\t3. Usuario" << endl;
        cout << "\t0. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        if (cin.fail()==true){
        	cout << "\a";
        	cin.clear(); //Resetea las banderas
   			cin.ignore(100, '\n'); //Vacia el buffer
			opcion=999;	
		}
		string codigo;
        system("cls");
        switch (opcion) {
            case 1:
            	cout << "\n\tIngrese su codigo de administrador de Hoteles: ";
        		cin >> codigo;
            	if (adminH.validarCodigoH(codigo)){ //comprobarSiAdminH
					adminHoteles(); 
				}
				else{
					system("cls");  
					cout<<"No existe ningun administrador registrado bajo ese codigo.";
				    system("pause>nul"); // Pausa
				    cout << "\a";
				}
                break;
            case 2:
            	cout << "\n\tIngrese su codigo de administrador de Agencias: ";
        		cin >> codigo;
            	if (adminA.validarCodigoA(codigo)){ //comprobarSiAdminA
            		adminAgencias();
				}
				else{
					system("cls");  
					cout<<"No existe ningun administrador registrado bajo ese codigo.";
				    system("pause>nul"); // Pausa
				    cout << "\a";
				}
				break;                
            case 3:
            	cout << "\n\tIngrese su codigo de Usuario: ";
        		cin >> codigo;
            	if (usuarios.validarCodigoU(codigo)){ //comprobarUsuarios
            		userMenu();
				}
				else{
					system("cls");  
					cout<<"No existe ningun usuario registrado bajo ese codigo.";
				    system("pause>nul"); // Pausa
				    cout << "\a";         
				}
				break;
    	}
	}
}
int main()
{ 
	hoteles.crearListaHotel();
	pisos.crearListaPisos();
	habitaciones.crearListaHabitaciones();
	agencias.crearListaAgencia();
	tiposFlotillas.crearListaTF();
	carros.crearListaCarros();
	adminH.crearListaAdminH();
	adminA.crearListaAdminA();
	usuarios.crearListaUsuarios();
	mainMenu();
	return 0;
}
