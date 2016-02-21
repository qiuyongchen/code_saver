/*
1004. I Conduit!

Constraints

Time Limit : 3 secs, Memory Limit : 32 MB

Description

Irv Kenneth Diggit works for a company that excavates trenches, digs holes and generally tears up people's yards. Irv's job is to make sure that no underground pipe or cable is underneath where excavation is planned.He has several different maps, one for each utility company, showing where their conduits lie, and he needs to draw one large, consolidated map combining them all.One approach would be to simply draw each of the smaller maps one at a time onto the large map.However, this often wastes time, not to mention ink for the pen - plotter in the office, since in many cases portions of the conduits overlap with each other(albeit at different depths underground).What Irv wants is a way to determine the minimum number of line segments to draw given all the line segments from the separate maps.

Input

Input will consist of multiple input sets.Each set will start with a single line containing a positive integer n indicating the total number of line segments from all the smaller maps.Each of the next n lines will contain a description of one segment in the format x1 y1 x2 y2 where(x1, y1) are the coordinates of one endpoint and (x2, y2) are the coordinates of the other.Coordi - nate values are floating point values in the range 0... 1000 specified to at most two decimal places.The maximum number of line segments will be 10000 and all segments will have non - zero length.Following the last input set there will be a line containing a 0 indicating end of input; it should not be processed.

Output

For each input set, output on a single line the minimum number of line segments that need to be drawn on the larger, consolidated map.

Sample Input
3
1.0 10.0 3.0 14.0
0.0 0.0 20.0 20.0
10.0 28.0 2.0 12.0
2
0.0 0.0 1.0 1.0
1.0 1.0 2.15 2.15
2
0.0 0.0 1.0 1.0
1.0 1.0 2.15 2.16
0


Sample Output
2
1
2

思路：
	计算线条是否重合？
*/

#include <iostream>
#include <cmath>
#include <algorithm>

int NA = 1000000;

bool same(double a, double b) {
	return fabs(a - b) < 1e-6;
}

class Line
{
public:
	double k, b, x1, y1, x2, y2;
};

Line l[10002];

bool cmp(Line a, Line b) {
	if (same(a.k, b.k))
	{
		if (a.k == NA)
		{
			if (same(a.b, b.b))
			{
				if (a.y1 == b.y1)
				{
					return a.y2 < b.y2;
				}
				else
				{
					return a.y1 < b.y1;
				}
			}
			else
			{
				return a.b < b.b;
			}
		}
		else if (same(a.b, b.b))
		{
			if (a.x1 == b.x1)
			{
				return a.x2 < b.x2;
			}
			else
			{
				return a.x1 < b.x1;
			}
		}
		else
		{
			return a.b < b.b;
		}
	}
	else
	{
		return a.k < b.k;
	}
}

int main() {
	int n, count;
	double x1, y1, x2, y2, temp, x, y;

	while (std::cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			std::cin >> x1 >> y1 >> x2 >> y2;

			if (x1 > x2 || x1 == x2 && y1 > y2)
			{
				temp = x1;
				x1 = x2;
				x2 = temp;
				temp = y1;
				y1 = y2;
				y2 = temp;
			}

			l[i].x1 = x1;;
			l[i].x2 = x2;
			l[i].y1 = y1;
			l[i].y2 = y2;

			if (x1 != x2)
			{
				l[i].k = (y2 - y1) / (x2 - x1);
				l[i].b = y1 - l[i].k * x1;
			}
			else
			{
				l[i].k = NA;
				l[i].b = x1;
			}
		}

		std::sort(l, l + n, cmp);

		x = l[0].x2;
		y = l[0].y2;
		count = 1;

		for (size_t i = 1; i < n; i++)
		{
			if (!same(l[i].k, l[i - 1].k) || !same(l[i].b, l[i - 1].b))
			{
				++count;
				x = l[i].x2;y = l[i].y2;
			}
			else if (l[i].k != NA && l[i].x1 > x || l[i].k == NA && l[i].y1 > y)
			{
				++count;
				x = l[i].x2;y = l[i].y2;
			}
			else if (l[i].k != NA && l[i].x2 > x || l[i].k == NA && l[i].y2 > y)
			{
				x = l[i].x2;y = l[i].y2;
			}

			
		}

		std::cout << count << "\n";
	}
	return 0;
}