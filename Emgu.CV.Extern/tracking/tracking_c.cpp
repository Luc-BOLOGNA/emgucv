//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2018 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#include "tracking_c.h"

/*
cv::Tracker* cveTrackerCreate(cv::String* trackerType)
{
   cv::Ptr<cv::Tracker> tracker = cv::Tracker::create(*trackerType);
   tracker.addref(); 
   return tracker.get();
}*/
bool cveTrackerInit(cv::Tracker* tracker, cv::Mat* image, CvRect* boundingBox)
{
   return tracker->init(*image, *boundingBox);
}
bool cveTrackerUpdate(cv::Tracker* tracker, cv::Mat* image, CvRect* boundingBox)
{
   cv::Rect2d box;
   bool result = tracker->update(*image, box);
   *boundingBox = box;
   return result;
}
/*
void cveTrackerRelease(cv::Tracker** tracker)
{
   delete *tracker;
   *tracker = 0;
}
*/

cv::TrackerBoosting* cveTrackerBoostingCreate(int numClassifiers, float samplerOverlap, float samplerSearchFactor, int iterationInit, int featureSetNumFeatures, cv::Tracker** tracker)
{
	cv::TrackerBoosting::Params p;
	p.numClassifiers = numClassifiers;
	p.samplerOverlap = samplerOverlap;
	p.samplerSearchFactor = samplerSearchFactor;
	p.iterationInit = iterationInit;
	p.featureSetNumFeatures = featureSetNumFeatures;
	cv::Ptr<cv::TrackerBoosting> ptr = cv::TrackerBoosting::create(p);
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerBoostingRelease(cv::TrackerBoosting** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::TrackerMedianFlow* cveTrackerMedianFlowCreate(int pointsInGrid, CvSize* winSize, int maxLevel, CvTermCriteria* termCriteria, CvSize* winSizeNCC, double maxMedianLengthOfDisplacementDifference, cv::Tracker** tracker)
{
	cv::TrackerMedianFlow::Params p;
	p.pointsInGrid = pointsInGrid;
	p.winSize = *winSize;
	p.maxLevel = maxLevel;
	p.termCriteria = *termCriteria;
	p.winSizeNCC = *winSizeNCC;
	p.maxMedianLengthOfDisplacementDifference = maxMedianLengthOfDisplacementDifference;

	cv::Ptr<cv::TrackerMedianFlow> ptr = cv::TrackerMedianFlow::create(p);
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerMedianFlowRelease(cv::TrackerMedianFlow** tracker)
{
	delete* tracker;
	*tracker = 0;
}

cv::TrackerMIL* cveTrackerMILCreate(
	float samplerInitInRadius,
	int samplerInitMaxNegNum,
	float samplerSearchWinSize,
	float samplerTrackInRadius,
	int samplerTrackMaxPosNum,
	int samplerTrackMaxNegNum,
	int featureSetNumFeatures,
	cv::Tracker** tracker)
{
	cv::TrackerMIL::Params p;
	p.samplerInitInRadius = samplerInitInRadius;
	p.samplerInitMaxNegNum = samplerInitMaxNegNum;
	p.samplerSearchWinSize = samplerSearchWinSize;
	p.samplerTrackInRadius = samplerTrackInRadius;
	p.samplerTrackMaxPosNum = samplerTrackMaxPosNum;
	p.samplerTrackMaxNegNum = samplerTrackMaxNegNum;
	p.featureSetNumFeatures = featureSetNumFeatures;
	
	cv::Ptr<cv::TrackerMIL> ptr = cv::TrackerMIL::create(p);
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerMILRelease(cv::TrackerMIL** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::TrackerTLD* cveTrackerTLDCreate(cv::Tracker** tracker)
{
	cv::Ptr<cv::TrackerTLD> ptr = cv::TrackerTLD::create();
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerTLDRelease(cv::TrackerTLD** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::TrackerKCF* cveTrackerKCFCreate(
	float detect_thresh,
	float sigma,
	float lambda,
	float interp_factor,
	float output_sigma_factor,
	float pca_learning_rate,
	bool resize,
	bool split_coeff,
	bool wrap_kernel,
	bool compress_feature,
	int max_patch_size,
	int compressed_size,
	int desc_pca,
	int desc_npca,
	cv::Tracker** tracker)
{
	cv::TrackerKCF::Params p;
	p.detect_thresh = detect_thresh;
	p.sigma = sigma;
	p.lambda = lambda;
	p.interp_factor = interp_factor;
	p.output_sigma_factor = output_sigma_factor;
	p.pca_learning_rate = pca_learning_rate;
	p.resize = resize;
	p.split_coeff = split_coeff;
	p.wrap_kernel = wrap_kernel;
	p.compress_feature = compress_feature;
	p.max_patch_size = max_patch_size;
	p.compressed_size = compressed_size;
	p.desc_pca = desc_pca;
	p.desc_npca = desc_npca;

	cv::Ptr<cv::TrackerKCF> ptr = cv::TrackerKCF::create(p);
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerKCFRelease(cv::TrackerKCF** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::TrackerGOTURN* cveTrackerGOTURNCreate(cv::Tracker** tracker)
{
	cv::Ptr<cv::TrackerGOTURN> ptr = cv::TrackerGOTURN::create();
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerGOTURNRelease(cv::TrackerGOTURN** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::TrackerMOSSE* cveTrackerMOSSECreate(cv::Tracker** tracker)
{
	cv::Ptr<cv::TrackerMOSSE> ptr = cv::TrackerMOSSE::create();
	ptr.addref();
	*tracker = dynamic_cast<cv::Tracker*>(ptr.get());
	return ptr.get();
}
void cveTrackerMOSSERelease(cv::TrackerMOSSE** tracker)
{
	delete *tracker;
	*tracker = 0;
}

cv::MultiTracker* cveMultiTrackerCreate()
{
   return new cv::MultiTracker();
}
bool cveMultiTrackerAdd(cv::MultiTracker* multiTracker, cv::Tracker* tracker, cv::Mat* image, CvRect* boundingBox)
{
   return multiTracker->add(tracker, *image, *boundingBox);
}

bool cveMultiTrackerUpdate(cv::MultiTracker* tracker, cv::Mat* image, std::vector<CvRect>* boundingBox)
{
   std::vector<cv::Rect2d> bb;
   bool result = tracker->update(*image, bb);
   boundingBox->clear();
   for (std::vector<cv::Rect2d>::iterator it = bb.begin(); it != bb.end(); ++it)
   {
      boundingBox->push_back(*it);
   }
   return result;
}
void cveMultiTrackerRelease(cv::MultiTracker** tracker)
{
   delete* tracker;
   *tracker = 0;
}