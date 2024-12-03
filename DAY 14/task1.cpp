TASK 1 :
------------------------------------------------------------------
C++ Program Management in Linux

`Objective`:  
Familiarize yourself with basic Linux commands 
by creating, compiling, and managing 
a simple C++ program within a project directory.

---

`Tasks`:
--------------------------------------------------------------------------
1. Create a directory called `cpp_project` 
to store your C++ programs.

 mkdir cpp_project
--------------------------------------------------------------------------	
2. Navigate into the `cpp_project` directory.

 cd cpp_project
--------------------------------------------------------------------------	
3. Create a C++ file named `first_program.cpp` 
in the directory.

 touch first_program.cpp
---------------------------------------------------------------------------	
4. Write a simple C++ program inside `first_program.cpp` 
that prints "Hello, World!" to the console.

 nano first_program.cpp
 - Ctrl + X 
 - Y
 - Enter
---------------------------------------------------------------------------
5. Compile the C++ program into an executable.

 g++ first_program.cpp
---------------------------------------------------------------------------	
6. Run the compiled executable to check the output.

 ./a.out
Hello World
---------------------------------------------------------------------------	
7. View the contents of `first_program.cpp` 
using a Linux command.

cat first_program.cpp
	
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

int main()
{
	cout << "Hello World" << endl;

	return EXIT_SUCCESS;
}
---------------------------------------------------------------------------	
8. Remove the `first_program.cpp` file after testing it.

 rm first_program.cpp
- ls
---------------------------------------------------------------------------
9. Check if the directory `cpp_project` is empty and 
then remove it if it is.

 cd ..
- ls
 rmdir cpp_project
- ls

---------------------------------------------------------------------------
Goals : 
	By completing these tasks, 
        you will practice using Linux commands related to file and 
        directory management, 
        text editing, 
        compiling, and 
        running C++ programs.
---------------------------------------------------------------------------
	
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ mkdir cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ cd cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ touch first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ nano first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ g++ first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ./a.out
Hello World
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ cat first_program.cpp
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

int main()
{
	cout << "Hello World" << endl;

	return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ rm first_program.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ ls
a.out
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/cpp_project$ cd ..
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ ls
a.out    cpp          Desktop    Downloads   hello_world.cpp  Pictures  snap       Videos
cmd.txt  cpp_project  Documents  helloworld  Music            Public    Templates
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ rmdir cpp_project
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ ls
a.out    cpp      Documents  helloworld       Music     project  snap       Videos
cmd.txt  Desktop  Downloads  hello_world.cpp  Pictures  Public   Templates
