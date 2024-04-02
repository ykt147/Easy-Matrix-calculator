#include<stdio.h>
#include<math.h>
#include<stdlib.h>//头文件 
int i,j,m,n,p,q,k,x,y,order;//
float result=0.0; //行列式结果 
float determinant(float **a,int order);//行列式函数 
float laplace(float **a,int r,int c,int order);//拉普拉斯展开函数 
float inverse(float **a,int r,int c,int order); //逆矩阵函数 
void print_inverse(float **a,int order);//输出逆矩阵函数 
float adjoint(float **a,int r,int c,int order);//伴随矩阵函数 
void print_adjoint(float **a,int order);//输出伴随矩阵函数 
int main()
{
    printf("-----------------矩阵计算器-----------------\n");
    printf("------请选择功能：（选择后请按回车键）  ----\n");
    printf("------    0：退出                -----------\n");
    printf("------    1：转置矩阵            -----------\n");
    printf("------    2：矩阵加法            -----------\n");
    printf("------    3：矩阵乘法            -----------\n");
    printf("------    4：矩阵行列式          -----------\n");
    printf("------    5：逆矩阵              -----------\n");
    printf("------    6：伴随矩阵            -----------\n");
    printf("--------------------------------------------\n");//头目 
    do
    {
    	scanf("%d",&x);//选择需要进行的功能 
    	switch(x)
    	{
    		case(0):
			{
				printf("\n");
    			printf("助教别忘了加分（一定要加分）\n"); 
    			printf("请从0、1中选择\n");
    			printf("0:大气加分\n");
    			printf("1:就这？？？\n");
    			do
				{
    			  scanf("%d",&y);
    			  switch(y) 
    			  {
    				  case(0):
    				  {
					      printf("\n");
    					  printf("万分感谢，助教你最好看！  (点击任意键<别点电源键、num lock键、ctrl键、fn键、中文状态下的字母键……>退出喔)");
					  }
					  break;
					  case(1):
					  {
						  printf("忘了加分啦 （呜呜呜没有加分  # __  #）\n");
						  printf("请再次从0、1中选择\n");
						  printf("0：好吧给你加分\n");
						  printf("1：就是不加分\n");
						  printf("\n"); 
					  }
					  break;
				  }
			    }
			    while(y);//当输入0时退出，否则一直循环 
		    }
			break;
			case(1):
			{
				printf("请输入矩阵行数和列数（用空格隔开）：\n");
				scanf("%d%d",&m,&n);
				float **a=(float**)malloc(sizeof(float*)*m);
	            int w;
	            for(w=0;w<m;w++)
	            a[w]=(float*)malloc(sizeof(float)*n);
	            float **b=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            b[w]=(float*)malloc(sizeof(float)*n);
				while(m<=0||n<=0)//判断是否合法 
				{
					printf("矩阵不合法，请重新输入");
					printf("请输入矩阵行数和列数（用空格隔开）：\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("请输入矩阵：（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）\n");
				for(i=0;i<m;i++)//输入 
	            {
		            for(j=0;j<n;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            b[i][j]=a[j][i];
		            }
	            }
	            printf("这是转置矩阵：\n");
	            for(i=0;i<m;i++)//输出 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",b[i][j]);
		            }
		            printf("\n");
               	}
               	printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n"); 
			}
			break;
			case(2):
			{
				printf("在这里进行矩阵加法：\n");
				printf("请输入矩阵a的行数和列数（用空格隔开）：");
				printf("\n");
				scanf("%d%d",&p,&q);
				printf("请输入矩阵b的行数和列数（用空格隔开）：");
				printf("\n");
				scanf("%d%d",&m,&n);
				float **a=(float**)malloc(sizeof(float*)*p);
	            int w;
	            for(w=0;w<p;w++)
	            a[w]=(float*)malloc(sizeof(float)*q);
	            float **b=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            b[w]=(float*)malloc(sizeof(float)*n);
	            float **c=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            c[w]=(float*)malloc(sizeof(float)*n);
				while(p!=m||q!=n)//不能相加重新输入 
				{
					printf("这两个矩阵不能相加。\n");
					printf("请重新输入矩阵b的行数和列数,使之与矩阵a的行数列数一致（用空格隔开）：\n");
					scanf("%d%d",&m,&n);
				}
				while(m<=0||n<=0||p<=0||q<=0)//判断是否合法 
				{
					printf("矩阵不合法，请重新输入");
					printf("请输入矩阵a的行数和列数（用空格隔开）：\n");
				    scanf("%d%d",&p,&q);
					printf("请输入矩阵b的行数和列数（用空格隔开）：\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("请输入矩阵a（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）：\n");
				for(i=0;i<p;i++)//输入 
	            {
		            for(j=0;j<q;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
				printf("\n");
				printf("请输入矩阵b（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）：\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            scanf("%f",&b[i][j]);
		            }
	            }
				printf("两个矩阵相加结果为：\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            c[i][j]=a[i][j]+b[i][j];//相加计算 
		            }
	            }
				for(i=0;i<m;i++)//输出 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",c[i][j]);
		            }
		            printf("\n");
	            }
	            printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n");
			}
			break;
			case(3):
			{
				printf("在这里进行矩阵乘法：\n");
				printf("请输入矩阵a的行数和列数（用空格隔开）：");
				printf("\n");
				scanf("%d%d",&p,&q);
				printf("请输入矩阵b的行数和列数（用空格隔开）：");
				printf("\n");
				scanf("%d%d",&m,&n);
				float **a=(float**)malloc(sizeof(float*)*m);
	            int w;
	            for(w=0;w<m;w++)
	            a[w]=(float*)malloc(sizeof(float)*n);
	            float **b=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            b[w]=(float*)malloc(sizeof(float)*n);
	            float **c=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            c[w]=(float*)malloc(sizeof(float)*n);
				while(q!=m)//排除不能相乘情况 
				{
					printf("这两个矩阵不能相乘。\n");
					printf("请重新输入矩阵b的行数和列数,使矩阵b的行数与矩阵a的列数相等（用空格隔开）：\n");
					scanf("%d%d",&m,&n);
				}
				while(m<=0||n<=0||p<=0||q<=0)//判断是否合法 
				{
					printf("矩阵不合法，请重新输入");
					printf("请输入矩阵a的行数和列数（用空格隔开）：\n");
				    scanf("%d%d",&p,&q);
					printf("请输入矩阵b的行数和列数（用空格隔开）：\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("请输入矩阵a（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）：\n");
				for(i=0;i<p;i++)//输入 
	            {
		            for(j=0;j<q;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
				printf("\n");
				printf("请输入矩阵b（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）：\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            scanf("%f",&b[i][j]);
		            }
	            }
				printf("两个矩阵相乘结果为：\n");
				for(i=0;i<p;i++)//相乘 
				{
					for(j=0;j<n;j++)
					{
						c[i][j]=0;
						for(k=0;k<q;k++)
						{
							c[i][j]+=a[i][k]*b[k][j];
						}
					}
				 }
				 for(i=0;i<m;i++)//输出 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",c[i][j]);
		            }
		            printf("\n");
	            } 
	            printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n");
			}
			break;
			case(4):
			{
				printf("在这里计算矩阵行列式：\n");
				printf("请输入矩阵的阶：\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//不合法时 
				{
					printf("这个矩阵不合法。\n");
					printf("请重新输入矩阵的阶：\n");
					scanf("%d",&order);
				}
				printf("请输入矩阵：（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）\n");//输入 
				for(i=0;i<order;i++)
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            result = determinant(a,order);//行列式函数计算行列式 
                printf("行列式的值为: %.2f",result);//输出 
				printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n"); 
			}
			break;
			case(5):
			{
				printf("在这里计算逆矩阵：\n");
				printf("请输入矩阵的阶：\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//不合法时 
				{
					printf("这个矩阵不合法。\n");
					printf("请重新输入矩阵的阶：\n");
					scanf("%d",&order);
				}
				printf("请输入矩阵：（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）\n");//输入 
				for(i=0;i<order;i++)
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            result = determinant(a,order);//行列式函数计算行列式 
	            if(result==0)
	            printf("没有逆矩阵。\n");//行列式为0时没有逆矩阵 
	            else
	            {
	            	printf("逆矩阵为：\n");
	            	print_inverse(a,order);//输出逆矩阵 
				}
				printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n");
			}
			break;
			case(6):
			{
				printf("在这里计算伴随矩阵：\n");
				printf("请输入矩阵的阶：\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//不合法 
				{
					printf("这个矩阵不合法。\n");
					printf("请重新输入矩阵的阶：\n");
					scanf("%d",&order);
				}
				printf("请输入矩阵：（输入时每个数用空格隔开,超出矩阵能容纳的数将自动忽略）\n");//输入 
				for(i=0;i<order;i++)//输入 
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            printf("伴随矩阵为：\n");
	            print_adjoint(a,order);//输出 
	            printf("\n");
               	printf("选择0退出，或选择下一个想执行的功能\n");
			}
			break;
			default://当输入的值不是0到6时 
			{
				printf("error\n");
				printf("从0到6里面选\n"); 
			}
		}
	}
	while(x);//输入0退出 
	return(0);
 } 
float determinant(float **a,int order)//行列式 
{
	int sign = 1,i;
    float temp;
    float result=0.0;
    if(order == 1)
        result = a[0][0];//直到阶数降到 1 
    else
    	for(i = 0;i < order;i ++)
        {
            temp = laplace(a,i,0,order);//余子式 
            result += sign * a[i][0] * temp;//第一列展开 
            sign *= -1;//相当于（-1）^(i+0) 
        }
    return result;
}
float laplace(float **a,int r,int c,int order)//拉普拉斯展开 
{
	float **ma=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            ma[w]=(float*)malloc(sizeof(float)*order);
    float result_l = 0;
    int i,j,temp_i,temp_j;
    for(i = 0;i < order;i ++)
        for(j = 0;j < order;j ++)
        {
            temp_i = i;
            temp_j = j;//先储存i和j的值，因为之后i和j会变动但要回到目前值 
            if(i == r || j == c);
            else
            {
                if(i > r)
                    i --;
                if(j > c)
                    j --;
                ma[i][j] = a[temp_i][temp_j];//删去一行一列后的矩阵 
                i = temp_i;
                j = temp_j;
            }
        }
    if(order >= 2)
        result_l = determinant(ma,order - 1);//计算降阶后的行列式，总阶数减 1 
    return result_l;
}
float inverse(float **a,int r,int c,int order)//逆矩阵 
{
	float result = 0;
    result = adjoint(a,r,c,order) / determinant(a,order);//AA*=det(A)I 
    return result;
}
void print_inverse(float **a,int order)//输出逆矩阵 
{
	int i,j;
    for(i = 0;i < order;i ++)
    {
        for(j = 0;j < order;j ++)
            printf("%.2f\t",inverse(a,i,j,order));
        printf("\n");
    }
}
float adjoint(float **a,int r,int c,int order)//伴随 
{
	float result = 0;
    if(order == 1 && r == 0 && c == 0)//直到阶数降到 1
        result = 1;
    else
        result = pow(-1,r + c) * laplace(a,c,r,order);//代数余子式 
    return result;
}
void print_adjoint(float **a,int order)//输出伴随矩阵 
{
	int i,j;
    for(i = 0;i < order;i ++)
    {
        for(j = 0;j < order;j ++)
            printf("%.2f\t",adjoint(a,i,j,order));
        printf("\n");
    }
}
