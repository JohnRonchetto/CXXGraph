/***********************************************************/
/***      ______  ____  ______                 _         ***/
/***     / ___\ \/ /\ \/ / ___|_ __ __ _ _ __ | |__	     ***/
/***    | |    \  /  \  / |  _| '__/ _` | '_ \| '_ \	 ***/
/***    | |___ /  \  /  \ |_| | | | (_| | |_) | | | |    ***/
/***     \____/_/\_\/_/\_\____|_|  \__,_| .__/|_| |_|    ***/
/***                                    |_|			     ***/
/***********************************************************/
/***     Header-Only C++ Library for Graph			     ***/
/***	 Representation and Algorithms				     ***/
/***********************************************************/
/***     Author: ZigRazor ***/
/***	 E-Mail: zigrazor@gmail.com 				     ***/
/***********************************************************/
/***	 Collaboration: John Ronchetto 				     ***/
/***********************************************************/
/***	 License: MPL v2.0 ***/
/***********************************************************/

// NOT OPTIMIZED SOLUTION
// UNDIRECTED GRAPH ASSUMPTION

#ifndef __CXXGRAPH_BRIDGES_IMPL_H__
#define __CXXGRAPH_BRIDGES_IMPL_H__

#pragma once

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#include "CXXGraph/Graph/Graph_decl.h"


namespace CXXGraph {

// Returns list of edges that are bridges in the graph
template <typename T>
const std::vector<std::pair<Node<T>, Node<T>>> Graph<T>::bridges(
    const Node<T> &start) const {

	std::vector<std::pair<Node<T>, Node<T>>> bridges;

	auto &nodeSet = start.getNodeSet();

	// Check that start node actually exists
	auto startNodeIt = std::find_if(
		nodeSet.begin(), nodeSet.end(),
		[&start](auto &node) {return node->getUserId() == start.getUserId();});
	// If start node not in graph, then return wmpty result
	if (startNodeIt == nodeSet.end())
		return bridges;

	// Helper that runs dfs on node and skips a specific edge (skipU-SkipV)
	std::fucntion<void(const std::shared_ptr<AdjacencyList<T>>,
						shared<const Node<T>>,
						shared<const Node<T>>,
						shared<const Node<T>>,
						std::vector<Node<T>> &)>
		dfs;

	dfs = [&explore](const std::shared_ptr<AdjacencyList<T>> adj,
					shared<const Node<T>> node,
					shared<const Node<T>> skipU,
					shared<const Node<T>> skipV,
					std::vector<Node<T>> &visited) -> void {

		// Mark current node as visited
		visited.push_back(*node);

		// if node has no out edges, then we're done
		if (adj->find(node) == adj->end()) {
			return;
		}

		// Explore all nighbors of current node
		for (const auto &x : adj->at(node)) {
			auto next = x.first;

			// Check whether the current edge (node-next) is
			// the one we want to remove. Check both directions.

			bool edgeRemoved =
				(node->getUserId() == skipU->getUserId() &&
				next->getUserId() == skipV->getUserId() ||
 				(node->getUserId() == skipV->getUserId() &&
 				next->getUserId() == skipU->getUserId());

			// Pretend that edge doesn't exist
			if (edgeRemoved) {
				continue;
			}

			// Standard dfs check using Node<T> value
			if (std::find(visited.begin(), visited.end(), *next) ==
				visited.end()) {
				dfs(adj, next, skipU, skipV, visited);
			}
		}
	};

	//

}

} // namespace CXXGraph

#endif // __CXXGRAPH_BRIDGES_IMPL_H__