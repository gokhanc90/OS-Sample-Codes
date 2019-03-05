# OS-Sample-Codes
## To compile the codes
gcc -o thread thread.c -pthread
gcc -o MutexSimple MutexSimple.c -pthread
gcc -o MutexandWithoutMutex MutexandWithoutMutex.c -pthread
gcc -o pipe pipe.c
gcc -o ProcessCreation ProcessCreation.c
gcc -o SemaphoreSimple SemaphoreSimple.c -pthread
gcc -o SharedMemory_Consumer SharedMemory_Consumer.c -lrt
gcc -o SharedMemory_Producer SharedMemory_Producer.c -lrt
