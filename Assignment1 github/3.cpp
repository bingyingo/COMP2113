#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

//initialize variables: input number M, the number of digits in M,
//and the number of permutaitons
string inputM;
int ndigits,  npermu;
//initialize a dynamic M array according to the number of digits in M
int * Marray = new int [ndigits];


//calculate the maximum number of permutaitons
//(is equivalent to the factorial of the number of digits in this question)
void calfactorial()
{
  int producti=1;

  for (int j=1; j<=ndigits; j++)
  {
    producti=producti*j;
  }
  npermu=producti;
}

void setuparray(int array[], int sizeofarray, string str)
{
  //convert the character into integers according to the ASCII code
  for (int i=0; i < sizeofarray; i++){
    array[i]=str[i]-48;
  }
}

//use selectionsort to sort the array in ascending order
void selectionsort(int array[], int sizeofarray)
{
  int i, j, idx;
  int min;

  for ( i = 0; i < sizeofarray; ++i )
  {
    min = array[i];
  	idx = i;
  	for ( j = i + 1; j < sizeofarray; ++j )
  	{
  		if ( array[j] < min )
  		{
  			min = array[j];
  			idx = j;
  		}
  	}
  	if ( idx != i )
    {
  		swap( array[i], array[idx] ); 	// swap values
    }
  }
}

//this function print an array
void printarray(int arr[])
{
  for (int i=0; i<ndigits-1;i++)
  {
    if(arr[i]!=arr[i+1])
    {
      cout << arr[i] << " ";
    }
  }
  cout << arr[ndigits-1];
}

string FirstPermutation(int arr[], int ndigits)
{
  string first;
	string digit;
	stringstream ss;
  for (int i=0; i<ndigits-1;i++)
  {
		ss << arr[i];
    first.append(ss.str());
  }
  return first;
}

void FindNextPermutation(int array[])
{


}

int main()
//从小排到大，下一个也是从小排到大，并且要保证它是所有人里面最小的而且比前一个大》
{
  //input M, calculate the number of digits and permutations
  cin >> inputM;
  ndigits=inputM.length();

  calfactorial();
  //convert the input string to an array of integers
  setuparray(Marray,ndigits,inputM);
  //sort in the ascending order
  selectionsort(Marray, ndigits);

  cout << "See here: " << FirstPermutation(Marray, ndigits) << endl;
  cout << npermu << " "<< endl;
  //printarray(Marray);

  //delete dynamic array to release memory space
  delete [] Marray;
  return 0;
}
