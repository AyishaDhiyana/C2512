TASK 1 :

ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ mkdir cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ cd cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ touch first_program
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ nano first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ g++ first_program.cpp -o first_program
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ./first_program
Hello World!
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ cat first_program.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

int main()
{
	cout << "Hello World!" << endl;

	return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ rm first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ls
a.out  first_program
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ rm first_program
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ls
a.out
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ rm a.out
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ls
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ cd ..
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ ls
cmd.txt  cpp_project  Documents  helloworld       Music     project  snap       Videos
cpp      Desktop      Downloads  hello_world.cpp  Pictures  Public   Templates
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ rmdir cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ ls
cmd.txt  Desktop    Downloads   hello_world.cpp  Pictures  Public  Templates
cpp      Documents  helloworld  Music            project   snap    Videos
