#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  //Record Queenie's Location
  int qx, qy;
  cin >> qx >> qy;


  //Input the number of puppies and record each puppy's location
  int n, total = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int xi, yi;
    double diff;
    cin >> xi >> yi;
    //calculate the distance between Queenie and the puppy, and output the id of puppy if it is too far away
    diff = (xi-qx)*(xi-qx)+(yi-qy)*(yi-qy);
    if (sqrt(diff) > 10)
    {
      //print "and" if there are more than one puppy too far away
      if (total != 0)
      {
        cout << "and ";
      }
      // print the id of the current puppy under consideration
      cout << "Puppy " << i << " ";
      // record the total number of puppies that are too far away
      total += 1;
    }
  }

  {if (total > 0)
  { // complete the statement about the id of each puppy far away
    cout << "too far away" << endl;

    //state the total number of puppies far away
    if (total == 1 )
    {
    cout << "Total " << total << " puppy too far away";
    }

    if (total > 1 )
    {
    cout << "Total " << total << " puppies too far away";
    }
  }

  else
  {
    cout << "No puppies too far away";
  }}

  return 0;
}
