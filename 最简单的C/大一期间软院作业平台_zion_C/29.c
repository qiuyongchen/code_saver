Good：

The using of function....strstr

Description:

If you have any doubt on this assignment, please send an email to its author 范子垚.
One day, our master py gives Uncle Long a task, which is a string match problem. If Uncle Long failed to finish the mission, his salary would be cut away. So he call you to help him about the mission.
You will get two string A and B, not including whitespaces but seperated by a whitespace. If B is a substring of A, you should output 'Bingo!', or 'Dead!' for not.
sample input:
idoitcanbetalent anbet
sample output:
Bingo!
中文题面：
昨天py给Uncle Long下达了一个字符串匹配任务。如果Uncle Long没有完成的话，就会被py扣工资！所以他要你帮他找出答案。
你将会得到两个不包含空格的字符串A和B，用空格隔开。如果B是A的子串（可以匹配A）就输出“Bingo!”，否则输出“Dead!”。
样例输入：
idoitcanbetalent anbet
样例输出：
Bingo!
备注：同学们，题目有所改正，鉴于系统设计没有马上生效，不管之前有没有通过，烦请大家在周六（2013.11.16）重新提交一次，谢谢。

Hint:

使用朴素算法可以得到绝大部分分数（好像满分也可以）（字符串匹配问题）
参考资料：http://zh.wikipedia.org/wiki/%E5%85%8B%E5%8A%AA%E6%96%AF-%E8%8E%AB%E9%87%8C%E6%96%AF-%E6%99%AE%E6%8B%89%E7%89%B9%E7%AE%97%E6%B3%95




#include <stdio.h>
#include <string.h>


int main() {
    char Smother[10000], Sson[10000], *Sjia;
    scanf("%s%s", Smother, Sson);
    Sjia = strstr(Smother, Sson);
    if (Sjia) {
        printf("Bingo!\n");
    } else {
        printf("Dead!\n");
    }
    return 0;
}

