#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>



void MostrarLinea(int, const char* const ,double);

int main(){
    int cuenta;
    char nombre[30];
    double saldo = 0.0;
    int opc;

    int num = 0;

    std::ifstream archivoClientesEntrada;
    archivoClientesEntrada.open("clientes.txt", std::ios::in);

    if(!archivoClientesEntrada){
        std::cerr<<"No se puedo abrir el archivo";
        exit(1);
    }

do{ 

    std::cout<<"\t --- MENU - INVESTIGACION DE CREDITOS  \n\n"
    <<"[1] - Mostrar cuentas con saldos en ceros   \n"
    <<"[2] - Mostrar cuentas con saldo acredor (-) \n"
    <<"[3] - Mostrar cuenta con saldo deudor(+)    \n"
    <<"[4] - Salir \n"
    <<"Seleccione una operacion: -> ";
    std::cin>>opc;
    switch (opc)
    {
    case 1:
        std::cout<<"\t --- SALDOS EN CEROS --- \n";   
        std::cout<<std::left<<std::setw(10)<<"CUENTA"<<std::setw(13)<<"NOMBRE"<<
        "SALDO"<<std::endl<<std::fixed<<std::showpoint;
        
        while(archivoClientesEntrada>>cuenta>>nombre>>saldo){//ciclo recolector 
        if(saldo == 0){
            MostrarLinea(cuenta,nombre ,saldo);
        }
    }
        break;
    case 2:
        std::cout<<"\t --- SALDOS ACREDOR --- \n";   
        std::cout<<std::left<<std::setw(10)<<"CUENTA"<<std::setw(13)<<"NOMBRE"<<
        "SALDO"<<std::endl<<std::fixed<<std::showpoint;
        while(archivoClientesEntrada>>cuenta>>nombre>>saldo){//ciclo recolector 
        if(saldo < 0){
            MostrarLinea(cuenta,nombre ,saldo);
        }
    }
        break;
    case 3:
        std::cout<<"\t --- SALDOS DEUDOR --- \n";   
        std::cout<<std::left<<std::setw(10)<<"CUENTA"<<std::setw(13)<<"NOMBRE"<<
        "SALDO"<<std::endl<<std::fixed<<std::showpoint;
        while(archivoClientesEntrada>>cuenta>>nombre>>saldo){//ciclo recolector 
        if(saldo > 0){
            MostrarLinea(cuenta,nombre ,saldo);
        }
    }
        break;
    case 4: 
        break;
    }
}while(opc != 0);

}

void MostrarLinea(int cuenta, const char * const nombre , double saldo){
    std::cout<<std::left<<std::setw(10)<<cuenta<<std::setw(13)<<nombre<<
    std::setw(7)<<std::setprecision(2)<<std::right<<saldo<<"\n";
}
