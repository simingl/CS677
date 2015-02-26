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

void mergesort(){

}

int main(int argc, char* argv[])
{
	char* array = "T I N Y E X A M P L E";
	cout << "Maximum is: " << (char)maximum(array, 0, 19)<<endl;
	system("pause");
	return 0;
}

