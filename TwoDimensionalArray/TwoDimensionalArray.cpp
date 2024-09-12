#include<iostream>
#include<array>
using namespace std;

bool isMember(int element, const array<int, 5>& a , int start) {
	if (start >= a.size()) {
		//cout << "is not a member" << endl;
		return false;
	}
	else if (a[start] == element) {
		//cout << "is a member" << endl;
		return true;
	}
	
	isMember(element, a, start + 1);

}

void countPositives(const array<int, 5>& a, int start, int& total, int& sum) {
	if (start >= a.size()) {		
		cout << "Number of positive elements : " << total << endl;
		cout << "Sum of positive elements: " << sum << endl;
		return;
	}

	if (a[start] >= 0) {
		total++;
		sum += a[start];
	}
	countPositives(a, start + 1, total, sum);

}

int sumOfArray(array<int, 5>& a, int start) {
	int sum{0};
	if (start >= a.size()) {	
		return 0;
	}
	sum = a[start] + sumOfArray(a, start + 1);
	
	if (start == 0) {
		cout << "Sum of array: " << sum << endl;
	}
}

int main() {
	array<int, 5> array{-3,2,-1,4,5};

	for (int i = 0; i < 5; i++) {
		int element;
		element = array.at(i);
		isMember(element, array, i);
	}	
	
	int sum{0};
	int total{0};
	countPositives(array, 0, total, sum);

	sumOfArray(array, 0);

}


