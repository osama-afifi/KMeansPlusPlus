#include "KmeansPP.h"

using namespace std;

KmeansPP::KmeansPP(const std::vector<datapoint> &input_data) 
	: input_data(input_data), random_index_gen(0, input_data.size()), random_real_gen(0, 1), random_engine(rd())
{}

KmeansPP::~KmeansPP(void)
{}

vector<vector<int> > KmeansPP::getKmeansPP(int K)
{
	vector<vector<int> > clusters_vec; 
	initial_centroids_.push_back(input_data[random_index_gen(random_engine)]);
	/*	Adding the rest of the points according to the probability D(x)/SIGMA(D(x))
	where D(x) is the distance between a datapoint x and it's nearest cluster */
	for(int i=1 ; i<K ; i++)
	{
		updateNearestClusters(initial_centroids_);
		initial_centroids_.push_back(input_data[getNextInitialCentroidIndex()]);
	}
	// Continue as regular K-means
	vector<datapoint> cur_centroids_ = initial_centroids_;
	vector<datapoint> prev_centroids_;
	do
	{
		prev_centroids_ = cur_centroids_;
		updateNearestClusters(cur_centroids_);
		updateCentroids();
	}
	while(!hasChanged(cur_centroids_,prev_centroids_));
	return clusters_vec;
}


int KmeansPP::getNextInitialCentroidIndex()
{
	int rand_num = random_real_gen(random_engine);
	for (int i = 0; i < cumm_prob.size() ; ++i)
		if (rand_num < cumm_prob[i])
			return i;
	return cumm_prob.size()- 1;
}

void KmeansPP::updateNearestClusters(const vector<datapoint> &centroids_)
{
	for (int i = 0; i < input_data.size() ; ++i)
	{
		int idx = getClosestCentroidIndex(i, centroids_);
		nearest_cluster_idx[i] = idx;
		nearest_cluster_dist[i] = distance(centroids_[idx],input_data[i]);
	}
}

void KmeansPP::updateCentroids()
{

}

int KmeansPP::getClosestCentroidIndex(int data_point_idx, const std::vector<datapoint> &centroids_)
{
	return -1;
}

double KmeansPP::distance(const datapoint &a , const datapoint &b)
{
	return -1;
}

bool KmeansPP::hasChanged(const vector<datapoint> &a , const vector<datapoint> &b)
{
	return false;
}


void KmeansPP::init()
{

}

