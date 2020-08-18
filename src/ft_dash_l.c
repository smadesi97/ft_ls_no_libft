#include "../includes/ft_ls.h"

void dash_l(DIR *p_dir, t_ls_flags *fs, char *path)
{
    //Defining the different components of the program
    //The directory: it's the folder we're browsing (we'll use an argument (argv) in order to identify it)
    // struct dirent *de;
    //The file: when a file is found in the directory readdir loop, it's going to be called this way.
    struct dirent *thefile;
    //The stat: It's how we'll retrieve the stats associated to the file.
    struct stat thestat;
    //will be used to determine the file owner & group
    struct passwd *tf;
    struct group *gf;

    //Creating a placeholder for the string.
    //We create this so later it can be properly adressed.
    //It's reasonnable here to consider a 512 maximum lenght, as we're just going to use it to display a path to a file,
    //but we could have used a strlen/malloc combo and declared a simple buf[] at this moment
    char buf[512];

    //It's time to assign thedirectory to the argument: this way the user will be able to browse any folder simply by mentionning it
    //when launching the lsd program.
    p_dir = opendir(path);

    //If a file is found (readdir returns a NOT NULL value), the loop starts/keep going until it has listed all of them.
    while ((thefile = readdir(p_dir)) != NULL)
    {
        if (!ft_strncmp(thefile->d_name, ".", 1))
            continue;
        //We print "the directory/thefile" which defines the path to our file
        ft_printf(buf, " %s/%s", fs->f_l, thefile->d_name);
        //Then we use stat function in order to retrieve information about the file
        stat(thefile->d_name, &thestat);

        //Now, we can print a few things !
        // Here's the right order
        // [file type] [permissions] [number of hard links] [owner] [group] [size in bytes] [time of last modification] [filename]

        // [file type]
        //Let's start with the file type
        //The stat manual is pretty complete and gives details about st_mode and S_IFMT: http://manpagesfr.free.fr/man/man2/stat.2.html
        //
        switch (thestat.st_mode & S_IFMT)
        {
        case S_IFBLK:
            ft_putstr("b");
            break;
        case S_IFCHR:
            ft_putstr("c");
            break;
        case S_IFDIR:
            ft_putstr("d");
            break; //It's a (sub)directory
        case S_IFIFO:
            ft_putstr("p");
            break; //fifo
        case S_IFLNK:
            ft_putstr("l");
            break; //Sym link
        case S_IFSOCK:
            ft_putstr("s");
            break;
        //Filetype isn't identified
        default:
            ft_putstr("-");
            break;
        }
        //[permissions]
        //Same for the permissions, we have to test the different rights
        //READ http://linux.die.net/man/2/chmod
        ft_putstr((thestat.st_mode & S_IRUSR) ? "r" : "-");
        ft_putstr((thestat.st_mode & S_IWUSR) ? "w" : "-");
        ft_putstr((thestat.st_mode & S_IXUSR) ? "x" : "-");
        ft_putstr((thestat.st_mode & S_IRGRP) ? "r" : "-");
        ft_putstr((thestat.st_mode & S_IWGRP) ? "w" : "-");
        ft_putstr((thestat.st_mode & S_IXGRP) ? "x" : "-");
        ft_putstr((thestat.st_mode & S_IROTH) ? "r" : "-");
        ft_putstr((thestat.st_mode & S_IWOTH) ? "w" : "-");
        ft_putstr((thestat.st_mode & S_IXOTH) ? "x" : "-");

        // [number of hard links]
        // Quoting: http://www.gnu.org/software/libc/manual/html_node/Attribute-Meanings.html
        // "This count keeps track of how many directories have entries for this file.
        // If the count is ever decremented to zero, then the file itself is discarded as soon as no process still holds it open."
        ft_printf("   %ld", thestat.st_nlink);

        //[owner]
        // http://linux.die.net/man/3/getpwuid
        tf = getpwuid(thestat.st_uid);
        //printf("\t%s", tf->pw_name);
        ft_putchar('\t');
        ft_putstr(tf->pw_name);

        //[group]
        // http://linux.die.net/man/3/getgrgid
        gf = getgrgid(thestat.st_gid);
        // printf("\t%s", gf->gr_name);
        ft_putchar('\t');
        ft_putstr(gf->gr_name);

        //And the easy-cheesy part
        //[size in bytes] [time of last modification] [filename]
        ft_printf("\t%ld", thestat.st_size);
        // printf("\t%s", thefile->d_name);
        ft_putchar('\t');
        ft_putstr(thefile->d_name);

        // printf("\t%s", ctime(&thestat.st_mtime));
        ft_putchar('\t');
        ft_putstr(ctime(&thestat.st_mtime));
    }
    closedir(p_dir);
}