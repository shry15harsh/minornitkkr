#ifndef RTRATIO_H
#define RTRATIO_H

#include "master.h"
#define ulli unsigned long long int

using namespace std;

class rtRatio
{
    vector<cluster *> clusts;
public:
    rtRatio(vector<cluster *> &t)
    {
        clusts.resize(100);
        clusts = t;
    }

    //Calculates the number of already classified messages that contain Xi - fn
    ulli fn(message &m)
    {
        ulli x_fn=0; //the number of already classified messages that contain Xi - fn
        for(int i=0;i<m.text.size();i++)
        {
            for(int k=0;k<clusts.size();k++)
            {
                cluster *clust = clusts[k];
                for(int j=0;j<clust->c_messages.size();j++)
                {
                    message c_m = clust->getMessage(j);
                    string s = m.text[i];
                    if(c_m.nd->getExactMatches(*(c_m.nd),0,s)>0)
                    {
                        x_fn++;
                    //    cout<<"Inc "<<x_fn<<endl;
                        continue;
                    }
                }
            }
          //  cout << "debugging..." ;
        }
       // cout<<"Return "<<endl;
        return x_fn;
    }

    //the number of messages that belong to the cluster Cj,k and do not contain Xi (KXi )
    ulli dn1(cluster &c1,message &m)
    {
        ulli x_dn1=0;
        for(int i=0;i<m.text.size();i++)
        {
            for(int j=0;j<c1.c_messages.size();j++)
            {
                message c_m = c1.getMessage(j);
                string s = m.text[i];
                if(c_m.nd->getExactMatches(*(c_m.nd),0,s) > 0 )
                {
                    continue;
                }
                else
                {
                    x_dn1++;
                }
            }
        }
       return x_dn1;
    }

    // the number of messages that contain the word but are not included in cluster Cj,k as KXi
    ulli dn2(cluster &c1,message &m)
    {
        ulli x_dn2=0;
        for(int i=0;i<m.text.size();i++)
        {
            for(int k=0;k<clusts.size();k++)
            {
                cluster *clust = clusts[k];
                if(c1.id==clust->id)
                    continue;
                for(int j=0;j<clust->c_messages.size();j++)
                {
                    message c_m = clust->getMessage(j);
                    string s = m.text[i];
                    if(c_m.nd->getExactMatches(*(c_m.nd),0,s)>0)
                    {
                        x_dn2++;
                        continue;
                    }
                }
            }
        }
        return x_dn2;
    }
    // DENOMINATOR
    ulli computeDenom(cluster &c1,message &m)
    {
        return dn1(c1,m)*dn2(c1,m);
    }
    // RATIO
    double computeRt(cluster &c1,message &m)
    {
        return ((double)fn(m)*10000)/computeDenom(c1,m);
    }
};

#endif // RTRATIO_H
