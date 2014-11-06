#ifndef MESSAGE_H
#define MESSAGE_H

#include "master.h"
#include "trie.h"

using namespace std;

class message{
public:
    vector<string> text;
    node *nd;
   // map<string,int> freqs;

    // CONSTRUCTOR
    //public:
    message()
    {
        nd->initialise(&nd,0,0);
    }

    message(string filepath)
    {
        nd->initialise(&nd,0,0);
        ifstream fin;
        fin.open( filepath.c_str() );
        string s;
        while(fin>>s)
        {
            if(s.size()==1)
                continue;
            nd->addWord(*nd,0,s);
            text.push_back(s);
        }
        fin.close();
    }

    void show()
    {
        cout<<"Showing Message : \n";
        for(int i=0;i<text.size();i++)
        {
            cout<<text[i]+" ";
        }
        cout<<endl;
    }

};

#endif // MESSAGE_H
