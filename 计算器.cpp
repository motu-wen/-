#include <stdio.h>
#include <conio.h>//控制台输入输出
#include <graphics.h>//引用esay x图库
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
    initgraph(320, 270);//操作说明界面
	settextstyle(20, 0, _T("黑体"));//----------字体大小设置
	outtextxy(0,0,"该计算器的使用规则如下：");
	outtextxy(0,24,"1：计算内容清零---鼠标右键单击");
	outtextxy(0,71,"2：结束本次计算---鼠标右键+ctrl");
	outtextxy(0,120,"3：该计算器只能计算非负数");
	outtextxy(0,240,"按任意键开始计算……");
	getch();				// 按任意键继续
	closegraph();			// 关闭界面
while(i)
{	t=0;
    j=1;
	initgraph(320, 270);  // 绘图环境初始化,计算器
	loadimage(NULL, "g:\\计算器.jpg");// 读取图片至绘图窗口
    MOUSEMSG m; //定义鼠标消息
	while(j)
{
	 m = GetMouseMsg();// 获取一条鼠标消息
     settextstyle(30, 0, _T("黑体"));
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
     	loadimage(NULL, "g:\\计算器.jpg");
		if(cal_value(exp)!=' ')
		   sprintf(s, "%lf", cal_value(exp));
	     else 
		 {
			 settextcolor( RGB(255,0,0));//(RGB(红,绿，蓝))-------红色
			 sprintf(s, "%s", "除数不能为0，错误！");}
	      settextstyle(30, 0, _T("黑体"));
	 	  outtext(s);
		for(int m=0;str[m]='\0';m++)
			str[m]=0;
	    for(m=0;exp[m]='\0';m++)
			exp[m]=0;
		}
    }	
	if(m.mkRButton)
	{
		if(m.mkCtrl)//右键单击+ctrl-------------------------------退出计算器程序
		{i=0;j=0;}
	    else//右键单击--------------------------------------------重新开始程序
		 j=0;
	}
}	
     closegraph();
}
    cout<<"谢谢使用!"<<endl;	
}

void translate(char str[],char exp[])//将输入表达式翻译成后缀表达式
{
       struct
       {
              char data[MaxSize];
              int top;                 
       }op; //运算符栈                   
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
                     break;//入栈
              case ')':              
                   while(op.data[op.top] != '(')    
				   {
                            exp[t]=op.data[op.top];
                            op.top--;
                            t++;
                    }
                     op.top--;
                     break;//括号内容清空
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
                     break;//将ch前的运算符转入表达式并将ch存入栈中
              case '*':
              case '/':
                     while(op.data[op.top] == '/'||op.data[op.top] == '*')      
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }//连乘连除情况
                     op.top++;
                     op.data[op.top] = ch;//将乘除储存入栈中（不直接进入表达式）
                     break;
              default:
                     while((ch >= '0'&&ch <= '9')||ch=='.')
                     {
                            exp[t] = ch;
							t++;
                            ch = str[i];
							i++;
                     }
                     i--;//将ch停留在运算符上
                     exp[t] = '#';         
                     t++;
              }
              ch = str[i];
              i++;
       }
       while(op.top != -1) //清除括号外剩余栈中运算符                 
       {
              exp[t] = op.data[op.top];
              t++;
              op.top--;
       }
       exp[t] = '\0';                        
}
double cal_value(char exp[])//计算后缀表达式
{
       struct
       {
              double data[MaxSize];
              int top;
       }st;//操作符式                         
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