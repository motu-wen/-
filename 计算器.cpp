#include <stdio.h>
#include <conio.h>//����̨�������
#include <graphics.h>//����esay xͼ��
#include <iostream.h>
#define MaxSize 99
void translate(char str[],char exp[]);
double cal_value(char exp[]);
void main()
{	
    char str[MaxSize];
    char exp[MaxSize];
	char s[MaxSize];
    int t,i=1,j;	
    initgraph(320, 270);//����˵������
	settextstyle(20, 0, _T("����"));//----------�����С����
	outtextxy(0,0,"�ü�������ʹ�ù������£�");
	outtextxy(0,24,"1��������������---����Ҽ�����");
	outtextxy(0,71,"2���������μ���---����Ҽ�+ctrl");
	outtextxy(0,120,"3���ü�����ֻ�ܼ���Ǹ���");
	outtextxy(0,240,"���������ʼ���㡭��");
	getch();				// �����������
	closegraph();			// �رս���
while(i)
{	t=0;
    j=1;
	initgraph(320, 270);  // ��ͼ������ʼ��,������
	loadimage(NULL, "g:\\������.jpg");// ��ȡͼƬ����ͼ����
    MOUSEMSG m; //���������Ϣ
	while(j)
{
	 m = GetMouseMsg();// ��ȡһ�������Ϣ
     settextstyle(30, 0, _T("����"));
	 if(m.mkLButton)
	  {
	     if(0<m.x&&m.x<67&&170<m.y&&m.y<218)
		 { 
		 str[t]='1';
		 t++;

		 outtext(49);
		 }

	     else if(67<m.x&&m.x<129&&170<m.y&&m.y<218)
		 { 
		 str[t]='2';
		 t++;
		 outtext(50);
		 }
	     else if(129<m.x&&m.x<192&&170<m.y&&m.y<218)
		 { 
		 str[t]='3';
		 t++;
		 outtext(51);
		 }
	    else if(0<m.x&&m.x<67&&123<m.y&&m.y<170)
		{ 
		 str[t]='4';
		 t++;
		 outtext(52);
		}
	   else if(67<m.x&&m.x<129&&123<m.y&&m.y<170)
	   { 
		 str[t]='5';
		 t++;
		 outtext(53);
	   }
	   else if(129<m.x&&m.x<192&&123<m.y&&m.y<170)
	   { 
		 str[t]='6';
		 t++;
		 outtext(54);
	   }
	   else if(0<m.x&&m.x<67&&74<m.y&&m.y<123)
	   { 
		 str[t]='7';
		 t++;
		 outtext(55);
	   }
	  else if(67<m.x&&m.x<129&&74<m.y&&m.y<123)
	  { 
		 str[t]='8';
		 t++;
		 outtext(56);
	  }
	  else if(129<m.x&&m.x<192&&74<m.y&&m.y<123)
	  { 
		 str[t]='9';
		 t++;
		 outtext(57);
	  }
	  else if(0<m.x&&m.x<129&&218<m.y&&m.y<270)
	  { 
		 str[t]='0';
		 t++;
		 outtext('0');
	   }
	   else if(129<m.x&&m.x<192&&218<m.y&&m.y<270)
	   { 
		 str[t]='.';
		 t++;
		 outtext('.');
	   }
	   else if(192<m.x&&m.x<255&&74<m.y&&m.y<123)
	   { 
		 str[t]='/';
		 t++;
		 outtext('/');
	   }
	  else if(192<m.x&&m.x<255&&123<m.y&&m.y<170)
	  { 
		 str[t]='*';
		 t++;
		 outtext('*');
	  }
	  else if(192<m.x&&m.x<255&&170<m.y&&m.y<218)
	  { 
		 str[t]='-';
		 t++;
		 outtext('-');
	  }
	   else if(192<m.x&&m.x<255&&218<m.y&&m.y<270)
	  { 
		 str[t]='+';
		 t++;
		 outtext('+');
	  }
	   else if(255<m.x&&m.x<320&&74<m.y&&m.y<123)
	   { 
		 str[t]='(';
		 t++;
		 outtext('(');
	   }
	  else if(255<m.x&&m.x<320&&123<m.y&&m.y<170)
	  { 
		 str[t]=')';
		 t++;
		 outtext(')');
	  }
	  else if(255<m.x&&m.x<320&&170<m.y&&m.y<270)
	  {
		str[t]='\0';
		closegraph();	
     	translate(str,exp);
		initgraph(320, 270); 
     	loadimage(NULL, "g:\\������.jpg");
		if(cal_value(exp)!=' ')
		   sprintf(s, "%lf", cal_value(exp));
	     else 
		 {
			 settextcolor( RGB(255,0,0));//(RGB(��,�̣���))-------��ɫ
			 sprintf(s, "%s", "��������Ϊ0������");}
	      settextstyle(30, 0, _T("����"));
	 	  outtext(s);
		for(int m=0;str[m]='\0';m++)
			str[m]=0;
	    for(m=0;exp[m]='\0';m++)
			exp[m]=0;
		}
    }	
	if(m.mkRButton)
	{
		if(m.mkCtrl)//�Ҽ�����+ctrl-------------------------------�˳�����������
		{i=0;j=0;}
	    else//�Ҽ�����--------------------------------------------���¿�ʼ����
		 j=0;
	}
}	
     closegraph();
}
    cout<<"ллʹ��!"<<endl;	
}

void translate(char str[],char exp[])//��������ʽ����ɺ�׺���ʽ
{
       struct
       {
              char data[MaxSize];
              int top;                 
       }op; //�����ջ                   
       char ch;                    
       int i = 0,t = 0;
       op.top = -1;
       ch = str[i];                      
       i++;
       while(ch != '\0')                 
       {
              switch(ch)
              {
              case '(':                
                   op.top++;
				   op.data[op.top]=ch;
                     break;//��ջ
              case ')':              
                   while(op.data[op.top] != '(')    
				   {
                            exp[t]=op.data[op.top];
                            op.top--;
                            t++;
                    }
                     op.top--;
                     break;//�����������
              case '+':
              case '-':
                     while(op.top != -1&&op.data[op.top] != '(')
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top++;           
                     op.data[op.top] = ch;
                     break;//��chǰ�������ת����ʽ����ch����ջ��
              case '*':
              case '/':
                     while(op.data[op.top] == '/'||op.data[op.top] == '*')      
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }//�����������
                     op.top++;
                     op.data[op.top] = ch;//���˳�������ջ�У���ֱ�ӽ�����ʽ��
                     break;
              default:
                     while((ch >= '0'&&ch <= '9')||ch=='.')
                     {
                            exp[t] = ch;
							t++;
                            ch = str[i];
							i++;
                     }
                     i--;//��chͣ�����������
                     exp[t] = '#';         
                     t++;
              }
              ch = str[i];
              i++;
       }
       while(op.top != -1) //���������ʣ��ջ�������                 
       {
              exp[t] = op.data[op.top];
              t++;
              op.top--;
       }
       exp[t] = '\0';                        
}
double cal_value(char exp[])//�����׺���ʽ
{
       struct
       {
              double data[MaxSize];
              int top;
       }st;//������ʽ                         
       double d,e;
       char ch;
       int t = 0,p;
       st.top = -1;
       ch = exp[t];
       while(ch != '\0')
       {
              switch(ch)                 
            {
               case '+':
                      st.data[st.top-1] = st.data[st.top-1]+st.data[st.top];
                      st.top--;
                      break;
               case '-':
                      st.data[st.top-1] = st.data[st.top-1]-st.data[st.top];
                      st.top--;
                      break;
               case '*':
                      st.data[st.top-1] = st.data[st.top-1]*st.data[st.top];
                      st.top--;
                      break;
               case '/':
                       if(st.data[st.top] != 0)
                              st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
                       else
                       {
                              return ' ';
                       }
                       st.top--;
                       break;
               default:
				   d=0;e=0;
                   while((ch >= '0'&&ch <= '9')||ch=='.')
						 {
		                	if(ch!='.')
							{d = 10*d+ch-'0';
							 t++;
							 ch = exp[t];
                             }
		                 	if(ch=='.')
							{
			                   	while(ch!='#')
									{
									t++;
				                	ch = exp[t];
									}
							     	p=t;
				                 	t--;
									ch = exp[t];
				                	while(ch >= '0'&&ch <= '9')
									{
									 e=0.1*e+0.1*(ch-'0');
	                 	   	         t--;
									 ch = exp[t];
                                    }
									ch='#';
									t=p;
							}
						 }
                      st.top++;
                      st.data[st.top] = d+e;		  
			  }
		    	t++;
                ch = exp[t];   
	   }
       return st.data[st.top];
}