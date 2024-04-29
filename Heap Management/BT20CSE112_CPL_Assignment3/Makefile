CC=g++
C_Flag=-c

all: final.exe
final.exe : Heap_Manager.o driver.o list.o listarray.o allocate.o deallocate.o
	$(CC) list.o listarray.o Heap_Manager.o driver.o allocate.o deallocate.o -o final.exe
list.o : list.cpp
	$(CC) $(C_Flag) list.cpp -o list.o
listarray.o:listarray.cpp
	$(CC) $(C_Flag) listarray.cpp -o listarray.o
driver.o:driver.cpp
	$(CC) $(C_Flag) driver.cpp -o driver.o
Heap_Manager.o:Heap_Manager.cpp
	$(CC) $(C_Flag) Heap_Manager.cpp -o Heap_Manager.o
allocate.o:allocate.cpp
	$(CC) $(C_Flag) allocate.cpp -o allocate.o
deallocate.o:deallocate.cpp
	$(CC) $(C_Flag) deallocate.cpp -o deallocate.o
clean:
	del *.o
	del *.exe