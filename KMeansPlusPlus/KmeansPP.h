#pragma once

#include<vector>
#include <random>
#include <iostream>

class KmeansPP
{	
public:

	typedef std::vector<double> datapoint;

	/*	Takes the input data where each data point is in a vector<double> format */
	KmeansPP(const std::vector<datapoint> &input_data);
	
	~KmeansPP(void);

	/*	Run the K-Means++ (Plus Plus) Algorithm
		Takes the number of desired clusters K
		Returns a vector for each cluster which includes the indices of their corresponding data points	*/
	std::vector<std::vector<int> > getKmeansPP(int K);
	
private:
	
	//Store the input data for many future runs without reinitializing
	std::vector<datapoint> input_data;

	std::vector<int> nearest_cluster_idx;
	std::vector<double> nearest_cluster_dist;
	std::vector<double> cumm_prob;
	std::vector<datapoint>initial_centroids_;

	// Random Number seed devices/engines/distributions
	//mt19937 mt;
    std::random_device rd;
	std::default_random_engine random_engine;
	std::uniform_int_distribution<int> random_index_gen;
	std::uniform_real_distribution<double> random_real_gen;

	void init();
	void updateNearestClusters(const std::vector<datapoint> &centroids_);
	void updateCentroids();
	int getNextInitialCentroidIndex();
	bool hasChanged(const std::vector<datapoint> &a , const std::vector<datapoint> &b);
	double distance(const datapoint &a , const datapoint &b);
	int getClosestCentroidIndex(int data_point_idx, const std::vector<datapoint> &centroids_);
	datapoint getMeanCentroid(const std::vector<datapoint> &centroids_);

};

