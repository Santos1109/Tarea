#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

unsigned  t1, t2;
fstream bin;

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
    int less = 0;
    int greaters = quantity - 1;
    float middle;
    ifstream readfile("record.bin",ios::in);
    if(!readfile)
    {
        cerr<<"No se puede abrir el archivo"<<endl;
        exit(0);
    }
    int code;
    char name[30];
    while(readfile>>code>>name)
    {
        bin.push_back(code);
    }
    while(less<=greaters)
    {
        middle = (greaters + less)/2;

        if(key<bin[middle])
        {
            greaters = middle - 1;
        }
        else if(key>bin[middle])
        {
            less = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    terminar();
    return -1;
}



int main(){

    return 0;
}