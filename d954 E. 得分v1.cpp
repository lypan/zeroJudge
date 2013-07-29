#include<iostream>
using namespace std;
int main(){
	int number = 0;
	cin >> number;
	for(int i = 0; i < number; i ++){
		int method = 0, score = 0;
		cin >> method >> score;
		int temp[method];
		for(int j = 1; j <= method; j ++){
			cin >> temp[j];
		}
		long long reference[method + 1][score + 1];
		
		for(int m = 0; m <= method; m ++){
			for(int s = 0; s <= score; s ++){
				if(s == 0)reference[m][s] = 1;
				else if(m == 0)reference[m][s] = 0;
				else{
					reference[m][s] = reference[m - 1][s];
					if(s - temp[m] >= 0)reference[m][s] += reference[m][s - temp[m]];
				}
			}
		}
		cout << reference[method][score] << endl;
	}

	return 0;
}

