#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Reduce(int A[], int inicio, int final) {
    int izq = inicio;
    int der = final;
    int pos = izq;
    int cen = 1;

    while (cen == 1) {
        cen = 0;

        
        while (A[pos] <= A[der] && pos != der) {
            der--;
        }
        if (pos != der) {
            int aux = A[pos];
            A[pos] = A[der];
            A[der] = aux;
            pos = der;
        }

    
        while (A[pos] >= A[izq] && pos != izq) {
            izq++;
        }
        if (pos != izq) {
            int aux = A[pos];
            A[pos] = A[izq];
            A[izq] = aux;
            pos = izq;
            cen = 1;
        }

        
        if (pos - 1 > inicio) {
            Reduce(A, inicio, pos - 1);
        }

        
        if (pos + 1 < final) {
            Reduce(A, pos + 1, final);
        }
    }
}
	

void QuickSort(int A[],int n){
	
	Reduce(A,0,n);
	
}

void InterDirIzq(int A[],int n){
	for(int i=1;i<n;i++){
		for(int j=n-1;j>i-1;j--){
			if(A[j] < A[j-1]){
				int aux = A[j-1] ;
				A[j-1] = A[j] ;
				A[j] = aux ;
			}
		}
	
	}
}
int main(){
	int resp;
	srand(time(0));
	int tam;
	cout<<"Ingrese la cantidad de terminos a evaluar\n";
	cin>>tam;
	
	int QUICK[tam];
	int ORDI[tam];
	int A[tam];
	for(int i=0;i<tam;i++){
		A[i]=rand()%tam+1;
	}
	cout<<"Lista generada: ( ";
	for(int i=0; i<tam;i++){
		if(i==tam-1){
			cout<<A[i]<<" ) ";
		}else{
			cout<<A[i]<<" , ";
		}	
	}
	for(int i=0;i<tam;i++){
		QUICK[i]=A[i];
	}
	for(int i=0;i<tam;i++){
		ORDI[i]=A[i];
	}
	do{
		cout<<"\nELIJA EL METODO DE ORDENAMIENTO:";
		cout<<"\n1)Quicksorth\n";
		cout<<"\n2)Ordenamiento directo por la izquierda"<<"\nresp: ";cin>>resp;
		if(resp==1){
			
			clock_t inicio = clock();
			QuickSort(QUICK,tam);
			
			clock_t fin = clock();
    		double duracion = double(fin - inicio) / CLOCKS_PER_SEC;
    		// Mostrar el tiempo en segundos
    		
    		
			cout<<"Lista despues: ( ";
			for(int i=0; i<tam;i++){
				if(i==tam-1){
					cout<<QUICK[i]<<" ) ";
				}else{
					cout<<QUICK[i]<<" , ";
					}	
			}
			cout << "Tiempo de ejecución: " << duracion << " segundos" << endl;
		}else if(resp==2){
			
			clock_t ini = clock();
			InterDirIzq(ORDI,tam);
			
			clock_t fini = clock();
    		double duracio = double(fini - ini) / CLOCKS_PER_SEC;
    		// Mostrar el tiempo en segundos
    		
    		
			cout<<"Lista despues: ( ";
			for(int i=0; i<tam;i++){
				if(i==tam-1){
					cout<<ORDI[i]<<" ) ";
				}else{
					cout<<ORDI[i]<<" , ";
					}	
			}
			cout << "Tiempo de ejecución: " << duracio << " segundos" << endl;
		}
		
		
	}while(resp!=0);
	
	
	
	cout<<endl<<endl;
	
	
	
	
	return 0;
}
