#pragma once

#include "../../../clustering/BBBinaryClusteringVector.hpp"

class BBAlgorithmFor2SCC {
 private:
  /**
   * The source graph to be clustered.
   */
  IGraphPtr graph_;
  /**
   * Record value.
   * @see ::GetBestClustering
   */
  unsigned record_{0};
  /**
   * Best clustering.
   * @see ::GetBestClustering
   */
  IClustPtr best_clustering_ = nullptr;

 private:
  /**
   * Branch out the range of feasible solutions.
   * @param clustering current vector of labels.
   */
  void Branch(BBBinaryClusteringVector &clustering);

 public:
  explicit BBAlgorithmFor2SCC() = default;
  /**
   * Get optimal solution for source graph.
   * @param graph source graph.
   * @param initial_clustering initial clustering.
   * @return optimal solution for source graph.
   */
  IClustPtr GetBestClustering(const IGraphPtr &graph,
                              const IClustPtr &initial_clustering,
                              unsigned first_cluster_vertex,
                              unsigned second_cluster_vertex);
};



