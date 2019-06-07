#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std; 
void add1();
void del(); 
void disp();
void sort1(); 
void sort2();
void bubbleSort(string str[],int arr[], int n); 
void backup();
int main()
{
int n,z;
int password=1234;
int password1=NULL;
printf(" WELCOME USER\n");
//gotoxy(25,10); home :
printf("Enter passward to login: "); 
scanf("%d",&password1);
if(password==password1)
{
system("cls"); 
do
{
cout<<"\n**** MAIN MENU ****"<<endl<<endl; 
cout<<"1) ADD a new song "<<endl;
cout<<"2) DELETE a song "<<endl;
cout<<"3) SORT songs"<<endl;
cout<<"4) DISPLAY songs"<<endl;
cout<<"5) CREATE BACK-UP"<<endl;
cout<<"6) EXIT\n";
cout<<"\n Enter a valid option\n"; cin>>n;
switch(n)
{
case 1:add1();
cout<<"Song Added\n"; 
break;
case 2:del();
cout<<"Song Deleted \n"; 
break;
case 3:int y;
cout<<"Sort by name or by size ? (1,2)\n"; cin>>y;
switch(y)
{
case 1:cout<<"Sort by name :\n"; sort1();
break;
case 2:cout<<"Sort by song Size\n"; sort2();
break;
default:cout<<"Enter valid option";
}
break; case 4:disp();
break;
case 5: backup(); 
break;
case 6:return 0; 
break;
default:cout<<"Enter valid option\n";
}cout<<"Goto Main Menu ? (1/0)"<<endl;
cin>>z;
//z=getch();
}while(z==1);
}
else
{
printf("\n Invalid password..enter again!\n"); 
goto home;
}}
void backup()
{
char target_file[100],ch; 
FILE *source,*target;
system("cls"); 
fflush(stdin);
source = fopen("sup.txt", "r"); 
if( source == NULL )
{
cout<<"Press any key to exit...\n";
}
cout<<"Enter name of backup file\n"; 
gets(target_file);
target = fopen(target_file, "wb"); 
if( target == NULL )
{
fclose(source);
printf("Press any key to exit...\n");
}
while( ( ch = fgetc(source) ) != EOF ) fputc(ch, target);
cout<<"back up successfully created\n";
fclose(source); fclose(target);
}
void add1()
{
fstream f; int num; string str;
cout<<"Enter the song and the size\n"; 
cin>>str>>num; 
f.open("sup.txt",ios::app); f<<"\n"<<str<<" "<<num;
f.close();
}
void del()
{
//fstream f; int num;
string str,name;
cout<<"Enter the name of the song to be deleted:\n"; cin>>name;
//f.open("sup.txt"); 
ifstream fin; 
ofstream temp;
fin.open("sup.txt");
temp.open("temp.txt");
while (!fin.eof())
{
fin>>str>>num;
if (str!= name)
temp << "\n"<<str <<" " <<num;
}
fin.close();
temp.close(); 
remove("sup.txt"); 
rename("temp.txt", "sup.txt");
}
void disp()
{
fstream f; string str; int num;
f.open("sup.txt") ; 
if(!f)
{
cout<<"Unable to open\n";
// return 0;
}
else
{
 f.seekg(0);
//cout<<"Opened\n"; 
while(!f.eof())
{
f>>str>>num;
cout<<str<<" "<<num<<"\n";
}
}
f.close();
}
void sort1()
{
fstream f; string str;
vector <string> arr;
int count_lines=0,pos1,i=0;
f.open("sup.txt"); 
if (!f) {
cout << "Unable to open file\n";
}
else
{
 f.seekg(0);
while(!f.eof())
{
getline(f,str); 
count_lines++;
arr.push_back(str);
}
cout<<"\n\n";
sort(arr.begin(),arr.end()); 
for(int i=0;i<count_lines;i++) 
cout<<arr[i]<<endl;
}
}
void sort2()
{
fstream f;
string str[20],str1;
int num[20],stotal=0,i=0; f.open("sup.txt") ;
if(!f)
{
cout<<"Unable to open\n";
//return 0;
}
else
{	
f.seekg(0);
while(!f.eof())
{
f>>str[i]>>num[i]; stotal ++;
i++;
}
bubbleSort(str,num,stotal);
for(int i=0;i<stotal;i++) 
cout<<str[i]<<" "<<num[i]<<endl;
}
f.close();
// return 0;
}
void bubbleSort(string str[],int arr[], int n)
{
bool swapped = true;
int j = 0;
int tmp; string str1;
while (swapped) {
swapped = false;
j++;
for (int i = 0; i < n - j; i++) {
if (arr[i] > arr[i + 1]) {
tmp = arr[i];
str1= str[i]; arr[i] = arr[i + 1];
str[i]= str[i+1]; arr[i + 1] = tmp; str[i+1]=str1; swapped = true;
}
}
}
}
