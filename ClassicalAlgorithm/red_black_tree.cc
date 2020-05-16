#include <string>

using namespace std;

using Key = int;
using Value = std::string;

/*
红黑树定义:
	0.每个节点非红即黑
	1.根节点为黑色
	2.叶子节点为黑色
	3.双红不连
	4.任一节点到底部，黑高相等
*/
struct RedBlackTree
{
	RedBlackTree()
	  : root_(NULL)
	{}

	void insert(Key key, Value val) {
		root_ = put(root_, key, val);
		root_->color = BLACK; // 这里一定要放后面
	}

private:
	static const bool RED 	= true;
	static const bool BLACK = false;

	struct Node {
		Key key;
		Value val;
		int N; // 总节点数
		bool color;
		Node *left, *right;
		Node(Key key, Value val, int N, bool color)
		  : key(key), val(val), N(N), color(color), left(NULL), right(NULL)
		{}
	};
	Node *root_;

	static bool isRed(Node *x) {
		return x != NULL && x->color == RED;
	}

	static int size(Node *x) {
		if (x == NULL) return 0;
		return x->N;
	}

	// 左旋的时候，h的右节点必是红色
	static Node *rotateLeft(Node *h) {
		auto x = h->right;
		h->right = x->left;
		x->left = h;
		x->color = h->color;
		h->color = RED;
		x->N = h->N;
		h->N = 1 + size(h->left) + size(h->right);
		return x;
	}

	// 右旋的时候，h的左节点必是红色
	static Node *rotateRight(Node *h) {
		auto x = h->left;
		h->left = x->right;
		x->right = h;
		x->color = h->color;
		h->color = RED;
		x->N = h->N;
		h->N = 1 + size(h->left) + size(h->right);
		return x;
	}

	static int compare(Key k1, Key k2) {
		if (k1 < k2) return -1;
		if (k1 > k2) return 1;
		return 0;
	}

	static void flipColors(Node *h) {
		h->color = RED;
		h->left->color = BLACK;
		h->right->color = BLACK;
	}

	Node *put(Node *h, Key key, Value val) {
		if (h == NULL) {
			return new Node(key, val, 1, RED);
		}
		// BST的插入逻辑
		int cmp = compare(key, h->key);
		if (cmp < 0) h->left = put(h->left, key, val);
		else if (cmp > 0) h->right = put(h->right, key, val);
		else h->val = val; // 更新val
		// 插入后开始调整结构，顺序不能颠倒
		// 仅右红则左旋
		if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
		// 左双红则右旋
		if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
		// 左右皆红则变色
		if (isRed(h->left) && isRed(h->right)) flipColors(h);
		// 插入完成后更新树的总节点数
		h->N = 1 + size(h->left) + size(h->right);
		return h;
	}
};






































