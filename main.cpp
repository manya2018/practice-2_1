#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;  // TASK 1:
class camera
{
public:
    string type;
    double memory;
    double resolution;
public:
    camera()
    {
        type=' ';
        memory =0;
        resolution =0;
    }
    camera(char type,double memory, double resolution)
    {
        this -> type=type;
        this -> memory=memory;
        this -> resolution=resolution;
    }
    void print()
    {
        cout << "memory capacity:   " << memory << " Gb" <<  endl;
        cout << "camera resolution: " << resolution << " Mp" << endl;
        cout << "data type:         " << type << endl;
    }

    void Size()
    {
        if (type=="raw")
        {
            cout << "maximum number of photos : " << memory * pow(2, 10) / (resolution * 3) << endl;
        }
        if (type=="jpeg")
            {
            cout << "maximum number of photos : " << memory * pow(2, 10) / (resolution * 3) * 10 << endl;
            }
    };
};
class copter
{
public:
    double speed;
    double power;
    double weight;
public:
    copter()
    {
        speed =0;
        power =0;
        weight =0;
    }
    void print()
    {
        cout << "maximum speed:     " << speed << " km/h" <<  endl;
        cout << "power:             " <<power << " W" << endl;
        cout << "weight:            " << weight  << " kg" << endl;
    }
    copter(double  speed, double power, double weight)
    {
        this -> speed=speed;
        this -> power=power;
        this -> weight=weight;
    }
    void overclocking()
    {
        cout << "acceleration time to maximum speed : " << weight*speed*speed/2/power<<" s" << endl;
    }
};
class quadrocopter : public camera , public copter
{
public:
    void print()
    {
        cout << "memory capacity:   " << memory << " Gb" <<  endl;
        cout << "camera resolution: " << resolution << " Mp" << endl;
        cout << "data type:         " << type << endl;
        cout << "maximum speed:     " << speed << " km/h" <<  endl;
        cout << "power:             " << power << " W" << endl;
        cout << "weight:            " << weight  << " kg" << endl;
    }
    void data_record()                                                    //TASK 2:
    {
        ofstream fout("Quadrocopter.txt");
        fout << "memory capacity:   " << memory << " Gb" <<  endl;
        fout << "camera resolution: " << resolution << " Mp" << endl;
        fout << "data type:         " << type << endl;
        fout << "maximum speed:     " << speed << " km/h" <<  endl;
        fout << "power:             " << power << " W" << endl;
        fout << "weight:            " << weight  << " kg" << endl;
        fout.close();
    }
};
void arr_output()                                                            //TASK 3
{
    int arr[]={1,2,3,4,5,6,78,8,};
    int Size=8;
    for (int i=0; i<Size;i++)
    {
        cout << *(arr+i) << ", ";
    }

}
int main() {
    quadrocopter A;                                               // TASK 1,2
    A.speed=90;
    A.weight=20;
    A.power=100;
    A.resolution=4;
    A.memory=1;
    A.type="raw";

    A.print();
    A.overclocking();
    A.Size();
    A.data_record();                                            //TASK 3
    arr_output();
    return 0;
}
