#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector <vector <int > > LeerTabla( int variables, int dimension);

int main() {
	//int temp2=0;
	int variables=0;
	int dimension=0;
	vector<vector <int > > T;
	cout<<"Ingrese la cantidad de variables de su funcion"<<endl;
	cin>> variables;
	cout<<"Ingrese la dimension de su funcion"<<endl;
	cin>>dimension;
	T=LeerTabla(variables,dimension);
	cout<<"La tabla de verdad leida desde el documento Tabla.txt es:"<<endl;
	for(int k=0; k<variables;k++){
			cout<<"x"<<k+1<<"\t";
	}
	for(int k=0; k< dimension;k++){
		cout<<"F"<<k+1<<"\t";
	}
	cout<<endl;
	for(int i=0; i< T.size();i++){
		vector<int> temp=T[i];	
		for(int j=0; j<temp.size();j++){
			cout<<temp[j]<<"\t";
		}
		cout<<endl;
	}
	int opcion;
	do{
		cout<<"Seleccione una opcion \n1.Miniterminos \n2.Maxiterminos \n3.Ambos"<<endl;
		cin>>opcion;	
	}while(opcion!=1 && opcion!=2 && opcion!=3);
	
	if(opcion==1){
		for(int k=0; k<dimension; k++){ //Recorrer las filas correspondientes a cada funcion f_k+1
			vector < vector <int> > terms; //Tabla que guardará los minitérminos de la función f_k+1
			for(int i=0; i<T.size();i++){ //Bucle para añadir cada minitérmino
				int t=T[i].size();
				if(T[i][t-dimension+k]==1){
					terms.push_back(T[i]);
				}
			}
			//Impresión de la función f_k+1
			cout<<"f"<<k+1<<":";
			for(int i=0; i< terms.size(); i++){
				vector<int > temp=terms[i];
				for(int j=0; j<temp.size()-dimension;j++){ //Impresión de cada minitérmino				
					if(temp[j]==0){
						cout<<"x"<<j+1<<"'";
					}else{
						cout<<"x"<<j+1;
					}					
				}
				if(i!=terms.size()-1){//Condición para no imprimir un signo + extra
					cout<<" + ";
				}
				
			}
			
			cout<<endl;	
		}	
	}else if(opcion==2){
		for(int k=0; k<dimension; k++){ //Recorrer las filas correspondientes a cada funcion f_k+1
			cout<<"f"<<k+1<<":";
			//Impresión de la función f_k+1
			for(int i=0; i<T.size();i++){ //
				vector <int> temp=T[i];
				if(temp[temp.size()-dimension+k]==0){
					cout<<"(";
					for(int j=0; j<temp.size()-dimension;j++){				
						if(temp[j]==1){
							cout<<"x"<<j+1<<"'";
						}else{
							cout<<"x"<<j+1;
						}
						if(j+1<variables){
				 			cout<<"+";	//condición para no imprimr un signo + extra considerando el número de variables
						}	
					}
					cout<<")";
				}
			}
			cout<<endl;	
		}
		}
		else{
			cout<<"Miniterminos\n";
			for(int k=0; k<dimension; k++){ //Recorrer las filas correspondientes a cada funcion f_k+1
			vector < vector <int> > terms; //Tabla que guardará los minitérminos de la función f_k+1
			for(int i=0; i<T.size();i++){ //Bucle para añadir cada minitérmino
				int t=T[i].size();
				if(T[i][t-dimension+k]==1){
					terms.push_back(T[i]);
				}
			}
			//Impresión de la función f_k+1
			cout<<"f"<<k+1<<": ";
			for(int i=0; i< terms.size(); i++){
				vector<int > temp=terms[i];
				for(int j=0; j<temp.size()-dimension;j++){ //Impresión de cada minitérmino				
					if(temp[j]==0){
						cout<<"x"<<j+1<<"'";
					}else{
						cout<<"x"<<j+1;
					}					
				}
				if(i!=terms.size()-1){//Condición para no imprimir un signo + extra
					cout<<" + ";
				}
				
			}	
			cout<<endl;	
		}	
		cout<<"\n\nMaxiterminos\n";
		for(int k=0; k<dimension; k++){ //Recorrer las filas correspondientes a cada funcion f_k+1
			cout<<"f"<<k+1<<": ";
			//Impresión de la función f_k+1
			for(int i=0; i<T.size();i++){
				vector <int> temp=T[i];
				if(temp[temp.size()-dimension+k]==0){
					cout<<"(";
					for(int j=0; j<temp.size()-dimension;j++){				
						if(temp[j]==1){
							cout<<"x"<<j+1<<"'";
						}else{
							cout<<"x"<<j+1;
						}
						if(j+1<variables){ //condición para no imprimr un signo + extra considerando el número de variables
				 			cout<<"+";	
						}	
					}
					cout<<")";
				}
			}
			cout<<endl;	
			
			
		}
		
	}
	cout<<"\nF=(";
	for(int k=0; k< dimension; k++){
		cout<<"f"<<k+1;
		if(k<dimension-1){
			cout<<",";	
		}
		
	}
	cout<<")";
	
	
	
	return 0;
}
vector<vector <int > > LeerTabla(int variables, int dimension){
	ifstream file("Tabla.txt");
	vector<vector <int > > T;
	for(int i=0;i<pow(2,variables);i++){
		vector <int> fila;
		int temp;
		for(int j=0; j< variables+dimension; j++){
			file >> temp;
			fila.push_back(temp);
		}
		T.push_back(fila);
	}
	return T;	
}

