#include <dirent.h> /* opendir, readdir */
#include <stdio.h>  /* puts */
#include <stdlib.h> /* exit */
#include <sys/stat.h> /* stat */
#include <unistd.h>
#include <string.h>

int main()
{
    DIR *cwd = opendir( "." );

    if ( !cwd )
        perror( "opendir ." ), exit( 1 );

    struct dirent *dirp;

    while ( 1 )
    {
        dirp = readdir( cwd );

        if ( !dirp )
            break;

        struct stat st;
        unsigned long links = 0;
        unsigned long size = 0;

        if ( stat( dirp->d_name, &st ) == 0 )
        {
            links = st.st_nlink;
            if (S_ISREG(st.st_mode))
            {
                size = st.st_size;
            }
        }

        struct stat lst;
        char target[256] = "";
        if (lstat(dirp->d_name, &lst) == 0 && (S_ISLNK(lst.st_mode)))
        {
            readlink(dirp->d_name, target, sizeof (target));
            links = lst.st_nlink;

        }

        char type = 'f';
        if (dirp->d_type == DT_DIR) {
            type = 'd';
        }
        if (dirp->d_type == DT_LNK) {
            type = 'l';
        }

        printf( "%c %lu %lu %lu %s", type, (dirp->d_ino), links, size, dirp->d_name);
        if (strlen(target) > 0)
        printf(" ... %s", target);

        printf("\n");
    }
}