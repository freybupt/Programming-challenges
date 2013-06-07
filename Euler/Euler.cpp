#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
#include<fstream>
#include<vector>
#include"Euler.h"

using namespace std;

int factorial(int x) {
    return (x == 1 ? x : x * factorial(x - 1));
}

