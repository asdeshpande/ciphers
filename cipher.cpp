/*
* Caesar Cipher
* Author - Aniruddha
* Date -
--------History----------
* Creation-
* Completion- 23 Mar 2012
*/

#include <iostream>
#include <string>
using namespace std;

class caesar
{
private: 
	string encryptd, decryptd;
public:
	void encrypt(string str, int n);
	void decrypt(int n);
};
	
//------------------------------------------Encrypt----------------------------------------
void caesar::encrypt(string str, int n)
{
int i=0;
char temp;
	while(i<str.length())
	{
		temp=str[i]+n;		
		encryptd=encryptd+temp;
		i++;
	}
int z=0;

cout<<encryptd;

}
//-----------------------------------Decrypt-----------------------------
void caesar::decrypt(int n)
{
int i=0;
char temp;
	while(i<encryptd.length())
	{
		temp=encryptd[i]-n;
		decryptd=decryptd+temp;
		i++;
	}
cout<<decryptd<<"\n";
}
//----------------------------------main--------------------------------------
int main()
{
int n,dn,i=0;
caesar ob;
string str;
cout<<"Enter data to be encrypted: ";
getline(cin,str);
cout<<"Enter cipher key: ";
cin>>n;
ob.encrypt(str,n);
cout<<"\nEnter decryption key: ";
cin>>dn;
ob.decrypt(dn);
return 0;
}	
