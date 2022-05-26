#include<iostream>
#include <vector> // za rabota so vektori
#include<algorithm> // za sortiranjeto
#include <fstream>  // za rabota so fajlovi
using namespace std;

struct Profil
{
int IDBroj;
string Nickname;
float nivo;

};


// funckija koja pravi sporedba na elementite od vektorot
// proveruva eden po eden za sekoj profil  i gi sortira po azbucen redosled
bool customCompare(const Profil &x, const Profil &y)
{
   return (x.Nickname < y.Nickname);
}


// funkcija koja ja pecati strukturata od vektori
void Print(vector<Profil> &p)
{
for(int i = 0; i<p.size(); ++i)
{
cout<<p[i].IDBroj << " " << p[i].Nickname << " " << p[i].nivo << endl;
}
}



int main()
{

// deklaracija na vektorot
vector<Profil> p;

// inicijalizacija na vektorot
p.push_back({1,"Ljupcho", 4});
p.push_back({2,"Dimitar", 6});
p.push_back({3,"Tome", 3});
p.push_back({4,"Mitko", 5});
p.push_back({5,"Naume", 4});

cout<<"Pred da se sortira:\n"<<endl;
Print(p);

    // sortiranje 
sort(p.begin(),p.end(), customCompare);

cout<<endl<<"Posle Sortiranje :\n"<<endl;
Print(p);


// otvoranje na fajl i zapisuvanje vo fajlots
fstream file;
    file.open("885Dimitar.txt",ios_base::out);
 
 
 // cikluz za zapisuvanje vo fajlot po red na id nickname i nivo
    for(int i=0;i<p.size();i++)
    {
        file<<p[i].IDBroj << " " << p[i].Nickname << " " << p[i].nivo << endl;
    }
 
    file.close();

}
