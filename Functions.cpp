/*  Taskkill /F /IM "Functions.exe" /T
*/
#include <iostream>
#include <windows.h>
using namespace std;


int getSize(char* charArray) //returns the actual size of an char* array. char[20]="Hi!\n"; actual size 4.
{
    int size = 0; //size = number of characters before '\0'

    while (charArray[size] || charArray[size]!=NULL)
    {
        size++;
    }
    return( size );
}

void get_If_Int(int* pInput)//take input if input is `int or float` 
{	
							//pInput is a pointer to the actual int_variable. ``main(){int i; getIntegerInput(&i);}``
	if(cin >>*pInput) //if inputs are in expexted format(int), 'cin' returns 'true'. so, code inside 'if' is executed
	{
		return; /*do stuff*/ //'if(cin >>i >>j)' is possible too. pInput is pointer, so *pInput is the actual variable
	}
	else //inputs(i or j or both) are not in expected format(int). so clear cin-s internal buffer and the input buffer
	{
		cout<< "Invalid input type.\n";
		cin.clear(); //clears cin-s internal buffer
		cin.ignore(100, '\n'); //100 --> asks cin to discard 100 characters from the input stream.
		Sleep(950); //wait 950 millisec cause humans need time to read.
		//exit(EXIT_FAILURE); //if want to stop the program here
	} 
}

void get_Untill_Int(int* pInput)//keep taking input untill input is `int or float`
{
	cin>> *pInput;
	/*-----------check input validation----------------*/
	while (!cin) 
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout<<"Invalid Input Type.\nEnter again: ";
		cin >>*pInput;
	}
	/*-----------checked input validation-------------*/
}

string StringInput()  //returns null-terminated string
{
    string input;
    getline(cin, input);
    while(input.length()==0)//keep taking input untill valid string is taken
    {
        getline(cin, input);
    }
    return input.c_str();
}

void Exchange(int *p,int *q)
{
     int temp=*p;
     *p = *q;
     *q = temp;
}

void quicksort(int a[],int low,int high) //low = 0; high = arraysize; a[] = unsorted array;
{
	int i, j, key;
	if(low>=high)
	return;
	key=low; i=low+1; j=high;
	while(i<=j)
	{
		while (a[i]<= a[key]) i= i+1;
		while (a[j]> a[key]) j= j-1;

		if(i<j) Exchange(&a[i], &a[j]);

	}

	Exchange(&a[j], &a[key]);
	quicksort(a, low, j-1);
	quicksort(a, j+1, high);
}

bool isPrime(int num) //returns 0 if `num` is prime, else return -1
{
    if (num == 2)
    {
        return 0; //2 is a prime number
    }
    if (num%2 == 0)
    {
    	return -1; //num is an even number, so, not prime
    }

    int limit = sqrt(num); //sqrt(56) will return 7.544 but limit will store 7, cause limit<-int
    if (limit*limit == num)
    {
        return -1; //num is a square number, so, not prime
    }

    for (int i = 3; i <= limit; i = i+2)//to find if a number is prime or not, we only have to divide it from 2 to sqrt(num).
    {                                   //i=i+2 skips even number, cause already cheacked if it's even or not.
        if (num % i == 0)
        {
            return -1; //`num` is divisible by i, so, not prime
        }
    }
    return 0; //no divisible number found. so, num is prime.
}

int main(int argc, char const *argv[])
{
	wall(6);
	int i;
	get_Untill_Int(&i);
	return 0;
}
