# CC stands for C compiler and in the make file we can indicate
# the compiler we wish to use using this CC command.
CC = gcc

# The CCFLAGS command can be used for compiler options
# This isn't necessary here but this is simply for illustration.
CCFLAGS = -O3

# The LDFLAGS can be used for linking options

LDFLAGS = -lm

# Now, we specify a target and execute the code. You must tap in this case
# unlike other times in C. Now the above commands can be used to carry
# out the executable.
matmultc: main.o matmult.o
	$(CC) -o matmultc main.o matmult.o $(LDFLAGS)

# Now we generate the dependencies by essentially 'writing the rules'
# for them.
matmult.o: matmult.c
	$(CC) -c $(CCFLAGS) matmult.c

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c


