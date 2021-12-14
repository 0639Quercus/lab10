#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double PrevBalance, Interest, InterestRate, Total, Payment, MaxPayment, NewBalance;
	int EndOfYear = 0;

	cout << "Enter initial loan: ";
	cin >> PrevBalance;

	cout << "Enter interest rate per year (%): ";
	cin >> InterestRate;
	InterestRate /= 100;

	cout << "Enter amount you can pay per year: ";
	cin >> MaxPayment;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	do {
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
		EndOfYear++;
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << EndOfYear; 

		cout << setw(13) << left << PrevBalance;

		Interest = PrevBalance * InterestRate;
		cout << setw(13) << left << Interest;

		Total = PrevBalance + Interest;
		cout << setw(13) << left << Total;

		Payment = MaxPayment;
		if (Total < MaxPayment) Payment = Total;
		cout << setw(13) << left << Payment;

		NewBalance = Total - Payment;
		cout << setw(13) << left << NewBalance;
		PrevBalance = NewBalance;

		cout << "\n";	
	} while (NewBalance > 0);

	return 0;
}
