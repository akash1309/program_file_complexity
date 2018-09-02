#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sett=0,operand=0,oper=0,cyclo=0,lineo=0;
//working
void cc()
{
  FILE *ad=fopen("additional.txt","r");
  char a[200];
  while(!feof(ad))
  { lineo++;
    fgets(a,199,ad);
    int i,set=0;
    for(int i=0;i<strlen(a);i++)
    {
      if(a[i]=='(')
      {
        set=1; break;
      }
    }
    int t1;

    if(set==1)
    {
    char gh[]="(: ;\t";
    char *tokkk;
    //printf("%s\n",a);
    tokkk=strtok(a,gh);

    while(tokkk!=NULL)
    { if(strlen(tokkk)>1)
      {
      if((strcmp(tokkk,"for")==0)||(strcmp(tokkk,"while")==0)||(strcmp(tokkk,"if")==0))
      {cyclo++;
         //printf("%s %d\n",tokkk,lineo);
         //scanf("%d",&t1);
       }
      }
      tokkk=strtok(NULL,gh);
    }
  }
  }
  fclose(ad);
}
void ope(char filename[])
{ FILE *fpp=fopen(filename,"r");
  char text[200];
  while(!feof(fpp))
  {
    fgets(text,199,fpp);
    int i;
      for(i=0;i<strlen(text);i++)
      { if(text[i]=='#') continue;
        if(((text[i]>=33)&&(text[i]<=47))||((text[i]>=60)&&(text[i]<=63))||((text[i]>=91)&&(text[i]<=94))||((text[i]>=123)&&(text[i]<=126)))
        {oper++;
          //printf("%c\n",text[i]);
        }
        if(text[i]==41 || text[i]==93 || text[i]==95 || text[i]==125)
        oper--;


      }
      for(i=0;i< strlen(text)-1 ;i++)
      {  if(text[i]=='#') continue;
        if(((text[i]=='+')&&(text[i+1]=='+'))||((text[i]=='-')&&(text[i+1]=='-'))||((text[i]=='&')&&(text[i+1]=='&'))||((text[i]=='|')&&(text[i+1]=='|')))
        oper--;
        if((text[i]=='*')&&(text[i]==47))
        oper--;
      }
      char *token;
      char s[]="; +*-\=#\n";
      token=strtok(text,s);
      while(token!=NULL)
      {
        if(((token[0]-'0')>=0)&&((token[0]-'0')<=9))
        {operand++;
          //printf("%s\n",token);
        }
      token=strtok(NULL,s);
      }


  }

}

void occ(char str[],char substr[],int line)
{ // printf("\\\ ");
    int i,j;
    int b=strlen(str);
    int c=strlen(substr);
	for(i=0;i< b-c;i++)
	{  for(j=0;j<c;j++)
	    {   if(substr[j]!=str[i+j])
	        break;
		  }

      if(j==c)
        { //printf("ggh");
              if(i==0)
                 {
                    if((str[i+c]<97)||(str[i+c]>122))
                     {
                          if((str[i+c]<65)||(str[i+c]>90))
                        {  //printf("%s occurs at %d position and line %d \n",substr,i,line);
                          operand++;
                        }
                      }
                 }
              else
                 {

	                	 if((str[i-1]<97)||(str[i-1]>122))
	                	  {
	                 		    if((str[i+c]<97)||(str[i+c]>123))
	                		      {
	                		         if((str[i-1]<65)||(str[i-1]>90))
	                		          {
	                		           	if((str[i+c]<65)||(str[i+c]>90))
	                		            	{
	                		              		//printf("%s occurs at %d position and line %d \n",substr,i,line);
                                        operand++;
	                	                    sett=1;
										                }
					              				}

		                      	}
		                  }
     	           }

        }
	}
}

void occurence(char filename[])
{	  FILE *fp,*in;
	  char *pos;
    char name[200],text[200];
	  fp=fopen(filename,"r");
	  in=fopen("input.txt","r");
	  fgets(name,199,in);
	  while(!feof(in))
	   {
	     	if ( (pos=strchr(name, '\n')) != NULL  )
	     	*pos='\0';
	    	rewind(fp);
	    	int line=0;
	 //   printf("111%s",name);
		    while(!feof(fp))
		    {   sett=0;
		      	fgets(text,200,fp);
		    		line++;
      //  printf("%s \n",text);
            if(strcmp(name," ")!=0)
			      {
              occ(text,name,line);
            }
        }
	      fgets(name,199,in);
	//	printf("%s hhhhhh\n",name);
	   }
	  fclose(fp);
	  fclose(in);
}
void check(char str[])
{
  int i;
  for(i=0;i<strlen(str);i++)
    {
      if(str[i]=='(')
        return;
    }
  FILE *var;
	var=fopen("input.txt","a");
	int set=0;
	char s[]=",\n* ;";
  char *token;
	token=strtok(str,s);
  while(token != NULL)
	   {
			 if(set==0)
		    	 {
		     	 	if((strcmp(token,"int")==0)||(strcmp(token,"float")==0)||(strcmp(token,"char")==0))
	                  set=1;
	             //   else
	               // break;
	              }
	         else
	            {
                char str[100];
                strcpy(str,token);
              //  printf("%s\n",str);
                int len=strlen(str);
                int k=0,p=0;
                char substr[50];
                substr[0]='\0';
                while(k<len)
                  {
                  if(((str[k]-'A')>=0)&&((str[k]-'A')<=25))
                    {
                      substr[p]=str[k];
                         p++;
                      //   settt=1;
                    }
                    else
                    {  if(((str[k]-'a')>=0)&&((str[k]-'a')<=25))
                       {
                         substr[p]=str[k];
                         p++;
                        // settt=1;
                       }
                       else
                       {  if(((str[k]-'0')>=0)&&((str[k]-'0')<=9))
                          {
                            substr[p]=str[k];
                            p++;
                          //  settt=1;
                          }
                          else
                          if((str[k]-'\0')==0)
                          {substr[p]=str[k];
                          break;
                          }
                          else
                          {
                               substr[p]='\0';
                              //  printf("%s\n",substr);
                               break;
                          }
                       }
                    }
                k++;
                  if(k==len)
                  {substr[k]='\0';
                   break;
                   }
                }
                if(p!=0)
                fprintf(var,"%s\n",substr);
              //  substr[0]='\0';
              //  printf("%s\n",substr);
               if((strcmp(token,"for")==0)||(strcmp(token,"while")==0)||(strcmp(token,"do")==0)||(strcmp(token,"printf")==0)||(strcmp(token,"scanf")==0))
                oper++;

                //printf("%s\n",token);
						// fprintf(var,"%s\n",token);
            }
			        token=strtok(NULL,s);
	   }
	   fclose(var);
}
int main()
{
	char line[200],str[200];
	FILE *fp;
	FILE *f=fopen("input.txt","w");
    fclose(f);
	printf("enter the file ");
	char filename[20];
    gets(filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	printf("File does not exist!!");
	else
	{    FILE *pre=fopen("additional.txt","w");
	     char ch1,ch2;
	     ch1=getc(fp);
	    //ch2=getc(fp);
	    //printf("%c%c",ch1,ch2);
	    while((ch2=getc(fp))!=EOF)
	     {
	        if((ch1=='/')&&(ch2=='*'))
	        {
			         fprintf(pre,"%c%c",'/','*');
				       ch1=getc(fp);
		           ch2=getc(fp);
		           while(ch2!=EOF)
		            {  //printf("%c ",ch1);
		                if((ch1=='*')&&(ch2=='/'))
		                 { fprintf(pre,"%c%c",'*','/');
		                    ch2=fgetc(fp);
		                    ch1=ch2;
					            	 break;
				             }
				           // if(ch1=='\n')
                    if(ch2=='\n')
                    {fprintf(pre,"%c%c",ch1,'\n');
                     ch2=getc(fp);
                     }
		                	 else
		               	 {
						              if(ch1==' ')
		                   	  fprintf(pre,"%c",' ');
		                  	  else
						              fprintf(pre,"%c",'#');
					           }
		                   	 ch1=ch2;
		                  	 ch2=getc(fp);
		  	        }
               if(ch2==EOF)
	               break;
			    }
		    	else
			    {  if((ch1=='/')&&(ch2=='/'))
	                {  fprintf(pre,"%c%c",'/','/');
				             ch1=getc(fp);
		                 ch2=getc(fp);
		                 while(ch2!=EOF)
		                  {  //printf("%c ",ch1);

				                  if(ch2=='\n')
				                   {
				                  		 fprintf(pre,"%c%c",ch1,'\n');
                               ch2=getc(fp);
				                   		 break;
				           	       }
		                    	 else
		                     	 {
				    		                if(ch1==' ')
		                        	  fprintf(pre,"%c",' ');
		                          	else
				        		            fprintf(pre,"%c",'#');
				     	             }
		                  	    ch1=ch2;
		            	          ch2=getc(fp);
		  	              }
                 if(ch2==EOF)
	                    break;
		     	        }
   		        else
			        	{
                     if(ch1=='"')
                     {
                       fprintf(pre,"%c",'"');
                       while((ch1=fgetc(fp)) !=EOF)
                       {   if(ch1=='"')
                           { fprintf(pre,"%c",'"');
                             ch2=getc(fp);
                             ch1=ch2;
                             break;
                           }
                           else
                           {
                             fprintf(pre,"%c",'#');
                           }
                       }
                       if(ch1==EOF)
                       break;
                     }
				            else
                     {
			              	 fprintf(pre,"%c",ch1);
                       ch1=ch2;
                    }
		       	    }
	 }
   }
   fprintf(pre,"%c",ch1);
     fclose(pre);
	  }
    fclose(fp);
		 FILE *pr=fopen("additional.txt","r");
		while(!feof(pr))
	    {
	       fgets(str,199,pr);
	       check(str);
        }
        cc();
		occurence("additional.txt");
    ope("additional.txt");
 printf("no of operands : %d\nno of operator : %d\n with cyclometric complexity : %d\n",operand,oper,cyclo);
	return 0;
}
