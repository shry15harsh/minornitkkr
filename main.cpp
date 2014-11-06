#include "master.h"

using namespace std;

int main()
{
   // freopen("out.txt","w",stdout);
    cluster ham(0),spam(1);

    // DIRECTORY HAM
    string hamDir = "/root/Minor_Project/EmailProject/Datasets/PreProcessed/enron1/ham";
    // DIRECTORY SPAM
    string spamDir = "/root/Minor_Project/EmailProject/Datasets/PreProcessed/enron1/spam";

    cout<<"Starting\n";
    messageReader mReader;
    // CREATING INITIAL CLUSTERS FOR HAM AND SPAM
    mReader.createCluster(&ham,hamDir);
    mReader.createCluster(&spam,spamDir);
    // ASSUMING LIVE MAILS STORED IN liveDir DIRECTORY
    string liveDir="/root/Minor_Project/EmailProject/Datasets/PreProcessed/enron2/ham";
    // clusters CARRY REFERENCES TO existing cluster
    vector<cluster *> clusters;
    clusters.push_back(&ham);
    clusters.push_back(&spam);
    //Prepaing rRatio, Needed By CLASSIFIER
    rtRatio rtR(clusters);
    //PREPARING CLASSIFIER
    classfifer cls;
    cls.readAndClassify(&spam,liveDir,rtR);

    return 0;
}
