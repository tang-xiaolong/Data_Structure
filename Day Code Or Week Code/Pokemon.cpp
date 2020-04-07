//https://www.nowcoder.com/practice/a4cc4ef629f146f68c5d02e06dfd6b99?tpId=110&tqId=33450&tPage=2&rp=2&ru=/ta/job-code&qru=/ta/job-code/question-ranking
class Solution {

public:

    /**

     * 

     * @param HP long长整型 HP

     * @param ACK long长整型 ACK

     * @param HP2 long长整型 HP2

     * @param ACK2 long长整型 ACK2

     * @return long长整型

     */

    long long Pokemonfight(long long HP, long long ACK, long long HP2, long long ACK2) {

        // write code here

        //如果一回合没被秒而自己可以干掉对方，则返回1

        if(ACK < HP2 && ACK2 >= HP)

            return 1;

        if(ACK * 2 >= HP2)

            return -1;

        //计算杰尼龟可以挨几个回合打，前k回合可以攻击k次，后面每k回合攻击k-1次

        long long k = HP2 / ACK;

        //看是否为0，如果为0则k需要减一

        if(HP2 - k * ACK == 0)k -= 1;

        //计算自己几回合可以打死对方

        long long killCount = HP / ACK2;

        if(HP - killCount * ACK2 != 0)//如果余数不为0，则需要多一回合

            killCount += 1;

        //如果自己杀死对方需要的回合数小于等于自己能挨打的次数，则直接杀死

        if(killCount <= k)

            return killCount;

        killCount -= k;//第一次攻击k次

        //后面每k回合可以攻击k－1次

        long long res = killCount / (k - 1);

        long long remain = killCount - res * (k - 1);

        if(remain != 0 )

            res = res * k + remain + 1;//有剩余，则还需加上最后多出的那次恢复回合

        else

            res *= k;

        return res + k;

    }

};
