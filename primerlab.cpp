#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int factorial(int valor){
	int fact=1;
	for(int i=1;i<=valor;i++){
		fact*=i;
	}
	return fact;
}



double  valoreuler(int valorx){
	int denom,base=valorx;
        double sumando,euler=1;
	for(int i=1;i<=13;i++){
		denom=factorial(i);
		sumando=((pow(base,i))/denom);
		euler+=sumando;		
        }
	return euler;
}

double valordiagonal(int a1,int a2,int b1,int b2){
	double d;
	int x=pow((a2-a1),2);
	int y=pow((b2-b1),2);
	d=pow((x+y),(0.5));
	return d;
}

void imprimir(int a1,int a2,int b1,int b2){
	double d;
	int x=pow((a2-a1),2);
	int y=pow((b2-b1),2);
	d=pow((x+y),(0.5));
	cout<<"Distancia: "<<d<<endl;
}

bool puntoscolineales(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
	if((x1==x2==x3)||(x1==x2==x4)||(x1==x3==x4)||(x2==x3==x4)){
		return false;	
	}else if((y1==y2==y3)||(y1==y2==y4)||(y1==y3==y4)||(y2==y3==y4)){
		return false;
	}else{
		return true;
	}
}

int main(int argc, char* argv[]){
	int opcion;
		
	cout<< "Bienvenido"<<endl<<"1: Número de Euler"<<endl
	<< "2: Área de trapezoide"<<endl;
	cout<<" x= ";
	cin>>opcion;

	if(opcion==1){
		int valorx;
		cout<< "Número de Euler"<<endl;
		cout<< "Ingrese el valor para x: ";
		cin >>valorx; 
		cout<< valoreuler(valorx)<<endl;	
	}else if(opcion==2){
		int x1,x2,x3,x4;
		int y1,y2,y3,y4;
		double diagonal;	
		bool bandera=false;		
		while(bandera==false){
			cout<<"X1= ";
			cin>>x1;
			cout<<"Y1= ";
			cin>>y1;
			cout<<"X2= ";                           
		        cin>>x2;
		        cout<<"Y2= ";                           
		        cin>>y2;
			cout<<"X3= ";                           
		        cin>>x3;
		        cout<<"Y3= ";                           
		        cin>>y3;
			cout<<"X4= ";                           
		        cin>>x4;
		        cout<<"Y4= ";                           
		        cin>>y4;
			bandera=puntoscolineales(x1,x2,x3,x4,y1,y2,y3,y4);
		}		
		//		
		diagonal=valordiagonal(x1,x4,y1,y4);
		
		cout<<" Lados del trapezoide: "<<endl;
		imprimir(x1,x2,y1,y2);
		imprimir(x1,x3,y1,y3);
		imprimir(x3,x4,y3,y4);
		imprimir(x4,x2,y4,y2);

									
	}else{
		cout<<"Escribió otro dato, vuelva a ejecutar"<<endl;
	} 	


}
