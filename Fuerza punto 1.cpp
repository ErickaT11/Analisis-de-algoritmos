using namespace std;
#include <bits/stdc++.h>
#define largo 100
void insercion(int A[])
{
      int i,j,v;
      for (i = 1; i < largo; i++)
        {
             v = A[i];
             j = i - 1;
             while (j >= 0 && A[j] > v)
             {
                  A[j + 1] = A[j];
                  j--;
             }
             A[j + 1] = v;
      }   
}
void generarCadena(int n[])
{
    int i;
    for(i=0;i<largo;i++)
    {
        n[i] = 1+rand()%(101-1);
    }
}

void muestraCadena(int cant,vector<int> n)
{
    int i;
    
    for(i=0;i<cant;i++)
    {
        
        cout<<n[i]<<"  ";
    }
    cout<<endl;
}

int partir(vector<int> A, int n){
    vector<int> B;
    
    if(A.size() < 5){
        return 1;
    }
    else{
     muestraCadena(5, A);

     for(int i = 5; i<n; i++)
         B.push_back(A[i]);
    
     A.clear();
     for(int j = 0; j<B.size(); j++)
        A.push_back(B[j]);
     
     return partir(A, A.size());
    }
}
int main () 
{
    int A[largo],n, resultado;
    std::vector<int> arr;
    //genera la cadena con nC:meros aleatorios de 1 hasta 100
    generarCadena(A);
    //Ordena la cadena completa
    insercion(A);
    //Divide en grupos de 5 elementos 
    for(int i = 0; i<largo; i++)
        arr.push_back(A[i]);

    resultado = partir(arr, largo);
}
