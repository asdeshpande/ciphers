/*
* Vigenere Cipher
* Author - Aniruddha Deshpande
* Date   - 

----- History ------
* 23-Mar-2012 : Aniruddha - Creation.

----- Comments ------
* (not working for UPPER CASE and numbers)

----------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class vcipher
{
private: 
	char v[27][27];
	string encrypted, decrypted, spc;
	
public:
	vcipher();	//constructor
	void matrix(int i, int j);		//recursive
	//void display_matrix(int x,int y);
	void encrypt(string str, string key);
	void decrypt(string key);
};

/***********************constructor************************/
vcipher::vcipher()

{
spc=" ,?.!@#$%^&*();:'+-*`~[]{}=/<>|_";			//special character list||ascii? 
int j=1;
v[0][1]='a';						
	while(j<26)				//fills 'a-z' in first row
	{	
		v[0][j+1]=v[0][j]+1;
		j++;
	}
int i=1;
v[1][0]='a';						
	while(i<26)				//fills 'a-z in first column
	{	
		v[i+1][0]=v[i][0]+1;
		i++;
	}

}
/***************************matrix(recursive)*************************/
void vcipher::matrix(int i,int j)
{
if(i==27){return;}
v[i][j]='a'+(i-1);						

	while(j<26&&v[i][j]!='z')									//fills across
	{	
		v[i][j+1]=v[i][j]+1;
		j++;
	}

if(j==26){return matrix(i+1,1);} //new row
else
{
j=j+1;
v[i][j]='a';												//repeat index from 'a'
	while(j<26)
	{
		v[i][j+1]=v[i][j]+1;
		j++;
	}
return matrix(i+1,1); //new row
}
}
/***************************display(recursive)******************
void vcipher::display_matrix(int x,int y)
{
if(x==27){return;}
	while(y<27)				//reads across
	{	
		cout<<v[x][y]<<" ";
		y++;
	}

cout<<"\n";
return display_matrix(x+1,0); //new row
}

/*****************************encrypt*****************/
void vcipher::encrypt(string str, string key)
{
string tempkey;
int i=0;
while(tempkey.length()<str.length())
{	
	tempkey=tempkey+key[i];	
	i++;	
	if(i==key.length()){i=0;}
}
	

int z=0,x=1,y=1,sp;
while(z<str.length())
{
sp=0;	
	while(sp<spc.length() && str[z]!=spc[sp]){sp++;}	
	if(str[z]==spc[sp]){encrypted=encrypted+spc[sp];z++;continue;}	
	
	x=1;
	y=1;		
	while(tempkey[z]!=v[x][0]&&x<27) {x=x+1;} 
	while(str[z]!=v[0][y]&&y<27) {y=y+1;}

encrypted=encrypted+v[x][y];

z=z+1;
}
cout<<"Encrypted data is: "<<encrypted;

}//lxfopvefrnhr
/****************************decrypt***************************************/
void vcipher::decrypt(string key)
{
int i=0,x=1,y=1,k=0,sp;
string tempkey;
while(tempkey.length()<encrypted.length())
{	
	tempkey=tempkey+key[i];	
	i++;	
	if(i==key.length()){i=0;}
}
cout<<"Decrypted data is: ";

while(k<encrypted.length())
{	
x=1;
y=1;
sp=0;
	while(sp<spc.length() && encrypted[k]!=spc[sp]){sp++;}	
	if(encrypted[k]==spc[sp]){decrypted=decrypted+spc[sp];k=k+1;continue;}	
			
	while(v[x][0]!=tempkey[k]){x++;}	//find key letter in first column
	while(v[x][y]!=encrypted[k]){y++;}	//find encrypted letter postion in matrix

	decrypted=decrypted+v[0][y];
k++;
}
cout<<decrypted<<"\n";
}
/*********************************main***********************************/		
int main()
{
vcipher ob;
int i=1,j=1;
ob.matrix(i,j);
int id=0,jd=1;
//cout<<"  ";
//ob.display_matrix(0,1);
string str,key,d_key;
cout<<"Enter data to be encrypted: ";
getline(cin,str);
cout<<"Enter key: ";
cin>>key;

ob.encrypt(str,key);
cout<<"\n";

cout<<"Enter decryption key: ";
cin>>d_key;

ob.decrypt(d_key);

return 0;
}



