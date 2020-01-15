#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "kWtoA.h"
#include "VItoRP.h"
#include "nrMbrapsht.h"
using namespace std;
void main2();
void resProgram(){
	char yn;
	rpt:
	cout << "-----------------------------------------------------------------\n\n";
	cout << " { Y = Restart Program }\n"
	     << " { N = Close Program }\n\n";
	cout << " { Y/N } : ";
	cin >> yn;
	if (yn == 'Y' || yn == 'y'){
		cout << "\n----------------------------------------------------------------\n\n";
		cout << "Programi eshte restartuar !\n\n";
		main2();
	}else if(yn == 'N' || yn == 'n'){
		cout << "\nFaleminderit per perdorimin e Programit !";
	}else{
		cout << "\nLejohet vetem Y dhe N !!!\n\n";
		goto rpt;
	}
	
}

double Rfnc1(int px , int x){
	double fnc = 1;
	fnc = px * pow(x,2);
	if (x>1){
		fnc = Rfnc1(fnc ,x-1);
	}
	return fnc;
}

void fnc1(){
	int x;
	cout << "Vendos x : ";
	cin >> x;
	if (x > 1 ){
		cout << "Vlera e Funksionit eshte : " << Rfnc1(x,x-1) << endl; 
	}else{
		cout << "--------------------------------------------------------------\n";
		cout << "Vlera x duhet te jet me e madhe se 1 [x>0]\n";
	}
	resProgram();
}
void RkEtoUL(int euro,int n){
	if (n == 1){
		cout << "Vlera prej " << euro << " Euro eshte = " << euro * 1.12 << " Dollar\n";
		RkEtoUL(euro,2);
	}else{
		cout << "Vlera prej " << euro << " Euro eshte = " << euro * 121.82 << " Lek\n";
		resProgram();
	}
}
void kEtoUL(){
	double euro;
	cout << "Vendos vleren e Euros : ";
	cin >> euro;
	cout << "--------------------------------------------------------------\n";
	RkEtoUL(euro,1);
}
void RfibSeries(int n){
   static int n1=0, n2=1, n3;
   if(n>0){
	   n3 = n1 + n2;
	   n1 = n2;
	   n2 = n3;
	   cout<<n3<<" ";
	   RfibSeries(n-1);
	 }else{
	 	cout << endl;
	 	n1=0;n2=1;n3=0;
	 	resProgram();
	 }
}
void fibSeries(){
    int num;
    cout<<"Vendos numrin e elementeve te seris se Fibonaccit : "; 
	cin>>num;
    cout<<"Seria Fibonacci per "<<num<<" numra: ";
    cout<<"0 "<<"1 ";
    RfibSeries(num-2);
}
int RmbrapshtNr(int n, int temp){
   if (n == 0)
     return temp;
     temp = (temp * 10) + (n % 10);
     return RmbrapshtNr(n / 10, temp);
}
void mbrapshtNr(){
	int num;
    cout<<"Sheno numrin dhe kqyr a lexohet njejt edhe mbrapsht:";
	cin>>num;
    int result = RmbrapshtNr(num, 0);
    cout << "--------------------------------------------------------------\n";
	if (result == num){
		cout << "Numri "<<num<<" mundet te lexohet njejt nga te dyja anet" << endl;
	}else{
		cout << "Numri "<<num<<" nuk mundet te lexohet njejt nga te dyja anet"<< endl;
	}
	resProgram();
}
int Rshuma(int n){
    if(n != 0)
        return n + Rshuma(n - 1);
    return 0;
}
void shuma(){
	int n;
    cout << "Vendos numer pozitiv : ";
    cin >> n;
    cout << "--------------------------------------------------------------\n";
    cout << "Shuma =  " << Rshuma(n) << endl;
    resProgram();
}
int Rperpjestuesi(int n1, int n2){
    if (n2 != 0)
       return Rperpjestuesi(n2, n1 % n2);
    else 
       return n1;
}
void perpjestuesi(){
	int n1, n2;
    cout << "Vendos numrin e par pozitiv : ";
    cin >> n1;
    cout << "Vendos numrin e dyt pozitiv : ";
    cin >> n2;
    cout << "--------------------------------------------------------------\n";
    cout << "Perpjestuesi i " << n1 << " & " <<  n2 << " eshte: " << Rperpjestuesi(n1, n2) << endl;
    resProgram();
}
int RcalcPower(int baza, int rritur){
    if (rritur != 0)
        return (baza*RcalcPower(baza, rritur-1));
    else
        return 1;
}
void calcPower(){
	int baza, rritur, rez;
    cout << "Vendos numrin baz : ";
    cin >> baza;
    cout << "Vendos fuqin(numer pozitiv): ";
    cin >> rritur;
    rez = RcalcPower(baza, rritur);
    cout << baza << "^" << rritur << " = " << rez << endl;
    resProgram();
}
double RmaxNrV(int A[],int max,int i,const int n){
    if (A[i] > max){
		max = A[i];
		if (n > i+1){
			max = RmaxNrV(A,max,i+1,n);
		}
	}else{
		if (n>i+1){
			max = RmaxNrV(A,max,i+1,n);
		}
	}
	return max;
}
void maxNrV(){
	const int n = 5;
	int i=0;
	int A[n];
	int max = 0;
	cout << "Vendos 5 vlera per Vektorin A : \n";
	for (i; i<n; i++){
		cout << "Vendos A[" << i+1 << "]=";
		cin >> A[i];
	}
	max = A[0];
	cout <<  "Vlera Max e Vektorit A eshte = "<<RmaxNrV(A,max,1,n)<<endl;
	resProgram();
}
void RpnNrV(int A[],int i,const int n,int poz,int neg){
	if (A[i] > 0){
		poz++;
	}else{
		neg++;
	}
	i++;
	if (n > i){
		RpnNrV(A,i,n,poz,neg);
	}else{
		cout << "Vektori A ka " << poz << " Nr pozitiv dhe " << neg << " Nr negativ !"<<endl;
	}
}
void pnNrV(){
	const int n = 5;
	int i=0;
	int A[n];
	int max = 0;
	cout << "Vendos 5 vlera per Vektorin A : \n";
	for (i; i<n; i++){
		cout << "Vendos A[" << i+1 << "]=";
		cin >> A[i];
	}
	RpnNrV(A,0,n,0,0);
	resProgram();	
}
void RnrDeriN(int i , int n){
	cout << "Numri : " << i << endl;
	i++;
	if (n >= i){
		RnrDeriN(i,n);
	}
}
void nrDeriN(){
	int n;
	cout << "Vendos numrin per te cilin do te numerohet prej 0 deri tek ai :";
	cin >> n;
	RnrDeriN(1,n);
	resProgram();
}
void main2(){
	int zgjedhja = 0;
	ag:
	cout << "-----------------------------------------------------------------\n";
	cout << "1 - Konverto kW ne Amper [1 Faz dhe 3 Faz]\n"
	     << "2 - Gjej Rezistencen(R)  dhe Fuqin(P) prej V , I\n"
	     << "3 - Numero Mbrapsht\n"
	     << "4 - f(x)= x(x-1)^2 [x > 1 edhe x != 0]\n"
	     << "5 - Koverto EURO ne DOLLAR dhe LEK\n"
	     << "6 - Seria e Finonaccit \n"
	     << "7 - Shiko a Lexohet njejt Numri edhe mbrapsht\n"
	     << "8 - Gjej Shumen e Numrit\n"
	     << "9 - Gjej perpjestuesin e 2 numrave \n"
	     << "10 - Gjej Fuqin e Numrit\n"
	     << "11 - Gjej Numrin me te madh prej 1 Vektorit \n"
	     << "12 - Sa nr pozitiv dhe negativ ka Vektori A \n"
	     << "13 - Numero deri ne Ndonje Numer\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Zgjedh se cilen prej detyrave ke nevoj ta besh me posht : ";
    cin >> zgjedhja;
    cout << "-----------------------------------------------------------------\n";
	switch (zgjedhja){
		case 1:
			kWtoA();
			resProgram();
			break;
		case 2:
			VItoRP();
			resProgram();
			break;
		case 3:
			nrMbrapsht();
			resProgram();
			break;
		case 4:
			fnc1();
			break;
		case 5:
			kEtoUL();
			break;
		case 6:
			fibSeries();
			break;
		case 7:
			mbrapshtNr();
			break;
		case 8:
			shuma();
			break;
		case 9:
			perpjestuesi();
			break;
		case 10:
			calcPower();
			break;
		case 11:
			maxNrV();
			break;
		case 12:
			pnNrV();
			break;
		case 13:
			nrDeriN();
			break;
		default:
			cout << "\nJu lutem zgjedhni vetem prej 1-13!\n\n";
    		goto ag;
			break;
	}
	cout << "\n\n";
}

int main() {
	main2();
	return 0;
}

