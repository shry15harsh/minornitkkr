#ifndef CLUSTER_H
#define CLUSTER_H

#include "master.h"

class cluster{
    public :
    vector<message> c_messages;
    int id;
    // CONSTRUCTOR
    cluster(){}
    cluster(int id)
    {
        this->id=id;
    }
    int getSize()
    {
        return c_messages.size();
    }

    //INSERT Message
    void insertMessage(message m)
    {
      //  cout<<"Message Inserted\n";
      //  m.show();
       c_messages.push_back(m);
    }

    message getMessage(int i)
    {
     /*   try {
            if(i>c_messages.size()-1)
                  throw 2;

        }catch(...) {
            cout << "hehe" ;
        }
        cout << "escape from exception" ;*/
        return c_messages[i];

        //cout<<"Returning Msg : "<<i<<endl;
    }
};


#endif // CLUSTER_H
