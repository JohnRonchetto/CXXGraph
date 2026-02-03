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
/***	 Collaboration: ----------- 				     ***/
/***********************************************************/
/***	 License: MPL v2.0 ***/
/***********************************************************/

#ifndef __CXXGRAPH_BRIDGES_IMPL_H__
#define __CXXGRAPH_BRIDGES_IMPL_H__

#pragma once

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#include "CXXGraph/Graph/Graph_decl.h"


namespace CXXGraph {

// returns list of edges that are bridges in the graph
template <typename T>
const std::vector<std::pair<Node<T>, Node<T>>> Graph<T>::bridges(
    const Node<T> &start) const {



}

} // namespace CXXGraph

#endif // __CXXGRAPH_BRIDGES_IMPL_H__