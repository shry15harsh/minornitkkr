#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "master.h"

class classfifer{
public:
    DIR *dp;
    struct dirent *dirp;
    struct stat filestat;
    void readAndClassify(cluster *c1,string &dir,rtRatio rtR)
    {
        cout<<"CLassifying \n";
        dp = opendir( dir.c_str() );
         if (dp == NULL)
           {
           cout << "Error(" << errno << ") opening " << dir << endl;
           return ;
           }

         while ((dirp = readdir( dp )))
           {
           string filepath = dir + "/" + dirp->d_name;

           // If the file is a directory (or is in some way invalid) we'll skip it
           if (stat( filepath.c_str(), &filestat )) continue;
           if (S_ISDIR( filestat.st_mode ))         continue;
           //cout<<filepath<<endl;
           // Endeavor to read a single number from the file and display it
           message msg(filepath);
           time_t t_p = time(NULL);
           cout<<"rtR :  "<<rtR.computeRt(*c1,msg)<<" ";
           time_t t_c = time(NULL);
           cout<<"Time Taken : "<<t_c - t_p <<" secs "<<endl;
           }

         closedir( dp );
    }

};

#endif // CLASSIFIER_H
