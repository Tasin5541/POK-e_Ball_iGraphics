/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include<stdlib.h>
#include<string.h>
#define ESC 27
/* 
	function iDraw() is called again and again by the system.
*/


struct ms
{
	char name[10];
	char cgpa[10];
}hs[6];
int score1[6];

int page=1;
double len=96,wid=16;
int f1x,f1y,f2x,f2y,f3x,f3y,f4x,f4y,b1x,b1y,b2x,b2y,s1x,s1y,lf1x,lf1y,lf2x,lf2y,dy=4,l1=0,l2=0,namex=200,namey=550,scorex=500,scorey=550;
int a=4,b=5,c=7;
int stickposition_x=244,stickposition_y=0;
int ballposition_x=stickposition_x+16,ballposition_y=0,balldirection=1,ballmidpoint;
int score=0,lives=1,sub=0,level=1;
int flag;
int stlen;
int mode;
float cgpa=0;
char text[100],text2[100],text3[100];
char shwname[5][30],shwscore[5][30];
char life[100],srl[10];
char str[100], str2[100],lvlshw[10];
int l3=0;


bool stick301=true,stick302=true,stick303=true,stick304=true,stick305=true,stick306=true,stick307=true,stick308=true,stick309=true,
	stick310=true,stick311=true,stick312=true,stick313=true,stick314=true,stick315=true,stick316=true,stick317=true,stick318=true,
	stick319=true,stick320=true,stick321=true;
bool f1=false,f2=false,f3=false,f4=false,lf1=false,lf2=false,b1=false,b2=false,s1=false,cover=true;
bool gamestart=true,ball=true,play=false,ballpos=true,shw=true,start=false; /*start :notun system add krsi.eta ekhn lgbe na*/
bool stick1=true,stick2=true,stick3=true,stick4=true,stick5=true,stick6=true,stick7=true,stick8=true,
	stick9=true,stick10=true,stick11=true,stick12=true,step1=true;
bool stick21=true,stick22=true,stick23=true,stick24=true,stick25=true,stick26=true,stick27=true,stick28=true,stick29=true,stick210=true,
	stick211=true,stick212=true,stick213=true,stick214=true,stick215=true,stick216=true,stick217=true,stick218=true,stick219=true,stick220=true,
	stick221=true,stick222=true,stick223=true,stick224=true,stick225=true,stick226=true,stick227=true,stick228=true,stick229=true,stick230=true,
	stick231=true,stick232=true,stick233=true,stick234=true,stick235=true,stick236=true,stick237=true,stick238=true,stick239=true,stick240=true,
	stick241=true,stick242=true;
bool newhs=true,congratz=false;


void restart()
{
	 score1[6]=0;

 page=1;
 len=96,wid=16;
 f1x=0,f1y=0,f2x=0,f2y=0,f3x=0,f3y=0,f4x=0,f4y=0,b1x=0,b1y=0,b2x=0,b2y=0,s1x=0,s1y=0,lf1x=0,lf1y=0,lf2x=0,lf2y=0,
	 dy=4,l1=0,l2=0,l3=0,namex=200,namey=550,scorex=500,scorey=550;
 a=4,b=5,c=7;
 stickposition_x=244,stickposition_y=0;
 ballposition_x=stickposition_x+16,ballposition_y=0,balldirection=1,ballmidpoint=0;
 score=0,lives=1,sub=0,level=1;
 flag=0;
 stlen=0;
 mode=0;
 cgpa=0;
/*char text[100],text2[100],text3[100];
char shwname[5][30],shwscore[5][30];
char life[100];
char str[100], str2[100]; */


f1=false,f2=false,f3=false,f4=false,lf1=false,lf2=false,b1=false,b2=false,s1=false,cover=true;
 gamestart=true,ball=true,play=false,ballpos=true,shw=true,start=false; /*start :notun system add krsi.eta ekhn lgbe na*/
 stick1=true,stick2=true,stick3=true,stick4=true,stick5=true,stick6=true,stick7=true,stick8=true,
	stick9=true,stick10=true,stick11=true,stick12=true,step1=true;
 stick21=true,stick22=true,stick23=true,stick24=true,stick25=true,stick26=true,stick27=true,stick28=true,stick29=true,stick210=true,
	stick211=true,stick212=true,stick213=true,stick214=true,stick215=true,stick216=true,stick217=true,stick218=true,stick219=true,stick220=true,
	stick221=true,stick222=true,stick223=true,stick224=true,stick225=true,stick226=true,stick227=true,stick228=true,stick229=true,stick230=true,
	stick231=true,stick232=true,stick233=true,stick234=true,stick235=true,stick236=true,stick237=true,stick238=true,stick239=true,stick240=true,
	stick241=true,stick242=true;
 newhs=true,congratz=false;
  
 stick301=true,stick302=true,stick303=true,stick304=true,stick305=true,stick306=true,stick307=true,stick308=true,stick309=true,
	stick310=true,stick311=true,stick312=true,stick313=true,stick314=true,stick315=true,stick316=true,stick317=true,stick318=true,
	stick319=true,stick320=true,stick321=true;
}

void balldirect()
{
	if(balldirection==1)
		balldirection=3;
		else if(balldirection==2)
			balldirection=4;
		else if(balldirection==5)
			balldirection=6;
		else if(balldirection==7)
			balldirection=9;
		else if(balldirection==8)
			balldirection=10;
		else if(balldirection==3)
		    balldirection=1;
		else if(balldirection==4)
			balldirection=2;
		else if(balldirection==6)
			balldirection=5;
		else if(balldirection==9)
			balldirection=7;
		else if(balldirection==10)
			balldirection=8;
}

void ballmovement()
{
	if(sub>=1)
		cgpa=score/sub;

	if(ballpos){
		ballposition_x=stickposition_x+((len/2)-16);ballposition_y=16;}
	if(play){
		balldirection=1;
		play=false;
		ballpos=false;
	}
	ballmidpoint=ballposition_x+16;
	 
	if(ballposition_y<=20 && ballposition_y>=0)
	{
		//ballmidpoint=ballposition_x+16;
		if(ballmidpoint>=stickposition_x+10 && ballmidpoint<=stickposition_x+24)
			balldirection=1;
		else if(ballmidpoint>=stickposition_x+(len-24) && ballmidpoint<=stickposition_x+(len+6))
			balldirection=2;
		else if(ballmidpoint>=stickposition_x+24 && ballmidpoint<=stickposition_x+(len-24))
			balldirection=5;
		else if(ballmidpoint>=stickposition_x-16 && ballmidpoint<=stickposition_x+10)
			balldirection=8;
		else if(ballmidpoint>=stickposition_x+(len+6) && ballmidpoint<=stickposition_x+len+16)
			balldirection=7;

	}

	
	 
	
	
	 if(ballposition_x<=0)
	{
		if(balldirection==1)
			balldirection=2;
		else if(balldirection==3)
			balldirection=4;
		else if(balldirection==8)
			balldirection=7;
		else if(balldirection==10)
			balldirection=9;
	}
	else if(ballposition_x>=552)
	{
		if(balldirection==2)
			balldirection=1;
		else if(balldirection==4)
			balldirection=3;
		else if(balldirection==7)
			balldirection=8;
		else if(balldirection==9)
			balldirection=10;
	}
	else if(ballposition_y>=548)
	{
		if(balldirection==1)
		balldirection=3;
		else if(balldirection==2)
			balldirection=4;
		else if(balldirection==5)
			balldirection=6;
		else if(balldirection==7)
			balldirection=9;
		else if(balldirection==8)
			balldirection=10;
	}
	else if(ballposition_y<0){
		ballposition_x=stickposition_x+16;ballposition_y=16;
		balldirection=1;
		lives--;
		ballpos=true;
		if(lives==0)
			ball=false;
		
	}
	
	

	if(balldirection==1)
	{
		ballposition_x-=a;
		ballposition_y+=a;
	}
	else if(balldirection==2)
	{
		ballposition_x+=a;
		ballposition_y+=a;
	}
	else if(balldirection==3)
	{
		ballposition_x-=a;
		ballposition_y-=a;
	}
	else if(balldirection==4)
	{
		ballposition_x+=a;
		ballposition_y-=a;
	}
	else if(balldirection==5)
	{
		
		ballposition_y+=b;
	}
	else if(balldirection==6)
	{
		ballposition_y-=b;
	}

	else if(balldirection==7)
	{
		ballposition_x+=c;
		ballposition_y+=a;
	}

	else if(balldirection==8)
	{
		ballposition_x-=c;
		ballposition_y+=a;
	}

	else if(balldirection==9)
	{
		ballposition_x+=c;
		ballposition_y-=a;
	}

	else if(balldirection==10)
	{
		ballposition_x-=c;
		ballposition_y-=a;
	}


	
	
}

void fail()
{
	f1y-=2;
	f2y-=2;
	f3y-=2;
	f4y-=2;
	b1y-=2;
	b2y-=2;
	s1y-=2;
	lf1y-=2;
}


void level1()
{
	if(stick1)
	    iShowBMP(0,548,"c.bmp");
	if(stick2)
		iShowBMP(0,484,"m.bmp");
    if(stick3)
		iShowBMP(0,420,"h.bmp");
	if(stick4)
		iShowBMP(0,356,"m1.bmp");
	if(stick5)
	    iShowBMP(520,548,"e.bmp");
	if(stick6)
		iShowBMP(520,484,"h.bmp");
    if(stick7)
		iShowBMP(520,420,"c.bmp");
	if(stick8)
		iShowBMP(520,356,"m.bmp");
	if(stick9)
	    iShowBMP(276,548,"m1.bmp");
	if(stick10)
		iShowBMP(276,484,"e.bmp");
    if(stick11)
		iShowBMP(276,420,"m.bmp");
	if(stick12)
		iShowBMP(276,356,"c.bmp");
}

void lvl1()
{
	ballmidpoint=ballposition_x+16;
	if(stick1)
	 {
	if(ballposition_y>=(548-32) && ballposition_y<=(548+32))
	{
		if(ballmidpoint>=(0-16) && ballmidpoint<=(64+16))
		{
			balldirect();
			stick1=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick2)
	 {
	if(ballposition_y>=(484-32) && ballposition_y<=(484+32))
	{
		if(ballmidpoint>=(0-16) && ballmidpoint<=(64+16))
		{
			balldirect();
			stick2=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick3)
	 {
	if(ballposition_y>=(420-32) && ballposition_y<=(420+32))
	{
		if(ballmidpoint>=(0-16) && ballmidpoint<=(64+16))
		{
			balldirect();
			stick3=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick4)
	 {
	if(ballposition_y>=(356-32) && ballposition_y<=(356+32))
	{
		if(ballmidpoint>=(0-16) && ballmidpoint<=(64+16))
		{
			balldirect();
			stick4=false;
			score+=4;
			sub++;
			l1++;
			b1=true;
			b1x=16;
			b1y=356;
		}
	}
     }

 if(stick5)
	 {
	if(ballposition_y>=(548-32) && ballposition_y<=(548+32))
	{
		if(ballmidpoint>=(520-16) && ballmidpoint<=(584+16))
		{
			balldirect();
			stick5=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick6)
	 {
	if(ballposition_y>=(484-32) && ballposition_y<=(484+32))
	{
		if(ballmidpoint>=(520-16) && ballmidpoint<=(584+16))
		{
			balldirect();
			stick6=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick7)
	 {
	if(ballposition_y>=(420-32) && ballposition_y<=(420+32))
	{
		if(ballmidpoint>=(520-16) && ballmidpoint<=(584+16))
		{
			balldirect();
			stick7=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick8)
	 {
	if(ballposition_y>=(356-32) && ballposition_y<=(356+32))
	{
		if(ballmidpoint>=(520-16) && ballmidpoint<=(584+16))
		{
			balldirect();
			stick8=false;
			score+=4;
			sub++;
			l1++;
			s1=true;
			s1x=520+16;
			s1y=356;
		}
	}
     }
	 if(stick9)
	 {
	if(ballposition_y>=(548-32) && ballposition_y<=(548+32))
	{
		if(ballmidpoint>=(276-16) && ballmidpoint<=(276+80))
		{
			balldirect();
			stick9=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick10)
	 {
	if(ballposition_y>=(484-32) && ballposition_y<=(484+32))
	{
		if(ballmidpoint>=(276-16) && ballmidpoint<=(276+80))
		{
			balldirect();
			stick10=false;
			score+=4;
			sub++;
			l1++;
		}
	}
     }

	 if(stick11)
	 {
	if(ballposition_y>=(420-32) && ballposition_y<=(420+32))
	{
		if(ballmidpoint>=(276-16) && ballmidpoint<=(276+80))
		{
			balldirect();
			stick11=false;
			score+=4;
			sub++;
			lf1=true;
			lf1x=292;
			lf1y=388;
			l1++;
		}
	}
     }

	 if(stick12)
	 {
	if(ballposition_y>=(356-32) && ballposition_y<=(356+32))
	{
		if(ballmidpoint>=(276-16) && ballmidpoint<=(276+80))
		{
			balldirect();
			stick12=false;
			score+=4;
			sub++;
			f2=true;
			f2x=292;
			f2y=356;
			l1++;
		}
	}
     }
	 if(l1==12)
	 {
		 //step1=false;
		 level=2;
		 ballpos=true;
		 l1++;
		 
		 //gamestart=true;
	 }
		 
}


void level2_1()
{
	if(stick21)
	    iShowBMP(100,448,"lab.bmp");
	if(stick22)
		iShowBMP(100,432,"lab.bmp");
    if(stick23)
		iShowBMP(100,416,"lab.bmp");
	if(stick24)
		iShowBMP(100,400,"lab.bmp");
	if(stick25)
	    iShowBMP(100,384,"lab.bmp");
	if(stick26)
		iShowBMP(100,368,"lab.bmp");
    if(stick27)
		iShowBMP(164,368,"lab.bmp");
	if(stick28)
		iShowBMP(228,368,"lab.bmp");
	if(stick29)
	    iShowBMP(292,368,"lab.bmp");
	if(stick210)
		iShowBMP(356,368,"lab.bmp");
    if(stick211)
		iShowBMP(420,368,"lab.bmp");
	if(stick212)
		iShowBMP(420,448,"lab.bmp");
	if(stick213)
		iShowBMP(420,432,"lab.bmp");
    if(stick214)
		iShowBMP(420,416,"lab.bmp");
	if(stick215)
		iShowBMP(420,400,"lab.bmp");
	if(stick216)
	    iShowBMP(420,384,"lab.bmp");
	if(stick217)
		iShowBMP(164,448,"lab.bmp");
    if(stick218)
		iShowBMP(228,448,"lab.bmp");
	if(stick219)
		iShowBMP(292,448,"lab.bmp");
	if(stick220)
	    iShowBMP(356,448,"lab.bmp");
	
}

void level2_2()
{
	if(stick222)
	    iShowBMP(100,448,"lab2.bmp");
	if(stick223)
		iShowBMP(100,432,"lab2.bmp");
    if(stick224)
		iShowBMP(100,416,"lab2.bmp");
	if(stick225)
		iShowBMP(100,400,"lab2.bmp");
	if(stick226)
	    iShowBMP(100,384,"lab2.bmp");
	if(stick227)
		iShowBMP(100,368,"lab2.bmp");
    if(stick228)
		iShowBMP(164,368,"lab2.bmp");
	if(stick229)
		iShowBMP(228,368,"lab2.bmp");
	if(stick230)
	    iShowBMP(292,368,"lab2.bmp");
	if(stick231)
		iShowBMP(356,368,"lab2.bmp");
    if(stick232)
		iShowBMP(420,368,"lab2.bmp");
	if(stick233)
		iShowBMP(420,448,"lab2.bmp");
	if(stick234)
		iShowBMP(420,432,"lab2.bmp");
    if(stick235)
		iShowBMP(420,416,"lab2.bmp");
	if(stick236)
		iShowBMP(420,400,"lab2.bmp");
	if(stick237)
	    iShowBMP(420,384,"lab2.bmp");
	if(stick238)
		iShowBMP(164,448,"lab2.bmp");
    if(stick239)
		iShowBMP(228,448,"lab2.bmp");
	if(stick240)
		iShowBMP(292,448,"lab2.bmp");
	if(stick241)
	    iShowBMP(356,448,"lab2.bmp");
	if(stick242)
	    iShowBMP(260,408,"m.bmp");
}

void lvl2_1()
{
	if(level==2){
	if(stick21)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick21=false;
			
		}
	}
     }
	if(stick22)
	 {
	if(ballposition_y>=(432-32) && ballposition_y<=(432+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick22=false;
		}
	}
     }
	if(stick23)
	 {
	if(ballposition_y>=(416-32) && ballposition_y<=(416+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick23=false;
			
		}
	}
     }
	if(stick24)
	 {
	if(ballposition_y>=(400-32) && ballposition_y<=(400+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick24=false;
			
		}
	}
     }
	if(stick25)
	 {
	if(ballposition_y>=(384-32) && ballposition_y<=(384+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick25=false;
			
		}
	}
     }
	if(stick26)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick26=false;
			
		}
	}
     }
	if(stick27)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(164-16) && ballmidpoint<=(228+16))
		{
			balldirect();
			stick27=false;
			
		}
	}
     }
	if(stick28)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(228-16) && ballmidpoint<=(292+16))
		{
			balldirect();
			stick28=false;
			
		}
	}
     }
	if(stick29)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(292-16) && ballmidpoint<=(356+16))
		{
			balldirect();
			stick29=false;
			
		}
	}
     }
	if(stick210)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(356-16) && ballmidpoint<=(420+16))
		{
			balldirect();
			stick210=false;
			
		}
	}
     }
	if(stick211)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick211=false;
			
		}
	}
     }
	if(stick212)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick212=false;
			
		}
	}
     }
	if(stick213)
	 {
	if(ballposition_y>=(432-32) && ballposition_y<=(432+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick213=false;
			
		}
	}
     }
	if(stick214)
	 {
	if(ballposition_y>=(416-32) && ballposition_y<=(416+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick214=false;
			
		}
	}
     }
	if(stick215)
	 {
	if(ballposition_y>=(400-32) && ballposition_y<=(400+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick215=false;
			
		}
	}
     }
	if(stick216)
	 {
	if(ballposition_y>=(384-32) && ballposition_y<=(384+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick216=false;
			
		}
	}
     }
	if(stick217)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(164-16) && ballmidpoint<=(228+16))
		{
			balldirect();
			stick217=false;
			
		}
	}
     }
	if(stick218)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(228-16) && ballmidpoint<=(292+16))
		{
			balldirect();
			stick218=false;
			
		}
	}
     }
	if(stick219)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(292-16) && ballmidpoint<=(356+16))
		{
			balldirect();
			stick219=false;
			
		}
	}
     }
	if(stick220)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(356-16) && ballmidpoint<=(420+16))
		{
			balldirect();
			stick220=false;
			
		}
	}
     }
	}
	}

	void lvl2_2()
{
	if(level==2){
	if(!stick21 && stick222)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick222=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick22 && stick223)
	 {
	if(ballposition_y>=(432-32) && ballposition_y<=(432+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick223=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick23 && stick224)
	 {
	if(ballposition_y>=(416-32) && ballposition_y<=(416+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick224=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick24 && stick225)
	 {
	if(ballposition_y>=(400-32) && ballposition_y<=(400+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick225=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick25 && stick226)
	 {
	if(ballposition_y>=(384-32) && ballposition_y<=(384+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick226=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick26 && stick227)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(100-16) && ballmidpoint<=(164+16))
		{
			balldirect();
			stick227=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick27 && stick228)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(164-16) && ballmidpoint<=(228+16))
		{
			balldirect();
			stick228=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick28 && stick229)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(228-16) && ballmidpoint<=(292+16))
		{
			balldirect();
			stick229=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick29 && stick230)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(292-16) && ballmidpoint<=(356+16))
		{
			balldirect();
			stick230=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick210 && stick231)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(356-16) && ballmidpoint<=(420+16))
		{
			balldirect();
			stick231=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick211 && stick232)
	 {
	if(ballposition_y>=(368-32) && ballposition_y<=(368+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick232=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick212 && stick233)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick233=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick213 && stick234)
	 {
	if(ballposition_y>=(432-32) && ballposition_y<=(432+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick234=false;
			score+=4;
			sub++;
			l2++;
			f3=true;
			f3x=436;
			f3y=400;
		}
	}
     }
	if(!stick214 && stick235)
	 {
	if(ballposition_y>=(416-32) && ballposition_y<=(416+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick235=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick215 && stick236)
	 {
	if(ballposition_y>=(400-32) && ballposition_y<=(400+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick236=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick216 && stick237)
	 {
	if(ballposition_y>=(384-32) && ballposition_y<=(384+32))
	{
		if(ballmidpoint>=(420-16) && ballmidpoint<=(484+16))
		{
			balldirect();
			stick237=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick217 && stick238)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(164-16) && ballmidpoint<=(228+16))
		{
			balldirect();
			stick238=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick218 && stick239)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(228-16) && ballmidpoint<=(292+16))
		{
			balldirect();
			stick239=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick219 && stick240)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(292-16) && ballmidpoint<=(356+16))
		{
			balldirect();
			stick240=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(!stick220 && stick241)
	 {
	if(ballposition_y>=(448-32) && ballposition_y<=(448+32))
	{
		if(ballmidpoint>=(356-16) && ballmidpoint<=(420+16))
		{
			balldirect();
			stick241=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(stick242)
	 {
	if(ballposition_y>=(408-32) && ballposition_y<=(408+32))
	{
		if(ballmidpoint>=(260-16) && ballmidpoint<=(324+16))
		{
			balldirect();
			stick242=false;
			score+=4;
			sub++;
			l2++;
		}
	}
     }
	if(l2==21)
	 {
		 //step1=false;
		 level=3;
		 ballpos=true;
		 l2++;
		 
		 //gamestart=true;
	 }
	}
	}


void level3()
{
	if(stick301)
		iShowBMP(17,563,"m.bmp");
	if(stick302)
		iShowBMP(114,563,"lab.bmp");
	if(stick303)
		iShowBMP(211,563,"m1.bmp");
	if(stick304)
		iShowBMP(308,563,"h.bmp");
	if(stick305)
		iShowBMP(405,563,"e.bmp");
	if(stick306)
		iShowBMP(502,563,"c.bmp");


	if(stick307)
		iShowBMP(65,530,"c.bmp");
	if(stick308)
		iShowBMP(162,530,"e.bmp");
	if(stick309)
		iShowBMP(259,530,"h.bmp");
	if(stick310)
		iShowBMP(356,530,"m1.bmp");
	if(stick311)
		iShowBMP(453,530,"lab.bmp");


	if(stick312)
		iShowBMP(113,497,"m.bmp");
	if(stick313)
		iShowBMP(210,497,"lab.bmp");
	if(stick314)
		iShowBMP(307,497,"m1.bmp");
	if(stick315)
		iShowBMP(404,497,"h.bmp");


	if(stick316)
		iShowBMP(161,464,"e.bmp");
	if(stick317)
		iShowBMP(258,464,"c.bmp");
	if(stick318)
		iShowBMP(355,464,"m.bmp");


	if(stick319)
		iShowBMP(209,431,"m1.bmp");
	if(stick320)
		iShowBMP(306,431,"lab.bmp");

	if(stick321)
		iShowBMP(257,398,"h.bmp");
}


void lvl3()
{
	if(level==3){
	if(stick301)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(17-16) && ballmidpoint<=(17+64+16))
			{
				balldirect();
				stick301=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}



	if(stick302)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(114-16) && ballmidpoint<=(114+64+16))
			{
				balldirect();
				stick302=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}


	if(stick303)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(211-16) && ballmidpoint<=(211+64+16))
			{
				balldirect();
				stick303=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}


	if(stick304)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(308-16) && ballmidpoint<=(308+64+16))
			{
				balldirect();
				stick304=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}


	if(stick305)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(405-16) && ballmidpoint<=(405+64+16))
			{
				balldirect();
				stick305=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick306)
	{
		if(ballposition_y>=(563-32) && ballposition_y<=(563+32))
		{
			if(ballmidpoint>=(502-16) && ballmidpoint<=(502+64+16))
			{
				balldirect();
				stick306=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick307)
	{
		if(ballposition_y>=(530-32) && ballposition_y<=(530+32))
		{
			if(ballmidpoint>=(65-16) && ballmidpoint<=(65+64+16))
			{
				balldirect();
				stick307=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick308)
	{
		if(ballposition_y>=(530-32) && ballposition_y<=(530+32))
		{
			if(ballmidpoint>=(162-16) && ballmidpoint<=(162+64+16))
			{
				balldirect();
				stick308=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick309)
	{
		if(ballposition_y>=(530-32) && ballposition_y<=(530+32))
		{
			if(ballmidpoint>=(259-16) && ballmidpoint<=(259+64+16))
			{
				balldirect();
				stick309=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick310)
	{
		if(ballposition_y>=(530-32) && ballposition_y<=(530+32))
		{
			if(ballmidpoint>=(356-16) && ballmidpoint<=(356+64+16))
			{
				balldirect();
				stick310=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}


	if(stick311)
	{
		if(ballposition_y>=(530-32) && ballposition_y<=(530+32))
		{
			if(ballmidpoint>=(453-16) && ballmidpoint<=(453+64+16))
			{
				balldirect();
				stick311=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick312)
	{
		if(ballposition_y>=(497-32) && ballposition_y<=(497+32))
		{
			if(ballmidpoint>=(113-16) && ballmidpoint<=(113+64+16))
			{
				balldirect();
				stick312=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick313)
	{
		if(ballposition_y>=(497-32) && ballposition_y<=(497+32))
		{
			if(ballmidpoint>=(210-16) && ballmidpoint<=(210+64+16))
			{
				balldirect();
				stick313=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick314)
	{
		if(ballposition_y>=(497-32) && ballposition_y<=(497+32))
		{
			if(ballmidpoint>=(307-16) && ballmidpoint<=(307+64+16))
			{
				balldirect();
				stick314=false;
				score+=4;
				sub++;
				l3++;
				lf2=true;
				lf2x=323;
				lf2y=465;
			}
		}
	}

	if(stick315)
	{
		if(ballposition_y>=(497-32) && ballposition_y<=(497+32))
		{
			if(ballmidpoint>=(404-16) && ballmidpoint<=(404+64+16))
			{
				balldirect();
				stick315=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick316)
	{
		if(ballposition_y>=(464-32) && ballposition_y<=(464+32))
		{
			if(ballmidpoint>=(161-16) && ballmidpoint<=(161+64+16))
			{
				balldirect();
				stick316=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick317)
	{
		if(ballposition_y>=(464-32) && ballposition_y<=(464+32))
		{
			if(ballmidpoint>=(258-16) && ballmidpoint<=(258+64+16))
			{
				balldirect();
				stick317=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick318)
	{
		if(ballposition_y>=(464-32) && ballposition_y<=(464+32))
		{
			if(ballmidpoint>=(355-16) && ballmidpoint<=(355+64+16))
			{
				balldirect();
				stick318=false;
				score+=4;
				sub++;
				l3++;
				f4=true;
				f4x=371;
				f4y=432;
			}
		}
	}

	if(stick319)
	{
		if(ballposition_y>=(431-32) && ballposition_y<=(431+32))
		{
			if(ballmidpoint>=(209-16) && ballmidpoint<=(209+64+16))
			{
				balldirect();
				stick319=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick320)
	{
		if(ballposition_y>=(431-32) && ballposition_y<=(431+32))
		{
			if(ballmidpoint>=(306-16) && ballmidpoint<=(306+64+16))
			{
				balldirect();
				stick320=false;
				score+=4;
				sub++;
				l3++;
			}
		}
	}

	if(stick321)
	{
		if(ballposition_y>=(398-32) && ballposition_y<=(398+32))
		{
			if(ballmidpoint>=(257-16) && ballmidpoint<=(257+64+16))
			{
				balldirect();
				stick321=false;
				score+=4;
				sub++;
				l3++;
				b2=true;
				b2x=273;
				b2y=366;
			}
		}
	}
	

	if(l3==21)
	 {
		congratz=true;
	 }
}
}



void pages()
{
	if(page==1)
	iShowBMP(35,45,"menu.bmp");
	if(page==3)
	iShowBMP(35,45,"d1.bmp");
	if(page==4)
	iShowBMP(35,45,"d2.bmp");
	if(page==5)
	iShowBMP(35,45,"d3.bmp");
	if(page==7)    /*this section is for resetting the high score*/
	{
		/*FILE *p;
				p=fopen("score.txt","w");
				strcpy(hs[0].name,"dpk");
				strcpy(hs[1].name,"ifti");
				strcpy(hs[2].name,"skb");
				strcpy(hs[3].name,"paps");
				strcpy(hs[4].name,"srk");
				
				int hsscore[]={16,12,8,4,0};
				double hscg[]={4,4,4,4,3.5};

				for(int i=0;i<5;i++)
				fprintf(p,"%s %d %.2f\n",hs[i].name,hsscore[i],hscg[i]);      /*file e auto string hoye jai jai dei*/
				//fclose(p); 
	}
	if(page==8)
	iShowBMP(35,45,"instruction.bmp");

}

void highscore()
{
	iText(350,40,"Pres ESC to go back",GLUT_BITMAP_HELVETICA_18);
	iText(230,570,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(180,500,"NAME");
		iText(300,500,"SCORE");
		FILE *p;
				p=fopen("score.txt","r");
				//char score[20];
				for(int i=0;i<5;i++)
				fscanf(p,"%s %d %s\n",hs[i].name,&score1[i],hs[i].cgpa);      
				
				
				for(int i=0;i<5;i++)
				{
				sprintf(shwname[i],"%s",hs[i].name);
				sprintf(shwscore[i],"%d [CGPA %s]",score1[i],hs[i].cgpa);
				sprintf(srl,"%d:",i+1);
				iText(150,450-i*50,srl);
				iText(180,450-i*50,shwname[i]);
				iText(300,450-i*50,shwscore[i]);
				}
				fclose(p);
}




void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(131, 327, 250, 30);
}

void newhighscore()
{
		FILE *p;
				p=fopen("score.txt","r");
		for(int i=0;i<5;i++)
				fscanf(p,"%s %d %s\n",hs[i].name,&score1[i],hs[i].cgpa);
		//fclose(p);
		
		int temp;
		char nam[10];
		if(newhs)
		{
		for(int i=0;i<5;i++)              /*for checcking if there is a high score*/
		{
			if(score1[i]<score)
			{
				
				score1[5]=score;
				strcpy(hs[5].name,str2);
				for(int j=0;j<6;j++)      /*for sorting the score*/
				{
					for(int k=5;k>j;k--)
					{
						if(score1[k]>score1[k-1])
						{
							temp=score1[k-1];
							score1[k-1]=score1[k];
							score1[k]=temp;

							strcpy(nam,hs[k-1].name);
							strcpy(hs[k-1].name,hs[k].name);
							strcpy(hs[k].name,nam);

						}
					}
				}
				
				
				//FILE *p;
				p=fopen("score.txt","w");
				for(int i=0;i<5;i++)
				fprintf(p,"%s %d %s\n",hs[i].name,score1[i],hs[i].cgpa);      /*file e auto string hoye jai jai dei*/
				fclose(p);
				flag=1;         /*for showing NEW HIGH SCORE on the screen*/ 
				newhs=false;    /*1 bar sort korei jate sorting bondho hoye jai*/
				
				break;
			}
		}
		}
fclose(p);
}

void bonus()
{
	if(f1)
	iShowBMP(f1x,f1y,"f.bmp");
    if(f2)
	iShowBMP(f2x,f2y,"f.bmp");
	if(f3)
	iShowBMP(f3x,f3y,"f.bmp");
    if(f4)
	iShowBMP(f4x,f4y,"f.bmp");
	if(b1)
    iShowBMP(b1x,b1y,"big.bmp");
	if(b2)
    iShowBMP(b2x,b2y,"big.bmp");
	if(lf1)
    iShowBMP(lf1x,lf1y,"live.bmp");
	if(s1)
    iShowBMP(s1x,s1y,"small.bmp");
}

void bonuscol()
{
	if(f1y==20)
	{
		if(f1x>=stickposition_x-30 && f1x<=stickposition_x+len)
			score-=4;
	}

	if(f2y==20)
	{
		if(f2x>=stickposition_x-30 && f2x<=stickposition_x+len)
			score-=4;
	}

	if(f3y==20)
	{
		if(f3x>=stickposition_x-30 && f3x<=stickposition_x+len)
			score-=4;
	}

	if(f4y==20)
	{
		if(f4x>=stickposition_x-30 && f4x<=stickposition_x+len)
			score-=4;
	}

	if(b1y==20)
	{
		if(b1x>=stickposition_x-30 && b1x<=stickposition_x+len)
			len=len*1.5;
	}
	if(b2y==20)
	{
		if(b2x>=stickposition_x-30 && b2x<=stickposition_x+len)
			len=len*1.5;
	}

	if(s1y==20)
	{
		if(s1x>=stickposition_x-30 && s1x<=stickposition_x+len)
			len=len*.8;
	}

	if(lf1y==20)
	{
		if(lf1x>=stickposition_x-30 && lf1x<=stickposition_x+len)
			lives+=1;
	}
	if(lf2y==20)
	{
		if(lf2x>=stickposition_x-30 && lf2x<=stickposition_x+len)
			lives+=1;
	}
}


void iDraw()
{
	//place your drawing codes here	
	iClear();

/*	if(start)
	{
		iShowBMP(35,45,"rules.bmp");
		iText(200,35,"press n to continue");
	} */
	
	if(!cover)
	pages();

	if(cover)
		iShowBMP(35,45,"start3.bmp");

	if(page==2)
	{
		drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(136, 340, str);
	}
	iText(131, 367, "ENTER NAME :",GLUT_BITMAP_HELVETICA_18);
	iText(131, 300, "Click to activate the box, enter to finish.",GLUT_BITMAP_HELVETICA_18);
	}


	if(page==7)
	highscore();
	
	if(page==6){
	
	if(ball)
	iShowBMP(ballposition_x,ballposition_y,"ball.bmp");
	
	if(level==1)
	level1();
	if(level==2)
	{
		a=5;
		b=6;
		c=8;
		f1=false; f2=false; b1=false; s1=false;
		if(ball)
	iShowBMP(ballposition_x,ballposition_y,"ball.bmp");
		level2_2();
		level2_1();
	}
	if(level==3)
	{
		a=6;
		b=7;
		c=9;
		f3=false;
		if(ball)
		iShowBMP(ballposition_x,ballposition_y,"ball.bmp");
		level3();
	}
	
	iSetColor(173,173,173);
		//iFilledCircle(ballposition_x,ballposition_y,16);
	iSetColor(154,123,123);
	
	bonus();

	iFilledRectangle(stickposition_x,stickposition_y,len,wid);
	iLine(0,580,584,580);
	
	iSetColor(163,163,163);
	sprintf(text,"marks : %d (cgpa : %.2f)",score,cgpa);
	iText(390,595, text,GLUT_BITMAP_HELVETICA_18);
	//iText(450,595,"score : ");
	
	sprintf(life,"lives : %d",lives);
	iText(5,595,life,GLUT_BITMAP_HELVETICA_18);

	sprintf(lvlshw,"level : %d",level);
	iText(240,595,lvlshw,GLUT_BITMAP_HELVETICA_18);

	if(gamestart)
	iText(220,250,"press space bar to start",GLUT_BITMAP_HELVETICA_18);
	
	iSetColor(132,167,345);
	//iFilledRectangle(154,460,56,20);
	}

	if(congratz)
	{
		iPauseTimer(0);
		page=101;
		if(page==101)
		{
		iShowBMP(35,45,"congrats.bmp");
		newhighscore();
		sprintf(text2,"YOUR SCORE || marks : %d (cgpa : %.2f)",score,cgpa);
	    iText(250,285, text2,GLUT_BITMAP_HELVETICA_18);
		sprintf(text3,"COMPLETED YEARS : %d",level-1);
		iText(250,255, text3,GLUT_BITMAP_HELVETICA_18);
		if(flag)
			iText(250,330,"NEW HIGH SCORE!!",GLUT_BITMAP_HELVETICA_18);
		iRectangle(460,570,120,40);
		iText(470,580,"main menu",GLUT_BITMAP_HELVETICA_18);
		}
	}

	if(lives==0)
	{
		page=100;   /*to remove everything from screen*/
		


		//iPauseTimer(1);
		//iPauseTimer(2);
		//iPauseTimer(3);
		if(page==100)
		{
		iPauseTimer(0);
        newhighscore();
		iShowBMP(35,45,"over.bmp");
		sprintf(text2,"YOUR SCORE || marks : %d (cgpa : %.2f)",score,cgpa);
	    iText(150,495, text2,GLUT_BITMAP_HELVETICA_18);
		sprintf(text3,"COMPLETED YEARS : %d",level-1);
		iText(150,475, text3,GLUT_BITMAP_HELVETICA_18);
		if(flag)
			iText(200,530,"NEW HIGH SCORE",GLUT_BITMAP_HELVETICA_18);
		iRectangle(460,570,120,40);
		iText(470,580,"main menu",GLUT_BITMAP_HELVETICA_18);
		}
		//iText(260,30,text);
	}
	
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(page==1)
		{
			/*pressing new game*/
			if(my>=467-59 && my<=467)
			{
				if(mx>=381-180 && mx<=381)
					page++;
			}
			/*pressing high score*/
			if(my>=377-71 && my<=377)
			{
				if(mx>=392-201 && mx<=392)
					page=7;
			}
			/*instruction*/
			if(my>=275-60 && my<=275)
			{
				if(mx>=402-221 && mx<=402)
					page=8;
			}
			/*exit*/
			if(my>=187-52 && my<=187)
			{
				if(mx>=330-78 && mx<=330)
					exit(0);
			}
		}
	
		if(page==2)
		{
			if(mx >= 131 && mx <= 381 && my >= 327 && my <= 357 && mode == 0)
		{
			mode = 1;
		}
		}

		if(page==100 || page==101)
		{
			if(mx>=460 && mx<=580 && my>=570 && my<=610)
				lives=-1;
			iResumeTimer(0);
				page=1;
				restart();
		}

	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	//if((mx<=0 && mx<=480) || (stickposition_x>=0 && stickposition_x<=489))
	stickposition_x=mx;
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	/*esc holds the ascii value 27.pressing esc returns to menu*/
	int i;
	if(mode == 1)                /*nam lekhar box e clicl krle mode=1 hobe*/
	{
		if(key == '\r')          /*nam lekhe enter tipar por egula hobe*/
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < stlen; i++)
				str[i] = 0;
			stlen = 0;           /*stlen 0 krse jate porer bar nam input krle abar index 0 thke input nei*/
			page++;
		}
		else
		{
			str[stlen] = key;   /*index 0 theke nam er letter nea strt hbe*/
			stlen++;            /*prottek ltr input er jnno str er index baraite hbe*/
		}
	}
	if(key == ' ')
	{
		play=true;
		gamestart=false;
	}
	if(key == 27)
	{
		page=1;
	}
	if(key == 'n')
	{
		if(mode==0)               /*so that page doesn't increase while typing name*/
		{
		if(page<=5 || page >6)    /*so that page doesn't increase while playing game*/
		page++;	
		}
	}
	if(key == 'p')
	{
		if(mode==0)
		{
		iPauseTimer(0);
		}
	}
	if(key == 'r')
	{
		iResumeTimer(0);	
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}

	if(key == GLUT_KEY_LEFT)
	{
		stickposition_x-=16;	
	}

	if(key == GLUT_KEY_RIGHT)
	{
		stickposition_x+=16;	
	}
	//place your codes for other keys here
}


/*eta lagbe na apatoto.game er pic add krle tkhn lgbe*/
void coverpage()
{
	cover=false;
}


int main()
{
	//place your own initialization codes here. 
	
	    stlen = 0;
	    mode = 0;
	    str[0]= 0;
		iSetTimer(1,ballmovement);
		iSetTimer(1,bonuscol);
		iSetTimer(20,lvl1);
		iSetTimer(20,lvl2_1);
		iSetTimer(20,lvl2_2);
		iSetTimer(20,lvl3);
		iSetTimer(4000,coverpage);
		iSetTimer(5,fail);
		//iSetTimer(20,ballposition);
		PlaySound("music\\intense",NULL,SND_ASYNC);
	iInitialize(584, 612, "DX BALL");
	return 0;
}	