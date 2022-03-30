#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


float f(float x){
	return (pow(x,5)-1);
}
 
 
void evalua (float f(float), float x){
	printf(" \nf(%g) = %g",x,f(x));
}


float falsaposmod(float xl,float xu,float es,float imax,float xr,float iter,float ea){
	iter=0;
	float xrold;
	float fl=f(xl);
	float fu=f(xu);
	float test;
	int il=0,iu=0;
	float fr;
	
	cout<<"Iteracion	xl				xu				xa				ea"<<endl;
	
	do{
		xrold=xr;
		xr=xu-((fu*(xl-xu))/(fl-fu));
		 fr=f(xr);
		iter =iter+1;
		
		if (xr != 0){
			ea=fabs((xr-xrold)/xr)*100;
		}
		test=fl*fr;
		if(test<0){
			xu=xr;
			fu=f(xu);
			 iu=0;
			il=il +1 ;
			if(il>=2){
				
				fl=fl/2;
			}
		}else if(test>0) {
			xl=xr;
			fl=f(xl);
			il=0;
			iu=iu+1;
			if(iu>=2){
					
				fu=fu/2;
			}
		}else{
			ea=0;
		}
		
		cout<<iter<<"		"<<xl<<"			"<<xu<<"			"<<xr<<"				"<<ea<<endl;
		
		
		if (iter==imax){
			break;
		}
		
	}while(ea>es);	
	
}

int main(){
	int i; 
	float xl=0,xu=0,es=0.5,imax=0,xr=0,iter=0,ea=0;
	
	int opc;
	do{
		cout<<"**************************************************************************"<<endl;
		cout<<"*******************Práctica 7. Falsa Posición Modificado*******************"<<endl;
		cout<<"**************************************************************************"<<endl;
		cout<<endl;
		cout<<"Seleccione su opcion"<<endl;
		cout<<"1.-Inicar su programa con los valores dados"<<endl;
		cout<<"2.-Inicar su programa ingresando nuevos valores"<<endl;
		cout<<"3.-Creditos"<<endl;
		cout<<"4.-Salir"<<endl;
		scanf("%d",&opc);
		system("CLS");
		
		switch(opc){
			case 1: 
				xl=0.2;
				xu=1.5;
				imax=20;
				es=0.5;
				system("cls");
				falsaposmod(xl,xu,es,imax,xr,iter,ea);
				system("pause");
				system("cls");
				break;
			case 2:
			system("cls");
				cout<<"Ingrese el valor de xl : ";
				cin>>xl;
				cout<<"Ingrese el valor de xu : ";
				cin>>xu;
				cout<<"Ingrese el margen de error : ";
				cin>>es;
				cout<<"Ingrese las cantidad de iteraciones : ";
				cin>>imax;
				system("pause");
				system("cls");
				falsaposmod(xl,xu,es,imax,xr,iter,ea);
				system("pause");
				system("cls");
			case 3:
				system("CLS");
				cout<<"Universidad Autonoma de Aguascalientes"<<endl;
				cout<<"**********************************************************"<<endl;
				cout<<"MAESTRA:"<<endl;
				cout<<"Dra. Aurora Torres Soto"<<endl;
				cout<<"Alumno:                               ID:"<<endl;
				cout<<"Juan Pablo Martínez Rocha              243645"<<endl;
				cout<<"**********************************************************"<<endl;
				system("pause");
				system("CLS");
		}
	}while(opc!=4);

}
