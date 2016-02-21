/* *
Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

Most bicycle speedometers work by using a Hall Effect sensor fastened to the front fork of the bicycle. A magnet is attached to one of the spokes on the front wheel so that it will line up with the Hall Effect switch once per revolution of the wheel. The speedometer monitors the sensor to count wheel revolutions. If the diameter of the wheel is known, the distance traveled can be easily be calculated if you know how many revolutions the wheel has made. In addition, if the time it takes to complete the revolutions is known, the average speed can also be calculated.

For this problem, you will write a program to determine the total distance traveled (in miles) and the average speed (in Miles Per Hour) given the wheel diameter, the number of revolutions and the total time of the trip. You can assume that the front wheel never leaves the ground, and there is no slipping or skidding.


Input

Input consists of multiple datasets, one per line, of the form:

diameter revolutions time

The diameter is expressed in inches as a floating point value. The revolutions is an integer value. The time is expressed in seconds as a floating point value. Input ends when the value of revolutions is 0 (zero).


Output

For each data set, print:

Trip #N: distance MPH

Of course N should be replaced by the data set number, distance by the total distance in miles (accurate to 2 decimal places) and MPH by the speed in miles per hour (accurate to 2 decimal places). Your program should not generate any output for the ending case when revolutions is 0.

Constants

For p use the value: 3.1415927.
There are 5280 feet in a mile.
There are 12 inches in a foot.
There are 60 minutes in an hour.
There are 60 seconds in a minute.
There are 201.168 meters in a furlong.


Sample Input

26 1000 5
27.25 873234 3000
26 0 1000

Sample Output

Trip #1: 1.29 928.20
Trip #2: 1179.86 1415.84
* */

#include <ios>
#include <iomanip>
#include <iostream>

int main()
{
	float p = 3.1415927;
	float diameter, time;
	int revolutions;
	
	int N = 1;
	double distance, MPH;
	
	std::cin >> diameter >> revolutions >> time;
	
	while (revolutions != 0)
	{
		diameter = diameter / 63360;
		time = time / 3600;
		distance = p * diameter * revolutions;
		MPH = distance / time;
		
		std::cout << "Trip #" << N++ << ": ";
		std::cout << std::fixed << std::setprecision(2) << distance << " " << MPH << "\n";
		std::cin >> diameter >> revolutions >> time;
	}
	return 0;
}

/* *
后记：
    这种题目，似乎是大一的小师弟们做的？
	一次过，
	倒是复习了小数精度的输出问题--->先声明为fixed，而后指定精度，这就够了。
* */