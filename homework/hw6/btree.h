#include <iostream>
#include <sstream>
#include <memory>
using namespace std;
// From http://www.cprogramming.com/tutorial/lesson18.html
struct node
{
  int key_value;
  unique_ptr<node> left;
  unique_ptr<node> right;
};

class KeyNotFound : public exception {
    public:
string what () {
        return "Key Not Found";
    }
};

class btree
{
    public:
		btree() {
			root = unique_ptr<node>(nullptr);
		}

        btree (const btree &b) {
            copy(root, b.root);
        };

        btree& operator= (const btree &b) {
            copy(root, b.root);
            return *this;
        }



		void insert(int key) {
			if (root)
				insert(key, root);
			else
			{
				root = make_unique<node>();
				root->key_value = key;
				root->left = unique_ptr<node>(nullptr);
				root->right = unique_ptr<node>(nullptr);
			}
		}
		int search(int key) {
			return search(key, root);
		}

    private:
    	friend ostream &operator<<(ostream &, btree &);

		void insert(int key, unique_ptr<node> &leaf) {
			if (key< leaf->key_value)
			{
				if (leaf->left)
					insert(key, leaf->left);
				else
				{
					leaf->left = make_unique<node>();
					leaf->left->key_value = key;
					leaf->left->left = unique_ptr<node>(nullptr);    //Sets the left child of the child node to null
					leaf->left->right = unique_ptr<node>(nullptr);   //Sets the right child of the child node to null
				}
			}
			else if (key >= leaf->key_value)
			{
				if (leaf->right)
					insert(key, leaf->right);
				else
				{
					leaf->right = make_unique<node>();
					leaf->right->key_value = key;
					leaf->right->left = unique_ptr<node>(nullptr);  //Sets the left child of the child node to null
					leaf->right->right = unique_ptr<node>(nullptr); //Sets the right child of the child node to null
				}
			}
		}
		int search(int key, unique_ptr<node> &leaf) {
			if (leaf)
			{
				if (key == leaf->key_value)
					return leaf->key_value;
				if (key<leaf->key_value)
					return search(key, leaf->left);
				else
					return search(key, leaf->right);
			}

            throw KeyNotFound();
		}

        void print_leaf(unique_ptr<node> &leaf, bool end_line) {
            if (leaf) {
                cout << leaf->key_value << " ";
                if (end_line) {
                    cout << endl;
                }
                print_leaf(leaf->left, false);
                print_leaf(leaf->right, end_line);
            }
        }

        void copy(unique_ptr<node> &new_leaf, const unique_ptr<node> &old_leaf) {
            new_leaf = make_unique<node>(old_leaf->key_value);
            if (old_leaf->left) {
                copy(new_leaf->left, old_leaf->left);
            }

            if (old_leaf->right) {
                copy(new_leaf->right, old_leaf->right);
            }
        };

        unique_ptr<node> root;

};

inline ostream&
operator<<(ostream &os, btree &b) {
    b.print_leaf(b.root, true);
    return os;
}
