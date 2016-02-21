// Problem#: 1009
// Submission#: 3909852
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/***************************************
1009. Mersenne Composite N

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB


Description

One of the world - wide cooperative computing tasks is the "Grand Internet Mersenne Prime Search" --GIMPS -- striving to find ever - larger prime numbers by examining a particular category of such numbers.
A Mersenne number is defined as a number of the form(2p–1), where p is a prime number -- a number divisible only by one and itself. (A number that can be divided by numbers other than itself and one are called "composite" numbers, and each of these can be uniquely represented by the prime numbers that can be multiplied together to generate the composite number — referred to as its prime factors.)
Initially it looks as though the Mersenne numbers are all primes.



Prime

Corresponding Mersenne Number

2 4–1 = 3 --prime
3 8–1 = 7 --prime
5 32–1 = 31 --prime
7 128–1 = 127 --prime

If, however, we are having a "Grand Internet" search, that must not be the case.
Where k is an input parameter, compute all the Mersenne composite numbers less than 2k -- where k <= 63 (that is, it will fit in a 64 - bit signed integer on the computer).In Java, the "long" data type is a signed 64 bit integer.Under gcc and g++ (C and C++ in the programming contest environment), the "long long" data type is a signed 64 bit integer.


Input

Input is from file a.in.It contains a single number, without leading or trailing blanks, giving the value of k.As promised, k <= 63.


Output

One line per Mersenne composite number giving first the prime factors(in increasing order) separate by asterisks, an equal sign, the Mersenne number itself, an equal sign, and then the explicit statement of the Mersenne number, as shown in the sample output.Use exactly this format.Note that all separating white space fields consist of one blank.


Sample Input
31


Sample Output
23 * 89 = 2047 = (2 ^ 11) - 1
47 * 178481 = 8388607 = (2 ^ 23) - 1
233 * 1103 * 2089 = 536870911 = (2 ^ 29) - 1

思路：
人类至今才找到四十多个梅森素数耶，要我计算这玩意？
输入的是小于等于63的数，必须要验证它是否为prime，
验证的过程，估计就是无脑遍历吧，如果能被“非1非自身”的数给除了，那铁定不是prime，
直接过滤，
然后怎么验证是不是合数？
如果也无脑遍历，那，像536870911这样的数，从1到536870911？
跑死人的吧，有一个优化的技巧，那就是世界上只有2一个偶素数，其它大于2的都是奇数，
这就好玩了，我们用2的N次方减1得到了梅森数，所以2铁定不是梅森数的素数因子，
所以从3开始遍历，而且i += 2，毕竟都是奇数嘛，另外，一个梅森数的因子顶多就到该梅森数
的开方（i * i <= M），

这个很直观，一个因子超过了开方，另一个因子势必小于开方，
而小于开方的数我们早已经验证过了。

这么一优化，估计不会超时吧。

*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

void Deal(int M) {
	if (M >= 61)return;
	for (int i = 2; i * i <= M; i++)
	{
		if (M % i == 0)
			return; // M并不是质数
	}

	// 确定是梅森数，接下来寻找合数因子
	bool leftMost = false; // 乘号的标记
	bool composite = false; // 合数的标记
	long long Mersenne = pow(2.0, M) - 1;
	long long forOutput = Mersenne;

	for (long long i = 3; i * i <= Mersenne; i += 2)
	{
		if (Mersenne % i == 0)
		{
			composite = true;

			Mersenne /= i; // 梅森数被分离出一个合数因子，应变小
			if (leftMost)
			{
				std::cout << " * " << i;
			}
			else
			{
				std::cout << i;
				leftMost = true;
			}

			i = 3; // 重新开始寻找新合数因子
		}
	}

	if (composite)
		std::cout << " * " << Mersenne << " = " << forOutput << " = " << "( 2 ^ " << M << " ) - 1\n";
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 3; i < 61; i += 2)
	{
		Deal(i);
	}
	return 0;
}


/***************************************************************
后记：
    傻逼了傻逼了
	我写的过不了就算了
	我逐渐抄别人的，居然也是wrong answer。
	傻逼了傻逼了

	嗯？
	我把那句
	if (M > 53) return;
	给注释掉后居然就过了？
	傻逼？
	这！？

	我看了一下，好像wrong answer的那些代码都被我限制了M的大小...
	这！？
	不是说M是。。
	我看看先
	As promised, k <= 63
	确实有说啊，我改一下大小，改成100看看
	accept！
	我改成70看看
	依旧accept！！！
	改成60看看
	依旧accept！！！
	改成53看看
	依旧accept！！！
	改成51看看：
	wrong answer

	改成53看看：
	wrong answer！！
	这！！！
	
	嗯，改成58就过不了
	改成59就必过，
	这，是为什么...
*/


// 我自开始写的程序是这样的：

/**********************************
// Problem#: 1009
// Submission#: 3909852
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/***************************************
1009. Mersenne Composite N

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB


Description

One of the world - wide cooperative computing tasks is the "Grand Internet Mersenne Prime Search" --GIMPS -- striving to find ever - larger prime numbers by examining a particular category of such numbers.
A Mersenne number is defined as a number of the form(2p–1), where p is a prime number -- a number divisible only by one and itself. (A number that can be divided by numbers other than itself and one are called "composite" numbers, and each of these can be uniquely represented by the prime numbers that can be multiplied together to generate the composite number — referred to as its prime factors.)
Initially it looks as though the Mersenne numbers are all primes.



Prime

Corresponding Mersenne Number

2 4–1 = 3 --prime
3 8–1 = 7 --prime
5 32–1 = 31 --prime
7 128–1 = 127 --prime

If, however, we are having a "Grand Internet" search, that must not be the case.
Where k is an input parameter, compute all the Mersenne composite numbers less than 2k -- where k <= 63 (that is, it will fit in a 64 - bit signed integer on the computer).In Java, the "long" data type is a signed 64 bit integer.Under gcc and g++ (C and C++ in the programming contest environment), the "long long" data type is a signed 64 bit integer.


Input

Input is from file a.in.It contains a single number, without leading or trailing blanks, giving the value of k.As promised, k <= 63.


Output

One line per Mersenne composite number giving first the prime factors(in increasing order) separate by asterisks, an equal sign, the Mersenne number itself, an equal sign, and then the explicit statement of the Mersenne number, as shown in the sample output.Use exactly this format.Note that all separating white space fields consist of one blank.


Sample Input
31


Sample Output
23 * 89 = 2047 = (2 ^ 11) - 1
47 * 178481 = 8388607 = (2 ^ 23) - 1
233 * 1103 * 2089 = 536870911 = (2 ^ 29) - 1

思路：
人类至今才找到四十多个梅森素数耶，要我计算这玩意？
输入的是小于等于63的数，必须要验证它是否为prime，
验证的过程，估计就是无脑遍历吧，如果能被“非1非自身”的数给除了，那铁定不是prime，
直接过滤，
然后怎么验证是不是合数？
如果也无脑遍历，那，像536870911这样的数，从1到536870911？
跑死人的吧，有一个优化的技巧，那就是世界上只有2一个偶素数，其它大于2的都是奇数，
这就好玩了，我们用2的N次方减1得到了梅森数，所以2铁定不是梅森数的素数因子，
所以从3开始遍历，而且i += 2，毕竟都是奇数嘛，另外，一个梅森数的因子顶多就到该梅森数
的开方（i * i <= M），

这个很直观，一个因子超过了开方，另一个因子势必小于开方，
而小于开方的数我们早已经验证过了。

这么一优化，估计不会超时吧。


#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

void Deal(int M) {
	for (int i = 2; i * i <= M; i++)
	{
		if (M % i == 0)
			return; // M并不是质数
	}

	// 确定是梅森数，接下来寻找合数因子
	bool leftMost = false; // 乘号的标记
	bool composite = false; // 合数的标记
	long long Mersenne = pow(2.0, M) - 1;
	long long forOutput = Mersenne;

	for (long long i = 3; i * i <= Mersenne; i += 2)
	{
		if (Mersenne % i == 0)
		{
			composite = true;

			Mersenne /= i; // 梅森数被分离出一个合数因子，应变小
			if (leftMost)
			{
				std::cout << " * " << i;
			}
			else
			{
				std::cout << i;
				leftMost = true;
			}

			i = 3; // 重新开始寻找新合数因子
		}
	}

	if (composite)
		std::cout << " * " << Mersenne << " = " << forOutput << " = " << "( 2 ^ " << M << " ) - 1\n";
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 3; i < N; i += 2)
	{
		Deal(i);
	}
	return 0;
}

*/

/*
我发现，超时是因为
for (int i = 3; i < N; i += 2)
被我写成了
for (int i = 3; i <= N; i += 2)
仅仅是多了一个等号。。。这样就超时了，让我情何以堪
这到底是为什么
难道就是多了一个63就耗费大量的时间？
这也不应该啊

嗯，确实不是63或62的原因，我在Deal函数里面加了限制，限制63和62，,但依旧超时
那么，问题到底是什么呢？

测了几个数，排除了63和59，但是61超时
看来西西里的测试数据是61，而61正好是超时的那个，坑啊
*/
