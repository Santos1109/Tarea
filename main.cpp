#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
fstream f;
unsigned  t1, t2;
int less=0;
float middle;


struct item{
    int cod;
    string name;
};

void iniciar(){
    t1=clock();
}

void terminar(){
    t2=clock();
}

double duracion(){
    double time = (double(t2-t1)/CLOCKS_PER_SEC);
    return time;
}

void resetear(){
    t1=0;
    t2=0;
}

item item;
int file_Size=34;

string name="Nombre_";

int ss(int quantity){
    int g =quantity - 1;
    while(less<=g)
    {
        middle = (g + less)/2;

        if(key<f[middle])
        {
            g = middle - 1;
        }
        else if(key>f[middle])
        {
            less = middle + 1;
        }
        else
        {
            return middle;
        }
    }
}

void write_on_file(string file_name)
{
    iniciar();
    ofstream out (file_name.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(file_name.c_str());
    }
    out.seekp(ios::ate);
    out.write(item.name.c_str(),30);
    out.write((char*)&item.cod,4);
    out.close();
    terminar();
    cout<<"Tiempo de ejecucion: "<<duracion()<<" s"<<endl;
}


void read(string file_name, int pos)
{
    iniciar();
    char name[30];
    int cod;

    ifstream in(file_name.c_str());
    in.seekg(pos*file_Size);

    in.read(name,50);
    in.read((char*)&cod,4);

    in.close();
    terminar();
    cout<<"Tiempo de ejecucion: "<<duracion()<<" s"<<endl;

}

int BinarySearch(int key,int quantity)
{
    iniciar();
    int greaters = quantity - 1;
    ifstream readfile("record.bin",ios::in);
    if(!readfile)
    {
        cerr<<"No se puede abrir el archivo"<<endl;
        exit(0);
    }

    while(readfile>>item.cod>>item.name)
    {
        f.push_back(item.cod);
    }
    ss(quantity);
    terminar();
    return -1;
}



int main(){

    return 0;
}