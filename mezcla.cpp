#include<iostream>

using namespace std;
//declaracion de las funciones
void mezcla(int arreglo[], int inicio, int nElementos);
void algoritmoMezcla(int arreglo[], int inicio, int n1, int n2);
// dentro del metodo main lo unico que se hace es la impresion de los dos arreglos el arreglo de los datos y el otro donde manda a llamar el arreglo
int main(){
	int arreglo[8]={5,2,3,1,6,4,8,7};
	cout<<"\n\t\t\t\tDesordenada:\n";
	for(int i=0;i<8;i++){
	cout<<"\t"<<"<>";	cout<<arreglo[i];
	}
	cout<<"\n";system("pause");
	mezcla(arreglo,0,8);
	cout<<"\n\t\t\t\tOrdenada:\n";
	for(int i=0;i<8;i++){
	cout<<"\t"<<"<>";	cout<<arreglo[i];
	}
	cout<<"\n";system("pause");
	return 0;
}

//esta función se encarga de recibir los datos ordenados por la funcion de alritmo_Mezcla 
void mezcla(int arreglo[], int inicio, int nElementos){
    int n1, n2;

    if(nElementos > 1){
        n1 = nElementos / 2;
        n2 = nElementos - n1;
        mezcla(arreglo, inicio, n1);
        mezcla(arreglo, inicio + n1, n2);
        algoritmoMezcla(arreglo, inicio, n1, n2);
    }
}

//esta funcion es donde se hace el ordenamiento de los datos que estan dentro del arreglo
void algoritmoMezcla(int arreglo[], int inicio, int n1, int n2){
    int buffer[n1 + n2];
    int temp = 0;
    int temp1 = 0;
    int temp2 = 0;
    int i;

    while((temp1 < n1) && (temp2 < n2)){
        if(arreglo[inicio + temp1] < arreglo[inicio + n1 + temp2])
            buffer[temp++] = arreglo[inicio + (temp1++)];
        else
            buffer[temp++] = arreglo[inicio + n1 + (temp2++)];
    }
    while(temp1 < n1)
        buffer[temp++] = arreglo[inicio + (temp1++)];
    while(temp2 < n2)
        buffer[temp++] = arreglo[inicio + n1 + (temp2++)];
    for(i = 0; i < n1 + n2; i++)
        arreglo[inicio + i] = buffer[i];
}
