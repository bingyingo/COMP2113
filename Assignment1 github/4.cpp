//key找到上下左右各自的bound

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//initialize the leftest, rightest, highest, lowerst points and the
//central position x, y of AABB
double yhigh,ylow,xleft,xright, x, y, width, height;
//intialize the temp group for intermediate calculations
double yhightemp, ylowtemp, xlefttemp, xrighttemp;
//record the number of input lines
int numberofinputs=0;

//this function update the position variables of AABB according to each input line
void update()
{
  //if there are no prior inputs, the AABB is set to be the minimum-sized AABB
  //that can enclose the first figure
  if (numberofinputs == 0)
  {
    yhigh = yhightemp;
    ylow = ylowtemp;
    xleft =xlefttemp;
    xright = xrighttemp;
  }
  //if there are prior inputs, the function will compare the previous AABB with
  //the minimum-sized AABB that can enclose the current figure, and update the
  //previous AABB if it is too small
  else
  {
    if (yhigh < yhightemp)
    {
      yhigh = yhightemp;
    }
    if (ylow > ylowtemp)
    {
      ylow=ylowtemp;
    }
    if (xleft > xlefttemp)
    {
      xleft = xlefttemp;
    }
    if (xright < xrighttemp)
    {
      xright = xrighttemp;
    }
  }
  numberofinputs++;
}
//this function returns the minimu-sized AABB that can enclose a given rectangle
void rectangle(double xi, double yi, double widthi, double heighti)
{
  yhightemp = yi+heighti/2;
  ylowtemp = yi-heighti/2;
  xlefttemp =xi-widthi/2;
  xrighttemp = xi+widthi/2;

  update();

}

//this function returns the minimu-sized AABB that can enclose a given circle
void circle(double xi, double yi, double radius)
{
  yhightemp = yi+radius;
  ylowtemp = yi-radius;
  xlefttemp =xi-radius;
  xrighttemp = xi+radius;

  update();
}

//this function returns the minimu-sized AABB that can enclose a given point
void point(double xi, double yi)
{
  yhightemp = yi;
  ylowtemp = yi;
  xlefttemp =xi;
  xrighttemp = xi;

  update();
}

int main()
{
  string line, type;
  //reads the input line by line
  while (getline(cin,line))
  {
    //use stringstream to process words in each line one by one
    stringstream ss(line);
    //the first word indicates the type of figure/stop word #
    ss >> type;
    {
      if (type == "#")
      {
        break;
      }
      else
      {
        if (type == "R")
        {
          //reads the dimenstions of the rectangle
          double xi, yi, widthi, heighti;
          ss >> xi; ss >> yi; ss >> width; ss >>height;
          rectangle(xi,yi,width,height);
        }
        else if (type == "C")
        {
          //reads the dimensions of the circle
          double xi, yi, radius;
          ss >> xi; ss >> yi; ss >> radius;
          circle(xi, yi, radius);
        }
        else if (type == "P")
        {
          //reads the number of points and the position of each point
          int n;
          ss >> n;
          for (int i=1; i <=n; i++)
          {
            double xi, yi;
            ss >> xi; ss >> yi;
            point(xi,yi);
          }
        }
      }
    }
  }
  height = yhigh - ylow;
  width = xright - xleft;
  x = (xright+xleft)/2;
  y = (yhigh+ylow)/2;
  cout << x << " " << y << " " << width << " " << height;
  return 0;
}
