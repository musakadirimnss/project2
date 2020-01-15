using namespace std;

void RVItoRP(double Volt , double Intensitet, int n){
	double R,P;
	if (n == 1){
		R = Volt / Intensitet;
		cout << "Rezistenca prej " << Volt << " Volteve dhe " << Intensitet << " Amperave eshte = " << R  << " (OHM)"<< endl;
		RVItoRP(Volt,Intensitet,2);
	}else{
		P = Volt * Intensitet;
		cout << "Fuqia prej " << Volt << " Volteve dhe " << Intensitet << " Amperave eshte = " << P << " Watt" <<  endl;
		//resProgram();
	}
}
void VItoRP(){
	double V;
	double I;
	cout << "Vendos vleren e V = ";
	cin >> V;
	cout << "Vendos vleren e I = ";
	cin >> I;
	cout << "--------------------------------------------------------------\n";
	RVItoRP(V,I,1);
}
