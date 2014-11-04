#include<bits/stdc++.h>
#include<dirent.h>
#include "mysql/mysql.h"
#include "mysql_connection.h"

#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(){
    map<string,long long> freqs;
    DIR *dir;
    struct dirent *ent;
    vector <char *> files;
    if ((dir = opendir ("/home/harsh/Downloads/enron1/ham/")) != NULL) {
    /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            char *name, *file_path = "/home/harsh/Downloads/enron1/ham/", *file_name = ent->d_name;
            char *buffer = (char*)malloc (strlen(file_path)  + strlen(file_name) + 2);
            strcpy (buffer, file_path);
            strcat (buffer, file_name);

            files.push_back(buffer);

        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
    for(int i=0;i<files.size();++i){
        //const char name[] = files[i];
//        cout<<name<<endl;
        freopen("/home/harsh/Downloads/enron1/ham/5166.2002-01-09.farmer.ham.txt","r",stdin);
        string s;
        while(cin>>s)
        {
           cout<<s<<" ";
           freqs[s]++;
        }
    }
    /*freopen(buffer,"r",stdin);
            string s;
            while(cin>>s)
            {
                cout<<s<<" ";
                freqs[s]++;
            }*/
    /*sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "hadujee2012");

    stmt = con->createStatement();
    stmt->execute("USE minor");
    stmt->execute("INSERT INTO ham_freq VALUES ('harsh' , 1)");

    delete stmt;
    delete con;*/

    freopen("/home/harsh/Downloads/enron1/ham/result.txt","w",stdout);
    map<string,long long> :: iterator i;
    for( i = freqs.begin();i!=freqs.end();++i)
    {
        string s = i->first;
        int f = i->second;
        cout<<s<<" "<<f<<endl;
    }
}
