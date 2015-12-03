#include<fstream>
using namespace std;


int main()
{
fstream amirstream;
amirstream.open("amirFile",ios::out);
amirstream<<"Hello everybody,thank you for your commits"<<endl;
amirstream<<"In this repository Do anything and learn everything!!"<<endl;
return 0;
}


