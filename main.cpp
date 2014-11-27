#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NodoArbolB
{
public:
    int datos[4];
    NodoArbolB* hijos[5];
    int cant_datos;

    NodoArbolB()
    {
        for(int i=0;i<4;i++)
            datos[i]=0;

        for(int i=0;i<5;i++)
            hijos[i]=NULL;

        cant_datos=0;
    }

    void agregar(int dato)
    {
        if(cant_datos<4)
        {
            //Buscamos donde los agregar
            int pos=0;
            while(pos<cant_datos)
            {
                if(dato<datos[pos])
                    break;
                pos++;
            }
            //cout<<"Pos:"<<pos<<endl;
            //Corremos los demas datos
            for(int i=4;i>pos;i--)
            {
                //cout<<datos[i]<<"<-"<<datos[i-1]<<endl;
                datos[i]=datos[i-1];
            }
            //Lo agregamos
            datos[pos]=dato;
            cant_datos++;
        }else
        {
            cout<<"Ya no hay espacio!"<<endl;
            NodoArbolB* hijo_i = new NodoArbolB();
            NodoArbolB* hijo_d = new NodoArbolB();
            hijos[0]=hijo_i;
            hijos[1]=hijo_d;

            vector<int> temp;
            for(int i=0;i<4;i++)
                temp.push_back(datos[i]);
            temp.push_back(dato);
            sort(temp.begin(),temp.begin()+5);

            hijo_i->datos[0]=temp[0];
            hijo_i->datos[1]=temp[1];
            hijo_i->cant_datos=2;

            datos[0]=temp[2];
            cant_datos=1;

            hijo_d->datos[0]=temp[3];
            hijo_d->datos[1]=temp[4];
            hijo_d->cant_datos=2;

        }
    }

    void imprimirDatos()
    {
        for(int i=0;i<cant_datos;i++)
            cout<<"Dato "<<i<<": "<<datos[i]<<endl;

        for(int i=0;i<cant_datos+1;i++)
            if(hijos[i]!=NULL)
                hijos[i]->imprimirDatos();
    }
};

int main()
{
    NodoArbolB n;

    cout<<"----------"<<endl;
    n.agregar(10);
    n.imprimirDatos();
    cout<<"----------"<<endl;

    cout<<"----------"<<endl;
    n.agregar(30);
    n.imprimirDatos();
    cout<<"----------"<<endl;

    cout<<"----------"<<endl;
    n.agregar(20);
    n.imprimirDatos();
    cout<<"----------"<<endl;

    cout<<"----------"<<endl;
    n.agregar(15);
    n.imprimirDatos();
    cout<<"----------"<<endl;

    cout<<"----------"<<endl;
    n.agregar(35);
    n.imprimirDatos();
    cout<<"----------"<<endl;

    return 0;
}
