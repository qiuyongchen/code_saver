// Problem#: 1027
// Submission#: 3843065
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/** *
1027. MJ, Nowhere to Hide


Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

On BBS, there is a familiar term called MJ (short for MaJia), which means another BBS ID of one person besides his/her main ID.
These days, a lot of ACMers pour water on the ACMICPC Board of argo. Mr. Guo is very angry about that and he wants to punish these guys. ACMers are all smart boys/girls, right? They usually use their MJs while pouring water, so Mr. Guo can not tell all the IDs apart.  Unfortunately, the IP can not be changed, i.e, the posts of main ID and MJ of the same person has the same IP address, meanwhile, the IP addresses of different person is different.  Assuming that each person has exactly one main ID and one MJ, by reading their posts on BBS, you then tell Mr. Guo whom each MJ belongs to.


Input

The first line of each test cases is an even integer n (0<=n<=20), the number of posts on BBS.
Then n lines follow, each line consists of two strings:
BBS_ID IP_Address
BBS_ID means the ID who posts this post. BBS_ID is a string contains only lower case alphabetical characters and its length is not greater than 12.
Each BBS ID appears only once in each test cases.
IP_Address is the IP address of that person. The IP address is formatted as “A.B.C.D”, where A, B, C, D are integers ranging from 0 to 255.
Your program should be terminated by n = 0.
It is sure that there are exactly 2 different BBS IDs with the same IP address. The first ID appears in the input is the main ID while the other
is the MJ of that person.


Output

For each test case, output n/2 lines of the following format: “MJ_ID is the MaJia of main_ID”
They should be displayed in the lexicographical order of the main_ID.
Print a blank line after each test cases.
See the sample output for more details.


Sample Input

8
inkfish 192.168.29.24
zhi 192.168.29.235
magicpig 192.168.50.170
pegasus 192.168.29.235
iamcs 202.116.77.131
finalBob 192.168.29.24
tomek 202.116.77.131
magicduck 192.168.50.170
4
mmmmmm 172.16.72.126
kkkkkk 192.168.49.161
llllll 192.168.49.161
nnnnnn 172.16.72.126
0


Sample Output

tomek is the MaJia of iamcs
finalBob is the MaJia of inkfish
magicduck is the MaJia of magicpig
pegasus is the MaJia of zhi

llllll is the MaJia of kkkkkk
nnnnnn is the MaJia of mmmmmm


Problem Source

ZSUACM Team Member

* */

#include <iostream>
#include <map>

#include <set>
#include <string>
#include <vector>

int main()
{
    int n;
    std::string name, ip;
    std::map<std::string, std::string> info;
    std::map<std::string, std::string> info_out;
    std::map<std::string, std::string>::iterator it;
    std::cin >> n;

    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            std::cin >> name >> ip;

            it = info.find(ip);
            // that ip exits!
            if (it != info.end())
            {
                info_out.insert(std::pair<std::string, std::string>(info.find(ip)->second, name));
                info.erase(ip);
            }
            else
            {
                info[ip] = name;
            }

        }

        for (it = info_out.begin(); it != info_out.end(); ++it)
        {
            std::cout << it->second << " is the MaJia of " << it->first << "\n";
        }
        info.clear();
        info_out.clear();
        
        std::cout << "\n";
        std::cin >> n;
    }
    return 0;
}

/* *
 后记：这道题差点弄死我了，虽说逻辑比较简单，但很久没用过STL，很多用法都模糊了。
 况且，使用STL的时候，我必须依赖vs2013之类的自动补全功能，不然真是记不得容器的接口函数等玩意。
 让哥哥来总结一下

 ****************复习了map/set/vector等容器的功能
 ****************复习了iterator的声明
 ****************复习了命名空间
 ****************查看容器是否有某个元素，只需用得到的iterator和end做比较即可
 ****************iterator的内容直接查，iterator并没有提供函数（it->second）
 ****************临时构建pair的方法：std::pair<std::string, std::string>("hi", "hello")
 ****************以前用erase的时候，都不起作用，这次居然可以了，神奇的人类啊
 ****************哦，差点忘了一点，map根据key排序！好像是从小到大排...
* */                                 