// Problem#: 1021
// Submission#: 3841080
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/** *
夫妻圆环问题，从一个排成圆圈的一堆人，如果相邻的人是夫妻，则他们离开圆圈，这般筛选到最后，如果圆圈里边没人了那就成功了。

没有好的思路，怎么样才能减小时间和空间的复杂度呢？
莫非只能暴力一轮一轮地查看，不断地去掉夫妻们？这，效率也太低了，我觉得应该有什么巧妙的数学模型在里面...
可惜我找不出。
先暴力轮询一遍看看。

思路：设置一个环，这个环暂时用链条代替，头尾相连就成了一个环。
     往环中输入数据，把相邻夫妻踢出去，如果最后环为空，肯定是输出yes了。
     但是，如果链条不为空呢？岂不是死循环...也许可以加入一个flag，循环了一定次数后就自动跳出来。
     
     flag的规则，是这样的，有2N个元素，如果有一对夫妻被踢，那么之后顶多死循环2N-2次。
     所以我们设置一个2N的最大死循环数，每踢一对夫妻，该最大死循环数减小2。
     另外设置flag为0，如果有人不属于相邻的夫妻，那flag增1，如果flag>最大死循环数,说明失败了。
     一旦出现夫妻对，flag立即归0，重新来过（有种情况是，循环一遍正准备结束的时候，头尾两个人正好是夫妻，
     踢掉他们后环发生变化，可能有新的相邻夫妻出现，这时就需要重新扫描了）

这样暴力地循环，应该可以得到答案，问题就是时间和空间的复杂度能否满足要求了。

失望ing：我本打算直接就用c++的容器list来当圆环，但现在似乎不行？没有vs2013那样的
        自动补全，我压根记不住容器的用法，怎么声明都不知道，杯具了。
        难道说，我注定了要自己写链条了？
        


Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

N couples are standing in a circle, numbered consecutively clockwise from 1 to 2N. 
Husband and wife do not always stand together. We remove the couples who stand together until 
the circle is empty or we can't remove a couple any more.

Can we remove all the couples out of the circle?


Input

There may be several test cases in the input file. In each case, the first line is 
an integer N(1 <= N <= 100000)----the number of couples. In the following N lines, 
each line contains two integers ---- the numbers of each couple.
N = 0 indicates the end of the input.


Output

Output "Yes" if we can remove all the couples out of the circle. Otherwise, output "No".


Sample Input

4
1 4
2 3
5 6
7 8

2
1 3
2 4

0


Sample Output

Yes
No

Problem Source

ZSUACM Team Member
* */

#include <iostream>
#include <malloc.h>

using namespace std;

// store all the husbands and wifes
long entry[200010] = {0};

// the entry of the link which is got to be a circle
struct E
{
    long couple;
    struct E *front, *next;
};
#define LEN sizeof(struct E)
        
int main()
{

    // the count of couple
    long N;
    
    cin >> N;
    
    while (N != 0)
    {
        int husband = 0;
        int wife = 0;
        
        for (int i = 1; i <= N; i++)
        {
            cin >> husband >> wife;
            // the ith couple, where is husband, where is wife
            entry[husband] = i;
            entry[wife] = i;
        }
        
        struct E *head = new struct E;
        head->couple = entry[1];
        
        struct E *end = head;
        
        // make up a link
        for (int i = 2; i <= 2 * N; i++)
        {
            struct E *temp = new struct E;
            temp->couple = entry[i];
            temp->front = end;
            end->next = temp;
            end = temp;
        }
        
        // make up a circle
        end->next = head;
        head->front = end;
        
        struct E *p = head;
        int flag = 0;
        int max = 2 * N;
        
        while(p->next != p && flag <= 2 * N)
        {
            // they are couples!!!
            if (p->next->couple == p->couple)
            {
                struct E *pNext = p->next;
                p->front->next = pNext->next;
                pNext->next->front = p->front;
                p = p->front;
                flag = 0;
                N -= 1;
            }
            else
            {
                flag++;
                p = p->next;
            }
        }
        
        int numToDelete = 2 * N;
        while (numToDelete>=2)
        {
            struct E *temp = p;
            delete(temp);
            p = p->next;
			numToDelete--;
        }

        if (N <= 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        
        // get in another test case
        cin >> N;
    }
    
    return 0;
}                                 

/** *
后记：我去，问了学霸们的思路，结果发现我的算法没问题，
     一直runtime error的原因是---我的数组仅为题目要求的一半。
	 以后做西西里也得长记性了，一旦runtime error，那么快点看看题目要求的大小。
* */