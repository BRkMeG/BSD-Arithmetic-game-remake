#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main(){

	int x = 0, y = 0;
	int av_err = 3;
	int maxnum = 0;
	int p_s_m, res_fin, res_us;
	int diffic_num;
	int count = 0;
	int ri_an = 0;
	int message = 0;
	int pick_mesg = 0;
	int bonus_count = 0;
	bool correct = true;



	srand(time(NULL));

	cout << "\033[2J\033[1;1H";

	cout << "Welcome to Arithmetic, the remake of the BSD game!" << endl << endl;
	cout << "1. Easy\n2. Normal\n3. Medium\n4. Hard\n5. Master" << endl << endl;
	cout << "Please, type the number of difficulty: ==> ";
	cin >> diffic_num;

	switch(diffic_num){

		case 1: maxnum = 10; break;
		case 2: maxnum = 20; break;
		case 3: maxnum = 40; break;
		case 4: maxnum = 70; break;
		case 5: maxnum = 100; break;

	} // end of the switch

	cout << "\033[2J\033[1;1H";

	while(av_err != 0){
		
		for(int i = 1; i<=15; i++){

			cout << "|------------------------|" << endl;
			cout << "| Right answer: " << ri_an << endl;
			cout << "| Errors avaible: " << av_err << endl;
			cout << "| Record to beat: 100" << endl;
			cout << "|------------------------|" << endl << endl;

			message++;
			if(message==18){
				cout << "Message from CPU: ";
				message = 0;
				pick_mesg = rand() % 9;

				switch(pick_mesg){
					case 0:	cout << "Good Job!"; break;
					case 1: cout << "Great!"; break;
					case 2: cout << "Go on!"; break;
					case 3: cout << "Amazing!"; break;
					case 4: cout << "Rock 'n Roll!"; break;
					case 5: cout << "Nice!"; break;
					case 6: cout << "Fantastic!"; break;
					case 7: cout << "Wow!"; break;
					case 8: cout << "Awesome!"; break;
					case 9: cout << "Excellent!"; break;
				}
				cout << endl << endl;
			}	// here ends the if


			bonus_count++;
			if(bonus_count==50){
				bonus_count = 0;
				cout << "You got a little bonus: you got a plus error avaible! Great job!" << endl << endl;
				av_err++;}



			correct = true;

			if(av_err == 0)
				break;

			x = 0;
			while(x==0)			// <== if x = 0 then y must be 0, and this cycle prevent from this.
				x = rand() % maxnum;

			y = rand() % x;
			p_s_m = rand() % 100;

			if(p_s_m < 50){
				res_fin = x - y;
				cout << x << " - " << y << " = ";
			}else if(p_s_m >= 50){
				res_fin = x + y;
				cout << x << " + " << y << " = ";}

			// here "ends" the automation, now it's the turn of user who must type the correct result.

			cin >> res_us;

			while(res_us != res_fin){

				av_err--;
				ri_an--;
				correct = false;

				if(av_err == 0)
					break;

				cout << "Not correct! Retry: ==> ";
				cin >> res_us;}				// here ends the while which decides if the answer is right or wrong.

			if(correct == true)
				ri_an++;

			cout << "\033[2J\033[1;1H";

		} // end of the for; the for repeats for every single operation.

		cout << "\033[2J\033[1;1H";

	} // end of the "main" while; the while repeats for every fifteen operations.

	cout << "You lost the game!" << endl;
	cout << "Good try!" << endl << endl << endl << endl;

	return 0;

} // end of the game
