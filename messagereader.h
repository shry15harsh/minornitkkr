#include "master.h"
#include "rtRatio.h"

class messageReader
{
public:
    string dir, filepath;
    DIR *dp;
    struct dirent *dirp;
    struct stat filestat;
    messageReader(){}
    void createCluster(cluster *c1,string &dir)
    {
        cout<<"Creating Cluster\n";
        dp = opendir( dir.c_str() );
         if (dp == NULL)
           {
           cout << "Error(" << errno << ") opening " << dir << endl;
           return ;
           }

         while ((dirp = readdir( dp )))
           {
           filepath = dir + "/" + dirp->d_name;

           // If the file is a directory (or is in some way invalid) we'll skip it
           if (stat( filepath.c_str(), &filestat )) continue;
           if (S_ISDIR( filestat.st_mode ))         continue;
           //cout<<filepath<<endl;
           // Endeavor to read a single number from the file and display it
           message msg(filepath);
           c1->insertMessage(msg);
           }
         cout<<"Clustering Done\n";
         cout<<c1->getSize()<<" : Messages Clustered !\n\n";
         closedir( dp );
    }
};
