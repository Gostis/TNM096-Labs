#include <vector>
#include <queue>
#include <map>

using namespace std;
struct Node
{
	int PuzzleState[9];
	int g; //g sum of actual costs from the start to the current node
	int h; //h estimated cost from the current node to the goal
		   //f is the sum of g + h
	int f_cost;
};

class puzzleNodeComp {
	bool reverse;
public:
	puzzleNodeComp(const bool& revparam = false) {
		reverse = revparam;
	}

	bool operator() (const Node& lhs, const Node& rhs) const {
		if (reverse)
			return (lhs.f_cost > rhs.f_cost);
		else
			return (lhs.f_cost < rhs.f_cost);
	}
};

class EightPuzzle {
public:
	//constructor
	EightPuzzle();
	
	void PuzzleSolver();

	void print();
	//destructor
	//~EightPuzzle();


private:
	int manhattan(Node puzzleNode);
	int manhattanDist(int p1, int p2);
	int findEmpty(Node puzzleNode);

	void moveZero(int from,int to, char dir);
	
	string keyGen(Node puzzleNode);
	
	bool isExpanded(Node puzzleNode);

	bool SameBoard(Node puzzleNode, Node goalNode);

	Node goalState;
	Node *lastExpBranch;

	map<string, Node> expTree;
	typedef priority_queue <Node, vector<Node>, puzzleNodeComp> puzzlePQ;
	puzzlePQ openNodes;

	


};
