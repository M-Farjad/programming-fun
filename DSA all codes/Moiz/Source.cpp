////#include<iostream>
////using namespace std;
////class Heap {
////public:
////	int size, count;
////	int* arr;
////	void Heap_Max(int child) {
////		int parent = (child - 1) / 2;
////		if (arr[child] > arr[parent]) {
////			int temp = arr[child];
////			arr[child] = arr[parent];
////			arr[parent] = temp;
////			Heap_Max(parent);
////		}
////	}
////	void Heap_Min(int root) {
////		int last = count - 1;
////		int leftChild = root * 2 + 1;
////		int rightChild = root * 2 + 2;
////		int bigBrother;
////		if (leftChild <= last) {
////			if (leftChild == last)
////				bigBrother = leftChild;
////			else {
////				if (arr[leftChild] > arr[rightChild])
////					bigBrother = leftChild;
////				else
////					bigBrother = rightChild;
////			}
////
////			if (arr[bigBrother] > arr[root]) {//swap
////				int temp = arr[bigBrother];
////				arr[bigBrother] = arr[root];
////				arr[root] = temp;
////				Heap_Min(bigBrother);
////			}
////		}
////	}
////public:
////	Heap(int size) {
////		this->size = size;
////		arr = new int[size];
////		count = 0;
////	}
////	void BuildHeap(int num) {
////		if (count == size) {
////			cout << "Not Enough Space!";
////		}
////		else {
////			arr[count] = num;
////			if (count > 0)
////				Heap_Max(count);//Heap_Min(count) for minimun heap 
////			count++;
////		}
////	}
////	void simpleheap(int num)
////	{
////		if (count == size)
////		{
////			return;
////		}
////		else {
////			arr[count] = num;
////			count++;
////		}
////	}
////	int removeTop() {
////		if (count == 0) {
////			cout << "Not Enough Space!";
////			return NULL;
////		}
////		else {
////			int top = arr[0];
////			arr[0] = arr[count - 1];
////			arr[0] = arr[count - 1];
////			count--;
////			Heap_Min(0);
////			return top;
////		}
////	}
////	void heapSort()
////	{
////		for (int i = size / 2 - 1; i >= 1; i--)
////			heapify(size, i);
////		for (int i = size - 1; i >= 1; i--)
////		{
////			swap(&array[1], &array[i]);
////			heapify(i, 1);
////		}
////	}
////	void heapify(int last)
////	{
////		if (last == 1)
////		{
////			return;
////		}
////		int parent = (last - 1) / 2;
////		if (arr[parent] < arr[last])
////		{
////			int temp = arr[parent];
////			arr[parent] = arr[last];
////			arr[last] = temp;
////		}
////		heapify(last - 1);
////	}
////	void display() {
////		for (int i = 0; i < count; i++) {
////			cout << arr[i] << " ";
////		}
////	}
////};
////void main()
////{
////	Heap myHeap(15);
////	myHeap.BuildHeap(131);
////	myHeap.BuildHeap(134);
////	myHeap.BuildHeap(103);
////	myHeap.BuildHeap(52);
////	myHeap.BuildHeap(66);
////	myHeap.BuildHeap(7);
////	myHeap.display();
////}
////
//
//
//
//#include <iostream>
//using namespace std;
//class BSTNode
//{
//public:
//    BSTNode();
//    BSTNode(int value);
//    void setLeft(BSTNode* left);
//    void setRight(BSTNode* right);
//    void setParent(BSTNode* parent);
//    BSTNode* getLeft();
//    BSTNode* getRight();
//    BSTNode* getParent();
//    int getInfo();
//    void setInfo(int info);
//
//private:
//    BSTNode* parent;
//    BSTNode* left;
//    BSTNode* right;
//    int info;
//};
//BSTNode::BSTNode()
//{
//    this->info = -1;
//    this->left = this->right = this->parent = NULL;
//}
//BSTNode::BSTNode(int value)
//{
//    this->info = value;
//    this->left = this->right = this->parent = NULL;
//}
//void BSTNode::setLeft(BSTNode* left)
//{
//    this->left = left;
//}
//void BSTNode::setRight(BSTNode* right)
//{
//    this->right = right;
//}
//void BSTNode::setParent(BSTNode* parent)        //a.setleft(B)//B.setparent(a);
//{
//
//    this->parent = parent;
//}
//BSTNode* BSTNode::getLeft()
//{
//
//    return this->left;
//}
//BSTNode* BSTNode::getRight()
//{
//
//    return this->right;
//}
//BSTNode* BSTNode::getParent()
//{
//
//    return this->parent;
//}
//int BSTNode::getInfo()
//{
//
//    return this->info;
//}
//void BSTNode::setInfo(int info)
//{
//
//    this->info = info;
//}
//
//class BST
//{
//public:
//    BSTNode* root;
//    BST();
//    void insert(int value);
//    void preorder(BSTNode* node);
//    void postorder(BSTNode* node);
//    void inorder(BSTNode* node);
//    BSTNode* findMin(BSTNode* Node);
//    BSTNode* findMax(BSTNode* Node);
//    bool search(int value);
//    BSTNode* remove(BSTNode* tree, int info);
//};
//BST::BST()
//{
//    this->root = NULL;
//}
//void BST::insert(int value)
//{
//
//    BSTNode* p = root,
//        * prev = 0;
//    // find a place for inserting new node;
//    while (p != 0 && root != 0)
//    {
//        prev = p;
//        if (value < p->getInfo())
//            p = p->getLeft();
//        else
//            p = p->getRight();
//    }
//
//    if (root == 0) // tree is empty;
//        root = new BSTNode(value);
//    else if (value < prev->getInfo())
//    {
//        BSTNode* temp = new BSTNode(value);
//        temp->setParent(prev);
//        prev->setLeft(temp);
//    }
//    else
//    {
//        BSTNode* temp = new BSTNode(value);
//        temp->setParent(prev);
//        prev->setRight(temp);
//    }
//}
//void BST::preorder(BSTNode* BSTNode)
//{
//    if (BSTNode != NULL)
//    {
//        cout << BSTNode->getInfo() << " ";
//        preorder(BSTNode->getLeft());
//        preorder(BSTNode->getRight());
//    }
//}
//void BST::postorder(BSTNode* BSTNode)
//{
//    if (BSTNode != NULL)
//    {
//        postorder(BSTNode->getLeft());
//        postorder(BSTNode->getRight());
//        cout << BSTNode->getInfo() << " ";
//    }
//}
//void BST::inorder(BSTNode* BSTNode)
//{
//    if (BSTNode != NULL)
//    {
//        inorder(BSTNode->getLeft());
//        cout << BSTNode->getInfo() << " ";
//        inorder(BSTNode->getRight());
//    }
//}
//BSTNode* BST::findMin(BSTNode* Node)
//{
//    if (Node == NULL)
//        return NULL;
//    if (Node->getLeft() == NULL)
//        return Node; // this is it.
//    return findMin(Node->getLeft());
//}
//BSTNode* BST::findMax(BSTNode* Node)
//{
//    if (Node == NULL)
//        return NULL;
//    if (Node->getRight() == NULL)
//        return Node; // this is it.
//    return findMax(Node->getRight());
//}
//bool BST::search(int value)
//{
//    BSTNode* p = root;
//    while (p != 0)
//    {
//        if (value == p->getInfo())
//            return true;
//        else if (value < p->getInfo())
//            p = p->getLeft();
//        else
//            p = p->getRight();
//    }
//    return 0;
//}
//
////            2
////     5            4
//// 55       10           8
////     6         9
////         7 
//
//BSTNode* BST::remove(BSTNode* tree, int info)
//{
//    BSTNode* t;
//    // int cmp = info - tree->getInfo();       
//    if (info < tree->getInfo())
//    {
//        t = remove(tree->getLeft(), info);
//        tree->setLeft(t);
//    }
//    else if (info > tree->getInfo())
//    {
//        t = remove(tree->getRight(), info);
//        tree->setRight(t);
//    }
//
//    // two children, replace with inorder successor
//    else if (tree->getLeft() != NULL && tree->getRight() != NULL)
//    {
//        BSTNode* minNode;
//        minNode = findMin(tree->getRight());
//        tree->setInfo(minNode->getInfo());
//        t = remove(tree->getRight(),
//            minNode->getInfo());
//        tree->setRight(t);
//    }
//    else
//    {
//        BSTNode* nodeToDelete = tree;
//        if (tree->getLeft() == NULL)                //         4
//            tree = tree->getRight();         //     3       8
//        else if (tree->getRight() == NULL)          //   4     6       5
//            tree = tree->getLeft();
//        else
//            tree = NULL;
//
//        delete nodeToDelete;
//    }
//    return tree;
//}
//
////int main()
////{
////
////    BST tree;
////    tree.insert(34);
////    tree.insert(56);
////    tree.insert(0);
////    tree.insert(5);
////    tree.insert(234);
////    cout << endl;
////    tree.preorder(tree.root);
////    cout << "Pre Order" << endl;
////    cout << endl;
////    cout << "Post Order" << endl;
////    tree.postorder(tree.root);
////    cout << endl;
////    cout << "In Order" << endl;
////    tree.inorder(tree.root);
////    cout << endl;
////    cout << "The Min Value of tree is: " << tree.findMin(tree.root)->getInfo() << endl;
////    cout << "Max Value of tree is: " << tree.findMax(tree.root)->getInfo() << endl;
////    cout << "search : " << tree.search(20) << endl;
////    cout << "Traversing tree pre order after Deleting node with value 0 in the tree ";
////    tree.remove(tree.root, 0);
////    tree.preorder(tree.root);
////    return 0;
////}
//
//
//
//
//















#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
void QuickSort(int arr[], int l, int r)
{
    if (1 < r)
    {
        int pi = partition(arr, l, r); // pivot
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}
int main()
{
    int array[] = { 1, 6, 3, 5, 4 };
    QuickSort(array, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}