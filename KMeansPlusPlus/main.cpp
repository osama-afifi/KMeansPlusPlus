#include<iostream>

#include "KmeansPP.h"

using namespace std;

typedef std::vector<double> datapoint;

void normalizeData(const vector<datapoint> &data , vector<datapoint> &normalized_data)
{


}


int main()
{
	// Data Generation for testing the K-Means PlusPlus
	vector<datapoint> data(5,vector<double>(2));
	data[0][0]= 1;data[0][1]= 1;
	data[1][0]= 2;data[1][1]= 2;
	data[2][0]= 3;data[2][1]= 3;
	data[3][0]= 4;data[3][1]= 4;
	data[4][0]= 5;data[4][1]= 5;

	// For Regularization
	vector<datapoint> normalized_data;
	//normalizeData(data,normalized_data);

	// Sample K-Means Plus Plus Run
	int K=3;
	KmeansPP KMPP(data);	
	vector<vector<int> > clusters_ = KMPP.getKmeansPP(3);

	// Print Results
	for(int i = 0 ; i<clusters_.size() ; i++)
	{
		cout << "Cluster " << i << ": ";
		for(int j = 0 ; j<clusters_[i].size() ; j++)
			cout << clusters_[i][j] << " ";
		cout << "\n";
	}

	return 0;
}