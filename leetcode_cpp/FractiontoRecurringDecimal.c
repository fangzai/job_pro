    #include <stdio.h>
    #include <stdlib.h>

    #include<math.h>
    #include<string.h>

    #define true 1
    #define false 0
    #define INT_MIN  -2147483648
    int isIn(long long int*a, int len, long long int num)
    {
            int i;
            for (i = 0; i < len; i++)
                if (a[i] == num)
                    return true;
            return false;
    }
    char*num2str(long long int n)
    {
            long long int mod, len = 0, num;
            num = n;
            while (num >= 10)
            {
                num = num / 10;
                len++;
            }
            char*str = (char*)malloc((len + 1)*sizeof(char));
            len = 0;
            num = n;
            while (num >= 10)
            {
                str[len] = num % 10 + '0';
                num = num / 10;
                len++;
            }
            str[len] = num + '0';
            int i, head, tail;
            for (i = 0; i <= len / 2; i++)
            {
                head = i;
                tail = len - i;
                char temp = str[head];
                str[head] = str[tail];
                str[tail] = temp;
            }

            str[len + 1] = '\0';
            return str;
    }
    long long int gcd(long long int m, long long int n)
    {
        while (n)
        {
            n = m^n;
            m = m^n;
            n = (m^n) % m;
        }

        return m;
    }

    char* fractionToDecimal(int numerator, int denominator)
    {
            // 第一步  判定符号
        int sign = false; //默认都为正数；
        long long int newNum, newDen;
        newNum = numerator;
        newDen = denominator;
        if (newNum*newDen < 0)
        {
            sign = true;
        }
        newDen = abs(newDen);
        if(newDen < 0 )
        {
            newDen = -1*newDen;  //abs不接受long long int 整数
			//以前bug一直是这个地方的
        }
        if(newNum<0)
        {
            newNum = -1*newNum;
        }
        //newNum = abs(newNum);

        // 第二步  求最大公约数
        long long int GreatCommonFactor = gcd(newNum, newDen);

        newNum = newNum / GreatCommonFactor;
        newDen = newDen / GreatCommonFactor;

        //第三步   求小数点前面的位置

        long long int front = newNum / newDen;  //存放在小数点前面的位置

        newNum = newNum % newDen;     // newNum更新

        char * head = NULL;

        head = num2str(front);  //前面的数值转化为string

        if (newNum == 0)        //余数为0
        {
            if(sign)
            {   
				//符号不能忘了
                char*newHead = (char*)malloc((strlen(head)+2)*sizeof(char));
                newHead[0] = '-';
                memcpy(newHead+1,head,(strlen(head)+1)*sizeof(char));
                return newHead;
            }
            else
            {
                return head;
            }
        }

        ////第四步    newDen是10的倍数
        long long int num = newDen;

        int size = 1000;     //数组大小开100  用于存储出现过的余数
        long long int *array = (long long int*)malloc(size*sizeof(long long int));
        long long int *quaArray = (long long int*)malloc(size*sizeof(long long int));
        int pointer = 0;   //指向array的最后一个的下一个位置

        //第5步    确定newNum需要补几个0才开始循环余数
        int len = 0;  //用于计算每次循环需要补几个0
        int mark = false;


        int  circle = false;
        int circleIndex = 0;    //循环开始的位置
        long long int mod = 0, qua = 0; //mod表示余数，qua表示商
        num = newNum;

        pointer = 0;
        array[pointer] = num;
        pointer++;
        while (num <newDen)
        {
            num *= 10;
            mod = num % newDen;
            qua = num / newDen;

            num = mod;
            len++;
            if (len == 30)
            {
                printf("hello world !\n");
            }
            if (!isIn(array, pointer, mod))
            {
                if (mod == 0)
                {
                    break;  //同样退出
                }
                //添加进去
                array[pointer] = num;   //需要判断是否出现过
                quaArray[pointer - 1] = qua;
                pointer++;
            }
            else
            {
                //已经出现过了  退出
                circle = true;
                break;
            }

        }
        int i, j;
        quaArray[pointer - 1] = qua;
        for (i = 0; i < pointer; i++)
        {
            if (array[i] == num)
            {
                circleIndex = i;
            }
        }
        //说明circleIndex  ---- pointer-1这个地方，quaArray里面全部存的都是循环体。
        int tailLen = len, headLen;
        char*tail = NULL, *charTail = NULL;

        long long int tailNum = 1;
        tailNum = 0;
        for (i = 0; i < len; i++)
        {
            //printf("%d ====== %d \n",i ,quaArray[i]);
            tailNum *= newDen;
            tailNum += quaArray[i];  //这个地方也有一个大bug
			//如果直接使用数值计算的话，容易越界 这是第一个出现runtime error的地方
        }
        //printf("%d \n", tailNum);
        if (circle)
        {
            //tailNum -= num;       //如果循环的话，就把余数减掉
            tailLen += 2;
        }
        tail = (char*)malloc((tailLen + 1)*sizeof(char));

        tailNum /= newDen;
        charTail = num2str(tailNum);
        j = strlen(charTail) - 1;
        for (i = pointer - 1; i >= 0; i--)
        {
            tail[i] = quaArray[i] + '0';
        }
        tail[len] = '\0';
        if (circle)
        {
            tail[tailLen] = '\0';
            tail[tailLen - 1] = ')';
            for (i = tailLen - 2; i > circleIndex; i--)
            {
                tail[i] = tail[i - 1];
            }
            tail[i] = '(';
        }
        tailLen = strlen(tail);
        headLen = strlen(head);

        char *result = NULL;
        int resultLen = tailLen + headLen + 1; //还有一个小数点
        if (sign)
        {
            resultLen++;
        }
        result = (char*)malloc((resultLen + 1)*sizeof(char));

        pointer = 0;
        if (sign)
        {
            result[pointer] = '-';
            pointer++;
        }
        for (i = 0; i < headLen;i++)
        {
            result[pointer] = head[i];
            pointer++;
        }
        //memcpy(result + pointer, head, headLen*sizeof(char));
        //pointer += headLen;
        result[pointer] = '.';
        pointer++;
        for (i = 0; i < tailLen; i++)
        {
            result[pointer] = tail[i];
            pointer++;
        }
        //memcpy(result + pointer, tail, tailLen*sizeof(char));

        result[pointer] = '\0';
        //printf("%s \n", head);
        //printf("%s \n", tail);
        return  result;
    }

    int main()
    {
        int numerator =  -2147483648;
        int denominator =1;
        //printf("%s\n", num2str(12));
        printf("%s \n", fractionToDecimal(numerator, denominator));
        printf("=====================Hello world!\n");
        return 0;
    }
