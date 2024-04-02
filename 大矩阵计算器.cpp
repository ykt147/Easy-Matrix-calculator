#include<stdio.h>
#include<math.h>
#include<stdlib.h>//ͷ�ļ� 
int i,j,m,n,p,q,k,x,y,order;//
float result=0.0; //����ʽ��� 
float determinant(float **a,int order);//����ʽ���� 
float laplace(float **a,int r,int c,int order);//������˹չ������ 
float inverse(float **a,int r,int c,int order); //������� 
void print_inverse(float **a,int order);//���������� 
float adjoint(float **a,int r,int c,int order);//��������� 
void print_adjoint(float **a,int order);//������������ 
int main()
{
    printf("-----------------���������-----------------\n");
    printf("------��ѡ���ܣ���ѡ����밴�س�����  ----\n");
    printf("------    0���˳�                -----------\n");
    printf("------    1��ת�þ���            -----------\n");
    printf("------    2������ӷ�            -----------\n");
    printf("------    3������˷�            -----------\n");
    printf("------    4����������ʽ          -----------\n");
    printf("------    5�������              -----------\n");
    printf("------    6���������            -----------\n");
    printf("--------------------------------------------\n");//ͷĿ 
    do
    {
    	scanf("%d",&x);//ѡ����Ҫ���еĹ��� 
    	switch(x)
    	{
    		case(0):
			{
				printf("\n");
    			printf("���̱����˼ӷ֣�һ��Ҫ�ӷ֣�\n"); 
    			printf("���0��1��ѡ��\n");
    			printf("0:�����ӷ�\n");
    			printf("1:���⣿����\n");
    			do
				{
    			  scanf("%d",&y);
    			  switch(y) 
    			  {
    				  case(0):
    				  {
					      printf("\n");
    					  printf("��ָ�л����������ÿ���  (��������<����Դ����num lock����ctrl����fn��������״̬�µ���ĸ������>�˳��)");
					  }
					  break;
					  case(1):
					  {
						  printf("���˼ӷ��� ��������û�мӷ�  # __  #��\n");
						  printf("���ٴδ�0��1��ѡ��\n");
						  printf("0���ðɸ���ӷ�\n");
						  printf("1�����ǲ��ӷ�\n");
						  printf("\n"); 
					  }
					  break;
				  }
			    }
			    while(y);//������0ʱ�˳�������һֱѭ�� 
		    }
			break;
			case(1):
			{
				printf("����������������������ÿո��������\n");
				scanf("%d%d",&m,&n);
				float **a=(float**)malloc(sizeof(float*)*m);
	            int w;
	            for(w=0;w<m;w++)
	            a[w]=(float*)malloc(sizeof(float)*n);
	            float **b=(float**)malloc(sizeof(float*)*m);
                for(w=0;w<m;w++)
	            b[w]=(float*)malloc(sizeof(float)*n);
				while(m<=0||n<=0)//�ж��Ƿ�Ϸ� 
				{
					printf("���󲻺Ϸ�������������");
					printf("����������������������ÿո��������\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("��������󣺣�����ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ�\n");
				for(i=0;i<m;i++)//���� 
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
	            printf("����ת�þ���\n");
	            for(i=0;i<m;i++)//��� 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",b[i][j]);
		            }
		            printf("\n");
               	}
               	printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n"); 
			}
			break;
			case(2):
			{
				printf("��������о���ӷ���\n");
				printf("���������a���������������ÿո��������");
				printf("\n");
				scanf("%d%d",&p,&q);
				printf("���������b���������������ÿո��������");
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
				while(p!=m||q!=n)//��������������� 
				{
					printf("��������������ӡ�\n");
					printf("�������������b������������,ʹ֮�����a����������һ�£��ÿո��������\n");
					scanf("%d%d",&m,&n);
				}
				while(m<=0||n<=0||p<=0||q<=0)//�ж��Ƿ�Ϸ� 
				{
					printf("���󲻺Ϸ�������������");
					printf("���������a���������������ÿո��������\n");
				    scanf("%d%d",&p,&q);
					printf("���������b���������������ÿո��������\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("���������a������ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ���\n");
				for(i=0;i<p;i++)//���� 
	            {
		            for(j=0;j<q;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
				printf("\n");
				printf("���������b������ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ���\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            scanf("%f",&b[i][j]);
		            }
	            }
				printf("����������ӽ��Ϊ��\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            c[i][j]=a[i][j]+b[i][j];//��Ӽ��� 
		            }
	            }
				for(i=0;i<m;i++)//��� 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",c[i][j]);
		            }
		            printf("\n");
	            }
	            printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n");
			}
			break;
			case(3):
			{
				printf("��������о���˷���\n");
				printf("���������a���������������ÿո��������");
				printf("\n");
				scanf("%d%d",&p,&q);
				printf("���������b���������������ÿո��������");
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
				while(q!=m)//�ų����������� 
				{
					printf("��������������ˡ�\n");
					printf("�������������b������������,ʹ����b�����������a��������ȣ��ÿո��������\n");
					scanf("%d%d",&m,&n);
				}
				while(m<=0||n<=0||p<=0||q<=0)//�ж��Ƿ�Ϸ� 
				{
					printf("���󲻺Ϸ�������������");
					printf("���������a���������������ÿո��������\n");
				    scanf("%d%d",&p,&q);
					printf("���������b���������������ÿո��������\n");
				    scanf("%d%d",&m,&n);
				} 
				printf("���������a������ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ���\n");
				for(i=0;i<p;i++)//���� 
	            {
		            for(j=0;j<q;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
				printf("\n");
				printf("���������b������ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ���\n");
				for(i=0;i<m;i++)
	            {
		            for(j=0;j<n;j++)
		            {
			            scanf("%f",&b[i][j]);
		            }
	            }
				printf("����������˽��Ϊ��\n");
				for(i=0;i<p;i++)//��� 
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
				 for(i=0;i<m;i++)//��� 
	            {
		            for(j=0;j<n;j++)
		            {
			            printf("%.2f\t",c[i][j]);
		            }
		            printf("\n");
	            } 
	            printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n");
			}
			break;
			case(4):
			{
				printf("����������������ʽ��\n");
				printf("���������Ľף�\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//���Ϸ�ʱ 
				{
					printf("������󲻺Ϸ���\n");
					printf("�������������Ľף�\n");
					scanf("%d",&order);
				}
				printf("��������󣺣�����ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ�\n");//���� 
				for(i=0;i<order;i++)
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            result = determinant(a,order);//����ʽ������������ʽ 
                printf("����ʽ��ֵΪ: %.2f",result);//��� 
				printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n"); 
			}
			break;
			case(5):
			{
				printf("��������������\n");
				printf("���������Ľף�\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//���Ϸ�ʱ 
				{
					printf("������󲻺Ϸ���\n");
					printf("�������������Ľף�\n");
					scanf("%d",&order);
				}
				printf("��������󣺣�����ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ�\n");//���� 
				for(i=0;i<order;i++)
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            result = determinant(a,order);//����ʽ������������ʽ 
	            if(result==0)
	            printf("û�������\n");//����ʽΪ0ʱû������� 
	            else
	            {
	            	printf("�����Ϊ��\n");
	            	print_inverse(a,order);//�������� 
				}
				printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n");
			}
			break;
			case(6):
			{
				printf("���������������\n");
				printf("���������Ľף�\n");
				scanf("%d",&order);
				float **a=(float**)malloc(sizeof(float*)*order);
	            int w;
	            for(w=0;w<order;w++)
	            a[w]=(float*)malloc(sizeof(float)*order);
				while(order<=0)//���Ϸ� 
				{
					printf("������󲻺Ϸ���\n");
					printf("�������������Ľף�\n");
					scanf("%d",&order);
				}
				printf("��������󣺣�����ʱÿ�����ÿո����,�������������ɵ������Զ����ԣ�\n");//���� 
				for(i=0;i<order;i++)//���� 
	            {
		            for(j=0;j<order;j++)
		            {
			            scanf("%f",&a[i][j]);
		            }
	            }
	            printf("�������Ϊ��\n");
	            print_adjoint(a,order);//��� 
	            printf("\n");
               	printf("ѡ��0�˳�����ѡ����һ����ִ�еĹ���\n");
			}
			break;
			default://�������ֵ����0��6ʱ 
			{
				printf("error\n");
				printf("��0��6����ѡ\n"); 
			}
		}
	}
	while(x);//����0�˳� 
	return(0);
 } 
float determinant(float **a,int order)//����ʽ 
{
	int sign = 1,i;
    float temp;
    float result=0.0;
    if(order == 1)
        result = a[0][0];//ֱ���������� 1 
    else
    	for(i = 0;i < order;i ++)
        {
            temp = laplace(a,i,0,order);//����ʽ 
            result += sign * a[i][0] * temp;//��һ��չ�� 
            sign *= -1;//�൱�ڣ�-1��^(i+0) 
        }
    return result;
}
float laplace(float **a,int r,int c,int order)//������˹չ�� 
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
            temp_j = j;//�ȴ���i��j��ֵ����Ϊ֮��i��j��䶯��Ҫ�ص�Ŀǰֵ 
            if(i == r || j == c);
            else
            {
                if(i > r)
                    i --;
                if(j > c)
                    j --;
                ma[i][j] = a[temp_i][temp_j];//ɾȥһ��һ�к�ľ��� 
                i = temp_i;
                j = temp_j;
            }
        }
    if(order >= 2)
        result_l = determinant(ma,order - 1);//���㽵�׺������ʽ���ܽ����� 1 
    return result_l;
}
float inverse(float **a,int r,int c,int order)//����� 
{
	float result = 0;
    result = adjoint(a,r,c,order) / determinant(a,order);//AA*=det(A)I 
    return result;
}
void print_inverse(float **a,int order)//�������� 
{
	int i,j;
    for(i = 0;i < order;i ++)
    {
        for(j = 0;j < order;j ++)
            printf("%.2f\t",inverse(a,i,j,order));
        printf("\n");
    }
}
float adjoint(float **a,int r,int c,int order)//���� 
{
	float result = 0;
    if(order == 1 && r == 0 && c == 0)//ֱ���������� 1
        result = 1;
    else
        result = pow(-1,r + c) * laplace(a,c,r,order);//��������ʽ 
    return result;
}
void print_adjoint(float **a,int order)//���������� 
{
	int i,j;
    for(i = 0;i < order;i ++)
    {
        for(j = 0;j < order;j ++)
            printf("%.2f\t",adjoint(a,i,j,order));
        printf("\n");
    }
}
