using namespace std;

double RkWtoA(double kW,int volts,bool treFaz){
	double A = 1000 * kW / (volts);
	if (treFaz){
		A = 1000 * kW / (volts * sqrt(3));
	}
	cout << "Vlera e " << kW << " kW eshte e barabart me : " << A << " Ampera kur eshte ne tension " << volts << "Volts\n";
	if (volts != 380){
		RkWtoA(kW,380,true);
	}
}

void kWtoA(){
	double kW;
	cout << "Vendos vleren e kW = ";
	cin >> kW;
	cout << "--------------------------------------------------------------\n";
	RkWtoA(kW,220,false);
}
