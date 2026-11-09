#include <Core/Core.h>
#include <GraphLib/GraphLib.h>

using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_FILE);
	Cout() << "========================================\n";
	Cout() << "Running ShaderCheck Unit & Lifecycle Tests\n";
	Cout() << "========================================\n\n";

	// 1. Test GraphLib Graph, Nodes, and Edges
	Cout() << "[1] Testing GraphLib Graph data structures...\n";
	GraphLib::Graph g;
	GraphLib::Node& n1 = g.AddNode("node_1");
	GraphLib::Node& n2 = g.AddNode("node_2");
	GraphLib::Node& n3 = g.AddNode("node_3");

	ASSERT(g.GetNodeCount() == 3);
	ASSERT(&g.GetNode(0) == &n1);
	Cout() << "PASS: GraphLib Nodes created and indexed\n";

	GraphLib::Edge& e1 = g.AddEdge("node_1", "node_2", 2.5);
	GraphLib::Edge& e2 = g.AddEdge("node_2", "node_3", 1.5);
	ASSERT(g.GetEdgeCount() == 2);
	ASSERT(e1.GetWeight() == 2.5);
	ASSERT(e2.GetWeight() == 1.5);
	Cout() << "PASS: GraphLib Edges created with weights\n";

	// 2. Test Dijkstra shortest path
	Cout() << "\n[2] Testing GraphLib Dijkstra shortest path...\n";
	GraphLib::Dijkstra(g, n1);
	ASSERT(n2.distance == 2.5);
	ASSERT(n3.distance == 4.0);
	Cout() << "PASS: Dijkstra shortest path verified\n";

	Cout() << "\n========================================\n";
	Cout() << "ALL ShaderCheck TESTS PASSED SUCCESSFULLY!\n";
	Cout() << "========================================\n";
}
