#include <iostream>
#include <istream>
#include <sstream>
using namespace std;

int main()
{
  //initialize the string that store all the daily price inputs
  string daily;
  //initialize number of inputs, current price, possible buy in price,
  //possible sell price, and profit
  int ninputs = 0, price, in, out, profit=0;

  //input all daily prices and initialize a stringstream
  getline(cin,daily);
  istringstream ss(daily);
  while (ss >> price)
  {
    //set the price of the first day as the possible buy in price
    if (ninputs == 0 )
    {
      in = price;
    }

    else
    {
      //set the price of the first day as the possible sell price
      out = price;
      //if possible sell price > possible buy in price,sell the stock,
      //mark down the cummulative profit,
      //and reset the buy in price to the price of the day
      if (in < out)
      {
        profit=profit + (out - in);
        in = out;
      }
      if (in >= out)
      {
        in = out;
      }
    }
    ninputs++;
  }
  //print cumulative profit
  cout << profit;
  return 0;
}
