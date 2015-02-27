// Homework.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>

using namespace std;

int maximum(char* array, int l, int r){
	if (l == r) return array[l];
	int m = (l + r) / 2;
	int ml = maximum(array, l, m);
	int mr = maximum(array, m+1, r);
	int v = max(ml, mr);
	cout << (char)v << ", (" << l << "," << r << ")" << endl;
	return v;
}

void merge(char* array, int l, int m, int r, int length){
	int llen = m - l;
	int rlen = r - m;
	char* L = new char[llen+1];
	char* R = new char[rlen+1];

	L[llen] = 127;
	R[rlen] = 127;
	memcpy(L, &(array[l]), m - l);
	memcpy(R, &(array[m]), r - m);

	int i = 0;
	int j = 0;
	for (int k = l; k < r; k++){
		if (L[i] < R[j]){
			array[k] = L[i++];
		}
		else{
			array[k] = R[j++];
		}
	}

	
	for (int i = l; i < r; i++){
		cout << array[i];
	}
	cout << endl;

	delete L;
	delete R;
}

void mergesort(char* array, int length){
	int m = 1;
	for (m = 1; m < length; m *= 2){
		for (int i = 0; i < length; i += 2 * m){
			int l = i;
			int mid = i + m;
			int r = i + 2*m;
			if (mid > length) mid = length;
			if (r > length) r = length;
			merge(array, l, mid, r, length);
		}
	}

}

int main(int argc, char* argv[])
{
	char sa[] = "A S O R T I N G E X A M P L E";
	//problem 2
	mergesort(sa, sizeof(sa)-1);
	system("pause");
	return 0;

	//problem 1
	char ma[] = "T I N Y E X A M P L E Z";
	cout << "Maximum is: " << (char)maximum(ma, 0, sizeof(ma)-2)<<endl;
	system("pause");
	return 0;
}

