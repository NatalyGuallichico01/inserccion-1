#include <iostream>
#include <fstream>
using namespace std;


void algoritmoInterpolacion (int a[], int n);

void impirmirElementos(int a[], int n);
void Busqueda (int a[],int n,int dato);


int main()
{

    int A[7]= {1,5,8,9,2,3,7};
    int dato;

    impirmirElementos (A,7);
    cout<<"\n";
    
    impirmirElementos (A,7);
    cout<<"\n";
    algoritmoInterpolacion(A,7);

    cout<<"Ingrese el valor a buscar: ";
    cin>>dato;
     cout<<"\n";
      Busqueda(A,7,dato);


}


void impirmirElementos(int a[], int n)
{
  int pos,aux;
    cout<<"PRIMERA MATRIZ DESORDENADA SEGUNDA MATRIZ ORDENDADA\n";
    for(int i=0; i<n; i++)
    {
     
        cout<<"|"<<a[i]<<"|";
    }

    for(int i=0; i<n; i++)
    {
        pos=i;

        aux=a[i];

        while((pos>0)&&(a[pos-1]>aux))
        {
            a[pos] = a[pos-1];

            pos--;

        }

        a[pos]=aux;
    }


}



void algoritmoInterpolacion (int a[], int n)
{
    int primero = 0;

    int ultimo = n-1;

    int medio;

    int cont=0;

    int num=7;

    while(a[primero] != num && cont<=7 )
    {
        medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        {
            primero = medio +1;
        }
        else if(a[medio]>num)
        {
            ultimo = medio-1;
        }
        else
        {
            primero = medio;
        }
        cont++;
    }
}
void Busqueda(int a[],int n,int dato)
{
  ofstream Binario;
  Binario.open("Ordenamiento.txt",ios::out);
  int i,j,k;
  i=0;
  j=n-1;
  do{
  k=(i+j)/2;

  if(a[k]<=dato)
    {
      i=k+1;
    }
  if (a[k]>=dato)
    {
      j=k-1;
    }
}
 while (i<=j);

  if(a[k]==dato)
  {
  cout <<"\n ELEMENTO ENCONTRADO :"<<dato<<endl;
  Binario<<"\nELEMENTO ENCONTRADO EN LA POSICION:"<< a[k]<<j<<endl;
  }
  else {
    cout <<"\n ELEMNTO NO ENCONTRADO"<<endl;
   Binario <<"\n ELEMNTO NO ENCONTRADO"<<endl;
  }
  
}




