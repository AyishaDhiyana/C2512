ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_World.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cat Hello_World.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

int main(){
	cout << "Hello World!!!" << endl;
	return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_World.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Hello World!!!
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_Name.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_Name.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter name: Ayisha
Hello Ayisha
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cp Hello_Name.cpp Hello_students^C
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cp Hello_Name.cpp Hello_student.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano_Hello_student.cpp
nano_Hello_student.cpp: command not found
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_student.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cat Hello_student.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main(){
	int id;	
	char name[255];
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter name: ";
	cin >> name;
	cout << "Hello " << name <<" of id " << id << endl;
	return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_student.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter id: 201
Enter name: Ayisha
Hello Ayisha of id 201
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cp Hello_student.cpp Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_student.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cp Hello_student.cpp Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nanp Hello_2students.cpp
Command 'nanp' not found, did you mean:
  command 'nap' from snap nap-snippets (0.1.1)
  command 'nano' from snap nano (7.2+pkg-4057)
  command 'nano' from deb nano (7.2-2ubuntu0.1)
See 'snap info <snapname>' for additional versions.
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cat Hello_2students.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main(){
	int id1, id2;	
	char name1[255], name2[255];
	cout << "Enter first student details: "<<endl;
	cout << "Enter id1: ";
	cin >> id1;
	cout << "Enter name1: ";
	cin >> name1;
	cout << "Enter second student details: " << endl;
	cout << "Enter id2: ";
	cin >> id2;
	cout << "Enter name2: ";
	cin >> name2;
	cout << "Hello " << name1 <<" of id " << id1 << endl;
	cout << "Hello " << name1 <<"of id " << id2 << endl;
	return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details: 
Enter id1: 101
Enter name1: Ayisha
Enter second student details: 
Enter id2: 102
Enter name2: Dhiya
Hello Ayisha of id 101
Hello Ayishaof id 102
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details: 
Enter id1: 101
Enter name1: Ayisha
Enter second student details: 
Enter id2: 102
Enter name2: Dhiyana
Hello Ayisha of id 101
Hello Ayisha of id 102
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details: 
Enter id1: 101
Enter name1: Ayisha
Enter second student details: 
Enter id2: 102
Enter name2: Dhiyana
Hello Ayisha of id 101
Hello Dhiyana of id 102
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cp Hello_2students.cpp Hello_2students_v2.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students_v2.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ nano Hello_2students_v2.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cat Hello_2students_v2.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

void read(int& id, char name[]);
void print(int& id, char name[]);

int main(){
	int id1, id2;
	char name1[255], name2[255];
	cout << "Enter first student details: "<<endl;
	read(id1,name1);
	cout << "Enter second student details: " << endl;
	read(id2, name2);

	print(id1, name1);
	print(id2, name2);

	return EXIT_SUCCESS;
}

void read(int& id, char name[])
{
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter name: ";
	cin >> name;
}
void print(int& id, char name[])
{
	cout << "Hello " << name <<" of id " << id << endl;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students_v2.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details: 
Enter id: 101
Enter name: Ayisha
Enter second student details: 
Enter id: 201
Enter name: Dhiyana
Hello Ayisha of id 101
Hello Dhiyana of id 201

ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ vim Hello_2students_oops.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ cat Hello_2students_oops.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

struct student 
{
	int id;
	char name[255];
};

int main()
{
	student student1;
	student student2;

	cout << "Enter first student details:" << endl;
	cout << "Enter id: " << endl;
	cin >> student1.id;
	cout << "Enter name: " << endl;
	cin >> student1.name;
	
	cout << "Enter second student details: " << endl;
	cout << "Enter id: " << endl;
	cin >> student2.id;
	cout << "Enter name: " << endl;
	cin >> student2.name;

	cout << "Hello" << student1.name << " of id " << student1.id << endl;
        cout << "Hello" << student2.name << " of id " << student2.id << endl;

	return EXIT_SUCCESS;
}
      
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students_oops.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details:
Enter id: 
101
Enter name: 
Ayisha
Enter second student details: 
Enter id: 
102
Enter name: 
Dhiyana 
HelloAyisha of id 101
HelloDhiyana of id 102
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ vim Hello_2students_oops.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ g++ Hello_2students_oops.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ ./a.out
Enter first student details:
Enter id: 1001
Enter name: Ayisha
Enter second student details: 
Enter id: 1002
Enter name: Dhiyana PS
Hello Ayisha of id 1001
Hello Dhiyana of id 1002
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp/Hello_World.cpp$ 


