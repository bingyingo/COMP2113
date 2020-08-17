#include <iostream>
#include <istream>
#include <sstream>
using namespace std;

int main()
{
  //initialize the string that store all the daily price inputs
  string daily;
  //initialize number of inputs, current price, historic lowest price,
  //and profit
  int ninputs = 0, price, low, profit=0;

  //input all daily prices and initialize a stringstream
  getline(cin,daily);
  istringstream ss(daily);
  while (ss >> price)
  {
    //set the price of the first day as the historic lowest price
    if (ninputs == 0 )
    {
      low = price;
    }

    else
    {
      //calculate the daily difference
      int diff = price - low;
      //if the difference is positive and larger than the largest
      //profit in the history, update the largest historic profit accordingly
      if (diff > 0)
      {
        if (diff > profit)
        {
          profit = diff;
        }
      }
      //if the difference is negative, update the historic lowest price
      if (diff < 0)
      {
        low = price;
      }
    }
    ninputs++;
  }
  //print the largest historic profit possible
  cout << profit;
  return 0;
}
