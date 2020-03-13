// #include "ft_ls.h"

// This is the lsd function, yet another C implement of the classic ls, using UNIX functions

// Featuring "stat", "opendir", and "readdir"
// Credits: Jalil Benayachi, ECE PARIS - under MIT license
// contact [at] thejals.com

// Also thanks to some contributors on Stackoverflow

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

//THIS BELOW IS -l
// int main(int argc, char *argv[]) {
//     //Defining the different components of the program
//     //The directory: it's the folder we're browsing (we'll use an argument (argv) in order to identify it)
//     (void)argc;
//     // struct dirent *de;
//     DIR *directory;
//     //The file: when a file is found in the directory readdir loop, it's going to be called this way.
//     struct dirent *thefile;
//     //The stat: It's how we'll retrieve the stats associated to the file.
//     struct stat thestat;
//     //will be used to determine the file owner & group
//     struct passwd *tf;
//     struct group *gf;

//     //Creating a placeholder for the string.
//     //We create this so later it can be properly adressed.
//     //It's reasonnable here to consider a 512 maximum lenght, as we're just going to use it to display a path to a file,
//     //but we could have used a strlen/malloc combo and declared a simple buf[] at this moment
//     char buf[512];

//     //It's time to assign thedirectory to the argument: this way the user will be able to browse any folder simply by mentionning it
//     //when launching the lsd program.
//     directory = opendir(".");

//     //If a file is found (readdir returns a NOT NULL value), the loop starts/keep going until it has listed all of them.
//     while ((thefile = readdir(directory)) != NULL) {
//         //We sprint "thedirectory/thefile" which defines the path to our file
//         printf(buf, " %s/%s", argv[1], thefile->d_name);
//         //Then we use stat function in order to retrieve information about the file
//         stat(thefile->d_name, &thestat);

//         //Now, we can print a few things !
//         // Here's the right order
//         // [file type] [permissions] [number of hard links] [owner] [group] [size in bytes] [time of last modification] [filename]

//         // [file type]
//         //Let's start with the file type
//         //The stat manual is pretty complete and gives details about st_mode and S_IFMT: http://manpagesfr.free.fr/man/man2/stat.2.html
//         //
//         switch (thestat.st_mode & S_IFMT) {
//             case S_IFBLK:
//                 printf("b");
//                 break;
//             case S_IFCHR:
//                 printf("c");
//                 break;
//             case S_IFDIR:
//                 printf("d");
//                 break;  //It's a (sub)directory
//             case S_IFIFO:
//                 printf("p");
//                 break;  //fifo
//             case S_IFLNK:
//                 printf("l");
//                 break;  //Sym link
//             case S_IFSOCK:
//                 printf("s");
//                 break;
//             //Filetype isn't identified
//             default:
//                 printf("-");
//                 break;
//         }
//         //[permissions]
//         //Same for the permissions, we have to test the different rights
//         //READ http://linux.die.net/man/2/chmod
//         printf((thestat.st_mode & S_IRUSR) ? "r" : "-");
//         printf((thestat.st_mode & S_IWUSR) ? "w" : "-");
//         printf((thestat.st_mode & S_IXUSR) ? "x" : "-");
//         printf((thestat.st_mode & S_IRGRP) ? "r" : "-");
//         printf((thestat.st_mode & S_IWGRP) ? "w" : "-");
//         printf((thestat.st_mode & S_IXGRP) ? "x" : "-");
//         printf((thestat.st_mode & S_IROTH) ? "r" : "-");
//         printf((thestat.st_mode & S_IWOTH) ? "w" : "-");
//         printf((thestat.st_mode & S_IXOTH) ? "x" : "-");

//         // [number of hard links]
//         // Quoting: http://www.gnu.org/software/libc/manual/html_node/Attribute-Meanings.html
//         // "This count keeps track of how many directories have entries for this file.
//         // If the count is ever decremented to zero, then the file itself is discarded as soon as no process still holds it open."
//         printf("   %d", thestat.st_nlink);

//         //[owner]
//         // http://linux.die.net/man/3/getpwuid
//         tf = getpwuid(thestat.st_uid);
//         printf("\t%s", tf->pw_name);

//         //[group]
//         // http://linux.die.net/man/3/getgrgid
//         gf = getgrgid(thestat.st_gid);
//         printf("  %s", gf->gr_name);

//         //And the easy-cheesy part
//         //[size in bytes] [time of last modification] [filename]
//         printf("  %lld", thestat.st_size);
//         printf("  %s", thefile->d_name);
//         printf("\t%s", ctime(&thestat.st_mtime));
//     }
//     closedir(directory);
// }

//THIS BELOW IS -a
// int main(int argc, char *argv[]) {
//     (void)argc;
//     DIR *mydir;
//     struct dirent *myfile;
//     struct stat mystat;

//     char buf[512];
//     mydir = opendir(".");
//     while ((myfile = readdir(mydir)) != NULL) {
//         sprintf(buf, "%s/%s", argv[1], myfile->d_name);
//         stat(myfile->d_name, &mystat);
//         // printf("%lld", mystat.st_size);
//         printf("%s\n", myfile->d_name);
//     }
//     closedir(mydir);
// }

THIS BELOW IS - t int main(void) {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");  //set path to directory
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            //exclude "." and ".."
            if (strcmp(dir->d_name, ".") == 0 ||
                strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            printf("%s\n", dir->d_name);
            // getFileCreationTime(dir->d_name);
        }
        closedir(d);
    }
    return (0);
}