#include <iostream>
using namespace std;

#define MAX_ELEMENT 200      // heap array size

template <typename T>
struct Node {
private:
    int key;
    T data;
public:
    Node() {
        key = 0;
    }
    Node(int _key, T _data) {
        key = _key;
        data = _data;
    }
    ~Node() {}

    // getter/setter
    int getKey() {
        return key;
    }
    void setKey(int _key) {
        key = _key;
    }
    T getData() {
        return data;
    }
    void setData(T _data) {
        data = _data;
    }
};

template <typename T>
class MaxHeap {
private:
    Node<T> node[MAX_ELEMENT];
    int size;   // heap ��� ����
public:
    MaxHeap() {
        size = 0;
    }
    ~MaxHeap() {}

    // search node
    Node<T>& getParent(int index) {
        return node[index / 2];
    }
    Node<T>& getLeftChild(int index) {
        return node[index * 2];
    }
    Node<T>& getRightChild(int index) {
        return node[index * 2 + 1];
    }

    // ����
    void insert(int key, T data) {
        if (isFull()) {
            cout << "Heap is Full" << endl;
            return;
        }

        int index = ++size;     // ��Ʈ�� ������ ����� ���� ��ġ���� ����

        // ��Ʈ���� �Ž��� �ö󰡸� �θ� ���� ��
        while (index != 1 && key > getParent(index).getKey()) {
            node[index] = getParent(index);
            index /= 2;
        }

        // ���� ��ġ�� ������ ����
        node[index].setKey(key);
        node[index].setData(data);
    }

    // ����
    T remove() {
        if (isEmpty()) {
            cout << "Heap is Empty" << endl;
            exit(EXIT_FAILURE);
        }

        Node<T> itemNode = node[1];         // root node (���� ���)
        Node<T> lastNode = node[size--];    // ��Ʈ���� ������ ���
        int index = 1;                      // ������ ����� index (root ���� ����)

        // root ���� �������� �ڽ� ���� ��
        while (index <= size) {
            if (index * 2 > size) {             // leaf node�� ��� (�ڽ� ��尡 ���� ���)
                break;
            }
            else if (index * 2 == size) {      // �ڽĳ�尡 �ϳ��� ���
                if (lastNode.getKey() < getLeftChild(index).getKey()) {
                    node[index] = getLeftChild(index);
                    index *= 2;
                }
                else {
                    break;
                }
            }
            else {                          // �ڽĳ�尡 �ΰ��� ���
                int leftChildKey = getLeftChild(index).getKey();
                int rightChildKey = getRightChild(index).getKey();

                // �� �� key�� �� ū �ڽĳ��� ��ȯ
                if (lastNode.getKey() < leftChildKey || lastNode.getKey() < rightChildKey) {
                    node[index] = leftChildKey > rightChildKey ? getLeftChild(index) : getRightChild(index);
                    index = leftChildKey > rightChildKey ? index * 2 : index * 2 + 1;
                }
                else {
                    break;
                }
            }
        }
        node[index] = lastNode;     // ������ ��带 ���� ��ġ�� ����
        return itemNode.getData();  // ���� ����� data ��ȯ
    }

    // ���
    void display() {
        int level = 1;
        for (int i = 1; i <= size; i++) {
            if (i == level) {
                cout << endl;
                level *= 2;
            }
            cout << node[i].getData() << "(" << node[i].getKey() << ")  ";
        }
        cout << '\n' << "-------------------------" << endl;
    }

    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == MAX_ELEMENT - 1;
    }

};

int main() {
    MaxHeap<int> priorityQueue;

    // ����
    priorityQueue.insert(10, 10);
    priorityQueue.insert(5, 5);
    priorityQueue.insert(30, 30);
    priorityQueue.insert(8, 8);
    priorityQueue.insert(9, 9);
    priorityQueue.insert(3, 3);
    priorityQueue.insert(7, 7);
    priorityQueue.display();

    // ����
    priorityQueue.remove();
    priorityQueue.display();
    priorityQueue.remove();
    priorityQueue.display();

    return 0;
}