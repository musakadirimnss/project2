using namespace std;

void RnrMbrapsht(int n){
	cout << "NR:" << n << endl;
	n--;
	if (n == 0){
		//resProgram();
	}else{
		RnrMbrapsht(n);
	}
}
void nrMbrapsht(){
	int n;
	rpt:
	cout << "Vendos vleren e numrit n : ";
	cin >> n;
	if (n > 0){
		cout << "--------------------------------------------------------------\n";
		RnrMbrapsht(n);
	}else{
		cout << "\nNumri duhet te jep pozitiv !\n";
		goto rpt;
	}
}
