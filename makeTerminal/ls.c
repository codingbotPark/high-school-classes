#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// 설명 필요

struct aa
{
    char name[512];
};
char type(mode_t mode)
{
    if (S_ISREG(mode))
        return '-';
    if (S_ISDIR(mode))
        return 'd';
}
char *perm(mode_t mode)
{
    static char mystring[10] = "---------";
    // printf("mode = %o\n", mode);
    // printf("S_IREAD = %o\n", S_IREAD);

    strcpy(mystring, "---------");

    // printf("mystring = %s\n", mystring);
    if (mode & (S_IREAD >> 0))
    {

        mystring[0] = 'r';
    }
    if (mode & (S_IWRITE >> 0))
    {
        mystring[1] = 'w';
    }
    if (mode & (S_IEXEC >> 0))
    {
        mystring[2] = 'x';
    }

    if (mode & (S_IREAD >> 3))
    {
        // printf("S_IREAD>>3 = %o\n", S_IREAD >> 3);
        mystring[3] = 'r';
    }

    if (mode & (S_IWRITE >> 3))
    {
        mystring[4] = 'w';
    }
    if (mode & (S_IEXEC >> 3))
    {
        mystring[5] = 'x';
    }
    if (mode & (S_IREAD >> 6))
    {
        // printf("S_IREAD>>6 = %o\n", S_IREAD >> 6);
        mystring[6] = 'r';
    }

    if (mode & (S_IWRITE >> 6))
    {
        // printf("S_IWRITE>>6 = %o\n", S_IWRITE >> 6);
        mystring[7] = 'w';
    }
    if (mode & (S_IEXEC >> 6))
    {
        mystring[8] = 'x';
    }

    return (mystring);
}

void printstat(char *pathname, char *file, struct stat *st)
{
    // printf("pathname = %s ", pathname);
    printf("%c%s", type(st->st_mode), perm(st->st_mode));
    printf(" %ld\t", st->st_blocks);
    printf(" %3ld", st->st_nlink);
    printf(" %s %s", (getpwuid(st->st_uid))->pw_name,
           (getgrgid(st->st_gid))->gr_name);
    printf(" %9ld", st->st_size);
    printf(" %.12s", ctime(&st->st_mtime));
    printf(" %s\n", file);
}

void listFileDir(char current[512]){
	DIR *dp;
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    dp = opendir(current);
    if (dp == NULL){
        perror("wrong dp");
    }

    while((d = readdir(dp)) != NULL){
        sprintf(path, "%s%s", current, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        printstat(path, d->d_name, &st);
    }

}
