# a.out : main.o ls.o file.o dir.o
# 	gcc -o a.out main.o ls.o file.o dir.o

# main.o : main.c
# 	gcc -c -o main.o ./source/main.c

# ls.o : ls.c
# 	gcc -c -o ls.o ./source/ls.c

# file.o : file.c
# 	gcc -c -o file.o ./source/file.c

# dir.o : dir.c
# 	gcc -c -o dir.o ./source/dir.c

# clean :
# 	rm *.o a.out

a.out : main.o ls.o file.o dir.o
	gcc -o a.out main.o ls.o file.o dir.o

main.o : main.c
	gcc -c -o main.o main.c

ls.o : ls.c
	gcc -c -o ls.o ls.c

file.o : file.c
	gcc -c -o file.o file.c

dir.o : dir.c
	gcc -c -o dir.o dir.c

clean :
	rm *.o a.out


