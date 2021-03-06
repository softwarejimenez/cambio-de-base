/* (C) Programmed by:
   Antonio Jimenez Martínez

Sotware:cambio de base - funciones
Version:0.2

Este programa es capaz de realizar cambios de base, lo aplicamos sobre numeros naturales.
Escribe letras mayusculas en la representación de bases >10.
*/

#include <gtk/gtk.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>     /* atoi */
#include <sstream>//para el castg

using namespace std;

string cambiode10abase(int numero,const int & base);
string convertir(const int &a);
int convertir(const char &a);
int cambiodebasea10(const string &numero,const int &base);
string cambiobase(int baseE,int baseS,string numero);



string cambiobase(int baseE,int baseS,string numero) {
    //cambiado y numero son string ya que pueden estar en base 16 y tener letras
    string cambiado;
    int base10;//base10 es un numero ya que sabemos que esta en base 10.
    if(baseE!=baseS) {
        if(baseE==10) {
            //numeroE es int ya que esta en base 10
            int numeroE;
            numeroE=atoi(numero.c_str());//pasamos numero a int
            cambiado=cambiode10abase(numeroE,baseS);
        }
        else if(baseS==10) {
            base10=cambiodebasea10(numero,baseE);
            cambiado=static_cast<ostringstream*>( &(ostringstream() << base10) )->str();//pasamos base10 a string
        }
        else { //baseE!=10 && baseS!=10
            base10=cambiodebasea10(numero,baseE);
            cambiado=cambiode10abase(base10,baseS);
        }
    }
    else cambiado=numero;

    return cambiado;
}


string convertir(const int & a)
{
    string aux;
    if(a>=0 && a<=9)
        aux='0'+a;
    if(a==10)
        aux='A';
    if(a==11)
        aux='B';
    if(a==12)
        aux='C';
    if(a==13)
        aux='D';
    if(a==14)
        aux='E';
    if(a==15)
        aux='F';
    return aux;
}

int convertir(const char &a)
{
    int aux;
    if(a>='0' && a<='9')
        aux=a-'0';
    if(a=='A')
        aux=10;
    if(a=='B')
        aux=11;
    if(a=='C')
        aux=12;
    if(a=='D')
        aux=13;
    if(a=='E')
        aux=14;
    if(a=='F')
        aux=15;
    return aux;
}
//de atras a adelante, vamos tomando los numero y multiplicandolos por el parametro
//el parametro es base^posicion
int cambiodebasea10(const string &numero,const int &base) {
    int suma=0,parametro=1,aux;
    char a;
    for(int i=numero.size()-1; i>=0; i--) {
        a=numero.at(i);
        aux=convertir(a);
        suma+=parametro*aux;
        parametro*=base;
    }
    return suma;

}

string cambiode10abase(int numero,const int &base)
{
    string salida,aux;
    int a;
    while(numero!=0) {
        //mientras el numero sea distinto de 0, vamos tomando su resto dividiendolo por la base.
        a=numero%base;
        aux=convertir(a);
        salida=aux+salida;
        numero/=base;
    }
    return salida;
}
