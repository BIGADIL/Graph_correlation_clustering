#pragma once

#include "../graphs/IGraph.hpp"
#include "../common/ClusteringLabels.hpp"

/**
 * Base interface of clustering.
 */
class IClustering {
 public:
  /**
   * Setup label for specific vertex.
   *
   * @param vertex for which vertex we setup label.
   * @param label label for setup.
   */
  virtual void SetupLabelForVertex(const unsigned vertex,
                                   const ClusterLabels label) = 0;
  /**
   * Compute distance to specific graph.
   *
   * @param graph source graph.
   * @return distance to specific graph.
   */
  virtual unsigned GetDistanceToGraph(const IGraph &graph) const = 0;
  /**
   * Get copy of this clustering.
   *
   * @return copy of this clustering.
   */
  virtual std::shared_ptr<IClustering> GetCopy() const = 0;
  /**
   * Get label of specific vertex.
   *
   * @param vertex source vertex for which we find out label.
   * @return label of specific vertex.
   */
  virtual ClusterLabels GetLabel(const unsigned vertex) const = 0;
  /**
   * Find out if specific vertex is clustered.
   *
   * @param vertex source vertex for which we find out if it's clustered.
   * @return @code true, if vertex is non-clustered.
   */
  virtual bool IsNonClustered(const unsigned vertex) const = 0;
  /**
   * Find out if two vertices is same clustered.
   *
   * @param i first vertex.
   * @param j second vertex.
   * @return @code true, if two vertices is same clustered.
   */
  virtual bool IsSameClustered(const unsigned i,
                               const unsigned j) const = 0;
  /**
   * Calculate number of non-clustered vertices.
   *
   * @return number of non-clustered vertices.
   */
  virtual unsigned GetNumNonClusteredVertices() const = 0;
  /**
   * Calculate number of vertices of specific label.
   *
   * @param label source label.
   * @return number of vertices of specific label.
   */
  virtual unsigned GetNumVerticesByLabel(const ClusterLabels label) const = 0;
  /**
   * Sent object to json-string.
   * @return json-string.
   */
  virtual std::string ToJson() const = 0;
};

using IClustPtr = std::shared_ptr<IClustering>;
