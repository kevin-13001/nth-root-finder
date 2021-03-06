/****
* PSEUDOCODE:
*
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "nth_root_finder.h"

using namespace std;

double BinaryHelper(double given, int n, double start, double end, double stopPoint){
    double mid = start + (end - start)/2;
    double value = 1.0;
    for(int i = 1; i <= n; i++){
      value *= mid;
    }
    double diff = value - given;
    if(diff < 0){
      diff = -1 * diff;
    }
    if(diff < stopPoint){
      return mid;
    }
    if(value > given){
      return BinaryHelper(given, n, start, mid, stopPoint);
    }else if(value < given){
      return BinaryHelper(given, n, mid, end, stopPoint);
    }else{
      return mid;
    }
    return -1;

}

string FindNthRoot(int number, int n, int precision) {
    std::stringstream precisionValue;
    double given = static_cast<double>(number);
    double start = 0.0;
    double end = static_cast<double>(number);
    if(number == 1){
      precisionValue << fixed << std::setprecision(precision)<< end;
      return precisionValue.str();
    }
    double stopPoint = 1.0;
    for(int i = 0; i < precision; i++){
      stopPoint *= 0.1;
    }
    double output = BinaryHelper(given, n, start, end, stopPoint);
    precisionValue << fixed << std::setprecision(precision)<< output;
    return precisionValue.str();
}
