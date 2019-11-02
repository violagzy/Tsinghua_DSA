// hash.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

int main()
{
	char Name[59][20] ={"jinshan", "linanning", "xujiadong", "cuiwubing", "denghua", 
		"wangsiping", "limengxin", "qiaozhengping", "fanyingxue", "zhangjianwei", 
		"louhongxuan", "weixianzhu", "lijiachen", "zoulinwei", "litingwei",	
		"wujiaxin",	"guozijie",	"gengziyin","yujiangyue", "xuxingchen", 
		"wangyue", "bixiaoyu", "zhouyaoxiang", "liumin", "guoyan", 
		"jinenze", "xuechen", "panzhaoyue", "weixiao", "xiaqiuhan", 
		"zhanwenhao", "wujiaxiang",	 "yeliang",	"liyanxuan", "like",
		"yangqi","helizhe", "huangbotao", "houmingrong", "gaohao", 
		"dengweihao", "zhangxuefeng", "yangzeyuan", "zhanghongsen", "xiaochangrong", 
		"houbairu", "leichenyong", "wuzijian", "liyifan", "jilincheng", 
		"wangtianyu", "zhuzifei", "liziyue", "shezhucheng",	"chenkening",
		"shengyinuo","shenyihua","liyinwen", "linzhenghuan"};

	int i, n = 59, l, collision = 0;
	int a[59], b[100] = {0};

	int d = 71;
	int add = 17;
	for(i = 0; i < n; i++) 
	{
		l = strlen(Name[i]);
		a[i] = Name[i][0]*59^2 + Name[l/2][0]*59 + Name[l-1][0];
		a[i] = a[i] % d;
		while(1) 
		{
			if(b[a[i]] == 0) 
			{
				b[a[i]] = 1; 
				break;
			}
			else 
			{
				a[i] = (a[i] + add) % d; 
				collision++;
			}
		}
	}

	printf("Hash function = s[0]*59^2 + s[length(s)/2]*59 + s[length(s)-1]\n");
	printf("Table size = 71\n");
	printf("Collision = %d\n", collision);  // unfortunately, this number is still very big

	getchar();

	return 0;
}


